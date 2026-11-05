// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_selectionfilternatived97df675db8e6419.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <algorithm>
struct Filter;
struct Selection{char prefix[0x15c];std::vector<Filter*> items;void remove(Filter*);};
void Selection::remove(Filter* value){items.erase(std::find(items.begin(),items.end(),value));}
