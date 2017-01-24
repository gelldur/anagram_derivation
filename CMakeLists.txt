CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(anagram_derivation)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(anagram_derivation main.cpp algorithm.cpp)

TARGET_COMPILE_OPTIONS(anagram_derivation PRIVATE
		-Wall -pedantic -Werror
		-Wno-unused-private-field -Wnon-virtual-dtor)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(anagram_derivation-test test.cpp algorithm.cpp)
TARGET_LINK_LIBRARIES(anagram_derivation-test
		gtest gtest_main
		gmock
		)

TARGET_INCLUDE_DIRECTORIES(anagram_derivation-test PRIVATE
		./
		googletest/googletest/include
		)

TARGET_COMPILE_OPTIONS(anagram_derivation-test PRIVATE
		-Wall -pedantic -Werror
		-Wno-unused-private-field -Wnon-virtual-dtor)

CONFIGURE_FILE(dictionaries/sample_dict dictionaries/sample_dict COPYONLY)
