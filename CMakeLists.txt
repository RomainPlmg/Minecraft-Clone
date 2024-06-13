cmake_minimum_required(VERSION 3.10)
project(Minecraft_Clone VERSION 0.1.0 LANGUAGES C CXX)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find OpenGL on the system
find_package(OpenGL REQUIRED)

# Add the GLFW library
include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Declare all source files
file(GLOB_RECURSE EXEC_SOURCES
        src/*.c
        src/*.cpp
        include/*.h
)

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

# Set compile features for C++20
target_compile_features(MinecraftClone PRIVATE cxx_std_20)

# Set build configurations
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")