#include "copch.hpp"
#include "Application.hpp"

#ifdef COMET_PLATFORM_WINDOWS

int main(int argc, char** argv) {
    Comet::Application app = Comet::Application();
    app.run();
}

#endif