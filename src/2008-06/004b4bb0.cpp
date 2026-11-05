// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_erasedkey_fb80804e46c2095b.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
struct Key { int header; std::string text; };
typedef boost::shared_ptr<void> Shared;
typedef std::map<const void*,Shared> Map;
struct Manager {
    void* current();
    void set(void*);
    void release(void*);
};

extern Manager* __cdecl getManager();

struct Guard {
    void* saved;
    Guard(int);
    __forceinline ~Guard();
};

__forceinline Guard::~Guard() {
    Manager* manager = getManager();
    void* previous = manager->current();
    if (previous != saved) {
        manager->set(saved);
        if (previous)
            manager->release(previous);
    }
}


Shared __cdecl createDefault(Key*);
Shared __cdecl getLogger();
void __cdecl logMessage(void*,int,const char*,...);
struct S { char padding[0x2cfc]; Map objects; void* f(Key*); };
void* S::f(Key* key) {
 Guard guard(6);
 Key* original=key;
 key=original;
 Map::iterator it=objects.find(key);
 void* result;
 if(it==objects.end()) {
  Shared value=createDefault(original);
  if(!value) logMessage(getLogger().get(),3,"Replication: Can't create default object of type %s",original->text.c_str());
  key=original;
  objects[key]=value;
  result=value.get();
 } else result=it->second.get();
 return result;
}
