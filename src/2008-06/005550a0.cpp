// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_scheduleritems_bcf3aa9663e96bbd.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <boost/thread/mutex.hpp>
struct Item {virtual void reserved();virtual void update(double);};
struct S {char padding[0x280];boost::mutex mutex;std::set<Item*> items;void f(double);};
void S::f(double value) {
 boost::mutex::scoped_lock guard(mutex);
 for(std::set<Item*>::iterator it=items.begin();it!=items.end();++it) (*it)->update(value);
}
