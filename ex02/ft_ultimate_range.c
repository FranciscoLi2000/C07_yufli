#include <stdlib.h>
int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	*range;
	int	size;
	int	i;

	if (argc < 3)
		return (-1);
	size = ft_ultimate_range(&range, atoi(argv[1]), atoi(argv[2]));
	if (size > 0)
	{
		i = 0;
		while (i < size)
		{
			printf("%i ", range[i]);
			i++;
		}
		printf("\n");
	}
	free(range);
	return (0);
}
