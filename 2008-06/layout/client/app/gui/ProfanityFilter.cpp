// =============================================================================
// ProfanityFilter.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/gui/ProfanityFilter.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
