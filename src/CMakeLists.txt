option(BUILD_QSPRING_GUI "Build QSpring Gui Libraries" ON)
option(BUILD_QSPRING_CORE "Build QSpring Core Libraries" ON)
option(BUILD_QSPRING_CONTROLS "Build QSpring Controls Libraries" ON)

if(BUILD_QSPRING_GUI)
    add_subdirectory(Gui)
endif()

if(BUILD_QSPRING_CORE)
    add_subdirectory(Core)
endif()

if(BUILD_QSPRING_CONTROLS)
    add_subdirectory(Controls)
endif()