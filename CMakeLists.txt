cmake_minimum_required(VERSION 3.1)

project(machigaisagashi)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cc)

add_executable(machigaisagashi ${SOURCE_FILES})

if(OpenCV_FOUND)
  include_directories(${OpenCV_INCLUDE_DIRS})
  target_link_libraries(machigaisagashi ${OpenCV_LIBS})
endif(OpenCV_FOUND)
