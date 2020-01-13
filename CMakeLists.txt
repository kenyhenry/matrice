cmake_minimum_required(VERSION 3.0)

project(matrix)


set(SRCS
  main.c
)

set(HEADERS
)

include_directories("/share/home/khenry/simulateur/headers")

add_executable(${CMAKE_PROJECT_NAME} ${SRCS} ${HEADERS})

install (TARGETS ${CMAKE_PROJECT_NAME} DESTINATION build)
