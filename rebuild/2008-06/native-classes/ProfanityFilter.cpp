// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::WordList / RBX::ProfanityFilter (gui/ProfanityFilter.cpp, inactive), unit 00669fa0..0066a56e in
// source order: WordList::ContainsProfanity 00669fa0, ~WordList/~ProfanityFilter 0066a060 (folded), WordList()
// 0066a070, ProfanityFilter() 0066a340, ProfanityFilter::ContainsProfanity 0066a350 (called by ChatOutput::onEvent
// 00650cc0 on filter +0x154). Declarations: rbxgs gui/ProfanityFilter.h (std::set<std::string> blacklist, 0x20 bytes
// in VC9: ChatOutput filter +0x154 .. fifo +0x174). Statement shapes: openrbx Client/App/gui/ProfanityFilter.cpp.
#include "../../../tools/rbxgs/Client/App/include/gui/ProfanityFilter.h"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <vector>

namespace RBX
{
	namespace LDraw2Lua
	{
		// 0055d0b0 (registry name; asset folder + path, the helper LDrawParser.cpp / FontsGetFont.cpp declare). The
		// openrbx analog calls ContentProvider::singleton().getAssetFile here; 2008 calls this helper (0066a0c1).
		std::string resolveMapPath(const char*);
	}

	// 00669fa0: to_lower with std::locale() (0064fd00), blacklist.find (004a2fa0, folded _Tree::find) != end().
	bool WordList::ContainsProfanity(std::string word)
	{
		boost::algorithm::to_lower(word);
		return blacklist.find(word) != blacklist.end();
	}

	// 0066a060 (folded with ~ProfanityFilter)
	WordList::~WordList()
	{
	}

	// 0066a070: path "Fonts\\diogenes.fnt" (0084cfd0) through 0055d0b0, ifstream(path.c_str()), getline(file, line,
	// '\n') loop, to_lower, trim (is_space 00657c10), blacklist.insert (004a2eb0), file.close().
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

	// 0066a340
	ProfanityFilter::ProfanityFilter()
	{
	}

	// 0066a060
	ProfanityFilter::~ProfanityFilter()
	{
	}

	// 0066a350: to_lower, split into std::vector<std::string> on is_any_of(0084cfe4) (0048e620 / 004952f0), then
	// wordList.ContainsProfanity (00669fa0) of each word by index.
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
