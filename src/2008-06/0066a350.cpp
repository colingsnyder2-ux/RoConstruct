// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_tree_stage_words_off_2641e86a8c2442a8.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
namespace RBX {
class TreeStage { public: bool contains(std::string value); bool containsAny(std::string value); };
bool TreeStage::containsAny(std::string value)
{
    boost::to_lower(value);
    std::vector<std::string> words;
    boost::split(words, value, boost::is_any_of(" !.?,:;><[]{}|\\/@#$%^&*()_-+=\""), boost::token_compress_off);
    for (unsigned i = 0; i < words.size(); ++i)
        if (contains(words[i]))
            return true;
    return false;
}
}
