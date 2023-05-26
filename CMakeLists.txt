cmake_minimum_required(VERSION 3.12)
project(studentu_programa)

# Add the executable target
add_executable(studentai src/funkcijos.cpp src/v1.0_obj.cpp)

# Add any additional source files if needed
target_sources(studentai PRIVATE src/Biblioteka.h src/funkciju_bib.h)

# Set the include directories
target_include_directories(studentai PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
