# LOLIN S3 MINI MicroPython Helper Library

from micropython import const
from machine import Pin
import neopixel

# Pin Assignments

# SPI
SPI_MOSI = const(38)
SPI_MISO = const(39)
SPI_CLK = const(40)

# TFT
TFT_BL = const(33)
TFT_DC = const(36)
TFT_CS = const(35)
TFT_RST = const(34)

# I2C
I2C_SDA = const(12)
I2C_SCL = const(11)

# RGB_LED
RGB_POWER = const(7)
RGB_DATA = const(8)
_rgb_led = neopixel.NeoPixel(Pin(RGB_DATA), 1)

# IR
PIN_IR = const(9)


def rgb_led(r=0, g=0, b=0):
    _rgb_led[0] = (g, r, b)
    _rgb_led.write()

# BUTTON
BUTTON0 = const(0)
button0= Pin(BUTTON0, Pin.IN, Pin.PULL_UP)
BUTTON47 = const(47)
button47= Pin(BUTTON47, Pin.IN, Pin.PULL_UP)
BUTTON48 = const(48)
button48= Pin(BUTTON48, Pin.IN, Pin.PULL_UP)
