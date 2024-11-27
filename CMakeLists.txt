cmake_minimum_required(VERSION 3.30)
project(RedSocial)

set(CMAKE_CXX_STANDARD 20)

# Set the path to your Qt6 installation
set(Qt6_DIR /home/gabriels/Qt/6.8.0/gcc_64/lib/cmake/Qt6)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(RedSocial main.cpp mainwindow.cpp mainwindow.ui)
target_link_libraries(RedSocial Qt6::Widgets)