// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_historymergefirst5aaee9aec6a4f9f1.cpp

// Candidate translation unit (score above; library headers required).
#include <list>
struct Record{void merge(Record*);~Record();};
struct History{char prefix[0x138];std::list<Record*> records;std::list<Record*>::iterator forward,backward;void mergeFirst();};
void History::mergeFirst(){std::list<Record*>::iterator current=records.begin();++current;(*records.begin())->merge(*current);if(backward==current)--backward;if(forward==current)++forward;delete *current;records.erase(current);}
