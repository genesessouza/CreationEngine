file(GLOB_RECURSE PLATFORM_SRC
    src/*.cpp
)

add_library(Platform STATIC ${PLATFORM_SRC})

target_include_directories(Platform PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Platform
    Core
    Glad
    glfw
)