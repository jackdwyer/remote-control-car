upload:
	scp controller.py $(RPI_USER)@$(RPI_HOST):~/rc-car/

console:
	ssh $(RPI_USER)@$(RPI_HOST)
