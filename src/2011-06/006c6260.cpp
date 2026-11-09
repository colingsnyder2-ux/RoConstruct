// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_wordlist_plain_native_family_a48f6f07beb1c62f.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("util/ContentProvider.h", "../roc_wordlist_static_asset_header_179d09ed9a896b44.cpp")
#include <set>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "util/ContentProvider.h"
namespace RBX {
	class WordList
	{
	private:
		std::set<std::string> blacklist;
		void decrypt(std::string& str);
	public:
		WordList();
		~WordList();

		bool ContainsProfanity(std::string str);

	};


void WordList::decrypt(std::string& str)
{
	for(unsigned i = 0; i<str.size(); ++i){
		str[i] = 0x55 ^ str[i];
	}
}

WordList::WordList()
{
	/* Load blacklist

	
	*/

	std::string filename = ContentProvider::getAssetFile("Fonts\\diogenes.fnt");
	
	std::ifstream infile(filename.c_str());
	std::string line;
	while( std::getline(infile, line, '\n'))
	{
		boost::to_lower(line);
		boost::trim(line);
		blacklist.insert(line);
	}

	infile.close();
}
WordList::~WordList()
{

}
bool WordList::ContainsProfanity(std::string str)
{
	/*
	1. Convert query to lower case
	2. Check for in black list
	*/

	boost::to_lower(str);

	return blacklist.find(str) != blacklist.end();
}


}
