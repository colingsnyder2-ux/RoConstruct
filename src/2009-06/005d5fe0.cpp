// from server: 92% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct spin_mutex { volatile long lock; unsigned long owner; };
class scoped_lock {
    bool recursive;
    spin_mutex* m;
public:
    scoped_lock(spin_mutex& mm);
    ~scoped_lock();
};
template<class A> class Func1 {
public:
    void operator()(A a) const;
    operator bool() const { return true; }
};
struct Arg;
struct Item {
    int a;
    bool b;
    bool enabled;
    spin_mutex mutex;
    int pad[2];
    Func1<Arg*> func;
    bool isEnabled() const { return enabled; }
};
void invoke(Item* item, Arg* arg)
{
    scoped_lock lock(item->mutex);
    bool e = item->enabled;
    if (e)
        item->func(arg);
}
}
