cmake_minimum_required (VERSION 3.10)
project (lib_ab VERSION 0.1.0 LANGUAGES CXX)

# enable C and C++17 language
enable_language (C CXX)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

#-------------------------------------------------------------------------------
# LIBRARY SOURCES SETTING
#-------------------------------------------------------------------------------

find_library(LIB_A lib_a)
find_library(LIB_B lib_b)

if(NOT LIB_A OR NOT LIB_B)
    message(FATAL ERROR "libA or libB not found")
endif()

set (PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libAB.cpp
    )

add_library (${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_include_directories (${PROJECT_NAME} PUBLIC
    ${PROJECT_INCLUDE_DIR}
    ${CMAKE_INSTALL_PREFIX}/include
    )

target_link_libraries(${PROJECT_NAME}
    ${LIB_A}
    ${LIB_B})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})
