#include "libft.h"
#include "ft_itoa.c"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i ++;
	}
}

/*int	main(void)
{
	int	n = -2147483648;
	int	fd = 1;

	ft_putnbr_fd(n, fd);
}*/