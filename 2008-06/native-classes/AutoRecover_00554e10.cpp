// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <algorithm>

// INFERRED: boost 1.3x xtime layout {sec, nsec}; nsec at +8 per disassembly.
struct xtime {
    long long sec;
    int nsec;
};

extern "C" int fn_005a6b40(xtime* xt, int type);                          // boost::xtime_get (cdecl)
extern "C" void __fastcall fn_00594ce0(void* mutex, int unusedEdx);       // mutex::do_lock
extern "C" void __fastcall fn_00594d00(void* mutex, int unusedEdx);       // mutex::do_unlock
extern "C" bool __fastcall fn_00554c30(void* cond, int unusedEdx, void* lock, xtime* xt); // condition::timed_wait

// INFERRED: scoped_lock<mutex> {mutex*, locked}; dtor produces the SEH unwind frame.
struct ScopedLock {
    void* m;
    bool locked;
    explicit ScopedLock(void* mm) : m(mm), locked(false) {
        fn_00594ce0(m, 0);
        locked = true;
    }
    ~ScopedLock() {
        if (locked)
            fn_00594d00(m, 0);
    }
};

extern "C" void __fastcall fn_00554e10(char* self, int unusedEdx, double seconds)
{
    // INFERRED: std::max(0.0, seconds) via reference to local 0.0 temp
    seconds = (std::max)(0.0, seconds);

    xtime xt;
    fn_005a6b40(&xt, 1);
    // INFERRED: 1e9 scale constant at 0x82d3f8 (seconds -> nanoseconds)
    xt.nsec += (int)(seconds * 1000000000.0);

    ScopedLock lock(self + 0x240);
    fn_00554c30(self + 0x264, 0, &lock, &xt);
}
