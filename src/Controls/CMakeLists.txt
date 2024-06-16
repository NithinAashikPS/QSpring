set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/Controls)

set(
    QSCONTROLS_PUBLIC_HEADERS
    ${INCLUDE_DIR}/QSApplicationWindow
    ${INCLUDE_DIR}/qs_applicationwindow.hpp
)

set(
    PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/Controls/qs_applicationwindow.cpp
)

if(BUILD_SHARED_LIBS)
    add_library(QSControls SHARED ${PROJECT_SOURCES} ${QSCONTROLS_PUBLIC_HEADERS})
else()
    add_library(QSControls STATIC ${PROJECT_SOURCES} ${QSCONTROLS_PUBLIC_HEADERS})
endif()

target_include_directories(QSControls PRIVATE ${INCLUDE_DIR})
target_link_libraries(
    QSControls PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)

target_include_directories(QSControls PUBLIC
    $<BUILD_INTERFACE:${INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(FILES ${QSCONTROLS_PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(
    TARGETS QSControls
    EXPORT QSControlsTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT QSControlsTargets
    FILE QSControlsConfig.cmake
    NAMESPACE QSpring::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    COMPONENT Controls
)

# export(
#     EXPORT QSControlsTargets
#     FILE ${CMAKE_INSTALL_LIBDIR}/cmake/QSControlsConfig.cmake
#     NAMESPACE QSpring::
# )