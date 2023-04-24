#include "main.h"
/**
 * int_base_str - the func convert int to str
 * @num: num to be converted
 * @base: the to be converted to
 * @str: container for the converted str
 * Return: 0
 */

void int_base_str(int num, int base, char str[])
{
        int i = 0;
        int j, sign;
        char temp;
        int dgt;

        if ((sign = num) < 0)
        {
                num = -num;
        }
        do
        {
                dgt = num % base;
                if (dgt < 10)
                {
                        str[i++] = dgt + '0';
                }
                else
                {
                        str[i++] = dgt - 10 + 'a';
                }
        }while ((num /= base) > 0);
        if (sign < 0)
        {
                str[i++] = '-';
        }
        str[i] = '\0';
        for (j = 0; j < i / 2; j++)
        {
                temp = str[j];
                str[j] = str[i - j - 1];
                str[i -j - 1] = temp;
        }
}
