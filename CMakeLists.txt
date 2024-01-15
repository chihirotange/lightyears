cmake_minimum_required(VERSION 3.18)

project(LightYears)

set(LIGHT_YEAR_TARGET LightYearTarget)

add_subdirectory(lightyears)

include(FetchContent)
#SFML
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(SFML)

target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-graphics)
target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-window)
target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-system)
target_link_libraries(${LIGHT_YEAR_TARGET} PUBLIC sfml-audio)