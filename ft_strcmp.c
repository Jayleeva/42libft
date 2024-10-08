int	ft_strcmp(const char *s1, const char *s2)
{
    
}

int main(void)
{
    const char  s1[6] = "Hello";
    const char  s2[6] = "Hellp";
    int result;

    result = ft_strcmp(s1, s2);
    printf("%d", result);
}