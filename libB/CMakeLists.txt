cmake_minimum_required (VERSION 3.10)
project (lib_b VERSION 0.1.0 LANGUAGES CXX)

# enable C and C++17 language
enable_language (C CXX)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

#-------------------------------------------------------------------------------
# LIBRARY SOURCES SETTING
#-------------------------------------------------------------------------------

set (PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/libB.cpp
    )

add_library (${PROJECT_NAME} SHARED ${PROJECT_SOURCES})

target_include_directories (${PROJECT_NAME} PUBLIC
    ${PROJECT_INCLUDE_DIR}
    )

install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})
