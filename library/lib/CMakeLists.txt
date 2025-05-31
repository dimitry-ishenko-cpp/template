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

add_library(${PROJECT_NAME}_objects OBJECT ${HEADERS} ${SOURCES})
set_target_properties(${PROJECT_NAME}_objects PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(${PROJECT_NAME}_static STATIC $<TARGET_OBJECTS:${PROJECT_NAME}_objects>)
set_target_properties(${PROJECT_NAME}_static PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
)

add_library(${PROJECT_NAME}_shared SHARED $<TARGET_OBJECTS:${PROJECT_NAME}_objects>)
set_target_properties(${PROJECT_NAME}_shared PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    VERSION     ${PROJECT_VERSION}
    SOVERSION   ${PROJECT_VERSION_MAJOR}
)

foreach(target ${PROJECT_NAME}_objects ${PROJECT_NAME}_static ${PROJECT_NAME}_shared)
    target_include_directories(${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    )
    #target_link_libraries(${target} PUBLIC Qt6::Core Qt6::Widgets)
endforeach()

add_library(${PROJECT_NAME} ALIAS ${PROJECT_NAME}_shared)

####################
install(TARGETS ${PROJECT_NAME}_shared ${PROJECT_NAME}_static
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})
