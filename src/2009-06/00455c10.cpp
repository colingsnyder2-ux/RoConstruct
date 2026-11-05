// from server: 100% by EspClaude
// roc 2009-06 00455c10
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class SpinLock {
public:
    long v;
    class scoped_lock {
    public:
        scoped_lock(SpinLock& m);
        ~scoped_lock();
    private:
        long* p;
    };
};
struct Item { void* px; void* pn; bool flag; };
class ItemDeque {
public:
    void push_back(const Item& v);
private:
    char data[0x20];
};
class SafeQueue {
public:
    void push(const Item& v);
private:
    ItemDeque queue;
    SpinLock lock;
};
void SafeQueue::push(const Item& v)
{
    SpinLock::scoped_lock l(lock);
    queue.push_back(v);
}
}
