cmake_minimum_required(VERSION 3.22)
project(MAIN LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(SRC_F
	${PROJECT_SOURCE_DIR}/lib/SqlBuilder.cxx
)

set(HEAD_F
	${PROJECT_SOURCE_DIR}/lib/SqlBuilder.hxx
)

add_executable(${PROJECT_NAME} main.cxx ${SRC_F} ${HEAD_F})
