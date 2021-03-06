include_directories(../third_party/Catch/include)

# make llvm happy
add_definitions("-D__STDC_LIMIT_MACROS")
add_definitions("-D__STDC_CONSTANT_MACROS")

set(TEST_SRCS
	main.cpp
	TestCommon.hpp
	ContextTests.cpp
	JSONSerializer.cpp
	LangModuleTests.cpp
	NameManglerTests.cpp
	GraphModuleTest.cpp
	GraphFunctionEntryTest.cpp
	GraphFunctionLocalsTest.cpp
	GraphFunctionExitTest.cpp
	GraphFunctionInOutsTest.cpp
)

add_executable(api_tests ${TEST_SRCS})
target_link_libraries(api_tests PUBLIC libchig)

add_test(NAME api_tests 
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND api_tests
)

add_subdirectory(error)
add_subdirectory(codegen)
