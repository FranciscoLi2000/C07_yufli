#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	i;

	if (min < max)
		len = max - min;
	else
		len = min - max;
	tab = malloc((len + 1) * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (min < max)
			tab[i] = min++;
		else
			tab[i] = max++;
		i++;
	}
	return (tab);
}
