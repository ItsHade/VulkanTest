#ifndef GAME_H
# define GAME_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

typedef struct s_app
{
	GLFWwindow *window;
	VkInstance instance;
}	t_app;

/* PUT FUNCTIONS */

int		ft_strlen(const char *str);

void	ft_putstr(const char *str);

void	ft_putstr_fd(const char *str, int fd);


#endif
