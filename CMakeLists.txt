cmake_minimum_required(VERSION 3.5)
#sudo apt-get install graphviz-dev
#sudo dot -c
#name of project in directory
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)



include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(Graphviz)
message("${GRAPHVIZ_INCLUDE_DIRS}")
include_directories( ${GRAPHVIZ_INCLUDE_DIRS})

file (GLOB_RECURSE SRC_LIST src/*.cpp src/*.c   src/*.h  src/*.hpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${GRAPHVIZ_CDT_LIBRARY} ${GRAPHVIZ_GVC_LIBRARY} ${GRAPHVIZ_CGRAPH_LIBRARY} ${GRAPHVIZ_PATHPLAN_LIBRARY})
