PROJECT(CPP_MODULES)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Use C++11.
ADD_DEFINITIONS("-std=c++11")

# Reference own inlcudes.
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR})

# Create core library.
ADD_LIBRARY(
    core
    SHARED
    core/library.cpp
    core/print.cpp
)
# Create executable.
ADD_EXECUTABLE(cppModules main.cpp)
# Link executable with core library.
TARGET_LINK_LIBRARIES(cppModules core dl)

# Create user library.
ADD_LIBRARY(
    user
    MODULE
    user/user.cpp
    user/coreext.cpp
)
