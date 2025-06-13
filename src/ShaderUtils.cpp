//
// Created by rei on 2025-06-12.
//

#include "ShaderUtils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <glad/glad.h>

//// This is a mockup of stuff, and I've kinda tested the jetbrains auto suggest to trial and error, so I guess it's partial AI use? :<
namespace ShaderUtils {
    // This helper expects you to provide it with the location of a vertex shader or fragment shader
    std::string LoadFromFile(const std::string &filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "Failed to open file " << filepath << std::endl;
            return "";
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    // This one expects you to provide the type e.g. 'GL_VERTEX_SHADER' or 'GL_FRAGMENT_SHADER'
    // Not needed anymore. Use the create program function
    unsigned int CompileShader(const GLenum type, const std::string &sourceCode) {
        const char *source = sourceCode.c_str();
        const unsigned int shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);
        return shader;
    }


    // This can be called and then have 2 paths assigned to it one being vertex and one being fragment and it should work
    unsigned int CreateProgram(const std::string &vertexShaderPath, const std::string &fragmentShaderPath) {
        // Load shaders
        const std::string vertexCode = LoadFromFile(vertexShaderPath);
        const std::string fragmentCode = LoadFromFile(fragmentShaderPath);

        if (vertexCode.empty() || fragmentCode.empty()) {
            std::cerr << "Failed to load shaders" << std::endl;
            return 0;
        }

        const unsigned int vertexShader = CompileShader(GL_VERTEX_SHADER, vertexCode);
        const unsigned int fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentCode);
        if (vertexShader == 0 || fragmentShader == 0) {
            std::cerr << "Failed to compile shaders" << std::endl;
            return 0;
        }

        const unsigned int program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return program;
    }
} // ShaderUtils


//// These 2 look nearly identical, and so I decided; why not try to make them more reusable and abstract.
//// So I moved my previous stuff from the ShaderLoader.cpp thing and such into a shared namespace

// const char* vertexShaderSource = vertexCode.c_str();
// const unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
// glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
// glCompileShader(vertexShader);

// const char* fragmentShaderSource = fragmentCode.c_str();
// const unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
// glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
// glCompileShader(fragmentShader);
