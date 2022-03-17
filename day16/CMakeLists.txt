cmake_minimum_required(VERSION 3.10)

PROJECT(MyMuduo CXX)
SET(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++17 -pthread")
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

ADD_EXECUTABLE(HttpTest HttpTest.cpp)

target_link_libraries(HttpTest
    MyMuduoLib
)