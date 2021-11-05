#include "shared-bindings/board/__init__.h"

#include "supervisor/board.h"

STATIC const mp_rom_map_elem_t board_module_globals_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    // With USB on left. Bottom edge.
    { MP_OBJ_NEW_QSTR(MP_QSTR_D0), MP_ROM_PTR(&pin_GPIO_AD_B0_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_RX), MP_ROM_PTR(&pin_GPIO_AD_B0_03) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_RX1), MP_ROM_PTR(&pin_GPIO_AD_B0_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D1), MP_ROM_PTR(&pin_GPIO_AD_B0_02) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_TX), MP_ROM_PTR(&pin_GPIO_AD_B0_02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_TX1), MP_ROM_PTR(&pin_GPIO_AD_B0_02) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D2), MP_ROM_PTR(&pin_GPIO_EMC_04) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D3), MP_ROM_PTR(&pin_GPIO_EMC_05) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D4), MP_ROM_PTR(&pin_GPIO_EMC_06) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D5), MP_ROM_PTR(&pin_GPIO_EMC_08) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D6), MP_ROM_PTR(&pin_GPIO_B0_10) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D7), MP_ROM_PTR(&pin_GPIO_B1_01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D8), MP_ROM_PTR(&pin_GPIO_B1_00) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D9), MP_ROM_PTR(&pin_GPIO_B0_11) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D10), MP_ROM_PTR(&pin_GPIO_B0_00) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D11), MP_ROM_PTR(&pin_GPIO_B0_02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_GPIO_B0_02) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D12), MP_ROM_PTR(&pin_GPIO_B0_01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_GPIO_B0_01) },

    // Bottom Edge extended for 4.1
    { MP_OBJ_NEW_QSTR(MP_QSTR_D24), MP_ROM_PTR(&pin_GPIO_AD_B0_12) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A10), MP_ROM_PTR(&pin_GPIO_AD_B0_12) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D25), MP_ROM_PTR(&pin_GPIO_AD_B0_13) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A11), MP_ROM_PTR(&pin_GPIO_AD_B0_13) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D26), MP_ROM_PTR(&pin_GPIO_AD_B1_14) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A12), MP_ROM_PTR(&pin_GPIO_AD_B1_14) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D27), MP_ROM_PTR(&pin_GPIO_AD_B1_15) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A13), MP_ROM_PTR(&pin_GPIO_AD_B1_15) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D28), MP_ROM_PTR(&pin_GPIO_EMC_32) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D29), MP_ROM_PTR(&pin_GPIO_EMC_31) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D30), MP_ROM_PTR(&pin_GPIO_EMC_37) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D31), MP_ROM_PTR(&pin_GPIO_EMC_36) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D32), MP_ROM_PTR(&pin_GPIO_B0_12) },

    // Top edge
    { MP_OBJ_NEW_QSTR(MP_QSTR_D13), MP_ROM_PTR(&pin_GPIO_B0_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_LED), MP_ROM_PTR(&pin_GPIO_B0_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_GPIO_B0_03) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D14), MP_ROM_PTR(&pin_GPIO_AD_B1_02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A0), MP_ROM_PTR(&pin_GPIO_AD_B1_02) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D15), MP_ROM_PTR(&pin_GPIO_AD_B1_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A1), MP_ROM_PTR(&pin_GPIO_AD_B1_03) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D16), MP_ROM_PTR(&pin_GPIO_AD_B1_07) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A2), MP_ROM_PTR(&pin_GPIO_AD_B1_07) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D17), MP_ROM_PTR(&pin_GPIO_AD_B1_06) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A3), MP_ROM_PTR(&pin_GPIO_AD_B1_06) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D18), MP_ROM_PTR(&pin_GPIO_AD_B1_01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A4), MP_ROM_PTR(&pin_GPIO_AD_B1_01) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_GPIO_AD_B1_01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SDA0), MP_ROM_PTR(&pin_GPIO_AD_B1_01) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D19), MP_ROM_PTR(&pin_GPIO_AD_B1_00) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A5), MP_ROM_PTR(&pin_GPIO_AD_B1_00) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_GPIO_AD_B1_00) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_SCL0), MP_ROM_PTR(&pin_GPIO_AD_B1_00) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D20), MP_ROM_PTR(&pin_GPIO_AD_B1_10) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A6), MP_ROM_PTR(&pin_GPIO_AD_B1_10) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D21), MP_ROM_PTR(&pin_GPIO_AD_B1_11) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A7), MP_ROM_PTR(&pin_GPIO_AD_B1_11) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D22), MP_ROM_PTR(&pin_GPIO_AD_B1_08) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A8), MP_ROM_PTR(&pin_GPIO_AD_B1_08) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D23), MP_ROM_PTR(&pin_GPIO_AD_B1_09) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_A9), MP_ROM_PTR(&pin_GPIO_AD_B1_09) },

    // Top edge extended for Teensy 4.1
    { MP_OBJ_NEW_QSTR(MP_QSTR_D33), MP_ROM_PTR(&pin_GPIO_EMC_07) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D34), MP_ROM_PTR(&pin_GPIO_B1_13) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D35), MP_ROM_PTR(&pin_GPIO_B1_12) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D36), MP_ROM_PTR(&pin_GPIO_B1_02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D37), MP_ROM_PTR(&pin_GPIO_B1_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D38), MP_ROM_PTR(&pin_GPIO_AD_B1_12) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D39), MP_ROM_PTR(&pin_GPIO_AD_B1_13) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D40), MP_ROM_PTR(&pin_GPIO_AD_B1_04) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D41), MP_ROM_PTR(&pin_GPIO_AD_B1_05) },

    // SD Card slot
    { MP_OBJ_NEW_QSTR(MP_QSTR_DAT1), MP_ROM_PTR(&pin_GPIO_SD_B0_03) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D42), MP_ROM_PTR(&pin_GPIO_SD_B0_03) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_DAT0), MP_ROM_PTR(&pin_GPIO_SD_B0_02) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D43), MP_ROM_PTR(&pin_GPIO_SD_B0_02) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_CLK), MP_ROM_PTR(&pin_GPIO_SD_B0_01) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D44), MP_ROM_PTR(&pin_GPIO_SD_B0_01) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_CMD), MP_ROM_PTR(&pin_GPIO_SD_B0_00) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D45), MP_ROM_PTR(&pin_GPIO_SD_B0_00) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_DAT3), MP_ROM_PTR(&pin_GPIO_SD_B0_05) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D46), MP_ROM_PTR(&pin_GPIO_SD_B0_05) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_DAT2), MP_ROM_PTR(&pin_GPIO_SD_B0_04) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_D47), MP_ROM_PTR(&pin_GPIO_SD_B0_04) },

    // Flash expansion spot and PSRAM expansion spot on a shared QSPI BUS
    { MP_OBJ_NEW_QSTR(MP_QSTR_D48), MP_ROM_PTR(&pin_GPIO_EMC_24) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_PSRAM_CS), MP_ROM_PTR(&pin_GPIO_EMC_24) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D49), MP_ROM_PTR(&pin_GPIO_EMC_27) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_QSPI_IO1), MP_ROM_PTR(&pin_GPIO_EMC_27) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D50), MP_ROM_PTR(&pin_GPIO_EMC_28) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_QSPI_IO2), MP_ROM_PTR(&pin_GPIO_EMC_28) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D51), MP_ROM_PTR(&pin_GPIO_EMC_22) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_FLASH_CS), MP_ROM_PTR(&pin_GPIO_EMC_22) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D52), MP_ROM_PTR(&pin_GPIO_EMC_26) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_QSPI_IO0), MP_ROM_PTR(&pin_GPIO_EMC_26) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D53), MP_ROM_PTR(&pin_GPIO_EMC_25) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_QSPI_CLK), MP_ROM_PTR(&pin_GPIO_EMC_25) },

    { MP_OBJ_NEW_QSTR(MP_QSTR_D54), MP_ROM_PTR(&pin_GPIO_EMC_29) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_QSPI_IO3), MP_ROM_PTR(&pin_GPIO_EMC_29) },

    { MP_ROM_QSTR(MP_QSTR_I2C), MP_ROM_PTR(&board_i2c_obj) },
    { MP_ROM_QSTR(MP_QSTR_SPI), MP_ROM_PTR(&board_spi_obj) },
    { MP_ROM_QSTR(MP_QSTR_UART), MP_ROM_PTR(&board_uart_obj) },
};
MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);