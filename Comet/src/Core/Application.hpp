#pragma once 

#include <GL/glew.h>

namespace Comet {
    class Application {
    public:
        Application();
        virtual ~Application();
        
        GLuint loadShaders(const char* vertex_file_path, const char* fragment_file_path);
        
        void run();
    };
}