# Small

A minimalist C program that demonstrates low-level programming without external dependencies on Linux.

## Overview

This project shows how to build a C program that runs directly on Linux without the standard library (`libc`). It uses direct system calls to interact with the kernel and implements a simple command executor.

## Features

- No external dependencies (compiled with `-nostdlib`)
- Direct system calls via inline assembly
- Support for aarch64 architecture (x86_64 notes in comments)
- Minimal binary size through stripping and aggressive optimization
- Custom `_start` entry point

## Building

```sh
./mksmall.sh
```

The compiled `small` binary will be placed in the current directory.

## Usage

```sh
./small </path/to/command> [args...]
```

The program executes the specified command with the provided arguments.

## Architecture

- [`small.c`](small.c) - Minimal Program
- [`mksmall.sh`](mksmall.sh) - Builder shell script

## Requirements

- aarch64 Linux (x86_64 notes in comments)
- GCC

## Note

This program is Linux-specific due to the stable syscall ABI. MacOS and Windows require external dependencies (`libSystem.dylib` and `kernel32.dll` respectively) to function across OS versions.
