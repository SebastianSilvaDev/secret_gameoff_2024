cmake_minimum_required(VERSION 3.21)

project(
    Secret
    VERSION 1.0
    LANGUAGES CXX
)

file(GLOB_RECURSE SOURCES 
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(PRIVATE_DIRS
    ${PROJECT_SOURCE_DIR}/include
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PRIVATE_DIRS})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

find_package(SDL2 CONFIG REQUIRED)
find_package(libtcod CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main libtcod::libtcod)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)