// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_mergebinderreferences8856c89436d05c27.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct Receiver {virtual void apply(void*,void*)=0;};
struct Entry {Receiver* receiver;void* argument;unsigned value[2];};
struct Binder {unsigned reserved;std::vector<Entry> entries;bool flush();};
bool Binder::flush(){for(std::vector<Entry>::iterator i=entries.begin();i!=entries.end();++i){unsigned (&value)[2]=i->value;void*& argument=i->argument;Receiver*& receiver=i->receiver;receiver->apply(argument,&value);}entries.erase(entries.begin(),entries.end());return true;}
