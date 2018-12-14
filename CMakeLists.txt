cmake_minimum_required(VERSION 2.8)
project(spirit)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -DGLEW_NO_GLU)
set(OpenGL_GL_PREFERENCE GLVND)
#find_package(OpenGL REQUIRED)

add_subdirectory(glm-0.9.9.2/glm)
include_directories(glm-0.9.9.2/glm)

add_subdirectory(assimp)
include_directories(assimp/include)
include_directories(assimp/build/include)
#include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/assimp)


add_subdirectory(glfw-3.2.1)
add_subdirectory(glew-2.1.0/build/cmake)

include_directories(glfw-3.2.1/include
                    glew-2.1.0/include)

set(SOURCE_FILES src/main.cpp src/Texture.cpp src/Texture.h stb/stb_image.cpp src/Mesh.cpp src/Mesh.h src/SceneImporter.cpp src/SceneImporter.h src/DrawableStatic.cpp src/DrawableStatic.h src/VertecSpec.h src/Shader.cpp src/Shader.h src/Controller.cpp src/Controller.h src/Game.cpp src/Game.h src/GameState.cpp src/GameState.h src/FPSState.cpp src/FPSState.h src/MenuState.cpp src/MenuState.h src/FirstPerson.cpp src/FirstPerson.h)
add_executable(spirit ${SOURCE_FILES})

target_link_libraries(spirit glfw ${GLFW_LIBRARIES}
                      glew
                      assimp)
