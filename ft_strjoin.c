#include <stdlib.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[0])
		i ++;
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j ++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
    size_t  size;
    char    *result;

    size = ft_strlen(s1) + ft_strlen(s2);
    result = (char *)malloc((size + 1) * sizeof(char));
    if (result == NULL)
        return (NULL);
    result = ft_strcat((char *)s1, s2);
	return (result);
}

int main(void)
{
    const char  s1[] = "Hello";
    const char  s2[] = ", world";
    char        *result;

    result = ft_strjoin(s1, s2);
    printf("%s", result);
}