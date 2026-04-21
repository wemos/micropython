#!/bin/bash

if which nproc > /dev/null; then
    MAKEOPTS="-j$(nproc)"
else
    MAKEOPTS="-j$(sysctl -n hw.ncpu)"
fi

function ci_lolin_build {
    source esp-idf/export.sh
    make ${MAKEOPTS} -C mpy-cross
    make ${MAKEOPTS} -C ports/esp32 submodules
    
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_C3_MINI
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_S2_MINI
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_S2_PICO
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_S3
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_C3_PICO
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_D32
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_D32_PRO
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_S3_PRO
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_S3_MINI
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_S3_MINI_PRO
    make ${MAKEOPTS} -C ports/esp32 BOARD=LOLIN_C5

}


function ci_esp8266_build {
    make ${MAKEOPTS} -C mpy-cross
    make ${MAKEOPTS} -C ports/esp8266 submodules
    make ${MAKEOPTS} -C ports/esp8266 BOARD=LOLIN_D1_MINI
}

function ci_gc9a01_mpy_setup {
    git clone https://github.com/wemos/gc9a01_mpy.git ../gc9a01_mpy
    # find ~/ -name "gc9a01*"
    # find ~/ -name "micropython"
}

function ci_st7789_mpy_setup {
    git clone https://github.com/wemos/st7789_mpy.git ../st7789_mpy
}
