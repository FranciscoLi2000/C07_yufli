#include "ft_convert_base.h"
#include <unistd.h>
#include <stdlib.h>
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	base_from_len;
	int	base_to_len;
	int	n;

	base_from_len = check_base(base_from);
	base_to_len = check_base(base_to);
	if (base_from_len == 0 || base_to_len == 0)
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	return (ft_putnbr_base(n, base_to));
}
#include <stdio.h>
int	main()
{
	char	*result;
	char	*nbr;
	char	*base_from;
	char	*base_to;

	nbr = "2025";
	base_from = "0123456789";
	base_to = "0123456789ABCDEF";
	result = ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", result);
	free(result);
	return (0);
}
