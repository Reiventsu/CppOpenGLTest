//
// Created by rei on 2025-06-12.
//

#include "ShaderLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>

//// This is a mockup of stuff, and I've kinda tested the jetbrains auto suggest to trial and error, so I guess it's partial AI use? :<
std::string LoadShaderFromFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file) {
        std::cerr << "Failed to open file " << filepath << std::endl;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
