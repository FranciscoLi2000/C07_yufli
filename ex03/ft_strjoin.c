#include <stdlib.h>
static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
static char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] !='\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int	i;
	unsigned int	totlen;
	unsigned int	len;

	if (size == 0 || strs == NULL)
		return (0);
	totlen = 0;
	i = 0;
	while (i < size)
	{
		totlen += ft_strlen(strs[i]);
		i++;
	}
	totlen += size - 1;/* add the separator */
	totlen += 1;/* terminator '\0' */
	result = (char *)malloc(totlen * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
		{
			len = ft_strlen(result);
			ft_strcat(result, sep);
			result[len + 1] = '\0';
		}
		i++;
	}
	return (result);
}
#include <stdio.h>
int	main()
{
	char *strs[] = {"Hola", "mundo", "soy", "Yufeng"};
	int size = 4;
	char *sep = " ";
	char *result = ft_strjoin(size, strs, sep);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	else
		printf("memory allocation failed.\n");
	return (0);
}
