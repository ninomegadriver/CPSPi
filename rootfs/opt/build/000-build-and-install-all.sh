#!/bin/bash

# Lame, but let's keep it as clean as possible...
export CFLAGS="-w"

echo First, install some needed packages...
sudo apt install -y git bc bison flex libssl-dev make build-essential autoconf automake

echo Building the modded Linux Kernel... hang on, this will take a good while...
cd /opt/build
/opt/build/kernel.sh

echo Building Wiring PI, needed for Advance Mame/Menu/Mess
cd /opt/build/WiringPi
sudo ./build

echo Building Advance Mame/Menu/Mess
cd /opt/build/advancemame/
./build.sh

if [ ! -f /boot/config.txt-org ]
then
	echo Backing up original config.txt
	sudo cp -aiv /boot/config.txt /boot/config.txt-org
fi

if [ ! -f /boot/cmdline.txt-org ]
then
	echo Backing up original cmdline.txt
	sudo cp -aiv /boot/cmdline.txt /boot/cmdline.txt-org
fi

echo Installing new cmdline.txt and config.txt
sudo cp /opt/build/cmdline.txt /boot/cmdline.txt
sudo cp /opt/build/config.txt /boot/config.txt

echo
echo If everthing was build without any issues,
echo connect your Raspberry PI to your arcade 
echo monitor via the VGA666 Interface.
echo
echo The PI should show up in the original CPS
echo resolution of 384x224 and go straight into
echo Advance Menu.
echo
echo Use P1 Button 1 to start a game
echo Use P2 Button 2 to start a clone
echo
echo P1 UP + P1 Start   \=\> Opens the Options Menu
echo P1 DOWN + P! Start \=\> Opens the Load/Save/Exit Menu
echo
echo Have fun!
echo \[\]\'s
echo Nino MegaDriver
