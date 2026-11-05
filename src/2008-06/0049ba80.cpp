// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_guidconst_dfc950d9e2ef96aa.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <boost/thread/mutex.hpp>
struct Name;
struct Guid {const Name* scope;unsigned int index;bool operator<(const Guid&) const;};
struct Map {std::map<Guid,unsigned int> tree;boost::mutex mutex;};
extern const Name& __cdecl getLocalScope();
extern void __cdecl initializeMap();
extern void __cdecl initializeOnce(void (__cdecl*)(),int*);
extern Map* globalMap;
extern int initializationFlag;
bool __cdecl lookup(const Guid& key,unsigned int* result) {
 const Name* scope=key.scope;
 if(&getLocalScope()==scope) {*result=0;return true;}
 initializeOnce(initializeMap,&initializationFlag);
 Map* map=globalMap;
 boost::mutex::scoped_lock guard(map->mutex);
 std::map<Guid,unsigned int>::const_iterator it=map->tree.find(key);
 if(it!=map->tree.end()) {*result=it->second;return true;}
 *result=0;return false;
}
