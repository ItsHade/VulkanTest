#ifndef GAME_H
# define GAME_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <vulkan/vulkan.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;

typedef struct s_app
{
	GLFWwindow *window;
	VkInstance instance;
}	t_app;

/* PUT FUNCTIONS */

int		ft_strlen(const char *str);

int	ft_strcmp(const char *s1, const char *s2);

void	ft_putstr(const char *str);

void	ft_putstr_fd(const char *str, int fd);


#endif
