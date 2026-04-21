set(IDF_TARGET esp32c5)

set(SDKCONFIG_DEFAULTS
    boards/sdkconfig.base
    boards/sdkconfig.riscv
    boards/sdkconfig.ble
    boards/sdkconfig.240mhz
    boards/sdkconfig.free_ram
    boards/sdkconfig.spiram_sx
    boards/LOLIN_C5/sdkconfig.board
)
