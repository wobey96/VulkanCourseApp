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
	// Information about the applicatin itself 
	// Most data here doesn't affect the program and is for developer convenience  
	VkApplicationInfo appInfo = {}; 
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; 
	appInfo.pApplicationName = "Vulkan App";					// Custom name of the application 
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);		// custom version of application 
	appInfo.pEngineName = "No Engine";							// Custom engine name 
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);			// Custon engine version
	appInfo.apiVersion = VK_API_VERSION_1_3;					// Vulkan version 


	// Creation information for a VkInstance (Vulkan Instance)
	VkInstanceCreateInfo createInfo = {}; 
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO; 
	createInfo.pApplicationInfo = &appInfo;

	// Create list to hold  instance extensions		
	std::vector<const char*> instanceExtentions = std::vector<const char*>();  

	// Set up extensions Instance we will use 
	uint32_t glfwExtensionCount = 0;			// GLFW may require multiple extensions
	const char** glfwExtensions;	 // Extensions passed as array of cstrings, so need pointer (the array) to  

	// GET GLFW extensions
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	// Add GLFW extensions to list of extensions	
	for (size_t i = 0; i < glfwExtensionCount; i++)
	{
		instanceExtentions.push_back(glfwExtensions[i]);
	}

	createInfo.enabledExtensionCount = static_cast<uint32_t>(instanceExtentions.size());
	createInfo.ppEnabledExtensionNames = instanceExtentions.data(); 

	// TODO: Set up Validation Layers  that Instance will use
	createInfo.enabledLayerCount = 0; 
	createInfo.ppEnabledLayerNames = nullptr; 



	// Create instance
	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	
	if (result != VK_SUCCESS)
	{
		throw std::runtime_error("Failed to create vulkan instance"); 
	}
	
}
