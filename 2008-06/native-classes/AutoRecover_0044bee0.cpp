// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// INFERRED: minimal local types; layout from the disassembly (vtable +4 dispose, +8 destroy, counts at +4/+8)
struct Control {
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void release();
};

struct Team {
    void setParent(void* parent);
};

struct SharedTeam {
    Team* pointer;
    Control* control;
    ~SharedTeam()
    {
        if (control)
            control->release();
    }
};

struct SharedSettings {
    void* pointer;
    Control* control;
    ~SharedSettings()
    {
        if (control)
            control->release();
    }
    void* get() const { return pointer; }
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct GuidRegistryMutex {
    void lock();
    void unlock();
};

struct GuardLock {
    GuidRegistryMutex* m;
    bool acquired;
    GuardLock(GuidRegistryMutex* p) : m(p)
    {
        m->lock();
        acquired = true;
    }
    ~GuardLock()
    {
        if (acquired)
            m->unlock();
    }
};

// callees
extern "C" SharedTeam __cdecl fn_0044bdc0();
extern "C" SharedSettings __cdecl fn_005690f0();

// INFERRED: globals at fixed addresses
extern GuidRegistryMutex g_00974aa0;
extern void* g_0096dd10;

extern "C" void* __cdecl fn_0044bee0()
{
    GuardLock guard(&g_00974aa0);
    if (g_0096dd10 == 0) {
        SharedTeam team = fn_0044bdc0();
        team.pointer->setParent(fn_005690f0().get());
    }
    return g_0096dd10;
}
