
# ft_printf - A Simple Printf Clone

## Description
ft_printf is a custom implementation of the standard printf function in C. It mimics the behavior of printf by handling a variety of format specifiers to print characters, strings, integers, hexadecimal numbers, pointers, and more. This project was built to deepen understanding of variable argument lists (va_list) and custom formatting in C.

## Features
#### Supports format specifiers:

- **%c** - *Character*
- **%s** - *String*
- **%d** and **%i** - *Signed integers*
- **%u** - *Unsigned integers*
- **%x** - *Lowercase hexadecimal*
- **%X** - *Uppercase hexadecimal*
- **%p** - *Pointers/memory address*
- **%%** - *Literal percent sign*

#### Handles the edge case of null pointers and strings.

## Functions
- *ft_printf(const char \*str, ...):* The main function that processes the format string and arguments. It returns the total number of characters printed.
- *ft_putchar(char c):* Prints a single character.
- *ft_putstr(char \*s):* Prints a string. If the string is NULL, prints "(null)".
- *ft_putnbr_dec(long nb):* Prints a signed decimal number.
- *ft_putnbr_hex(unsigned long long nb, int up_or_low):* Prints a hexadecimal number in lowercase or uppercase based on the flag.
- *ft_putptr(void \*ptr):* Prints a pointer in the format 0x<hex_address>.
