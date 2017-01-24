//
// Created by Dawid Drozd aka Gelldur on 24/01/17.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include <algorithm>

//Yeah it is global :) but this is simple task :P
std::vector<char> ALPHABET = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'
		, 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

std::string normalize(std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	return word;
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
		//TODO check for invalid format
		dictionary.emplace_back(normalize(line));
	}
	return std::move(dictionary);
}

struct AnagramDerivation
{
	std::string left;
	std::string right;
};

std::vector<AnagramDerivation> findAnagram(
		const std::string& word
		, const std::map<std::string, std::string>& keyMap
		, const std::vector<AnagramDerivation>& anagramDerivationTrack = {})
{
	AnagramDerivation anagramDerivation;
	anagramDerivation.left = word;

	auto track = anagramDerivationTrack;//We need it for recursive search
	track.push_back(anagramDerivation);

	std::vector<AnagramDerivation> longestAnagramDerivation = track;

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

		track.back().right = letter;
		//Recursive search deeper we don't have words like 1kk of length :) Also it is simple and fast
		auto foundTrack = findAnagram(found->second, keyMap, track);
		if (foundTrack.size() > longestAnagramDerivation.size())
		{
			longestAnagramDerivation = foundTrack;
		}
	}

	return longestAnagramDerivation;
}

/**
 * @param startWord word from which we want to start
 * @param dictionary should contain normalized words
 * @return longest available word which we can create form startWord using our dictionary
 */
std::string findLongest(std::string startWord, const std::vector<std::string>& dictionary)
{
	assert(ALPHABET.size() == 26);//Double check :D maybe i skipped something :)

	startWord = normalize(startWord);//normalize our start word!

	//Prepare our map!
	std::map<std::string, std::string> keyMap;
	for (const auto& word: dictionary)
	{
		std::string key = word;//copy of word
		std::sort(key.begin(), key.end());
		keyMap[key] = word;
	}

	std::cout << std::endl;

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
	return longest.back().left;
}
