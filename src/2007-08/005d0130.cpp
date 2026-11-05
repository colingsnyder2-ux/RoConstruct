// from server: 95% by EspClaude
// roc 2007-08 005d0130  unit: RBX::LocalBackpackItem  size: 192 bytes
// LocalBackpack: remove the backpack item that refers to a tool. Offsets from the target:
// Instance children (CopyOnWrite shared_ptr<vector<shared_ptr<Instance>>>) @0xc0, item tool @0x100,
// backpack index @0x160, shared_ptr<Tool> @0x158. numChildren/setParent are out-of-line in 2007.
// roc-flags: /O2 /GS /EHsc /MD
#include <intrin.h>
#include <vector>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    void swap(shared_count& r) { sp_counted_base* tmp = r.pi_; r.pi_ = pi_; pi_ = tmp; }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    T* get() const { return px; }
    T& operator*() const { return *px; }
    void swap(shared_ptr& other) { T* tmp = other.px; other.px = px; px = tmp; pn.swap(other.pn); }
    void reset() { shared_ptr().swap(*this); }
};
}
namespace RBX {
class Instance {
public:
    char pad[0xc0];
    boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > > children;
    size_t numChildren() const;
    Instance* getChild(size_t i) { return (*children)[i].get(); }
    void setParent(Instance* newParent);
};
class Tool;
class LocalBackpackItem : public Instance {
public:
    char pad2[0x100 - 0xc8];
    Tool* tool;
};
class LocalBackpack : public Instance {
public:
    char pad2[0x158 - 0xc8];
    boost::shared_ptr<Tool> activeTool;
    int index;
    void removeTool(Tool* t);
};

void LocalBackpack::removeTool(Tool* t)
{
    for (size_t i = 0; i < numChildren(); i++)
    {
        LocalBackpackItem* item = static_cast<LocalBackpackItem*>(getChild(i));
        if (item->tool == t)
        {
            index = i;
            item->setParent(0);
            if (t == activeTool.get())
                activeTool.reset();
            return;
        }
    }
}
}
