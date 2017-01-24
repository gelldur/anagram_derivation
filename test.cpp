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

TEST(AnagramDerivation, bug1)
{
	EXPECT_EQ("abbacef", findLongest("abb", {"abba"
			, "abbac", "abbace", "abbacef"
			, "abbad", "abbade"}));
}

TEST(AnagramDerivation, sampleDictionary1)
{
	EXPECT_EQ("dictionary", findLongest("dit", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("dic", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tardyon", findLongest("yon", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tar", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rod", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("DICTIONARY", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("indicator", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("actinoid", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("acridin", findLongest("acridin", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("aroint", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("cyanid", findLongest("Cindy", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("CIA", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("CIO", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("CRA", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("DNA", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("DOI", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Dan", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("IAC", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Ian", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Ida", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Inc", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("NCO", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("cyanid", findLongest("NYC", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Nat", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("OIC", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("RCA", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("RNA", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ROI", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("crayon", findLongest("RYO", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Ron", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("crayon", findLongest("Roy", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("TCO", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("TIA", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("Tao", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("act", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ado", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("aid", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ain", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("air", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ait", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("and", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ani", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ant", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tardyon", findLongest("any", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("arc", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("art", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("cad", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("can", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("car", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("cat", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("cyanid", findLongest("cay", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("cit", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("cod", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("con", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("cor", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("cot", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("crayon", findLongest("coy", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("cairny", findLongest("cry", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("cyanid", findLongest("day", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("din", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("dir", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("dit", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("doc", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("don", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("dor", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("dot", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("yaird", findLongest("dry", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dicty", findLongest("icy", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ion", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("nit", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("nod", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("nor", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("not", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("oar", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("oat", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("oca", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("oda", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ora", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("orc", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ort", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rad", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rai", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ran", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rat", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tardyon", findLongest("ray", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ria", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rid", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rin", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("roc", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rod", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("rot", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tardyon", findLongest("rya", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tad", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tan", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tao", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tar", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tic", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tin", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tod", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("ton", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("dictionary", findLongest("tor", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tardyon", findLongest("toy", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tracy", findLongest("try", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("tardyon", findLongest("yar", loadDicationary("dictionaries/sample_dict")));
	EXPECT_EQ("cyanid", findLongest("yid", loadDicationary("dictionaries/sample_dict")));
}

TEST(AnagramDerivation, performanceTest)
{
	EXPECT_EQ("breadwinners", findLongest("daw", loadDicationary("dictionaries/crawled")));

	//Crypto message!
	EXPECT_EQ("alphabetisers", findLongest("Please", loadDicationary("dictionaries/crawled")));
	EXPECT_EQ("seaworthinesses", findLongest("hire", loadDicationary("dictionaries/crawled")));
	EXPECT_EQ("indeterminations", findLongest("me", loadDicationary("dictionaries/crawled")));
	EXPECT_EQ("distelfinks", findLongest("iLike", loadDicationary("dictionaries/crawled")));
	EXPECT_EQ("cuppas", findLongest("cpp", loadDicationary("dictionaries/crawled")));
	EXPECT_EQ("permissibly", findLongest("smiley", loadDicationary("dictionaries/crawled")));
}
