// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_70397b46f3ca20ff.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct Lock {
    void* cs;
    bool locked;
    Lock(void* c) : cs(c), locked(true) { EnterCriticalSection(cs); }
    ~Lock() { if (locked) LeaveCriticalSection(cs); }
};
struct Item {char padding[12];void* listener;};
struct Owner {char padding[44];char criticalSection[24];};
struct EventData {unsigned base;std::vector<Item*> items;unsigned reserved;Owner* owner;void detach();};
void EventData::detach(){Lock lock(owner->criticalSection);for(std::vector<Item*>::iterator i=items.begin();i!=items.end();++i)(*i)->listener=0;items.erase(items.begin(),items.end());}
