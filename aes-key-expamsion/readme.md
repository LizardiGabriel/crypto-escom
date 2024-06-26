# AES Key Expansion

## Table of Contents

- [run](#run)
- [Usage](#usage)

## run

compilar keygenerator.c:
'gcc -o keyGenerator keyGenerator.c -I/opt/homebrew/include -L/opt/homebrew/lib -lssl -lcrypto'

compilar main:
'gcc -o prueba main.c'


## Usage

The following algorithm expands a 128-bit key for AES to obtain 10 key rounds. It incorporates the following operations:

- **ROTWORD(B0, B1, B2, B3)**: Performs an acyclic shift of the four bytes B0, B1, B2, B3, i.e., ROTWORD(B0, B1, B2, B3) = B1, B2, B3, B0.

- **SUBWORD(B0, B1, B2, B3)**: Applies the S-box to each of the four bytes B0, B1, B2, B3, i.e., SUBWORD(B0, B1, B2, B3) = B′0, B′1, B′2, B′3.

- **Rcon**: An array of 10 words. These are constants in hexadecimal notation.

