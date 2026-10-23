*This project has been created as part of the 42 curriculum by maratana*

ft_printf

Description"
The ft_printf project aims to recreate the behavior of the standard printf() function using variadic arguments.

The function formats and prints different data types to standard output while returning the number of characters printed.

Instructions:

Compilation

Run the following command to compile the library:

make - This generates the static library libftprintf.a.

Other available Makefile commands:

make clean — removes object files.

make fclean — removes object files and libftprintf.a.

make re — recompiles the library from scratch.

Suported formats:

%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The void * pointer argument has to be printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.

Resources:

C standard library manual pages (man)

ChatGpt - research and explanation of new concepts.