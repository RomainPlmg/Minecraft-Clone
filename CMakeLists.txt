cmake_minimum_required(VERSION 3.10)
project(Minecraft_Clone VERSION 0.1.0 LANGUAGES C CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 20)

# Find OpenGL on the system
find_package(OpenGL REQUIRED)

# Declare all source files
set(EXEC_SOURCES
    src/glad/glad.c

    src/utils/Timer.cpp
    src/utils/Transformable.cpp

    src/gfx/IndexBuffer.cpp
    src/gfx/Renderer.cpp
    src/gfx/Shader.cpp
    src/gfx/Texture.cpp
    src/gfx/VertexArray.cpp
    src/gfx/VertexBuffer.cpp
    src/gfx/VertexBufferLayout.cpp
    src/gfx/Window.cpp
    src/gfx/Camera.cpp

    src/Cube.cpp
    src/Game.cpp
    src/Main.cpp
    
)

# Add the GLFW library
include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY "https://github.com/glfw/glfw.git"
  GIT_TAG "3.4" # Version 3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Add source files to the project
add_executable(MinecraftClone ${EXEC_SOURCES})

# Change the runtime output directory
set_target_properties(MinecraftClone PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# Target OpenGL and GLFW
target_link_libraries(MinecraftClone PRIVATE glfw ${OPENGL_LIBRARY})

# Add include directories
target_include_directories(MinecraftClone PRIVATE
    include/
    include/gfx
    include/utils
    include/vendor
)