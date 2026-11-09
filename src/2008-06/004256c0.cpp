// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_treeupdatearguments23c2a4766a673c9d.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <set>
#include <boost/shared_ptr.hpp>
struct Lock {void acquire();void release();};
struct Guard {Lock* lock;bool held;Guard(Lock*p):lock(p),held(false){lock->acquire();held=true;}~Guard(){if(held)lock->release();}};
struct Object{};
struct Selection {void erase(const boost::shared_ptr<Object>*);};
struct Index{void erase(Object*const*);};
struct Parent {virtual void unused();char padding[148];Index index;char gap[43];Lock lock;};
struct Node {char padding[12];std::map<Object*,void*> entries;std::set<void*> collection;char gap[4];Parent*parent;char gap2[4];Selection selection;void update(int unused,boost::shared_ptr<Object> value);};
typedef void (__thiscall*Notify)(Parent*,void*);
void Node::update(int unused,boost::shared_ptr<Object>value){ {Guard guard(&parent->lock);Object*key=value.get();parent->index.erase(&key);key=value.get();std::map<Object*,void*>::iterator position=entries.find(key);if(position!=entries.end())collection.insert(position->second);selection.erase(&value);}(*reinterpret_cast<Notify**>(parent))[87](parent,reinterpret_cast<char*>(this)-8);}
