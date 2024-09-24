# src/CMakeLists.txt

# Añadir todos los archivos .cpp en src
file(GLOB SRC_FILES *.cpp)

# Crear una biblioteca estática para src
add_library(src_lib STATIC ${SRC_FILES})

# Incluir directorios
target_include_directories(src_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
