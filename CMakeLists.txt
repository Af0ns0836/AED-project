cmake_minimum_required(VERSION 3.22)
project(AED_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(AED_project main.cpp Schedule.cpp Schedule.h Student.cpp Student.h Class.cpp Class.h Lecture.cpp Lecture.h UC.cpp UC.h)
