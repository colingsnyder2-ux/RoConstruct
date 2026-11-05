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
		bool ContainsProfanity(std::string);
	};

	class ProfanityFilter
	{
	private:
		WordList wordList;

	public:
		ProfanityFilter();
		~ProfanityFilter();
		bool ContainsProfanity(std::string);
	};
}
