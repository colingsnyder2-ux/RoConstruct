// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    void reset();
};
template<class T, class U> inline bool operator==(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() == b.get(); }
template<class T, class U> inline bool operator!=(const shared_ptr<T>& a, const shared_ptr<U>& b) { return a.get() != b.get(); }

class Item;
class Owner {
public:
    shared_ptr<Item> getItem();
};

class Listener {
public:
    virtual void onChanged(shared_ptr<Item> current, shared_ptr<Item> previous) = 0;
};

extern Owner* g_owner;
extern std::set<Listener*> g_listeners;
extern shared_ptr<Item> g_current;

void __cdecl setCurrent(bool on, Owner* owner)
{
    shared_ptr<Item> previous(g_current);
    if (on)
    {
        g_owner = owner;
        g_current = owner->getItem();
    }
    else
    {
        if (owner == g_owner)
            g_owner = 0;
        if (owner->getItem() == g_current)
            g_current.reset();
    }
    if (g_current != previous)
    {
        for (std::set<Listener*>::iterator it = g_listeners.begin(); it != g_listeners.end(); ++it)
            (*it)->onChanged(g_current, previous);
    }
}
