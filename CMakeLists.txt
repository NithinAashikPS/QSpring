cmake_minimum_required(VERSION 3.10)

set(PACKAGE_VERSION 1.0.0)
project(QSpring VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)

option(BUILD_EXAMPLES "Build QSpring Examples" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if(BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

set(
    QSPRING_PUBLIC_HEADERS
    ${CMAKE_SOURCE_DIR}/include/QSpring.hpp
)

set(
    PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/QSpring.cpp
)

if(BUILD_SHARED_LIBS)
    add_library(QSpring SHARED ${PROJECT_SOURCES})
else()
    add_library(QSpring STATIC ${PROJECT_SOURCES})
endif()

target_include_directories(QSpring PUBLIC ${CMAKE_SOURCE_DIR}/include)


install(FILES ${QSPRING_PUBLIC_HEADERS} DESTINATION include)
install(TARGETS QSpring LIBRARY DESTINATION lib)