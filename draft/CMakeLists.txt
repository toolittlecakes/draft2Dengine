cmake_minimum_required(VERSION 3.12)
project(draft)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib")
set(SFML_DIR "${PROJECT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(SFMLApp main.cpp objects/object.cpp objects/object.h image.cpp image.h io/output.cpp io/output.h io/input.cpp io/input.h levels/level.cpp levels/level.h levels/level1.cpp levels/level1.h objects/player.cpp objects/player.h globals.h vec2.cpp vec2.h objects/dog.cpp objects/dog.h objects/komet.cpp objects/komet.h component/component.cpp component/component.h component/all_components/transform.cpp component/all_components/transform.h component/component_container.cpp component/component_container.h component/all_components/script.cpp component/all_components/script.h component/all_components/draw.cpp component/all_components/draw.h)
target_link_libraries (SFMLApp sfml-graphics sfml-window sfml-system)