// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};
template<class T> struct shared_ptr {
    T* px;
    sp_counted_base* pi;
    ~shared_ptr() { if (pi) pi->release(); }
    T* get() const { return px; }
};
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    bool isDescendantOf(const Instance* a) const;
    bool isDescendantOf2(shared_ptr<Instance> a) const;
};
bool Instance::isDescendantOf2(shared_ptr<Instance> a) const
{
    bool r;
    if (a.get() == parent)
        r = true;
    else if (parent)
        r = parent->isDescendantOf(a.get());
    else
        r = false;
    return r;
}
