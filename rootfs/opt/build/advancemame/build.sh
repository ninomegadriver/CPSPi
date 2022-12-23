#!/bin/bash

make clean && \
LDFLAGS="-lwiringPi" \
CFLAGS="-w -mtune=cortex-a72 -mcpu=cortex-a72 -mfloat-abi=hard -mfpu=neon-fp-armv8 -O3" \
./configure --disable-sdl2 --disable-sdl --disable-ncurses --enable-vc --prefix=/usr && \
make -j4 && \ 
sudo cp /opt/build/advancemame/obj/mame/linux/blend/advmame /usr/bin/advmame-real && \
sudo cp /opt/build/advancemame/obj/mess/linux/blend/advmess /usr/bin/advmess && \
sudo cp /opt/build/advancemame/obj/menu/linux/blend/advmenu /usr/bin/advmenu  && \
sudo cp /opt/build/advancemame/advmame-fake /usr/bin/advmame && \
sudo cp /opt/build/advancemame/startup / && \
sudo cp /opt/build/advancemame/rc.local /etc/rc.local
sudo chmod 755 /usr/bin/advmame-real /usr/bin/advmess /usr/bin/advmenu /usr/bin/advmame /startup /etc/rc.local
sudo ln -s /mame /.advance 2>/dev/null
sudo ln -s /mame /root/.advance 2>/dev/null
sudo ln -s /mame /home/cpspi/.advance 2>/dev/null
sudo ln -s /mame /home/pi/.advance  2>/dev/null
