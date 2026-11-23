// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <set>
#include <boost/thread/mutex.hpp>

// INFERRED: slot-1 virtual receiving a double; key pointer sits at node+0xc.
struct FnListener {
    virtual void slot0() {}
    virtual void onTime(double t) {}
};

// INFERRED: owner class is unnamed; layout reconstructed from offsets 0x280 (mutex) and 0x288 (set).
struct FnOwner {
    char pad[0x280];
    boost::mutex mutex;                 // +0x280
    std::set<FnListener*> listeners;    // +0x288

    void notifyAll(double t);
};

void FnOwner::notifyAll(double t)
{
    boost::mutex::scoped_lock lock(mutex);
    for (std::set<FnListener*>::iterator it = listeners.begin(); it != listeners.end(); ++it)
        (*it)->onTime(t);
}

extern "C" void __fastcall fn_005550a0(FnOwner* self, int unusedEdx, double t)
{
    self->notifyAll(t);
}
