#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>

//I don't want header :P
std::vector<std::string> loadDicationary(const std::string& pathToDictionary);
std::string findLongest(std::string startWord, const std::vector<std::string>& dictionary);

int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please pass 3 letter work in first argument. Like: ./a.out ail" << std::endl;
		return 1;
	}
	const std::string startWord{argv[1]};
	if (startWord.size() < 3)
	{
		//If you want you can remove it
		std::cout << "Sorry! In task i have assumption that word will be 3 letters long ;) ABORT MISSION!" << std::endl;
		return 1;
	}

	//Default one
	std::vector<std::string> dictionary{"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"};
	if (argc >= 3)
	{
		dictionary = loadDicationary(argv[2]);
	}

	findLongest(startWord, dictionary);
	return 0;
}
