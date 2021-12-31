cmake_minimum_required(VERSION 3.15)

project(copyshaders VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(src/lib)

add_executable(demo
    src/main.cpp
)
add_custom_target(
    copy_shaders ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/shaders "$<TARGET_FILE_DIR:demo>/assets/shaders"
    COMMENT "Copying shaders"
)
add_dependencies(copy_shaders compile_shaders)
