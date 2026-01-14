file(GLOB_RECURSE FRAMEWORK_SRC
    src/*.cpp
)

add_library(Framework STATIC ${FRAMEWORK_SRC})

target_include_directories(Framework PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Framework
    Core
    Rendering
    Platform
)