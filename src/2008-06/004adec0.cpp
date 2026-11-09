// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_f07ad658386bfc8c.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <string>
struct Stream{int x;};
struct Key;
extern Stream& __cdecl operator<<(Stream&,unsigned int);extern Stream& __cdecl operator<<(Stream&,const std::string&);
struct S{std::map<const Key*,unsigned int> values;std::string get(const Key*);void f(Stream&);};
void S::f(Stream&output){output<<(unsigned int)values.size();for(std::map<const Key*,unsigned int>::iterator it=values.begin();it!=values.end();++it){unsigned int v=(*it).second;output<<v;std::string text=get((*it).first);output<<text;}}
