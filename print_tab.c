void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("\n%s", tab[i]);
		i ++;
	}
}