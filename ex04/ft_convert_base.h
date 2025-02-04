#ifndef FT_CONVERT_BASE_H
# define FT_CONVERT_BASE_H

int	check_base(char *base);
int	ft_atoi_base(char *str, char *base);
int	get_value(char c, char *base);
char	*ft_putnbr_base(int nbr, char *base);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif
