#include "../include/game.h"

const char* WIN_TITLE = "VulkanTest";
const uint32_t WIN_WIDTH = 800;
const uint32_t WIN_HEIGHT = 600;

void	createInstance(t_app *app)
{
	VkApplicationInfo appInfo = {
	.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
	.pApplicationName = "Hello Triangle",
	.applicationVersion = VK_MAKE_VERSION(1, 0, 0),
	.pEngineName = "No Engine",
	.engineVersion = VK_MAKE_VERSION(1, 0, 0),
	.apiVersion = VK_API_VERSION_1_0,
	.pNext = NULL
	};

	VkInstanceCreateInfo createInfo{
	.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	.pApplicationInfo = &appInfo
	};

}

void	initWindow(t_app *app)
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	app->window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE, NULL, NULL);
}

void	initVulkan(t_app *app)
{
	createInstance(app);
}

void	mainLoop(t_app *app)
{
	while (!glfwWindowShouldClose(app->window))
	{
		glfwPollEvents();
	}
}

void	cleanup(t_app *app)
{
	glfwDestroyWindow(app->window);

	glfwTerminate();
}

int	main(void)
{
	t_app app = {0};

	ft_putstr("Hello World!\n");
	initWindow(&app);
	initVulkan(&app);
	mainLoop(&app);
	cleanup(&app);
	return (0);
}
