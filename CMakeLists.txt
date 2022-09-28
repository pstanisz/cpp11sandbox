CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)

# set project name
PROJECT(cpp11)

# set version number.
SET(Cpp11_VERSION_MAJOR 0)
SET(Cpp11_VERSION_MINOR 7)

# set default compilers
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_C_COMPILER "gcc")

# C++ compiler flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -Wall -pedantic" )

# set source dir and test dir
SET(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
SET(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

# configure header file to pass CMake settings to the source code
CONFIGURE_FILE(
    ${PROJECT_SOURCE_DIR}/cpp11config.hh.in
    ${PROJECT_BINARY_DIR}/cpp11config.hh
)
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
INCLUDE_DIRECTORIES(
    ${PROJECT_BINARY_DIR}
    ${SOURCE_DIR}/Builder
    ${SOURCE_DIR}/Singleton
    ${SOURCE_DIR}/Factory
    ${SOURCE_DIR}/Visitor
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
    ${SOURCE_DIR}/Builder
)

ADD_SUBDIRECTORY(
    ${SOURCE_DIR}/Singleton
)

ADD_SUBDIRECTORY(
    ${SOURCE_DIR}/Factory
)

ADD_SUBDIRECTORY(
    ${SOURCE_DIR}/Visitor
)

ADD_SUBDIRECTORY(
    ${TEST_DIR}
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

ENABLE_TESTING()
INCLUDE(CTest)
