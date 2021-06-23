cmake_minimum_required(VERSION 3.10)
project(shm)

########################################################################
######### Download and unpack googletest at configure time #############
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
RESULT_VARIABLE result
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
${CMAKE_BINARY_DIR}/googletest-build
EXCLUDE_FROM_ALL)
if (CMAKE_VERSION VERSION_LESS 2.8.11)
include_directories("${gtest_SOURCE_DIR}/include")
endif()
########################################################################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/..)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

set(SOURCES
    ${SOURCE_DIR}/Cargo.cpp
    ${SOURCE_DIR}/Island.cpp
    ${SOURCE_DIR}/Map.cpp
    ${SOURCE_DIR}/Ship.cpp
    ${SOURCE_DIR}/Player.cpp
)

add_library(${PROJECT_NAME}-lib STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME}-lib PUBLIC ${INCLUDE_DIR})
target_compile_options(${PROJECT_NAME}-lib PRIVATE -Wall -Wextra -pedantic -Wconversion)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)

set(TESTS
    ${TEST_DIR}/Player-test.cpp
)

add_executable(${PROJECT_NAME}-ut ${TESTS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -pedantic -Wconversion)

target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)

enable_testing()
add_test(NAME ${PROJECT_NAME}-test COMMAND ${PROJECT_NAME}-ut)
