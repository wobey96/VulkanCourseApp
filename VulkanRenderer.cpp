#include "VulkanRenderer.h"

VulkanRenderer::VulkanRenderer()
{

}

int VulkanRenderer::init(GLFWwindow* newWindow)
{
	window = newWindow; 

	try {
		createInstance(); 
	}
	catch (const std::runtime_error& e) {
		printf("ERROR: %s \n", e.what()); 
		return EXIT_FAILURE; 
	}

	return 0;
}

VulkanRenderer::~VulkanRenderer()
{

}

void VulkanRenderer::createInstance()
{
	// Creation information for a VkInstance (Vulkan Instance)
	VkInstanceCreateInfo createInfo = {}; 
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; 
	createInfo.flags;
}
