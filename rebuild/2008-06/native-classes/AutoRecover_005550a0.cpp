// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <set>

// Boost mutex lock helpers (private members called directly in the original).
extern "C" void __fastcall fn_00594ce0(void* mtx, int unusedEdx); // boost::mutex::do_lock
extern "C" void __fastcall fn_00594d00(void* mtx, int unusedEdx); // boost::mutex::do_unlock

// INFERRED: listener objects with a vtable; slot 1 takes a double.
struct StepListener
{
    virtual void slot0();
    virtual void step(double t);
};

// INFERRED: layout of the owning object; only the touched members are modelled.
struct StepOwner
{
    char pad0[0x280];
    char mutex[8];                       // boost::mutex at +0x280
    std::set<StepListener*> listeners;   // container at +0x288
};

namespace {
struct ScopedLock
{
    void* m;
    explicit ScopedLock(void* mtx) : m(mtx) { fn_00594ce0(m, 0); }
    ~ScopedLock() { fn_00594d00(m, 0); }
};
}

extern "C" void __fastcall fn_005550a0(StepOwner* self, int unusedEdx, double t)
{
    ScopedLock lock(self->mutex);
    for (std::set<StepListener*>::const_iterator it = self->listeners.begin();
         it != self->listeners.end(); ++it)
    {
        (*it)->step(t);
    }
}
