set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/Gui)

set(
    QSGUI_PUBLIC_HEADERS
    ${INCLUDE_DIR}/QSGuiApplication
    ${INCLUDE_DIR}/qs_guiapplication.hpp
)

set(
    PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/Gui/qs_guiapplication.cpp
)

if(BUILD_SHARED_LIBS)
    add_library(QSGui SHARED ${PROJECT_SOURCES} ${QSGUI_PUBLIC_HEADERS})
else()
    add_library(QSGui STATIC ${PROJECT_SOURCES} ${QSGUI_PUBLIC_HEADERS})
endif()

target_include_directories(QSGui PRIVATE ${INCLUDE_DIR})
target_link_libraries(
    QSGui PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)

target_include_directories(QSGui PUBLIC
    $<BUILD_INTERFACE:${INCLUDE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(FILES ${QSGUI_PUBLIC_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(
    TARGETS QSGui
    EXPORT QSGuiTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT QSGuiTargets
    FILE QSGuiConfig.cmake
    NAMESPACE QSpring::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
    COMPONENT Gui
)

# export(
#     EXPORT QSGuiTargets
#     FILE ${CMAKE_INSTALL_LIBDIR}/cmake/QSGuiConfig.cmake
#     NAMESPACE QSpring::
# )