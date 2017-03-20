CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# set project name
PROJECT(cpp11)

# set version number.
SET(Cpp11_VERSION_MAJOR 0)
SET(Cpp11_VERSION_MINOR 6)

# set default compilers
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_C_COMPILER "gcc")

# C++ compiler flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -pthread" )

# set source dir
SET(${PROJECT_SOURCE_DIR} "src")

# configure header file to pass CMake settings to the source code
CONFIGURE_FILE(
    "${PROJECT_SOURCE_DIR}/cpp11config.hh.in"
    "${PROJECT_BINARY_DIR}/cpp11config.hh"
)
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
INCLUDE_DIRECTORIES(
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Builder"
    "${PROJECT_SOURCE_DIR}/Singleton"
    "${PROJECT_SOURCE_DIR}/Factory"
    "${PROJECT_SOURCE_DIR}/Visitor"
)

# Output directories
SET(
    EXECUTABLE_OUTPUT_PATH
    ${CMAKE_BINARY_DIR}/bin
)

SET(
    LIBRARY_OUTPUT_PATH
    ${CMAKE_BINARY_DIR}/lib
)

ADD_SUBDIRECTORY(
    "${PROJECT_SOURCE_DIR}/src/Builder"
)

ADD_SUBDIRECTORY(
    "${PROJECT_SOURCE_DIR}/src/Singleton"
)

ADD_SUBDIRECTORY(
    "${PROJECT_SOURCE_DIR}/src/Factory"
)

ADD_SUBDIRECTORY(
    "${PROJECT_SOURCE_DIR}/src/Visitor"
)

# add the executable
ADD_EXECUTABLE(
    cpp11
    src/main.cc
)

TARGET_LINK_LIBRARIES(
    cpp11
    Builder
    Singleton
    Factory
	Visitor
)

