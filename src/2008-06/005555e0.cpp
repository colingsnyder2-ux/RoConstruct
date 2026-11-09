// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_schedulercancel_b7c5cdc081454407.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <boost/thread/mutex.hpp>
struct Event { void signal(); };
struct S {char padding0[0x24c];Event event;char padding1[0x33];boost::mutex mutex;std::map<void*,bool> tree;unsigned int count;void f(void*);};
void S::f(void* key) {
 boost::mutex::scoped_lock lock(mutex);
 if(count==0)return;
 std::map<void*,bool>::iterator it=tree.find(key);
 if(it!=tree.end() && !it->second) {--count;it->second=true;}
 if(count==0)event.signal();
}
