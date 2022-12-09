cmake_minimum_required(VERSION 3.5)

project(src VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Sql Core Network Multimedia)

set(PROJECT_SOURCES
        main.cpp

        # Login Window files
        loginwindow.h
        loginwindow.cpp
        loginwindow.ui

        #Sign Up Window files
        signupwindow.h
        signupwindow.cpp
        signupwindow.ui

        # Main Page files
        mainpage.h
        mainpage.cpp
        mainpage.ui

        # Account files
        account.h
        account.cpp

        # There stored all images for program
        Images/resourses.qrc

        # Class For Communicating with Server
        communicatewithserver.h
        communicatewithserver.cpp

        # Checker For Logins & Passwords
        checker/checker.cpp
        checker/checker.h
        checker/ensuremessagebox.ui
        checker/ensuremessagebox.h
        checker/ensuremessagebox.cpp

        # Layouts deleter
        layoutsdeleter.h
        layoutsdeleter.cpp

)

add_executable(src
    ${PROJECT_SOURCES}
)

target_link_libraries(src PRIVATE
    Qt5::Widgets
    Qt5::Sql
    Qt5::Core
    Qt5::Network
    Qt5::Multimedia
)

set_target_properties(src PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS src
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
