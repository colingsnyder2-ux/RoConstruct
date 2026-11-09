// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espeon_schedulerinitialactive8c5062d2646ae3f9.cpp

// Candidate translation unit (score above; library headers required).
#define NOMINMAX
#include <windows.h>
#include <algorithm>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/xtime.hpp>
namespace G3D { class System { public: static double getLocalTime(); }; }
extern long heartbeatCount;
struct S {
    char padding[0x104];
    int running;
    char padding2[0x1b8 - 0x108];
    double interval;
    double nextTime;
    long pending;
    char padding3[4];
    boost::mutex mutex;
    boost::condition condition;
    void run();
};
void S::run()
{
    int active = running;
    double wait = interval;
    while (active) {
        {
            boost::mutex::scoped_lock lock(mutex);
            if (wait > 0) {
                int ms = std::max(1, (int)(wait * 1010.0));
                boost::xtime xt;
                boost::xtime_get(&xt, boost::TIME_UTC);
                xt.sec += ms / 1000;
                xt.nsec += (ms % 1000) * 1000000;
                if (xt.nsec >= 1000000000) {
                    ++xt.sec;
                    xt.nsec -= 1000000000;
                }
                condition.timed_wait(lock, xt);
            } else {
                condition.wait(lock);
            }
        }
        {
            boost::mutex::scoped_lock lock(mutex);
            if (interval != 0) {
                wait = nextTime - G3D::System::getLocalTime();
                if (wait <= 0) {
                    wait = interval;
                    if (InterlockedExchange(&pending, 1) == 0)
                        InterlockedIncrement(&heartbeatCount);
                }
            } else {
                wait = -1.0;
            }
        }
        active = running;
    }
}
