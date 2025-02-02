#include <unistd.h>
#include <stdlib.h>
int	*ft_range(int min, int max)
{
	int	*values;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min + 1;
	values = malloc(size * sizeof(int));
	if (values == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		values[i] = min + i;
		i++;
	}
	return (values);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	int	min;
	int	max;
	int	i;
	int	*arr;

	if (argc < 3)
		return (1);
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	arr = ft_range(min, max);
	if (arr != NULL)
	{
		i = 0;
		while (i <= max - min)
		{
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n");
	}
	else
		printf("Invalid input.\n");
	return (0);
}
