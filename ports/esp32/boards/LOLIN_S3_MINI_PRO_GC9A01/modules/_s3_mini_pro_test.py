# coding: utf-8
import s3minipro
import gc9a01
import tft_config
import vga1_8x16 as font
import vga1_16x16 as font16
import time
import qmi8658 as imu
from machine import I2C
from machine import Pin
import machine
import utime
import gc
import network
import esp32_rmt_ir as rmt_ir


# gc.collect()

wlan = network.WLAN(network.STA_IF)
wlan.active(True)

page_state=0
MAX_PAGE=3
tft = tft_config.config()

qmi=imu.QMI8658(I2C(0))

ir=rmt_ir.ESP32_RMT_IR(s3minipro.PIN_IR)

while(ir.available==0):
    ir=rmt_ir.ESP32_RMT_IR(s3minipro.PIN_IR)


print("Alreay...")

class Interrupt:
    def __init__(self,
                 pin,
                 pull=machine.Pin.PULL_UP,
                 trigger=machine.Pin.IRQ_RISING,
                 time=1000,
                 before=None,
                 final=None):
        self.pin = machine.Pin(pin, machine.Pin.IN, pull)
        self.trigger = trigger
        self.time = time
        self.last_time = utime.ticks_ms()
        self.before = before
        self.final = final

    def __call__(self, func):
        def wrapped_func(*args, **kwargs):
            if self.before is not None:
                self.before()
            this_time = utime.ticks_ms()
            res = None
            if this_time - self.last_time > self.time:
                self.pin.irq(handler=None)
                res = func(*args, **kwargs)
                self.pin.irq(handler=wrapped_func)
                self.last_time = this_time
            if self.final is not None:
                self.final()
            return res
        self.pin.irq(trigger=self.trigger, handler=wrapped_func)
        return wrapped_func



@Interrupt(0, time=300)
def handler(pin):
    global page_state

    s3minipro.rgb_led(0,0,0)

    if(page_state>0):
        page_state=page_state-1
        dis_page()
        # test()

    print(page_state)
    

@Interrupt(47, time=300)
def handler(pin):
    global ir
    if(page_state==1):
        ir.send_NEC(0x5F,0x41)
    # print("ok")

    
    


@Interrupt(48, time=300)
def handler(pin):
    global page_state,MAX_PAGE

    s3minipro.rgb_led(0,0,0)

    if(page_state<MAX_PAGE-1):
        page_state=page_state+1
        dis_page()
        # test()
    
    print(page_state)


def dis_page():
    global page_state,tft
    tft.rotation(4)
    tft.fill(gc9a01.BLACK)
    

    if(page_state==0):
        tft.text(font16, "IMU&RGB", 0, 0, gc9a01.GREEN, gc9a01.BLACK)
    elif(page_state==1):
        tft.text(font16, "IR", 0, 0, gc9a01.GREEN, gc9a01.BLACK)
        tft.text(font, "OK - SEND", 0, 16, gc9a01.YELLOW, gc9a01.BLACK)
    elif(page_state==2):
        tft.text(font16, "WIFI", 0, 0, gc9a01.GREEN, gc9a01.BLACK)

def dis_wifi():
    global tft,wlan,page_state
    nets=wlan.scan()
    print("\r\nnum=" + str(len(nets)))
    i=0
    for n in nets:
        if(n[0]!=b''and n[0]!=b' '):
            tft.text(font, "{:<13s}{:>3d}".format(n[0][0:12],n[3]), 0, 16+16*i, gc9a01.YELLOW, gc9a01.BLACK)
            i=i+1
            if(i>6):
                break
    
    while(1):
        if(page_state!=2):
            dis_page()
            return -1



def test_imu_rgb():

    global qmi,tft,page_state

    rgb_led_state=[(0,0,0),(2,0,0),(0,2,0),(0,0,2),(1,1,1)]
    
    while(1):
        for led in rgb_led_state:
            if(page_state!=0):
                dis_page()
                break
            gx,gy,gz=qmi.read_gyro()
            ax,ay,az=qmi.read_accel()

            tft.text(font, "Acc_X: {:>9.3f}".format(ax), 0, 16, gc9a01.YELLOW, gc9a01.BLACK)
            tft.text(font, "Acc_Y: {:>9.3f}".format(ay), 0, 32, gc9a01.YELLOW, gc9a01.BLACK)
            tft.text(font, "Acc_Z: {:>9.3f}".format(az), 0, 48, gc9a01.YELLOW, gc9a01.BLACK)
            tft.text(font, "Gyr_X: {:>9.3f}".format(gx), 0, 64, gc9a01.YELLOW, gc9a01.BLACK)
            tft.text(font, "Gyr_Y: {:>9.3f}".format(gy), 0, 80, gc9a01.YELLOW, gc9a01.BLACK)
            tft.text(font, "Gyr_Z: {:>9.3f}".format(gz), 0, 96, gc9a01.YELLOW, gc9a01.BLACK)

            s3minipro.rgb_led(led[0],led[1],led[2])
            
            for i in range(5):
                time.sleep(0.1)
                if(page_state!=0):
                    dis_page()
                    return -1
                

def test():
    if(page_state==0):
        test_imu_rgb()
    elif(page_state==1):
        
        pass

    elif(page_state==2):
        dis_wifi()
        pass

def main():

    global page_state,tft

    
    Pin(s3minipro.RGB_POWER,Pin.OUT,value=1)

    tft.init()
    tft.offset(2,1)  #offset for 0.85  GC9107 
    tft.fill(gc9a01.BLACK)

    dis_page()
    

    while(1):
        test()
        
main()