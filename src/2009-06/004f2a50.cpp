// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) { destroy(); } }
};
template<class T> class shared_ptr {
public:
    T* px;
    sp_counted_base* pn;
    ~shared_ptr() { if (pn != 0) pn->release(); }
};
class Item;
class Replicator {
public:
    virtual bool filter(shared_ptr<Item> item);
};
bool Replicator::filter(shared_ptr<Item> item) { return false; }
