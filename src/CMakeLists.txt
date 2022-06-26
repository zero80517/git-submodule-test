cmake_minimum_required(VERSION 3.5)

project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# See https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&index=1
# ${PROJECT_NAME} uses last project name. So you don't have to replace project name everywhere after the change.
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC math-tools)

# add the math_tools dir to the search path for include files
# so that we will find math_tools.h
target_include_directories(${PROJECT_NAME} PUBLIC
                          "${PROJECT_SOURCE_DIR}/../math-tools/math-tools"
                          )
