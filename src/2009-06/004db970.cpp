// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class SpinLock {
public:
    volatile long v;
    class scoped_lock {
        SpinLock* m;
    public:
        scoped_lock(SpinLock& m);
        ~scoped_lock();
    };
};
struct Guid { int a, b; };
class Instance;
template<class K, class V> class Map {
public:
    unsigned int erase(const K& k);
    V& operator[](const K& k);
};
struct Data {
    char pad[0x1d0];
    SpinLock lock;
    Map<Guid, Instance*> map;
};
class Registry {
    int pad[3];
    Data* data;
public:
    void remove(Guid g);
    Instance* get(Guid g);
};
Instance* Registry::get(Guid g)
{
    SpinLock& lk = data->lock;
    SpinLock::scoped_lock lock(lk);
    Data* d = data;
    return d->map[g];
}
}
