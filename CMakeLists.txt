cmake_minimum_required(VERSION 3.1)
project(template VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#add_definitions(-DASIO_STANDALONE)
add_definitions(-DVERSION="${PROJECT_VERSION}")

#find_package(Threads REQUIRED)

#find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

set(HEADERS ) # public headers, use SOURCES for private headers
set(SOURCES src/main.cpp)

# sub-project(s)
#option(BUILD_... "Build ..." ON)
#if(BUILD_...)
#    add_subdirectory(...)
#    set_property(TARGET ... PROPERTY ...)
#endif(BUILD_...)

include(GNUInstallDirs)

########################
# executable
add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
#target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
install(FILES LICENSE.md README.md DESTINATION ${CMAKE_INSTALL_DOCDIR})

########################
#string(REGEX REPLACE "^lib" "" LIBRARY_NAME ${PROJECT_NAME})
#set(PROJECT_NAME_DEV ${PROJECT_NAME}-dev)
#set(CMAKE_INSTALL_DOCDIR_DEV ${CMAKE_INSTALL_DATAROOTDIR}/doc/${PROJECT_NAME_DEV})

# shared library
#add_library(shared SHARED ${HEADERS} ${SOURCES})
#set_target_properties(shared PROPERTIES OUTPUT_NAME ${LIBRARY_NAME})
#set_target_properties(shared PROPERTIES VERSION ${PROJECT_VERSION})
#set_target_properties(shared PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})

#install(TARGETS shared DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT shared)
#install(FILES LICENSE.md README.md DESTINATION ${CMAKE_INSTALL_DOCDIR} COMPONENT shared)

# static dev library and headers
#add_library(static STATIC ${HEADERS} ${SOURCES})
#set_target_properties(static PROPERTIES OUTPUT_NAME ${LIBRARY_NAME})

#install(TARGETS static DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT static)
#install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME} COMPONENT static)
#install(FILES LICENSE.md README.md DESTINATION ${CMAKE_INSTALL_DOCDIR_DEV} COMPONENT static)

########################
# object files
#add_library(${PROJECT_NAME} OBJECT ${HEADERS} ${SOURCES})

# to use in other project(s), add $<TARGET_OBJECTS:...>
