cmake_minimum_required(VERSION 3.0)

project(MarkovText)

file(GLOB Source "src/*.*pp")

add_definitions(-std=c++1y -DDEBUG -g)
add_executable(Markov ${Source})

install(TARGETS Markov DESTINATION /usr/local/bin/)
