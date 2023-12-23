#include "../include/game.h"

void    ft_putstr(const char *str)
{
    write (1, str, ft_strlen(str));
}

void	ft_putstr_fd(const char *str, int fd)
{
	write (fd, str, ft_strlen(str));
}
