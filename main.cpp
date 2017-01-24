#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>

std::vector<char> ALPHABET = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'
		, 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

std::string normalize(std::string word)
{
	//TODO implement
}

std::vector<std::string> loadDicationary(const std::string& pathToDictionary)
{
	std::ifstream externalDictionary(pathToDictionary);
	if (externalDictionary.is_open() == false)
	{
		throw std::runtime_error("Can't open external dictionary! ABORT MISSION!");
	}

	std::vector<std::string> dictionary;
	std::string line;
	while (std::getline(externalDictionary, line))
	{
		//TODO check for invalid format && normalize word
		dictionary.push_back(std::move(line));
	}
	return dictionary;
}

struct AnagramDerivation
{
	std::string left;
	std::string right;
};

std::string getKey(std::string word)
{
	std::sort(word.begin(), word.end());
	return word;
}

std::vector<AnagramDerivation> findAnagram(
		const std::string& word
		, const std::map<std::string, std::string>& keyMap
		, const std::vector<AnagramDerivation>& anagramDerivationTrack = {})
{
	//TODO make random shuffle on ALPHABET to be like sherewood :D
	std::vector<AnagramDerivation> longestAnagramDerivationTrack{anagramDerivationTrack};

	AnagramDerivation anagramDerivation;
	anagramDerivation.left = word;

	longestAnagramDerivationTrack.push_back(anagramDerivation);

	for (const auto& letter : ALPHABET)
	{
		std::string sortedWordKey = word;//make a copy for sort
		sortedWordKey.push_back(letter);
		std::sort(sortedWordKey.begin(), sortedWordKey.end());//sort such new word key

		auto found = keyMap.find(sortedWordKey);
		if (found == keyMap.end())
		{
			continue;//Sorry we can't find indirect point so we skipp this letter
		}

		longestAnagramDerivationTrack.back().right = letter;
		auto longerAnagramDerivationTrack = findAnagram(found->second, keyMap, longestAnagramDerivationTrack);
		if (longerAnagramDerivationTrack.size() > longestAnagramDerivationTrack.size())
		{
			longestAnagramDerivationTrack = longerAnagramDerivationTrack;
		}
	}

	return longestAnagramDerivationTrack;
}

int main(int argc, const char* argv[])
{
	assert(ALPHABET.size() == 26);//Double check :D maybe i skiped something :)
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

	std::vector<std::string> dictionary{"ail", "tennis", "nails", "desk", "aliens", "table", "engine", "sail"};
	if (argc >= 3)
	{
		dictionary = loadDicationary(argv[2]);
	}

	//Prepare our map!
	std::map<std::string, std::string> keyMap;
	for (const auto& word: dictionary)
	{
		std::string key = word;//copy of word
		std::sort(key.begin(), key.end());
		keyMap[key] = word;
	}

	auto longest = findAnagram(startWord, keyMap);
	for (const auto& element : longest)
	{
		if (element.right.empty())
		{
			std::cout << element.left;
		}
		else
		{
			std::cout << element.left << " + " << element.right << " = ";
		}
	}

	std::cout << std::endl;
	return 0;
}
