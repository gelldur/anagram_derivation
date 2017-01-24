CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
PROJECT(anagram_derivation)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(anagram_derivation main.cpp algorithm.cpp)

TARGET_COMPILE_OPTIONS(anagram_derivation PRIVATE
		-Wall -pedantic -Werror
		-Wno-unused-private-field -Wnon-virtual-dtor)
