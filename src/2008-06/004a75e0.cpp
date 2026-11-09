// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_registryendrefresh1c7cffee408cbccd.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
struct String {unsigned char storage[28];__declspec(dllimport) ~String();};
struct Entry{unsigned int unused,key;};
extern unsigned int __cdecl lookup(String*);
extern std::vector<Entry*>& __cdecl registry();
struct S:std::vector<Entry*>{void assign(String name,unsigned int index);};
void S::assign(String name,unsigned int index){unsigned key=lookup(&name);std::vector<Entry*>::iterator i=registry().begin();for(;i!=registry().end();++i){if((*i)->key==key){(*this)[index]=*i;return;}}(*this)[index]=0;}
