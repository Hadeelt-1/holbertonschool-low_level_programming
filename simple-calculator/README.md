# Simple Calculator

A small terminal program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division, allowing the user to choose an operation from a menu and exit the program by selecting Quit.

## Compile

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

## Run

./calculator


## Supported Operations

	1. Addition
	2. Subtraction
	3. Multiplication
	4. Division
	5. Quit


## Numeric Behavior

The program uses decimal numbers (double). I chose the double data type because some division operations produce decimal results. For example, 7 divided by 2 equals 3.5, so using double allows the program to handle and display decimal numbers accurately.


## Known Limitations

- If the user types a non-numeric input (for example: x or hello),
  the program may loop indefinitely.

