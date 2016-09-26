.PHONY: all nunchuck

all:
	sudo arduino --upload Fade/Fade.ino --board arduino:avr:micro --port /dev/ttyACM0

nunchuck:
	sudo arduino --upload Nunchuck/Nunchuck.ino --board arduino:avr:micro --port /dev/ttyACM0

controller:
	sudo arduino --upload Controller/Controller.ino --board arduino:avr:micro --port /dev/ttyACM0

controller-verify:
	sudo arduino --verify Nunchuck/Nunchuck.ino

console:
	screen /dev/ttyACM0 9600
