cmake_minimum_required(VERSION 3.23)

project(Hybrid)

set(CMAKE_CXX_STANDARD 14)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/dist/${CMAKE_SYSTEM_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

add_executable(Hybrid main.cpp
        Main.cpp Menu.cpp Menu.h Functions.cpp Functions.h Functions.cpp Functions.h Menu.cpp Menu.h)

target_include_directories(${PROJECT_NAME}
        PRIVATE
        ${Python3_INCLUDE_DIRS}

        )
target_link_libraries(${PROJECT_NAME}
        PRIVATE
        ${Python3_LIBRARIES}
        )

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD

        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/python_modules/ ${OUTPUT_DIR}/python_modules)