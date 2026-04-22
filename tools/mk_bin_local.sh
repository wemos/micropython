#!/bin/bash

# build esp32 boards
source tools/ci_lolin.sh && ci_lolin_build

# Change firmware name
python ./tools/lolin_tool.py
