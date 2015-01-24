cmake_minimum_required(VERSION 2.6)

project(lambda)

set(BOOST_INCLUDEDIR /usr/local/boost_1_54_0)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

IF(NOT EXISTS ${BIN_DIR})
	FILE(MAKE_DIRECTORY ${BIN_DIR})
ENDIF(NOT EXISTS ${BIN_DIR})

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g")

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

add_executable(lambda src/main)

TARGET_LINK_LIBRARIES( lambda ${Boost_LIBRARIES} )

