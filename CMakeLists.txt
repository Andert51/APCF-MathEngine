cmake_minimum_required(VERSION 3.10)
project(APCF-MathEngine)

# Establecer estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Incluir directorios
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/exprtk)
include_directories(${PROJECT_SOURCE_DIR}/third_party/imgui)
include_directories(${PROJECT_SOURCE_DIR}/third_party/imgui/backends)

# Incluir los backends de ImGui para GLFW y OpenGL
set(IMGUI_BACKENDS
    ${PROJECT_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/third_party/imgui/backends/imgui_impl_opengl3.cpp
)

# Encontrar paquetes necesarios
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(SDL2 REQUIRED)

# Añadir subdirectorios
add_subdirectory(third_party/imgui)
add_subdirectory(src)

# Archivos de código fuente
file(GLOB_RECURSE SOURCES src/*.cpp src/*.h)

# Añadir los backends de ImGui a los archivos fuente
list(APPEND SOURCES ${IMGUI_BACKENDS})

# Compilar el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Especificar las librerías que deben enlazarse
target_link_libraries(${PROJECT_NAME} PRIVATE
    GLEW::GLEW
    OpenGL::GL
    glfw
    SDL2::SDL2
    imgui
    src_lib
)
