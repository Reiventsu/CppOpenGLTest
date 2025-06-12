//
// Created by rei on 2025-06-12.
//

#pragma once
#include <string>
#include <glad/glad.h>

namespace ShaderUtils {
    //// Function to aid in loading files into openGL we'll see if I can make this work lol
    std::string LoadFromFile(const std::string &filepath);

    //// To aid in compiling shaders
    unsigned int CompileShader(GLenum type, const std::string& sourceCode);
}
