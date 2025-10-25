#!/usr/bin/env bash

# This is a script to build a small c executable on linux.
# Smaller executables could be made by removing the symbol
# table for example, but this is retained in this example 
# to show the relationships between the c program and it's
# ELF output/assembly code.

#cc \                              # Compile the program
#  -s \                            # Strip symbols from program
#  -static \                       # Produce a fully static executable
#  -nostdlib \                     # Don't link libc/start files
#  small.c \                       # Input source file
#  -o small                        # Output binary

#strip \                           # Strip symbols from a binary
#  --strip-all \                   # Remove all metadata
#  --remove-section=.comment \     # Remove .comment metadata
#  --remove-section=.eh_frame \    # Remove unwind info
#  ./small                         # Target executable

cc \
 -s \
 -static \
 -nostdlib \
 small.c \
 -o small

strip \
 --strip-all \
 --remove-section=.comment \
 --remove-section=.eh_frame \
 small
