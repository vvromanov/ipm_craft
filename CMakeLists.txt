cmake_minimum_required(VERSION 3.25)
project(craft)

set(CMAKE_CXX_STANDARD 20)

add_executable(craft
        main.cpp
        Resource.cpp
        Resource.h
        Ore.cpp
        Ore.h
        Alloy.cpp
        Alloy.h
        ResourceList.cpp
        ResourceList.h
        Item.cpp
        Item.h
        Project.cpp
        Project.h
        rx_dump.c
        rx_dump.h
        ResourceRec.cpp
        ResourceRec.h
        MiningSettings.h)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
