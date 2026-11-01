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
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); }
    }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
    long use_count_; long weak_count_;
};
class shared_count {
    sp_counted_base* pi_;
public:
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    Instance* getParent() const { return parent; }
};
class Humanoid { public: static Humanoid* modelIsCharacter(Instance* model); };
struct BrickColor { int number; bool operator==(const BrickColor& o) const { return number == o.number; } };
namespace Network {
class Player {
public:
    char pad[0x94];
    BrickColor teamColor;
    bool neutral;
    bool getNeutral() const { return neutral; }
    BrickColor getTeamColor() const { return teamColor; }
};
class Players {
public:
    static Player* getPlayerFromCharacter(Instance* character);
    static bool backendProcessing(Instance* context, bool required);
};
}
class Flag;
class FlagStand;
class FlagStandService {
public:
    FlagStand* FindStandWithFlag(Flag* f);
    void AffixFlagToClosestStand(Flag* f);
};
class ServiceProvider { public: template<class T> static T* create(const Instance* context); };
class Flag : public Instance {
public:
    char pad2[0x1a0 - 0x4c];
    BrickColor teamColor;
    void onEvent_flagTouched(boost::shared_ptr<Instance> other);
};
void Flag::onEvent_flagTouched(boost::shared_ptr<Instance> other)
{
    if (Network::Players::backendProcessing(this, true)) {
        Instance* parent = other->getParent();
        if (!Humanoid::modelIsCharacter(parent))
            return;
        Network::Player* player = Network::Players::getPlayerFromCharacter(parent);
        if (!player)
            return;
        if (player->getNeutral())
            return;
        BrickColor current = teamColor;
        if (player->getTeamColor() == current) {
            FlagStandService* fss = ServiceProvider::create<FlagStandService>(this);
            if (!fss->FindStandWithFlag(this))
                fss->AffixFlagToClosestStand(this);
        }
    }
}
}
