// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
template<class T> struct shared_ptr { T* px; shared_count pn; T* get() const { return px; } };
namespace RBX {
class Instance { public: virtual ~Instance(); };
class PartInstance : public Instance { };
void countParts(shared_ptr<Instance> p, int& n)
{
    if (dynamic_cast<PartInstance*>(p.get())) ++n;
}
}
