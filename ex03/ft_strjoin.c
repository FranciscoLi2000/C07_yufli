#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] ='\0';
	return (dst);
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	len;
	char	*result;

	if (size == 0)
		return (NULL);
	i = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		if (i < size - 1)
			len = len + ft_strlen(sep);
		i++;
	}
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';/* initialize */
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}
#include <stdio.h>
int	main()
{
	char	*strs[] = {"hello", "world", "que", "tal", "yufeng"};
	char	*sep = " ";
	char	*result = ft_strjoin(5, strs, sep);

	printf("%s\n", result);
	free(result);
	return (0);
}
