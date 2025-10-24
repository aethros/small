#!/usr/bin/env bash

# This is a script to build a small c executable on linux.
# Smaller executables could be made by removing the symbol
# table for example, but this is retained in this example 
# to show the relationships between the c program and it's
# ELF output/assembly code.

#cc \                              # Compile the program
#  -static \                       # Produce a fully static executable (no external dependencies)
#  -nostdlib \                     # Don't link libc/start files
#  -ffunction-sections \           # Maintain sections in the ELF for each function
#  -fdata-sections \               # Maintain sections in the ELF for each data object
#  -fno-asynchronous-unwind-tables \  # No .eh_frame unwind info
#  -fno-ident \                    # No .comment section
#  -Wl,--gc-sections \             # Linker removes unused sections
#  -Wl,--strip-debug \             # Remove debug info sections but keep symbol names
#  -Wl,-z,norelro \                # Disable RELRO (Read-Only Relocations) Safety
#  small.c \                       # Input source file
#  -o small                        # Output binary

#strip \                           # Strip symbols from a binary
#  --remove-section=.comment \     # Remove .comment metadata
#  --remove-section=.eh_frame \    # Remove unwind info
#  --remove-section=.shstrtab \    # Remove the Section Header String Table
#  ./small                         # Target executable

cc \
 -static \
 -nostdlib \
 -ffunction-sections \
 -fdata-sections \
 -fno-asynchronous-unwind-tables \
 -fno-ident \
 -Wl,--gc-sections \
 -Wl,--strip-debug \
 -Wl,-z,norelro \
 small.c \
 -o small

strip --strip-debug \
 --remove-section=.comment \
 --remove-section=.eh_frame \
 --remove-section=.shstrtab \
 small
