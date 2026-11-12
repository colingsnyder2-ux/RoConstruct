// from server: 100% by EspClaude
// roc 2007-08 00421b80  unit: CSelectionTreeCtrl  size: 207 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Rewritten from target: scoped lock on this+0xb0 (0x725750/0x725770); std::map at +0x98
// find(key) (0x44f4c0, hidden-ptr iterator), VS2005 checked iterator compare against end()
// and deref (_invalid_parameter_noinfo), then std::set at +0xd8 insert(it->second) (0x4a9660).
#include <map>
#include <set>

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
class Item;

class SelectionOwner {
public:
    char pad0[0x98];
    std::map<Instance*, Item*> items;      // +0x98
    char pada4[0xb0 - 0x98 - sizeof(std::map<Instance*, Item*>)];
    Mutex mutex;                            // +0xb0
    char padb4[0xd8 - 0xb4];
    std::set<Item*> selected;               // +0xd8
    void Select(Instance* inst);
};

void SelectionOwner::Select(Instance* inst)
{
    ScopedLock lock(mutex);
    std::map<Instance*, Item*>::iterator it = items.find(inst);
    if (it != items.end())
        selected.insert(it->second);
}
