// from server: 100% by Intel_Inside


#include <string>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};

template <class T> struct shared_ptr {
    T* px;
    sp_counted_base* pi_;
    template <class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pi_(r.pi_) {
        if (pi_ != 0) pi_->add_ref_copy();
    }
    ~shared_ptr() { if (pi_ != 0) pi_->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};

class Item {
public:
    virtual ~Item();
    virtual void unused1();
    virtual void setName(const std::string& name);   // vtable slot 2 (+8)
    void setParent(Item* parent);                    // 0x541630, thiscall
};

class ChildItem : public Item {
};

shared_ptr<ChildItem> __cdecl createItem(void* arg);  // 0x45af20, cdecl, hidden return slot

class TypedStatsItem : public Item {
public:
    Item* createChildItem(const char* name, void* arg);
};

Item* TypedStatsItem::createChildItem(const char* name, void* arg)
{
    shared_ptr<Item> item = createItem(arg);
    item->setName(name);
    item->setParent(this);
    return item.get();
}
