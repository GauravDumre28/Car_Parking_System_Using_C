##############################################################
		## MakeFile ##
##############################################################


##############################################################

# Folder #
IDIR = Header_File
SRC = ./Source_File
ODIR = ./Object_File

# Executable File Name #
EXEC = ./Executable_File/Linked_List

# Commands and Flags #
CC = gcc
CFLAGS = -I$(IDIR) -Wall -Werror -g
RMV = rm -f
LIST = ls -aR

##############################################################


##############################################################

# Substituting Header File #
_DEPS = header.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

# Substitute Relocatable Object File in Object Folder #
source := $(shell find $(SRC) -name "*.c")
objects := $(patsubst $(SRC)/%.c, $(ODIR)/%.o, $(source))

# Generating Relocatable Object File #
$(ODIR)/%.o:$(SRC)/%.c
	$(CC) $(CFLAGS) $(OBJFLAG) -c -o $@ $<

# Generating Executable File #
$(EXEC): $(objects)
	$(CC) $(CFLAGS) $(OBJFLAG) -o $@ $^

##############################################################


##############################################################

# Assigning Phony Targets #
.PHONY: clean run list

# Removes Relocatable Object File and Executable File #
# > make clean #
clean:
	$(RMV) $(ODIR)/*.o $(EXEC)

# Executes Code #
# > make run #
run:
	./$(EXEC)

# List All Directory Content Recursively #
# > make list #
list:
	$(LIST)

##############################################################
