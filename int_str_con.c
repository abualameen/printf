/**
 * int_base_str - converts int to str
 * @num: num to be converted
 * @base: base of num
 * @str: buffer container
 * Return: 0
 */
void int_base_str(int num, int base, char str[])
{
	int i = 0;
	int j, sign;
	int digit;
	char temp;

	sign = num;
	if ((sign) < 0)
		num = -num;

	do {
		digit = num % base;
		if (digit < 10)
			str[i++] = digit + '0';
		else
			str[i++] = digit - 10 + 'a';
		} while ((num /= base) > 0);
		if (sign < 0)
			str[i++] = '-';

		str[i] = '\0';
		for (j = 0; j < i / 2; j++)
	{
			temp = str[j];
			str[j] = str[i - j - 1];
			str[i - j - 1] = temp;
	}
}

