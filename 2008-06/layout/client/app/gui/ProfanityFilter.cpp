#include "../../../../../../tools/rbxgs/Client/App/include/gui/ProfanityFilter.h"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <vector>

namespace RBX
{
	namespace LDraw2Lua
	{
		std::string resolveMapPath(const char*);
	}

	bool WordList::ContainsProfanity(std::string word)
	{
		boost::algorithm::to_lower(word);
		return blacklist.find(word) != blacklist.end();
	}

	WordList::~WordList()
	{
	}

	WordList::WordList()
	{
		std::string fileName = LDraw2Lua::resolveMapPath("Fonts\\diogenes.fnt");
		std::ifstream file(fileName.c_str());
		std::string line;

		while (std::getline(file, line, '\n'))
		{
			boost::algorithm::to_lower(line);
			boost::algorithm::trim(line);
			blacklist.insert(line);
		}

		file.close();
	}

	ProfanityFilter::ProfanityFilter()
	{
	}

	ProfanityFilter::~ProfanityFilter()
	{
	}

	bool ProfanityFilter::ContainsProfanity(std::string text)
	{
		boost::algorithm::to_lower(text);

		std::vector<std::string> words;
		boost::algorithm::split(words, text, boost::algorithm::is_any_of(" !.?,:;><[]{}|\\/@#$%^&*()_-+=\""));

		for (unsigned int i = 0; i < words.size(); i++)
		{
			if (wordList.ContainsProfanity(words[i]))
				return true;
		}

		return false;
	}
}
