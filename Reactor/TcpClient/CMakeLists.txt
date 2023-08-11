cmake_minimum_required(VERSION 3.0)
project(TcpClient)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(TcpClient  ${SRC_LIST})
