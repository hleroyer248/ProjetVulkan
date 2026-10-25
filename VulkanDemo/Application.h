#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include "Renderer.h"

class Application
{
public:
	int width = 800;
	int height = 600;

	GLFWwindow* window = nullptr;

	Renderer renderer;

	void Init();
	void Run();
	void Destroy();

	static void FramebufferResizeCallback(GLFWwindow* window, int width, int height);

private:
	void InitWindow();
	void InitVulkan();

	void DestroyWindow();
	void DestroyVulkan();
};
