// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_threadobject_e5195e4a281ef5d6.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
struct Object {char reserved[36];int references;char remaining[44];Object(unsigned long);};
typedef std::map<unsigned long,Object*> Tree;
struct Lock {int value;unsigned char flag;int count;void acquire();void release();};
extern Tree tree;
extern Lock lock;
struct Guard {Lock* lock;unsigned char active;Guard(Lock* p):lock(p){lock->acquire();active=1;}~Guard(){if(active)lock->release();}};
Object* getThreadObject(){
 Guard guard(&lock);
 unsigned long id=GetCurrentThreadId();
 Tree::iterator it=tree.find(id);
 if(it!=tree.end()){++it->second->references;return it->second;}
 Object* object=new Object(id);tree[id]=object;++object->references;return object;
}
