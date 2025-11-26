int	get_val(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1); // inválido
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	res = 0;
	int	val;

	if (str_base < 2 || str_base > 16)
		return (0);

	// sinal
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}

	// converter dígito a dígito
	while ((val = get_val(str[i])) != -1 && val < str_base)
	{
		res = res * str_base + val;
		i++;
	}
	return (res * sign);
}

