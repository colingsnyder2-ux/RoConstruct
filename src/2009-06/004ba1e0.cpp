// from server: 100% by EspClaude
// roc 2009-06 004ba1e0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class RecursiveSpinLock {
public:
    long v; long owner;
    class scoped_lock {
    public:
        scoped_lock(RecursiveSpinLock& m);
        ~scoped_lock();
    private:
        bool reentered;
        RecursiveSpinLock* m;
    };
};
class Callback {
public:
    void operator()(double t) const;
private:
    char data[0x20];
};
struct Pulse {
    int a;
    bool b;
    volatile bool enabled;
    RecursiveSpinLock lock;
    char pad[8];
    Callback callback;
    static void fire(Pulse* p, double t);
};
void Pulse::fire(Pulse* p, double t)
{
    RecursiveSpinLock::scoped_lock l(p->lock);
    if (p->enabled)
        p->callback(t);
}
}
