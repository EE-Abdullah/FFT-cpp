cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)
find_package(PythonLibs 3.6 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
FILE(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(program main.cpp ${SOURCES})
target_link_libraries(program
${PYTHON_LIBRARIES}
)
