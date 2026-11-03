// from server: 75% by EspClaude
// roc 2007-08 005a0210  SpawnLocation::onEvent_spawnerTouched(shared_ptr<Instance>) (body absent from rbxgs .cpp; rebuilt from asm)
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
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
    sp_counted_base* pi_;
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    T* operator->() const { return px; }
    T* get() const { return px; }
};
}
namespace RBX {
class Humanoid;
class Instance {
public:
    virtual ~Instance();
    char pad[0xb8];
    Instance* parent;   // exe +0xbc
    Instance* getParent() const { return parent; }
    template<class T> T* findFirstChildOfType() const;
};
class BrickColor { public: int number; };
namespace Network {
class Player {
public:
    void setTeamColor(BrickColor color);
    void setNeutral(bool value);
};
class Players {
public:
    static Player* getPlayerFromCharacter(Instance* character);
};
}
class SpawnLocation {
    char pad[0x280];
    BrickColor teamColor;   // exe +0x280
    char connection[0x14];
public:
    bool neutral;                 // +0x298
    bool allowTeamChangeOnTouch;  // +0x299
private:
    void onEvent_spawnerTouched(boost::shared_ptr<Instance> other);
};
void SpawnLocation::onEvent_spawnerTouched(boost::shared_ptr<Instance> other)
{
    if (!allowTeamChangeOnTouch)
        return;
    Instance* parent = other->getParent();
    if (parent && parent->findFirstChildOfType<Humanoid>()) {
        if (Network::Player* player = Network::Players::getPlayerFromCharacter(parent)) {
            player->setTeamColor(teamColor);
            player->setNeutral(neutral);
        }
    }
}
}
