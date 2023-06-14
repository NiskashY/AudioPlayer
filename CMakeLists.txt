cmake_minimum_required(VERSION 3.5)

project(src VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Sql Core Network Multimedia)

set(COMMON_INCLUDE ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDE})

# Define .cpp files
file(GLOB SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/checker/*.cpp
)

# Define .h files for QtCreator
file(GLOB HDR_FILES
    ${COMMON_INCLUDE}/*.h
)

# Define .ui files for QtCreator
file(GLOB UI_FILES
    ${PROJECT_SOURCES}/src/*.ui
)

set(PROJECT_SOURCES
    ${SRC_FILES}
    ${HDR_FILES}
    ${UI_FILES}

    # There stored all images for program
    images/resourses.qrc
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
