// from server: 100% by EspClaude
// from server: 100% by EspClaude
// from server: 97% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_f7c7b2ce8ef62f84.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <boost/shared_ptr.hpp>
struct Object {char padding[0x48];Object* parent;};
typedef boost::shared_ptr<Object> Shared;
struct Tree {Tree* insert(const Shared*);};
typedef std::map<Object*,Tree*> Map;
struct Lock {void acquire();void release();};
struct Guard {Lock* lock;bool locked;Guard(Lock* p):lock(p){lock->acquire();locked=true;}~Guard();};
extern Shared __cdecl makeShared(Object*);
struct CSelectionTreeCtrl {char padding[0x98];Map map;char tail[12];Lock lock;Tree* find(const Shared*);Tree* recurse(const Shared& p){return find(&p);}};
Tree* CSelectionTreeCtrl::find(const Shared* object){
 if(!*object)return 0;
 {Guard guard(&lock);
 Object* key=object->get();
 Map::iterator position=map.find(key);
 if(position!=map.end()){return position->second;}
 }
 Object* up=object->get()->parent;
 Tree* parent=recurse(makeShared(up));
 if(!parent)return 0;
 return parent->insert(object);
}

