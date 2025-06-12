project('CppOpenGLTest', ['cpp', 'c'],
        version : '1.0.0',
        default_options : ['warning_level=2', 'cpp_std=c++20'])

# Dependencies
glfw_dep = dependency('glfw3', required : true)
opengl_dep = dependency('gl', required : true)

# GLAD Generated through https://glad.dav1d.de/ as suggested by https://learnopengl.com/Getting-started/Creating-a-window
glad_inc = include_directories('ExternalLibrary/glad/include')
glad_src = files('ExternalLibrary/glad/src/glad.c')

# Shader includes
shader_dir = include_directories('ShaderFiles/')

# Files included add more .cpp things here >:3
sources = files(
    'src/main.cpp',
    'src/ShaderLoader.cpp',
    'src/ShaderLoader.h',
)

# Seems to be the holy grail of what to actually include n stuff.
executable('CppOpenGLTest',
           sources,
           glad_src,
           include_directories : [glad_inc, shader_dir],
           dependencies : [glfw_dep, opengl_dep],
)
