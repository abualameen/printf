#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * int_base_str - function convert unsigned int to str
 * @num: num to be converted
 * @base: base of to be convertee
 * Return: 0
 */

char* unsigned_int_Base_String(unsigned int num, int base)
{
	char* digits = "0123456789ABCDEF";
	char* result = malloc(32);
	int indx = 0;
	int t, j, temp; 
	do
	{
		result[indx++] = digits[num % base];
		num /= base;
	}while (num != 0);
	t = 0;
	j = indx -1;
	while (t < j)
	{
		temp = result[t];
		result[t++] = result[j];
		result[j--] = temp;	
	}
	result[indx] = '\0';
	return (result);
}
