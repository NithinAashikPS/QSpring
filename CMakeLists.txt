cmake_minimum_required(VERSION 3.10)

set(PACKAGE_VERSION 1.0.0)
project(QSpring VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
set(CMAKE_PREFIX_PATH C:\\Qt\\5.15.2\\mingw81_64)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(GNUInstallDirs)
add_subdirectory(src)

if(BUILD_SHARED_LIBS)
    add_library(
        QSpring SHARED 
        $<TARGET_OBJECTS:QSGui>
        $<TARGET_OBJECTS:QSControls>
    )
else()
    add_library(
        QSpring STATIC 
        $<TARGET_OBJECTS:QSGui>
        $<TARGET_OBJECTS:QSControls>
    )
endif()

target_link_libraries(
    QSpring PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/QSpringConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/QSpringConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/QSpringConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/QSpringConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/QSpringConfig.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
)