#!/bin/bash
echo "[000/007] Setup Called"
echo "----------------------------------"

echo "[001/007] Updating apt"
sudo apt-get update -y
echo "----------------------------------"

echo "[002/007] installing git"
sudo apt-get install -y git
echo "----------------------------------"

echo "[003/007] Creating $HOME/rc-car"
[[ -d $HOME/rc-car ]] || mkdir $HOME/rc-car
echo "----------------------------------"

echo "[004/007] installing python-pip gcc"
sudo apt-get install -y python-pip gcc 
echo "----------------------------------"

echo "[005/007] pip install readchar"
sudo pip install readchar
echo "----------------------------------"

echo "[006/007] Cloning wiringPi"
git clone git://git.drogon.net/wiringPi
echo "----------------------------------"

echo "[007/007] Building wiringPi"
cd wiringPi; ./build
echo "----------------------------------"

echo "Done!"
