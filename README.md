# Calculator_project
Calculator Application - Infix to Postfix Conversion and Evaluation

## Description
This project demonstrates a simple calculator that evaluates mathematical expressions in postfix notation. The system is implemented on an ATmega32 microcontroller, using custom drivers for the DIO, PORT, CLCD, and KEYPAD interfaces.

## Features:
Custom drivers for DIO, PORT, CLCD, and KEYPAD, providing low-level control over hardware.

Support for basic arithmetic operations (+, -, *, /).

Ability to handle multi-digit numbers and reject erroneous input.

Displays both postfix conversion and calculated results on a 16x2 LCD.

Keypad interface for user input, with real-time display of expressions and results.

## Components:
Microcontroller: ATmega32

Drivers: DIO, PORT, CLCD, KEYPAD (custom-written)

Input Device: 4x4 Keypad

Display: 16x2 LCD Display

## How it Works:
The user enters a mathematical expression via the keypad.
The input is converted to postfix notation using a stack-based algorithm.
The postfix expression is then evaluated, and the result is displayed on the LCD screen.

## vedio
![تصميم بدون عنوان](https://github.com/user-attachments/assets/241cbc9f-7bd7-4c39-af37-0eb8734a773e)
