#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
    int         i;
    const char  *s1_;
    const char  *s2_;

    s1_ = s1;
    s2_ = s2;
    i = 0;
    while (s1_[i] || s2_[i])
    {
        if (s1_[i] != s2_[i])
            return (s1_[i] - s2_[i]);
        i ++;
    }
    return (0);
}

int main(void)
{
    const char  s1[6] = "Hello";
    const char  s2[6] = "Hell!";
    size_t      n = 3;
    int result;

    result = ft_memcmp(s1, s2, n);
    printf("%d", result);
}