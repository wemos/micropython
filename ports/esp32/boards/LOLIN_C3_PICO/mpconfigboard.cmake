include(boards/mpconfigboard_esp32c3_common.cmake)

list(APPEND SDKCONFIG_DEFAULTS
    ${MICROPY_BOARD_DIR}/sdkconfig.board)

set(MICROPY_FROZEN_MANIFEST ${MICROPY_BOARD_DIR}/manifest.py)
