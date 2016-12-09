#include "../fillit.h"

char				*ft_empty_grid(unsigned int size)
{
	char			*str;
	int 			i;
	int 			j;
	unsigned int	tmp;

	i = 0;
	j = 0;
	str = (char*)malloc(sizeof(str) * (((size + 1) * size) + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		tmp = size;
		while (tmp--)
		{
			str[j] = '.';
			j++;
		}
		str[j] = '\n';
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char				*ft_grid_solver(t_position *tetriminos, char *empty_grid, int size)
{
	t_position		*ptr;
	int				i;

	i = 0;
	ptr = tetriminos;
	while (ptr != NULL)
	{
		i = 0;
		while (empty_grid[i])
		{
			if ((i % (size + 1) == ptr->x[0] && (i / (size + 1) == ptr->y[0]) && empty_grid[i] == '.'))
				empty_grid[i] = ptr->abc;
			if ((i % (size + 1) == ptr->x[1] && (i / (size + 1) == ptr->y[1]) && empty_grid[i] == '.'))
				empty_grid[i] = ptr->abc;
			if ((i % (size + 1) == ptr->x[2] && (i / (size + 1) == ptr->y[2]) && empty_grid[i] == '.'))
				empty_grid[i] = ptr->abc;
			if ((i % (size + 1) == ptr->x[3] && (i / (size + 1) == ptr->y[3]) && empty_grid[i] == '.'))
				empty_grid[i] = ptr->abc;
			i++;
		}
		ptr = ptr->next;
	}
	return (empty_grid);
}
/*
t_position			*ft_define_pos(t_position *tetrininos, int i)
{

}
*/
char				*ft_solve(t_position *tetriminos)
{
	char 			*empty_grid;
	unsigned int	size;

	//FOR EACH SIZE, WE WILL TRY TO FIT ALL THE PIECES IN THERE. IF WE CANNOT size++;
	size = 4;//4 just to try for the moment
	empty_grid = ft_empty_grid(size);
	empty_grid = ft_grid_solver(tetriminos, empty_grid, size);
	return (empty_grid);
}