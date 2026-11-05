// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_treecallback_e1247439bb426892.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <vector>
#include <algorithm>
#include <boost/thread/recursive_mutex.hpp>
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*,unsigned,unsigned,long);
struct Item {char padding[128];long handle;};
struct Vector:std::vector<Item*> {void collect(Item* const&);};
typedef std::set<Item*> Tree;
typedef boost::recursive_mutex Lock;
struct Owner {char padding[32];void* window;char reserved[160];Lock mutex;};
typedef void (Vector::*Callback)(Item* const&);
struct Functor {Callback callback;Vector* object;Functor(Callback c,Vector* p):callback(c),object(p){}void operator()(Item* const& item)const{(object->*callback)(item);}};
struct S {char padding[52];Tree tree;char reserved[4];Owner* owner;void f();};
void S::f(){
 Vector values;
 {Lock::scoped_lock guard(owner->mutex);std::for_each(tree.begin(),tree.end(),Functor(&Vector::collect,&values));tree.clear();}
 for(Vector::iterator i=values.begin();i!=values.end();++i)SendMessageA(owner->window,0x1101,0,(*i)->handle);
}
