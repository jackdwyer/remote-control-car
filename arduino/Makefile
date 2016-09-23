.PHONY: all nunchuck

all:
	sudo arduino --upload Fade/Fade.ino --board arduino:avr:micro --port /dev/ttyACM0

nunchuck:
	sudo arduino --upload Nunchuck/Nunchuck.ino --board arduino:avr:micro --port /dev/ttyACM0

console:
	screen /dev/ttyACM0 19200
