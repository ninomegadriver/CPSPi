#!/bin/bash

echo Installing Dependencies
sudo apt install -y netpbm git bc bison flex libssl-dev make build-essentials

# Replacing the Logo
for i in `find ./linux -name "*224.ppm"`
do
	echo Processando $i...
	pngtopnm kernel_logo.png | ppmquant 224| pnmtoplainpnm > $i
done

rm -rf linux/drivers/video/logo/*.o

echo Building Kernel
cd linux
make -j4 zImage modules dtbs
echo Installing new Kernel...
sudo make modules_install
sudo cp arch/arm/boot/dts/*.dtb /boot/
sudo cp arch/arm/boot/dts/overlays/*.dtb* /boot/overlays/
sudo cp arch/arm/boot/dts/overlays/README /boot/overlays/
sudo cp arch/arm/boot/zImage /boot/cpspi.img
echo Replacing "config.txt" and "cmdline.txt"
cd /opt/build
sudo cp /opt/build/cmdline.txt /boot/
sudo cp /opt/build/config.txt /boot/
echo "Next time you boot, be sure to have your pi connected to the arcade monitor via VGA666 Interface. The system will boot under the CPS Resolution of 384x224

