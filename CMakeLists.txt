cmake_minimum_required(VERSION 3.30)
project(RedSocial)

set(CMAKE_CXX_STANDARD 20)

# Set the path to your Qt6 installation
set(Qt6_DIR /home/gabriels/Qt/6.8.0/gcc_64/lib/cmake/Qt6)

# Set the CMake prefix path
set(CMAKE_PREFIX_PATH /home/gabriels/Qt/6.8.0/gcc_64/lib/cmake/Qt6)

# Find the Qt6 packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Enable automatic MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add the executable
add_executable(RedSocial main.cpp mainwindow.cpp mainwindow.ui)

# Link the Qt6 libraries
target_link_libraries(RedSocial Qt6::Core Qt6::Gui Qt6::Widgets)