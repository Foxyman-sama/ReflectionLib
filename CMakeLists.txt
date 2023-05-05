cmake_minimum_required (VERSION 3.20)
project(ReflectionLib)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

option(USE_COROUTINE "Coroutine support" ON)
option(TEST_ENABLE "Test" ON)

configure_file(networkcfg.hpp.in 
	${CMAKE_CURRENT_SOURCE_DIR}/include/networkcfg.hpp
)

find_package(Boost)
if (Boost_FOUND) 
	set(Boost_DIRS ${Boost_INCLUDE_DIRS})
	set(Boost_LIBS ${Boost_LIBRARIES})
else ()	
	if (CMAKE_SIZEOF_VOID_P EQUAL 8)
		set(Boost_DIRS "D:/Git/vcpkg/installed/x64-windows/include")
		set(Boost_LIBS "D:/Git/vcpkg/installed/x64-windows/lib")
	else ()	
		set(Boost_DIRS "D:/Git/vcpkg/installed/x86-windows/include")
		set(Boost_LIBS "D:/Git/vcpkg/installed/x86-windows/lib")
	endif ()
endif ()

list(APPEND INCLUDE 
	# Helpful
	include/definitions.hpp
	# Data 
	include/data.hpp
	# Connection
	include/network/connection/iconnection.hpp
	include/network/connection/connection.hpp
	include/network/connection/iacceptor.hpp
	include/network/connection/acceptor.hpp
	# Transfer
	include/network/transfer/isender.hpp
	include/network/transfer/sender.hpp
	include/network/transfer/ireceiver.hpp
	include/network/transfer/receiver.hpp
	# Input 	
	include/system/input/iinput.hpp
	include/system/input/inputfile.hpp
	# Output 	
	include/system/output/ioutput.hpp
	include/system/output/outputfile.hpp
)
list(APPEND SRC 
	# Data
	src/data.cpp
	# Transfer
	src/network/transfer/sender.cpp
	src/network/transfer/receiver.cpp
	# Connection
	src/network/connection/connection.cpp
	src/network/connection/acceptor.cpp
	# Input 
	src/system/input/inputfile.cpp
	# Output 
	src/system/output/outputfile.cpp
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