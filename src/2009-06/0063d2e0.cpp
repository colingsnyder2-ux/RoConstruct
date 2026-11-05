// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x48 - 4];
    Instance* parent;
    Instance* getParent() const { return parent; }
    Instance* hasTool() const;
};
class PartInstance;
class Humanoid {
public:
    static Humanoid* modelIsCharacter(Instance*);
    PartInstance* getTorso();
};
class FlagStand {
public:
    virtual ~FlagStand();
    char pad[0xc0 - 4];
    int state;
    void onTouched(boost::shared_ptr<Instance> other);
    void giveTo(Instance*);
};
void FlagStand::onTouched(boost::shared_ptr<Instance> other) {
    if (state == 2) {
        Instance* parent = other->getParent();
        Humanoid* h = Humanoid::modelIsCharacter(parent);
        if (h && h->getTorso() && !parent->hasTool())
            giveTo(parent);
    }
}
}
