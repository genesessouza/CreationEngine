file(GLOB_RECURSE CORE_SRC
    src/*.cpp
)

add_library(Core STATIC ${CORE_SRC})

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)