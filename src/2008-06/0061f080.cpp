// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_98e4d51f76676544.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
struct Entry;
std::map<unsigned int, Entry*>& getEntries();
Entry* lookup(int key)
{
	std::map<unsigned int, Entry*>::const_iterator iter = getEntries().find(key);
	if (iter != getEntries().end())
		return iter->second;
	return 0;
}
