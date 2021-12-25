cmake_minimum_required(VERSION 3.18)

project(python_embeded VERSION 1.0)


include_directories(${CMAKE_SOURCE_DIR}/include
					${CMAKE_SOURCE_DIR}/3rd/fmt/include
					${CMAKE_SOURCE_DIR}/3rd/python/include/python3.10)

set(SOURCE ${CMAKE_SOURCE_DIR}/source/main.cpp
		   ${CMAKE_SOURCE_DIR}/source/backend.cpp
		   ${CMAKE_SOURCE_DIR}/source/frontend.cpp)

link_directories(${CMAKE_SOURCE_DIR}/3rd/python/lib
				 ${CMAKE_SOURCE_DIR}/3rd/fmt/libs/linux)

add_executable(python_embeded ${SOURCE})
target_link_libraries(python_embeded python3.10 pthread util dl fmt)