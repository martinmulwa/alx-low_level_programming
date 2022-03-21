#include "main.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str1, *str2, *str3, *str4;

    str1 = "0123456789";
	str2 = "";
	str3 = "0";
	str4 = "12345";

    puts_half(str1);
	puts_half(str2);
	puts_half(str3);
	puts_half(str4);

    return (0);
}
