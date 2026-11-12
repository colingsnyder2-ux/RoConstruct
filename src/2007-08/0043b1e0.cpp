// from server: 100% by EspClaude
// roc 2007-08 0043b1e0  unit: CSelectionPropGrid  size: 168 bytes
// roc-flags: /O2 /GS /EHsc /MD
// Rewritten from target: shared_ptr<Item> by value (px [esp+0x1c], pn [esp+0x20], ret 8),
// null-checked this-adjust to a second base at +0x17c, item->+0x8c.Add(listener),
// this+0x1c4.Set(item), then inline shared_count release (dispose vtbl+4, destroy vtbl+8).
#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
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
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
};

class ItemListener { public: char pad[4]; };

struct ListenerSet {                // item+0x8c
    void insert(ItemListener* l);   // 0x432530
};

class Item {
public:
    char pad0[0x8c];
    ListenerSet listeners;
};

struct ItemSlot {                   // this+0x1c4
    void set(Item* item);           // 0x43ab60
};

class GridBase { public: char pad[0x17c]; };

class CSelectionPropGrid : public GridBase, public ItemListener {
public:
    char pad180[0x1c4 - 0x180];
    ItemSlot slot;
    void SetItem(shared_ptr<Item> item);
};

void CSelectionPropGrid::SetItem(shared_ptr<Item> item)
{
    ItemListener* listener = this;
    if (item.get())
        item->listeners.insert(listener);
    slot.set(item.get());
}
