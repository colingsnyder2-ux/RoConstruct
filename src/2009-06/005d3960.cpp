// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_537544c1cf7d5477.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
struct Filter;
struct Selection{char prefix[0x94];std::vector<Filter*> items;void remove(Filter*);};
void Selection::remove(Filter* value){items.erase(std::find(items.begin(),items.end(),value));}

