#!/bin/bash

echo "[000] Setup Called"
echo "----------------------------------"
echo "[001] Creating $HOME/rc-car"
[[ -d $HOME/rc-car ]] || mkdir $HOME/rc-car
echo "----------------------------------"
echo "[002] installing python-pip gcc"
sudo apt-get install -y python-pip gcc 
echo "----------------------------------"
echo "[003] pip install readchar"
sudo pip install readchar
echo "----------------------------------"
echo "Done!"
