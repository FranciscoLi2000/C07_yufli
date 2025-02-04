#include "ft_convert_base.h"
#include <unistd.h>
#include <stdlib.h>
int	check_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == 0 || base[1] == 0)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] <= ' ' || base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}
int	get_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	digit;
	int	base_len;

	result = 0;
	sign = 1;
	base_len = check_base(base);
	if (base_len == 0)
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	digit = get_value(*str, base);
	while (digit >= 0)
	{
		result = result * base_len + digit;
		str++;
	}
	return (result * sign);
}
char	*ft_putnbr_base(int nbr, char *base)
{
	char	*result;
	int	len;
	int	temp;
	int	base_len;
	unsigned int	n;

	base_len = check_base(base);
	if (base == 0)
		return (NULL);
	if (nbr < 0)
		n = (unsigned int)-nbr;
	else
		n = (unsigned int)nbr;
	temp = n;
	if (nbr <= 0)
		len = 2;
	else
		len = 1;
	while (temp)
	{
		temp = temp / base_len;
		len++;
	}
	result = malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	result[--len] = '\0';
	while (len--)
	{
		result[len] = base[n % base_len];
		n = n / base_len;
	}
	if (nbr < 0)
		result[0] = '-';
	return (result);
}
