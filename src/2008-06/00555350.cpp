// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_runviewsnative78091a74e96c019d.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
struct Task { virtual void invoke()=0; };
struct S { char padding[0x24c]; boost::condition event; char padding1[0x280-0x24c-sizeof(boost::condition)]; boost::mutex mutex; std::map<Task*,bool> tasks; int active; void f(); };
void S::f() {
 boost::mutex::scoped_lock guard(mutex);
 if(active!=0) return;
 active=tasks.size();
 if(active>0) {
  for(std::map<Task*,bool>::iterator it=tasks.begin();it!=tasks.end();++it) {
   it->first->invoke(); it->second=false;
  }
  event.notify_all();
 }
}
