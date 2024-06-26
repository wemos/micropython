# base modules
include("$(PORT_DIR)/boards/manifest.py")

# uasyncio
include("$(MPY_DIR)/extmod/asyncio")

# drivers
require("ssd1306")

# micropython-lib: file utilities
require("upysh")

# micropython-lib: requests
require("urequests")
require("urllib.urequest")

# micropython-lib: umqtt
require("umqtt.simple")
require("umqtt.robust")

freeze("./modules")

require("sht3x")
