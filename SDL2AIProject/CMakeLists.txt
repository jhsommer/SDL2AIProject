cmake_minimum_required(VERSION 3.29)
project(SDL2AIProject)

set(CMAKE_CXX_STANDARD 20)

#path to SDL2
set (SDL2_ROOT "C:/mingw64")
set (SDL2_INCLUDE_DIR "${SDL2_ROOT}/include")
set (SDL2_LIB_DIR "${SDL2_ROOT}/lib")
set (SDL2_DLL_DIR "${SDL2_ROOT}/bin")

#main of this project
add_executable(SDL2AIProject main.cpp
        CCharacter.cpp
        CCharacter.h
        CVector2.cpp
        CVector2.h
        CActor.cpp
        CActor.h
        CTarget.cpp
        CTarget.h)
target_include_directories(SDL2AIProject PRIVATE ${SDL2_INCLUDE_DIR})

#link to the SDL2 library
target_link_directories(SDL2AIProject PRIVATE ${SDL2_LIB_DIR})
target_link_libraries(SDL2AIProject PRIVATE SDL2)

add_custom_command(TARGET SDL2AIProject POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_if_different
"${SDL2_DLL_DIR}/SDL2.dll"
$<TARGET_FILE_DIR:SDL2AIProject>)