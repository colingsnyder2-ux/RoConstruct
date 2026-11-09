// from server: 100% by EspClaude
// from server: 92% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_f9f79afeaf76f4f4.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/thread/mutex.hpp>
#include <map>
#include <string>
typedef boost::mutex Lock;
typedef boost::mutex::scoped_lock Guard;
typedef std::map<std::string,void*> Map;
extern void __cdecl initialize(void (__cdecl*)(),void*);
extern void __cdecl initializeLock();
extern void __cdecl initializeDefault();
extern Lock* __cdecl getLock();
extern const Map* __cdecl getMap();
extern unsigned char lockStorage,defaultStorage;
extern void* defaultValue;
void* __cdecl lookup(const std::string& key) {
 initialize(initializeLock,&lockStorage);
 Guard guard(*getLock());
 Map::const_iterator it=getMap()->find(key);
 if(it!=getMap()->end()) return it->second;
 initialize(initializeDefault,&defaultStorage);
 return defaultValue;
}
