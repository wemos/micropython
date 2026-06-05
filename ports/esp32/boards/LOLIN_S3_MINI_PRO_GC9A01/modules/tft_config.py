"""LOLIN_S3_MINI_PRO
"""

from machine import Pin, SPI
import gc9a01

TFA = 0
BFA = 0
WIDE = 0
TALL = 1


def config(rotation=4, buffer_size=0, options=0):
    """Configure the display and return an instance of gc9a01.GC9A01."""

    spi = SPI(2, baudrate=40000000)
    return gc9a01.GC9A01(
        spi,
        128,
        128,
        reset=Pin(34, Pin.OUT),
        cs=Pin(35, Pin.OUT),
        dc=Pin(36, Pin.OUT),
        backlight=Pin(33, Pin.OUT),
        rotation=rotation,
        options=options,
        buffer_size=buffer_size
    )
