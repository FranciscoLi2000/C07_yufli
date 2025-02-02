#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strdup(char *src)
{
	size_t	len;
	char	*new;
	char	*start;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	new = malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	start = new;
	while (*src != '\0')
	{
		*new = *src;
		src++;
		new++;
	}
	*new = '\0';
	return (start);
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*s;
	char	*n;

	if (argc < 2)
		return (1);
	s = argv[1];
	n = ft_strdup(s);
	printf("%s\n", n);
	return (0);
}
