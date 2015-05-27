set(TEST_DIR ".")
set(TEST_EXE_DIR "${TEST_DIR}")
set(TEST_SRC_DIR "${TEST_DIR}/src")
set(TEST_INC_DIR "${TEST_DIR}/inc")
set(TEST_EXE ${TEST_EXE_DIR}/Tester)

if ("${GMOCK_DIR}" STREQUAL "")
	message(STATUS "No GMOCK_DIR variable set, trying to use system gmock")
	set(GMOCK_DIR "/usr/src")
	set(GMOCK_H_INCLUDE_DIR /usr/include/gmock)
	set(GMOCK_SUB_DIR /usr/src/gmock)
else ("${GMOCK_DIR}" STREQUAL "")
	set(GMOCK_SUB_DIR "../${GMOCK_DIR}")
	set(GMOCK_INCLUDE_DIR "${GMOCK_SUB_DIR}/include")
	set(GMOCK_H_INCLUDE_DIR "${GMOCK_DIR}/include/gmock")
	set(GTEST_INCLUDE_DIR "${GMOCK_SUB_DIR}/gtest/include")
	include_directories(${GMOCK_INCLUDE_DIR})
	include_directories(${GTEST_INCLUDE_DIR})
endif ("${GMOCK_DIR}" STREQUAL "")

set(GMOCK_INCLUDE "${GMOCK_H_INCLUDE_DIR}/gmock.h")
set(LIB_GMOCK gmock)


if (EXISTS "${GMOCK_INCLUDE}")
	message(STATUS "Using gmock from ${GMOCK_SUB_DIR}")
else (EXISTS "${GMOCK_INCLUDE}")
	message(FATAL_ERROR "Could not find googlemock in ${GMOCK_DIR}")
endif (EXISTS "${GMOCK_INCLUDE}")

set(GMOCK_INCLUDE_DIR "${GMOCK_DIR}/include/gmock")
set(GMOCK_INCLUDE "${GMOCK_INCLUDE_DIR}/gmock.h")

#projects parts
set(TESTS_POSTFIX Tests)
set(MOCKS_POSTFIX Mocks)

set(CONFIGURATION_TESTS_DIR Configuration${TESTS_POSTFIX})
set(CONFIGURATION_MOCKS_DIR Configuration${MOCKS_POSTFIX})

set(DATE_TIME_TESTS_DIR DateTime${TESTS_POSTFIX})
set(DATE_TIME_MOCKS_DIR DateTime${MOCKS_POSTFIX})

set(STREAM_TESTS_DIR Stream${TESTS_POSTFIX})
set(STREAM_MOCKS_DIR Stream${MOCKS_POSTFIX})
#project includes

#include_directories(${PROJECT_SOURCE_DIR}/${SRC_DIR}/GmockTest)
include_directories(${TEST_INC_DIR}/${CONFIGURATION_MOCKS_DIR}/)
include_directories(${TEST_INC_DIR}/${DATE_TIME_MOCKS_DIR}/)
include_directories(${TEST_INC_DIR}/${STREAM_MOCKS_DIR}/)

#externial libs

set(CMAKE_CXX_FLAGS_DEBUG "${NORMAL_WARNING_FLAGS}")

add_subdirectory(${GMOCK_SUB_DIR} gmock)

set(CMAKE_CXX_FLAGS_DEBUG "${EXTRA_WARNING_FLAGS}")

#test files
file(GLOB TEST_MAIN ${TEST_SRC_DIR}/*.cpp)
file(GLOB CONFIGURATION_TEST_FILES ${TEST_SRC_DIR}/${CONFIGURATION_TESTS_DIR}/*.cpp)
file(GLOB DATE_TIME_TEST_FILES ${TEST_SRC_DIR}/${DATE_TIME_TESTS_DIR}/*.cpp)
file(GLOB STREAM_TEST_FILES ${TEST_SRC_DIR}/${STREAM_TESTS_DIR}/*.cpp)

#tests
enable_testing()

file(MAKE_DIRECTORY ${TEST_EXE_DIR})

add_executable(${TEST_EXE} ${TEST_MAIN}
               ${CONFIGURATION_TEST_FILES} ${CONFIGURATION_LIB_FILES}
               ${DATE_TIME_TEST_FILES} ${DATE_TIME_LIB_FILES}
               ${STREAM_TEST_FILES} ${STREAM_LIB_FILES})
target_link_libraries(${TEST_EXE} ${LIB_GMOCK})
#TARGET_LINK_LIBRARIES(${TEST_EXE} ${Boost_LIBRARIES} )
add_test(gtests ${TEST_EXE}) 

set(COVERAGE_DIR coverage)
set(SOURCE_RAW_FILES_DIR "${CMAKE_BINARY_DIR}/Test/CMakeFiles/Tester.dir/__/Code")
set(THELPER_LIB_RAW_FILES_DIR "${CMAKE_BINARY_DIR}/Test/CMakeFiles/Tester.dir/__/Code/thelper/src")
set(THELPER_LIB_COVERAGE_RAW_FILES "${CMAKE_BINARY_DIR}/Test/CMakeFiles/Tester.dir/__/Code/thelper/src/*.gcda")
set(THELPER_LIB_O_FILES "${THELPER_LIB_COVERAGE_RAW_FILES_DIR}/*.o")

add_custom_target(coverage)
add_custom_command(TARGET coverage
	COMMAND mkdir -p ${COVERAGE_DIR}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(TARGET coverage
	COMMAND find ${CMAKE_BINARY_DIR} -name *.gcda -exec rm {} "\;" && ../${TEST_EXE}  && lcov -d  ${SOURCE_RAW_FILES_DIR} --capture --output-file thelper.info && genhtml thelper.info 
	WORKING_DIRECTORY ${COVERAGE_DIR})

add_dependencies(coverage ${TEST_EXE})

add_custom_target(coverage_view)
add_custom_command(TARGET coverage_view
	COMMAND x-www-browser index.html
	WORKING_DIRECTORY ${COVERAGE_DIR})

add_dependencies(coverage_view coverage)
