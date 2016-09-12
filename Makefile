.PHONY: upload console setup deploy

upload:
	scp nunchuck_reader.c controller.py $(RPI_USER)@$(RPI_HOST):~/rc-car/

console:
	ssh $(RPI_USER)@$(RPI_HOST)

setup:
	scp setup.sh $(RPI_USER)@$(RPI_HOST):~/setup.sh
	ssh $(RPI_USER)@$(RPI_HOST) /home/$(RPI_USER)/setup.sh
	@ echo "Setup Complete"
	@ echo "----------------------------------"

deploy: setup upload
