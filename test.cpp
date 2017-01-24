//
// Created by Dawid Drozd aka Gelldur on 24/01/17.
//

#include <vector>
#include <string>

#include <gtest/gtest.h>

//I don't want header :P
std::vector<std::string> loadDicationary(const std::string& pathToDictionary);
std::string findLongest(std::string startWord, const std::vector<std::string>& dictionary);

TEST(AnagramDerivation, sample)
{
	EXPECT_EQ("aliens", findLongest("ail", {"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"}));
	//We don't find any better results than 'zil'
	EXPECT_EQ("zil", findLongest("zil", {"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"}));
}

TEST(AnagramDerivation, checkCaseSensitivity)
{
	EXPECT_EQ("aliens", findLongest("AIL", {"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"}));
	EXPECT_EQ("aliens", findLongest("AiL", {"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"}));
	EXPECT_EQ("aliens", findLongest("AIl", {"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"}));
	EXPECT_EQ("aliens", findLongest("aIl", {"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"}));
}

TEST(AnagramDerivation, sampleDictionary1)
{
	EXPECT_EQ("dictionary", findLongest("dit", loadDicationary("dictionaries/sample_dict")));
}
