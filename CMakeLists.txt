cmake_minimum_required (VERSION 3.8)

project (Dophyn)

include_directories(include)

add_executable (${PROJECT_NAME} "src/main.cpp" "include/utils/Color.hpp" "include/core/Engine.hpp" "include/utils/matrix.hpp" "include/utils/Point.hpp" "include/utils/vector.hpp" "src/utils/Color.cpp" "src/core/Engine.cpp" "src/utils/matrix.cpp" "src/utils/Point.cpp" "src/utils/vector.cpp")

if(WIN32)
    find_package(SDL2 CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

    find_package(sdl2-image CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)
endif()


