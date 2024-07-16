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
find_path(HIREDIS_HEADER hiredis PATHS /usr/local/include /usr/include /opt/homebrew/include)
target_include_directories(pythiaObj PUBLIC ${HIREDIS_HEADER})
find_library(HIREDIS_LIB hiredis PATHS /usr/local/lib /usr/lib /opt/homebrew/lib)
target_link_libraries(pythiaObj PRIVATE ${HIREDIS_LIB})

# Find and link redis-plus-plus library
find_path(REDIS_PLUS_PLUS_HEADER sw PATHS /usr/local/include /usr/include /opt/homebrew/include)
target_include_directories(pythiaObj PUBLIC ${REDIS_PLUS_PLUS_HEADER})
find_library(REDIS_PLUS_PLUS_LIB redis++ PATHS /usr/local/lib /usr/lib /opt/homebrew/lib)
target_link_libraries(pythiaObj PRIVATE ${REDIS_PLUS_PLUS_LIB})

# Include CSV2 library (header-only)
set(CSV2_HEADER ${PROJECT_SOURCE_DIR}/csv2/include)
target_include_directories(pythiaObj PUBLIC ${CSV2_HEADER})

# Include nlohmann_json headers
target_include_directories(pythiaObj PUBLIC ${PROJECT_SOURCE_DIR}/json/include)

# Include Crow headers
set(CROW_HEADER ${PROJECT_SOURCE_DIR}/Crow/include)
target_include_directories(pythiaObj PUBLIC ${CROW_HEADER})

# Include Asio headers
set(ASIO_HEADER ${PROJECT_SOURCE_DIR}/asio/asio/include)
target_include_directories(pythiaObj PUBLIC ${ASIO_HEADER})

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
    gtest_discover_tests(pythia_test)
endif()

# Install a pkg-config file.
# CONFIGURE_FILE(
#     "${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in"
#     "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc"
# )
