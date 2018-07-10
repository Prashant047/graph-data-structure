cmake_minimum_required (VERSION 3.6.2)
project (cpp_test)
set(CMAKE_CXX_STANDARD 11)

include_directories(include)


#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(some_exec ${SOURCES})
