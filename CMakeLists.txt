cmake_minimum_required(VERSION 3.26)
project(lab2Buntsev)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2Buntsev main.cpp
        menu.h
        tests.h
        sequence.h
        Array&&List.h
        ImmutableLinkedList.h)
