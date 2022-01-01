cmake_minimum_required(VERSION 3.19)

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
    copy_shaders
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/shaders "$<TARGET_FILE_DIR:demo>/assets/shaders"
    COMMENT "Copying shaders"
    DEPENDS compile_shaders
)
add_dependencies(demo copy_shaders)
