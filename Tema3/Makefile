# Copyright PCLP Team, 2025

# Compiler setup.
CC=gcc
CFLAGS=-Wall -Wextra -std=c99

# Define targets, e.g., ninel, codeinvim, vectsecv, nomogram.
TARGETS=runic

# Manually define all targets.
build: $(TARGETS)

runic: runic.c
	$(CC) $(CFLAGS) runic.c -o runic


# Pack the solution into a zip file.
pack:
	zip -FSr 3XYCA_FirstnameLastname_Tema0.zip README Makefile *.c *.h

# Clean the solution.
clean:
	rm -f $(TARGETS)

.PHONY: pack clean
