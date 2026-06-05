import s3minipro
from machine import Pin

# Power off the RGB LED
Pin(s3minipro.RGB_POWER,Pin.OUT,value=0)

# Init the IR pin
Pin(s3minipro.PIN_IR,Pin.OUT,value=0)
