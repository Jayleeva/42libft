#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen_(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c || str[i])
		i ++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	c = (unsigned char)c;
	if (c == '\0')
		return ((char *)&s[ft_strlen_(s, '\0')]);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i ++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *) malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		result[j] = s[i];
		j ++;
		i ++;
	}
	result[j] = '\0';
	return (result);
}

size_t  count_nb(char const *s, char c)
{
    size_t  i;
    size_t  nb;

    i = 0;
    nb = 0;
    while (s[i])
    {
        if (s[i] == c)
            nb ++;
        i ++;
    }
    return (nb + 1);
}

char    **ft_split(char const *s, char c)
{
    char    **result;
    int  i;
    //size_t  j;
    int  nb;
    //size_t  len;

    nb = count_nb(s, c);
    //len = ft_strlen_(s, '\0');
    result = (char **)malloc((nb + 1)* sizeof(char *));
    if (result == NULL)
        return (NULL);
    /*i = 0;
    while (i < nb)
    {
        result[i] = (char *)malloc((len + 1) * sizeof(char));
        if (result[i] == NULL)
            return (NULL);
        i ++;
    }*/
    result[0] = (char *)s;
    i = 1;
    while (i < nb)
    {
        result[i] = ft_strchr(result[i -1], c) + 1;
        i ++;
    }
    nb -= 2;
    printf("%s", result[nb + 1]);
    while (nb >= 0)
    {
        printf("\n%s", result[nb]);
        //i = ft_strlen_(result[nb], c); //c'est la que ca bloque.
        i = 6;
        result[nb] = ft_substr(result[nb], 0, i);
        //printf("\n%s", result[nb]);
        nb --;
    }
    //result[i][j] = '\0';
    return (result);
}

int main(void)
{
    char const  s[] = "Salut ca va?-Ouais et toi?-Imotep-Cool";
    char        c = '-';

    ft_split(s, c);
}