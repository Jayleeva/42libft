#include <string.h>
#include <stdio.h>

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
	size_t	i;
    size_t  j;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
    j = 0;
	while (s[i])
	{
		if (s[i] == c)
        {
            while (j < n)
            {

            }
            return ((char *)&s[i]);
        }
		i ++;
	}
	return (NULL);
}

int main(void)
{
    const char  s[7] = "ABCDEF";
    int         c = 65;
    size_t      n = 2;
    char        *result;

    result = ft_memchr(s, c, n);
    printf("%s", result);
}