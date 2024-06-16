cmake_minimum_required(VERSION 3.10)

project(QSpringExample VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
    CMAKE_PREFIX_PATH
    "C://Projects//CPP//QSpring//build-debug//install//lib"
    "C:\\Qt\\5.15.2\\mingw81_64"
)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

find_package(QSpring REQUIRED)

add_executable(QSpringExample main.cpp)
target_link_libraries(QSpringExample PRIVATE QSpring::QSpring)
target_link_libraries(
    QSpringExample PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)

install(TARGETS QSpringExample RUNTIME DESTINATION bin)
