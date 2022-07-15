cmake_minimum_required (VERSION 3.8)

project (Dophyn)

include_directories(include)

add_executable (${PROJECT_NAME} "src/main.cpp" "include/core/Color.hpp" "include/core/Engine.hpp" "include/core/matrix.hpp" "include/core/Point.hpp" "include/core/vector.hpp" "src/core/Color.cpp" "src/core/Engine.cpp" "src/core/matrix.cpp" "src/core/Point.cpp" "src/core/vector.cpp")

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)
