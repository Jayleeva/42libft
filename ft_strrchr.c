
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

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
    int  temp;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
    temp = -1;
	while (s[i])
	{
		if (s[i] == c)
            temp = i;
		i ++;
	}
    if (temp >= 0)
        return ((char *)&s[temp]);
	return (NULL);
}

/*int	main(void)
{
	const char	s[7] = "ABCDCF";
	int			c = 67;
	char		*result;
   
	result = ft_strrchr(s, c);
	printf("\n%s", result);
	return (0);
}*/