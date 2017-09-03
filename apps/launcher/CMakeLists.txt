set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(UI_HEADERS ../../resources/ui/mainwindow.ui)

add_executable(launcher

    ../../resources/ui/mainwindow.ui
    main.cpp
    mainwindow.h
    mainwindow.cpp
    page.h
    playpage.h
    playpage.cpp
    graphicspage.h
    graphicspage.cpp
    processinvoker.h
    processinvoker.cpp
)

target_link_libraries(launcher SDL2::SDL2 Cel ${HUNTER_BOOST_LIBS} ${QT_LIB})
target_include_directories(launcher PUBLIC ${QT_INCL})

set_target_properties(launcher PROPERTIES COMPILE_FLAGS "${FA_COMPILER_FLAGS}")
