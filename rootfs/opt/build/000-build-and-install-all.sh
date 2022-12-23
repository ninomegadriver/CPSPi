#!/bin/bash

echo Building Kernel...
cd /opt/build
/opt/build/kernel.sh

echo Building Wiring PI...
cd /opt/build/WiringPi
sudo ./build

echo Build bannerd...
cd /opt/build/bannerd
make && sudo cp bannerd /usr/bin/bannerd

echo Building Advance Mame
cd /opt/build/advancemame/

echo If everthing was built without any issues,
echo connect your Raspberry PI to your arcade 
echo monitor via the VGA666 Interface.
echo The PI should show up in the original CPS
echo resolution of 384x224 and go straight into
echo Advance Menu.
echo .
echo Use P1 Button 1 to start a game
echo Use P2 Button 2 to start a clone
echo P1 UP + P1 Start   => Opens the Options Menu
echo P1 DOWN + P! Start => Opens the Load/Save/Exit Menu
echo.
echo Have fun!
echo \[\]\'s
echo Nino MegaDriver
