// from server: 100% by EspClaude
// roc 2007-08 00421af0  unit: CSelectionTreeCtrl  size: 139 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Rewritten from target: scoped lock on owner(+0x30)->mutex(+0xb0) (lock 0x725750 / unlock 0x725770),
// this+0x38 insert(arg) returning a pair through a hidden pointer (0x421640), then
// owner->virtual slot 0x154 (this).
#include <utility>

struct Mutex {
    void do_lock();                 // 0x725750
    void do_unlock();               // 0x725770
};

struct ScopedLock {
    Mutex* m;
    bool locked;
    __forceinline ScopedLock(Mutex& mx) : m(&mx) { m->do_lock(); locked = true; }
    __forceinline ~ScopedLock() { if (locked) m->do_unlock(); }
};

class Instance;
class CSelectionTreeCtrl;

struct CheckedIter { void* cont; void* node; };   // VS2005 checked iterator (8 bytes)
struct InstanceSet {                // this+0x38
    std::pair<CheckedIter, bool> insert(Instance* v);   // 0x421640
};

#define V4(n) virtual void v##n##a(); virtual void v##n##b(); virtual void v##n##c(); virtual void v##n##d();
class Owner {
public:
    // padding to the proven vtable slot 0x154 (85 slots before it)
    V4(0) V4(1) V4(2) V4(3) V4(4) V4(5) V4(6) V4(7) V4(8) V4(9)
    V4(10) V4(11) V4(12) V4(13) V4(14) V4(15) V4(16) V4(17) V4(18) V4(19)
    V4(20)
    virtual void v84();
    virtual void onSelectionChanged(CSelectionTreeCtrl* ctrl);   // vtbl+0x154
    char pad4[0xb0 - 4];
    Mutex mutex;                    // +0xb0
};

class CSelectionTreeCtrl {
public:
    char pad0[0x30];
    Owner* owner;                   // +0x30
    char pad34[4];
    InstanceSet selection;          // +0x38
    void Add(Instance* inst);
};

void CSelectionTreeCtrl::Add(Instance* inst)
{
    {
        ScopedLock lock(owner->mutex);
        selection.insert(inst);
    }
    owner->onSelectionChanged(this);
}
