#include "minishell.h"

t_bool	empty_line(char *str)
{
	while (is_blank(*str))
		str ++;
	if (*str == 0)
		return (TRUE);
	return (FALSE);
}

int	get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("minishell");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
