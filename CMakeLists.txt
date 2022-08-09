cmake_minimum_required(VERSION 1.9)
project (note-keeper)

include_directories(include)
file(GLOB SOURCES "src/*.c")
add_executable(note-keeper ${SOURCES})

#install(TARGETS note-keeper DESTINATION bin)