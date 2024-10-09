#include <stdlib.h>
//#include <stdio.h>

char	*ft_strdup(const char *src)
{
	int	    i;
	char	*copy;

	i = 0;
	while (src[i])
		i ++;
	copy = (char *) malloc((i +1) * sizeof(char));
	if (copy == NULL)
        return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i ++;
	}
	copy[i] = '\0';
	return (copy);
}

/*int main(void)
{
    const char  str[] = "hello world";
    char        *copy;

    copy = ft_strdup(str);
    printf("%s", copy);
}*/