# Bangladesh ASCII Map Generator in C

A C program that uses a run-length decompression algorithm to generate a pixel-perfect ASCII art map of Bangladesh in the terminal.

This project is designed as a well-commented example of using a simple decompression engine to generate complex visual output from compact data. It's a great project for students and those new to C, with detailed comments in both English and "Banglish".

---

## Final Output Screenshot

![Bangladesh ASCII Map Output](https://i.imgur.com/IiXpWmg.png)

---

## How to Compile and Run

This program is written in standard C (C99/C11) and can be compiled with any modern C compiler like GCC, which is commonly available on Windows (via MinGW), macOS, and Linux.

### 1. Compilation

Open a terminal or command prompt and run the following command to compile the code:

```sh
gcc main.c -o map_generator

2. Execution
Run the newly created program from your terminal:
code
Sh
./map_generator

3. Usage
The program will then prompt you to enter a country name. Type Bangladesh and press Enter to see the map.
code
Code
Enter country name: Bangladesh

About the Code
The core of this program is the generateMapFromCompressedData function. Instead of storing the map as a large visual block of text, it is stored as a highly compressed string of data.
For example, the code 19s1a1n means:
19s: Print 19 spaces ('s').
1a: Print 1 asterisk ('a').
1n: Print 1 new line ('n').
The function reads this code segment by segment and "decompresses" it to build the map on the screen. This is a very efficient and clever way to store complex visual data.
