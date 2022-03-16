cmake_minimum_required(VERSION 3.10)

PROJECT(MyMuduo CXX)
set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++17 -pthread")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

ADD_EXECUTABLE(HttpTest HttpTest.cpp)

target_link_libraries(HttpTest
    MyMuduoLib
)