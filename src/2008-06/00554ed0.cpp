// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espeon_timedwaitelapsednative37e1713acab32795.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/xtime.hpp>
extern double clockNow();
struct S { char pad0[0x1d0]; double elapsed; char pad1[0x240-0x1d8]; boost::mutex mutex; char pad2[0x24c-0x240-sizeof(boost::mutex)]; boost::condition condition; char pad3[0x2a8-0x24c-sizeof(boost::condition)]; int enabled; bool f(); };
bool S::f() {
 double start=clockNow();
 boost::xtime deadline;
 boost::xtime_get(&deadline,boost::TIME_UTC);
 ++deadline.sec;
 boost::mutex::scoped_lock guard(mutex);
 bool result=!enabled || condition.timed_wait(guard,deadline);
 elapsed=clockNow()-start;
 return result;
}
