.PHONY: upload console setup deploy controller

upload:
	scp Makefile controller.c nunchuck_reader.c controller.py $(RPI_USER)@$(RPI_HOST):~/rc-car/

console:
	ssh $(RPI_USER)@$(RPI_HOST)

controller:
	gcc -Wall -o controller controller.c -lwiringPi

nunchuck:
	gcc -Wall -lwiringPi -o nunchuck_reader nunchuck_reader.c 

deploy: upload

setup:
	scp setup.sh $(RPI_USER)@$(RPI_HOST):~/setup.sh
	# ssh $(RPI_USER)@$(RPI_HOST) /home/$(RPI_USER)/setup.sh
	# @ echo "Setup Complete"
	# @ echo "----------------------------------"
