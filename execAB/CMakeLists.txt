cmake_minimum_required (VERSION 3.10)
project (exec_ab VERSION 0.1.0 LANGUAGES CXX)

# enable C and C++17 language
enable_language (C CXX)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

#-------------------------------------------------------------------------------
# EXECUTABLE SOURCES SETTING
#-------------------------------------------------------------------------------

find_library(LIB_AB lib_ab PATHS ~/libraries/lib)

if(NOT LIB_AB)
    message(FATAL ERROR "libAB not found")
endif()

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    )

add_executable (${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories (${PROJECT_NAME} PUBLIC
    ${CMAKE_INSTALL_PREFIX}/include
    )

target_link_libraries(${PROJECT_NAME}
    ${LIB_AB})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
