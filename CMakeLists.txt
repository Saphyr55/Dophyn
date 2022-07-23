cmake_minimum_required (VERSION 3.8)

project (Dophyn)

file(GLOB_RECURSE CORE src/core/*.cpp)
file(GLOB_RECURSE UTILS src/utils/*.cpp)
file(GLOB_RECURSE RENDERER src/renderer/*.cpp)
file(GLOB_RECURSE GRAPHICS src/graphics/*.cpp)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

add_executable(${PROJECT_NAME} "src/main.cpp" ${CORE} ${UTILS} ${RENDERER} ${GRAPHICS})

if(WIN32)
    find_package(SDL2 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)

    find_package(sdl2-image CONFIG REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)

    include_directories(include ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

endif()

if(UNIX)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
    include_directories(include ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
endif(UNIX)

