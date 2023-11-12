#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>


#include <iostream>
#include <vector>
#include <stdexcept>

#include "VulkanRenderer.h"


GLFWwindow* window; 
VulkanRenderer vulkanRenderer; 


void initWindow(std::string wName = "Test Window", const int width = 800, const int height = 600)
{
	// init glfw
	glfwInit(); 

	// glfw not work with opengl
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); 
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); 

	window = glfwCreateWindow(width, height, wName.c_str(), nullptr, nullptr); 
}
	
int main() 
{ 
	// Create our window 
	initWindow("Test Window", 800, 600); 

	// create vulkan renderer instance 
	if (vulkanRenderer.init(window) == EXIT_FAILURE)
	{
		return EXIT_FAILURE; 
	}

	// loop until close 
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); 
	}

	// Destroy GLFW window and stop GLFW
	glfwDestroyWindow(window); 
	glfwTerminate(); 

	return 0;
}