cmake_minimum_required (VERSION 3.20)
project(ReflectionLib)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

option(USE_COROUTINE "Coroutine support" OFF)
option(TEST_ENABLE "Test" OFF)

configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h)

find_package(Boost)
if (Boost_FOUND) 
	set(Boost_DIRS ${Boost_INCLUDE_DIRS})
	set(Boost_LIBS ${Boost_LIBRARIES})
else ()	
	set(Boost_DIRS "D:/Git/vcpkg/installed/x64-windows/include")
	set(Boost_LIBS "D:/Git/vcpkg/installed/x64-windows/lib")
endif ()

if (USE_COROUTINE) 
	set(INCLUDE_DIR "async")
else ()
	set(INCLUDE_DIR "sync")
endif ()

list(APPEND INCLUDE 
	# Helpful
	include/${INCLUDE_DIR}/definitions.hpp
	# Transfer
	include/${INCLUDE_DIR}/transfer/isender.hpp
	include/${INCLUDE_DIR}/transfer/sender.hpp
	include/${INCLUDE_DIR}/transfer/ireceiver.hpp
	include/${INCLUDE_DIR}/transfer/receiver.hpp
	# Connection
	include/${INCLUDE_DIR}/connection/iconnection.hpp
	include/${INCLUDE_DIR}/connection/connection.hpp
	include/${INCLUDE_DIR}/connection/iacceptor.hpp
	include/${INCLUDE_DIR}/connection/acceptor.hpp
)
list(APPEND SRC 
	# Transfer
	src/${INCLUDE_DIR}/transfer/sender.cpp
	src/${INCLUDE_DIR}/transfer/receiver.cpp
	# Connection
	src/${INCLUDE_DIR}/connection/connection.cpp
	src/${INCLUDE_DIR}/connection/acceptor.cpp
)

add_library(ReflectionLib STATIC
	${INCLUDE}
	${SRC}
)
target_include_directories(${PROJECT_NAME} PUBLIC
	${Boost_DIRS}
)
target_link_libraries(${PROJECT_NAME} 
	${Boost_LIBS}
)
target_compile_definitions(${PROJECT_NAME} PUBLIC 
	_WIN32_WINNT=0x0601
)
target_include_directories(${PROJECT_NAME} INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (TEST_ENABLE)
	add_subdirectory(test)
endif ()