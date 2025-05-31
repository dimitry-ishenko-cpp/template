cmake_minimum_required(VERSION 3.16) # focal
project(mine VERSION 0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_definitions(-DASIO_STANDALONE)
add_definitions(-DVERSION="${PROJECT_VERSION}")

#find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

include(GNUInstallDirs)

#add_subdirectory(...)

#option(BUILD_... "Build ..." ON)
#if(BUILD_...)
#    add_subdirectory(...)
#endif()

add_executable(${PROJECT_NAME} main.cpp)
#target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
