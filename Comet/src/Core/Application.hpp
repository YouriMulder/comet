#pragma once 
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>

namespace Comet {
    class Application {
    public:
        Application();
        virtual ~Application();
        void run();
    private:
        GLFWwindow* window;
        VkInstance instance;
        VkDebugUtilsMessengerEXT debugMessenger;
        const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
        };

        void initWindow();
        void initVulkan();
        void createInstance();
        bool checkValidationLayerSupport();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        void setupDebugMessenger();
        std::vector<const char*> getRequiredExtensions();
        void loop();
        void cleanup();
    };
}