// from server: 100% by EspClaude
// from server: 94% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_12ef573da8216002.cpp

// Candidate translation unit (score above; library headers required).
#include <windows.h>
#include <vector>
#include <algorithm>
struct Lock { CRITICAL_SECTION* cs; bool locked; Lock(CRITICAL_SECTION* c) : cs(c), locked(true) { EnterCriticalSection(cs); } ~Lock() { LeaveCriticalSection(cs); } };
struct S {unsigned reserved;std::vector<void*> values;unsigned padding;char* owner;void remove(void*);};
void S::remove(void* value){Lock lock(reinterpret_cast<CRITICAL_SECTION*>(owner+0x2c));for(std::vector<void*>::iterator it=values.begin();it!=values.end();it++){if(*it==value){values.erase(it);break;}}}
