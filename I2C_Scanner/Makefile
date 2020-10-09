CC 		= arduino-cli
BOARD 	= arduino:avr:nano
FILE 	= i2c_scanner

all:
	$(CC) compile --fqbn $(BOARD) ./$(FILE)

upload:
	$(CC) upload ./$(FILE)
