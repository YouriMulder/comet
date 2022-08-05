#include "copch.hpp"
#include "Application.hpp"

#include <iostream>


namespace Comet {
    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        std::cout << "Hello world" << std::endl;
    }
}