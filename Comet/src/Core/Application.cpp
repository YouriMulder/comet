#include "copch.hpp"
#include "Application.hpp"

#include <iostream>
#include <GL/glew.h> 
#include <GLFW/glfw3.h>



namespace Comet {
    Application::Application() {}

    Application::~Application() {}

    static void error_callback(int error, const char* description)
    {
        fprintf(stderr, "Error: %s\n", description);
    }
    
    void Application::run() {
        if (!glfwInit())
        {
            std::cout << "Failed to initialize GLFW" << std::endl;
            // Initialization failed
        }
        
        glfwSetErrorCallback(error_callback);
        glfwWindowHint(GLFW_SAMPLES, 4); // anti aliasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // openGL major version to be 3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0); // minor set to 3, which makes the version 3.3
        
        GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);

        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        do {
            // Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw nothing, see you in tutorial 2 !

            // Swap buffers
            glfwSwapBuffers(window);
            glfwPollEvents();

        } // Check if the ESC key was pressed or the window was closed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
            glfwWindowShouldClose(window) == 0);
    }
}