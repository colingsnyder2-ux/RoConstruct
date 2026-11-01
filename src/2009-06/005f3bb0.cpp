// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost { namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::sp_counted_base* pi_;
    ~shared_ptr() { if (pi_) pi_->release(); }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
class PartInstance : public Instance { public: bool getAnchored() const; };
class Humanoid : public Instance {
public:
    char pad[0x1e1];
    bool sit;
    static Humanoid* humanoidFromBodyPart(Instance* part);
    PartInstance* getTorso();
    bool getDead() const;
};
class Workspace { public: static bool contextInWorkspace(const Instance* i); };
class Seat : public Instance {
public:
    bool isEnabled() const;
    Humanoid* getOccupant() const;
    void createSeatWeld(Humanoid* h);
    void onEvent_touched(boost::shared_ptr<Instance> other);
};
void Seat::onEvent_touched(boost::shared_ptr<Instance> other)
{
    if (Humanoid* humanoid = Humanoid::humanoidFromBodyPart(other.get())) {
        if (PartInstance* torso = humanoid->getTorso()) {
            if (isEnabled() && !getOccupant() && !humanoid->sit && !humanoid->getDead()
                && !torso->getAnchored()
                && Workspace::contextInWorkspace(torso) && Workspace::contextInWorkspace(this))
                createSeatWeld(humanoid);
        }
    }
}
}
