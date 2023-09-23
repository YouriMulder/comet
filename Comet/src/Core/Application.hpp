#pragma once 
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

namespace Comet {
    class Application {
    public:
        Application();
        virtual ~Application();
        void run();
    private:
        GLFWwindow* window;
        VkInstance instance;

        void initWindow();
        void initVulkan();
        void createInstance();
        void loop();
        void cleanup();
    };
}