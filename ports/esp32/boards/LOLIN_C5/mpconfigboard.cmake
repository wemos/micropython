include(boards/mpconfigboard_esp32c5_common.cmake)

list(APPEND SDKCONFIG_DEFAULTS
    boards/sdkconfig.free_ram
    # boards/sdkconfig.spiram_quad
    ${MICROPY_BOARD_DIR}/sdkconfig.board
)

set(MICROPY_FROZEN_MANIFEST ${MICROPY_BOARD_DIR}/manifest.py)
