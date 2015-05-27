cmake_minimum_required (VERSION 2.8.4) 

#variables
set(SRC_DIR "Code")
set(INCLUDE_DIR "include")
set(DEBUG_BIN_DIR "Debug")
set(RELEASE_BIN_DIR "Release")
set(LIB_NAME "THelper")

#project
project (thelper)

#externial libs

#compiler options
set(CMAKE_CXX_FLAGS "-std=c++1y")

if ("${NO_COVERAGE}" STREQUAL "true")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
else ("${NO_COVERAGE}" STREQUAL "true")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
endif ("${NO_COVERAGE}" STREQUAL "true")

set(NORMAL_WARNING_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
set(EXTRA_WARNING_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -Wall  -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG "${EXTRA_WARNING_FLAGS}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

#tests
set(COVERAGE_COMMAND "gcov")

set(CTEST_MEMORYCHECK_COMMAND "valgrind")
set(CTEST_MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --quiet
--tool=memcheck --leak-check=yes --show-reachable=yes
--num-callers=100 --verbose --demangle=yes")

#includes
include_directories(${INCLUDE_DIR})

#files
file(GLOB RANDOM_LIB_FILES ${SRC_DIR}/Random/src/*.cpp)
file(GLOB OS_LIB_FILES ${SRC_DIR}/OS/src/*.cpp)
file(GLOB CONFIGURATION_LIB_FILES ${SRC_DIR}/Configuration/src/*.cpp)
file(GLOB DATE_TIME_LIB_FILES ${SRC_DIR}/DateTime/src/*.cpp)
file(GLOB STREAM_LIB_FILES ${SRC_DIR}/Stream/src/*.cpp)

#executables
if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	if ("${NO_COVERAGE}" STREQUAL "true")
	else ("${NO_COVERAGE}" STREQUAL "true")
		add_definitions(--coverage)
	endif ("${NO_COVERAGE}" STREQUAL "true")
	file(MAKE_DIRECTORY ${DEBUG_BIN_DIR})
	set(LIBRARY_OUTPUT_DIRECTORY ${DEBUG_BIN_DIR})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DEBUG_BIN_DIR})
			
	#test		
	if (${BUILD_TESTS})
	add_subdirectory(Test)		
	endif (${BUILD_TESTS})
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")
	file(MAKE_DIRECTORY ${RELEASE_BIN_DIR})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RELEASE_BIN_DIR})
else (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	message(FATAL_ERROR "Invalid build type. Can be Debug | Release")
endif (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

add_library(${LIB_NAME} ${RANDOM_LIB_FILES} ${OS_LIB_FILES} ${CONFIGURATION_LIB_FILES} ${DATE_TIME_LIB_FILES} ${STREAM_LIB_FILES})

#libraries
#TARGET_LINK_LIBRARIES(${LIB_OUTPUT_FILE} ${Boost_LIBRARIES} )

