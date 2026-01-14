file(GLOB_RECURSE SANDBOX_SRC
    src/*.cpp
)

add_executable(Sandbox ${SANDBOX_SRC})

target_link_libraries(Sandbox
    Framework
)