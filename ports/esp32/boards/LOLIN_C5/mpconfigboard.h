// This configuration is for a generic ESP32C5 board with 4MiB (or more) of flash.

#define MICROPY_HW_BOARD_NAME               "LOLIN C5"
#define MICROPY_HW_MCU_NAME                 "ESP32C5"

#define MICROPY_HW_ENABLE_UART_REPL         (1)

#define MICROPY_HW_I2C0_SCL     (3)
#define MICROPY_HW_I2C0_SDA     (2)
