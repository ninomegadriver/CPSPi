#!/bin/bash

make -j4 && sudo cp obj/mame/linux/blend/advmame /usr/bin/advmame-real && sudo cp obj/mess/linux/blend/advmess /usr/bin/advmess && sudo cp obj/menu/linux/blend/advmenu /usr/bin/advmenu && sudo ./advmame sf2ce
