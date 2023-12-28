#include "../include/game.h"

const char* WIN_TITLE = "VulkanTest";
const u32 WIN_WIDTH = 800;
const u32 WIN_HEIGHT = 600;

bool	verifyExtensionsSupport(u32 extensionCount, VkExtensionProperties *extensions, u32 glfwExtensionCount, const char **glfwExtensions)
{
	u32 foundExtensions = 0;
	for (u32 i = 0; i < glfwExtensionCount; i++)
	{
		for (u32 j = 0; j < extensionCount; j++)
		{
			if (ft_strcmp(extensions[j].extensionName, glfwExtensions[i]) == 0)
				foundExtensions++;
			else
			{
				printf("Failed to find support for %s = %s\n", extensions[j].extensionName, glfwExtensions[i]);
			}
		}
	}
	return (foundExtensions == extensionCount);
}

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

	u32 glfwExtensionCount = 0;
	const char **glfwExtensions;

	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	VkInstanceCreateInfo createInfo = {
	.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
	.pApplicationInfo = &appInfo,
	.enabledExtensionCount = glfwExtensionCount,
	.ppEnabledExtensionNames = glfwExtensions
	};
	createInfo.enabledLayerCount = 0;

	if (vkCreateInstance(&createInfo, NULL, &app->instance) != VK_SUCCESS)
	{
		ft_putstr_fd("Failed to create Vulkan Instance\n", 2);
		exit(1);
	}

	u32 extensionCount = 0;
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

	VkExtensionProperties *extensions = (VkExtensionProperties*)malloc(sizeof(VkExtensionProperties) * extensionCount);
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, extensions);

	for (u32 i = 0; i < extensionCount; i++)
	{
		printf("\tExtension: %s\n", extensions[i].extensionName);
	}
	if (verifyExtensionsSupport(extensionCount, extensions, glfwExtensionCount, glfwExtensions) == 1)
		printf("All extensions supported\n");
	else {
		printf("Missing extension support!\n");
		exit(1);
	}

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
	vkDestroyInstance(app->instance, NULL);
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
