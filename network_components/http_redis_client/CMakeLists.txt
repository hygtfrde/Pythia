cmake_minimum_required(VERSION 3.22)
project(pythia VERSION 0.0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files excluding main.cpp
file(GLOB_RECURSE SOURCES "src/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Create an object library from the source files
add_library(pythiaObj OBJECT ${SOURCES})

# Find and link hiredis library
find_path(HIREDIS_HEADER hiredis)
target_include_directories(pythiaObj PUBLIC ${HIREDIS_HEADER})
find_library(HIREDIS_LIB hiredis)
target_link_libraries(pythiaObj PRIVATE ${HIREDIS_LIB})

# Find and link redis-plus-plus library
find_path(REDIS_PLUS_PLUS_HEADER sw)
target_include_directories(pythiaObj PUBLIC ${REDIS_PLUS_PLUS_HEADER})
find_library(REDIS_PLUS_PLUS_LIB redis++)
target_link_libraries(pythiaObj PRIVATE ${REDIS_PLUS_PLUS_LIB})

# Find and link CSV2 library
find_path(CSV2_HEADER csv2)
target_include_directories(pythiaObj PUBLIC ${CSV2_HEADER})
find_library(REDIS_PLUS_PLUS_LIB csv2)
target_link_libraries(pythiaObj PRIVATE ${REDIS_PLUS_PLUS_LIB})

# Find and link nlohmann_json library
find_package(nlohmann_json 3.11.3 REQUIRED)
target_link_libraries(pythiaObj PRIVATE nlohmann_json::nlohmann_json)

# Create the main executable with main.cpp
add_executable(pythia src/main.cpp)
target_link_libraries(pythia PRIVATE pythiaObj)

# Option to enable or disable GoogleTest
option(ENABLE_GTEST "Enable Google Test" OFF)

if(ENABLE_GTEST)
    enable_testing()
    find_package(GTest REQUIRED)

    # Add test executable
    add_executable(redis_api_test tests/redis_api_test.cc)
    target_link_libraries(redis_api_test PRIVATE GTest::gtest_main pythiaObj)

    include(GoogleTest)
    gtest_discover_tests(ptyhia_test)
endif()

# Install a pkg-config file.
# CONFIGURE_FILE(
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
# )
