#pragma once
#include <set>
#include <string>

namespace RBX
{
	class WordList
	{
	private:
		std::set<std::string> blacklist;

	public:
		WordList();
		~WordList();
		bool ContainsProfanity(std::string text);
	};

	class ProfanityFilter
	{
	private:
		WordList wordList;

	public:
		ProfanityFilter();
		~ProfanityFilter();
		bool ContainsProfanity(std::string text);
	};
}
// 2008-06 native header port of rbxgs App/include/gui/ProfanityFilter.h (2007 text). Kept only because every dependent exact native unit
// compiles to an identical object with it in native-headers (proof: work/donorfree-route/header_port_proof.json).
