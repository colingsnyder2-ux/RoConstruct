// from server: 98% by EspClaude
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
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
struct sp_empty {};
template<class Y, class T> struct sp_enable_if_convertible { typedef sp_empty type; };
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y>
    shared_ptr(shared_ptr<Y> const& r, typename detail::sp_enable_if_convertible<Y,T>::type = detail::sp_empty());
    T* operator->() const { return px; }
};
}
namespace RBX {
struct BrickColor { int number; };
class Player {
public:
    BrickColor getTeamColor() const;
};
class Instance {
public:
    virtual ~Instance();
    char padding[0x44];
    Instance* parent;
    Instance* getParent() const { return parent; }
    Player* getPlayer();
};
class Flag : public Instance {
public:
    char more[0x94 - 0x4c];
    BrickColor teamColor;
    bool inactive;
};
class Teams {
public:
    void captured(Player*);
};
struct FlagSignal {
    void operator()(boost::shared_ptr<Instance> flag);
};
bool __cdecl isServer(Instance*, bool);
int __cdecl isPart(Instance*);
Flag* __cdecl findFlag(Instance*);
boost::shared_ptr<Flag> __cdecl sharedFrom(Flag*);
Teams* __cdecl findTeams(Instance*);
class FlagStand : public Instance {
public:
    char more[0x250 - 0x4c];
    FlagSignal flagCaptured;
    BrickColor teamColor;
    void onTouched(boost::shared_ptr<Instance> other);
};
void FlagStand::onTouched(boost::shared_ptr<Instance> other)
{
    if (isServer(this, true))
    {
        Instance* part = other->getParent();
        if (!isPart(part))
            return;
        Player* player = part->getPlayer();
        if (!player)
            return;
        Flag* flag = findFlag(part);
        if (!flag || flag->inactive)
            return;
        int myColor = teamColor.number;
        if (flag->teamColor.number == myColor && player->getTeamColor().number != myColor)
        {
            flagCaptured(sharedFrom(flag));
            findTeams(this)->captured(player);
        }
    }
}
}
