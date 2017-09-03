set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

qt5_wrap_ui(UI_HEADERS ../../resources/ui/celview.ui)


add_executable(celview

    ../../resources/ui/celview.ui
    main.cpp
    mainwindow.h
    mainwindow.cpp
)

target_link_libraries(celview Render ${QT_LIB})
target_include_directories(celview PUBLIC ${QT_INCL})

set_target_properties(celview PROPERTIES COMPILE_FLAGS "${FA_COMPILER_FLAGS}")
