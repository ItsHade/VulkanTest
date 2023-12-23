#include "../include/game.h"

void	initWindow(void)
{
	ft_putstr("Window initialization\n");
}

void	initVulkan(void)
{
	ft_putstr("vulkan initialization\n");
}

void	mainLoop(void)
{
	ft_putstr("Main Loop\n");
}

void	cleanup(void)
{
	ft_putstr("Cleanup\n");
}

int	main(void)
{
	ft_putstr("Hello World!\n");
	initWindow();
	initVulkan();
	mainLoop();
	cleanup();
	return (0);
}
