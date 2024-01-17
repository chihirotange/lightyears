cmake_minimum_required(VERSION 3.18)

project(LightYears)

include(FetchContent)
#SFML
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1
    GIT_SHALLOW FALSE
)

FetchContent_MakeAvailable(SFML)
    
set(AI_ENGINE AiEngine)
set(LIGHTYEARS_GAME LightYearsGame) 

add_subdirectory(AiEngine)
add_subdirectory(LightYearsGame)