project('CppOpenGLTest', ['cpp', 'c'],
        version : '1.0.0',
        default_options : ['warning_level=2', 'cpp_std=c++20'])

# Dependencies
glfw_dep = dependency('glfw3', required : true)
opengl_dep = dependency('gl', required : true)

# GLAD Generated through https://glad.dav1d.de/ as suggested by https://learnopengl.com/Getting-started/Creating-a-window
glad_inc = include_directories('ExternalLibrary/glad/include')
glad_src = files('ExternalLibrary/glad/src/glad.c')

# Files included add more .cpp things here
sources = files(
    'src/main.cpp',
)

# Seems to be the holy grail of what to actually include n stuff.
executable('CppOpenGLTest',
           sources,
           glad_src,
           include_directories : glad_inc,
           dependencies : [glfw_dep, opengl_dep],
)
