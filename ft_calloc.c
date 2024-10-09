#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_;

	i = 0;
	b_ = b;
	while (i < len)
	{
		b_[i] = (unsigned char)c;
		i ++;
	}
    b_[i] = '\0';
	return (b);
}

void    *ft_calloc(size_t nelem, size_t elsize)
{
    void    *ptr;

    ptr = malloc((nelem + 1) * elsize);
    if (ptr == NULL)
        return (NULL);
    ptr = ft_memset(ptr, 65, nelem);
    return ((char *)ptr);
}

int main(void)
{
    size_t  nelem = 5;
    size_t  elsize = sizeof(char);
    char    *result;

    result = ft_calloc(nelem, elsize);
    printf("%s", result);
}