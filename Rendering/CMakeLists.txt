file(GLOB_RECURSE RENDERING_SRC
    src/*.cpp
)

add_library(Rendering STATIC ${RENDERING_SRC})

target_include_directories(Rendering PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Rendering
    Core
    glm
)