# lib

#find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

set(HEADERS
    mine/mine.hpp
)

set(SOURCES
    mine.cpp
)

####################
include(GNUInstallDirs)

set(name ${PROJECT_NAME})

add_library(${name}_objects OBJECT ${HEADERS} ${SOURCES})
set_target_properties(${name}_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(${name}_static STATIC $<TARGET_OBJECTS:${name}_objects>)
set_target_properties(${name}_static PROPERTIES
    OUTPUT_NAME ${name}
)

add_library(${name}_shared SHARED $<TARGET_OBJECTS:${name}_objects>)
set_target_properties(${name}_shared PROPERTIES
    OUTPUT_NAME ${name}
    VERSION     ${PROJECT_VERSION}
    SOVERSION   ${PROJECT_VERSION_MAJOR}
)

foreach(target ${name}_objects ${name}_static ${name}_shared)
    target_include_directories(${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )
    #target_link_libraries(${target} PUBLIC Qt6::Core Qt6::Widgets)
endforeach()

add_library(${name}::${name}_static ALIAS ${name}_static)
add_library(${name}::${name}_shared ALIAS ${name}_shared)
add_library(${name}::${name} ALIAS ${name}_shared)

####################
install(TARGETS ${name}_shared ${name}_static
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${name})
