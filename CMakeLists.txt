cmake_minimum_required(VERSION 3.23)
project(AudioPlayer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED
        )

add_executable(AudioPlayer main.cpp)
target_link_libraries(AudioPlayer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        )
