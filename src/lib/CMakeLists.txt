
add_executable(shadercompiler shadercompiler.cpp)

set(shader_outputs)
foreach(shader shader.vs shader.ps)
    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/shaders/${shader}.spv
        COMMAND shadercompiler ${CMAKE_CURRENT_SOURCE_DIR}/${shader} ${CMAKE_BINARY_DIR}/shaders/${shader}.spv
        COMMENT "Compile ${shader}"
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${shader}
    )
    list(APPEND shader_outputs ${CMAKE_BINARY_DIR}/shaders/${shader}.spv)
endforeach()

add_custom_target(compile_shaders DEPENDS ${shader_outputs})
