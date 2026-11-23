// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/xtime.hpp>

// INFERRED: the owning class is unknown, so the object is taken as a raw pointer.
// Layout from the disassembly: boost::mutex at +0x240, boost::condition at +0x264.
// INFERRED: the function is a thiscall taking a double timeout, with void return.
extern "C" void __fastcall fn_00554e10(char* self, int unusedEdx, double seconds)
{
    // clamp the timeout to >= 0
    double zero = 0.0;
    const double& t = (zero > seconds) ? zero : seconds;
    seconds = t;

    boost::xtime xt;
    boost::xtime_get(&xt, 1);
    // INFERRED: the scale is 1e9 (nanoseconds); it is added to the nsec field only, as in the disassembly.
    xt.nsec += (int)(seconds * 1000000000.0);

    boost::mutex::scoped_lock lock(*(boost::mutex*)(self + 0x240));
    ((boost::condition*)(self + 0x264))->timed_wait(lock, xt);
}
