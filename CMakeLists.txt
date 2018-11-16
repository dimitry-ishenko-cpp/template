cmake_minimum_required(VERSION 3.1)
project(name VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTOUIC ON)

#find_package(Qt5Core)
#find_package(Qt5Widgets)

#add_definitions(-D...)

include_directories(src)

set(MAIN src/main.cpp)
set(FILES LICENSE.md README.md)

# sub-project(s)
#option(BUILD_... "Build ..." ON)
#if(BUILD_...)
#    add_subdirectory(...)
#    set_property(TARGET ... PROPERTY ...)
#endif(BUILD_...)

########################
# executable
add_executable(${PROJECT_NAME} ${MAIN})
#target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

# dynamic library
#add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})
#set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
#set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

# static library
#add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

# install
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#install(TARGETS ${PROJECT_NAME} DESTINATION lib)
#install(DIRECTORY include/ DESTINATION include)
install(FILES ${FILES} DESTINATION share/doc/${PROJECT_NAME})

########################
# object files
#add_library(${PROJECT_NAME} OBJECT ${HEADERS} ${SOURCES})

# to use in other project(s), add $<TARGET_OBJECTS:...>

########################
# package
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_STRIP_FILES ON)
set(CPACK_PACKAGE_FILE_NAME
    ${PROJECT_NAME}_${PROJECT_VERSION}_${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}
)

# source
#set(CPACK_SOURCE_GENERATOR TBZ2)
#set(CPACK_SOURCE_IGNORE_FILES /\.git.*;/build/;\.user$)

# binary
#set(CPACK_GENERATOR DEB)
#set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "...")
#set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Dimitry Ishenko <dimitry (dot) ishenko (at) (gee) mail (dot) com>")
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "...")

#include(CPack)
