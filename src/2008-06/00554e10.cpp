// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espeon_timedwaitnativeee29dead92bb0dc0.cpp

// Candidate translation unit (score above; library headers required).
#include <algorithm>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/xtime.hpp>
struct S { char padding[0x240]; boost::mutex mutex; char padding2[0x264-0x240-sizeof(boost::mutex)]; boost::condition condition; void f(double); };
void S::f(double duration) {
 duration=std::max(duration,0.0);
 boost::xtime deadline;
 boost::xtime_get(&deadline,boost::TIME_UTC);
 deadline.nsec+=(int)(duration*1000000000.0);
 boost::mutex::scoped_lock lock(mutex);
 condition.timed_wait(lock,deadline);
}
