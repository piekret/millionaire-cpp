cmake_minimum_required(VERSION 3.16)
project(Millionaire VERSION 1.0 LANGUAGES CXX)

# ── standard i ostrzeżenia ───────────────────────────
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# ── źródła ───────────────────────────────────────────
file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "src/*.cpp")

add_executable(millionaire ${SRC})

target_include_directories(millionaire
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ── katalog wyjściowy binarki (build/out/) ───────────
set_target_properties(millionaire PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out
)

# ── kopiowanie zasobów obok pliku wykonywalnego ──────
add_custom_command(TARGET millionaire POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_CURRENT_SOURCE_DIR}/resources
            $<TARGET_FILE_DIR:millionaire>/resources
    COMMENT "Kopiuję resources/ -> katalog binarki"
)
