cmake_minimum_required(VERSION 3.10)
project(main)

set(CMAKE_CXX_STANDARD 14)

# Debes cambiar lo que esta en parentesis
# a la ruta del directorio donde está catch.hpp
include_directories(/Users/rarce/ccom3034)

add_executable(main main.cpp)
