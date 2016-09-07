cmake_minimum_required(VERSION 2.6)
project(Logger)

# define the project
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

## Target
set(SOURCES 
		Logs.cpp
)
set(HEADERS 	
		dirent_win.h
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})