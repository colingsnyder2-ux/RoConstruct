// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_60ae095e81079741.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <map>
#include <string>
struct Key { std::string text; };
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
    ~Guard();
};




Shared __cdecl createDefault(Key*);
Shared __cdecl getLogger();
void __cdecl logMessage(void*,int,const char*,...);
struct S { char padding[0x2c78]; Map objects; void* f(Key*); };
void* S::f(Key* key) {
 Guard guard(6);
 Key* original=key;
 key=original;
 Map::iterator it=objects.find(key);
 if(it==objects.end()) {
  Shared value=createDefault(original);
  if(!value) logMessage(getLogger().get(),3,"Replication: Can't create default object of type %s",original->text.c_str());
  key=original;
  objects[key]=value;
  return value.get();
 }
 return it->second.get();
}

