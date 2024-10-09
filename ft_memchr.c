#include <string.h>
//#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s_;

	s_ = s;
	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s_[ft_strlen(s)]);
	i = 0;
	while (i < n)
	{
		if (s_[i] == c)
            return ((char *)&s_[i]);
		i ++;
	}
	return (NULL);
}

/*int main(void)
{
    const char  s[7] = "ABCDEF";
    int         c = 66;
    size_t      n = 2;
    char        *result;

    result = ft_memchr(s, c, n);
    printf("%s", result);
}*/