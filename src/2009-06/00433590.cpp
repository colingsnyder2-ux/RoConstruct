// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_ac8e781d5a232937.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <map>
#include <boost/weak_ptr.hpp>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern long itemCount;
struct Item;
struct Counted {
    ~Counted() { InterlockedDecrement(&itemCount); }
};
struct ItemRef : Counted {
    boost::weak_ptr<Item> item;
};
typedef std::map<const void*, ItemRef> ItemMap;
ItemMap::iterator eraseItem(ItemMap& m, ItemMap::const_iterator it) { return m.erase(it); }
