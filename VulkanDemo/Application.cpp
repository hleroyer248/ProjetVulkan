#include "Application.h"

void Application::Init()
{
    InitWindow();
    InitVulkan();
}

void Application::Run()
{
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        renderer.DrawFrame();
    }

    renderer.WaitIdle();
}

void Application::Destroy()
{
    DestroyVulkan();
    DestroyWindow();
}

void Application::InitWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(width, height, "VulkanDemo", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, FramebufferResizeCallback);
}

void Application::FramebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    Application* app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
    app->renderer.framebufferResized = true;
}

void Application::InitVulkan()
{
    renderer.CreateInstance();
    renderer.CreateSurface(window);
    renderer.PickPhysicalDevice();
    renderer.CreateLogicalDevice();
    renderer.CreateSwapChain();
    renderer.CreateImageViews();
    renderer.CreateDescriptorSetLayout();
    renderer.CreateGraphicsPipeline();
    renderer.CreateCommandPool();
    renderer.CreateDepthResources();
    renderer.CreateTextureImage();
    renderer.CreateVertexBuffer();
    renderer.CreateIndexBuffer();
    renderer.CreateUniformBuffers();
    renderer.CreateDescriptorPool();
    renderer.CreateDescriptorSets();
    renderer.CreateCommandBuffers();
    renderer.CreateSyncObjects();
}

void Application::DestroyWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::DestroyVulkan()
{
    renderer.Destroy();
}
