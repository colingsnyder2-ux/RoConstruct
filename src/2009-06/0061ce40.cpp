// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_7b178a3a2a812112.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
struct Record{void merge(Record*);~Record();};
struct History{char prefix[0x94];std::list<Record*> records;std::list<Record*>::iterator forward,backward;void mergeFirst();};
void History::mergeFirst(){std::list<Record*>::iterator current=records.begin();++current;(*records.begin())->merge(*current);if(backward==current)--backward;if(forward==current)++forward;delete *current;records.erase(current);}

