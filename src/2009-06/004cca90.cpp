// from server: 100% by EspClaude
// from server: 83% by EspClaude
// roc 2009-06 004cca90  unit: RBX::Network::Players  size: 468 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004cca90
//

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
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
    shared_count() : pi_(0) {}
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    template<class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pn(r.pn) {}
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};
}
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    void setParent(Instance* parent);
};
template<class T> boost::shared_ptr<T> shared_from(T*);
template<class T> class PtrVector { public: void push_back(const T& v); };
template<class T> class CopyOnWrite {
public:
    const boost::shared_ptr<T>& write();
};
class ServiceProvider { public: template<class T> static T* find(const Instance*); };
class Teams;
struct CharacterAdded;
template<class Class, class Event> class Listener {
public:
    virtual void onEvent(const Class*, Event) = 0;
};
template<class Class, class Event> class Notifier {
public:
    void addListener(Listener<Class, Event>* listener) const;
};
namespace Network {
class Player;
class Players;
}
class Teams { public: void assignNewPlayerToTeam(Network::Player* player); };
namespace Reflection {
class SignalSource { public: virtual ~SignalSource(); };
template<class C, class S> class SignalDesc {
public:
    void fire(SignalSource* source, boost::shared_ptr<Instance> arg);
};
}
namespace Network {
void* findBackend(const Instance* context);
bool isClient(const Instance* context, bool testInDatamodel);
inline bool backendProcessing(const Instance* context, bool testInDatamodel)
{
    return findBackend(context) && !isClient(context, testInDatamodel);
}
class Player : public Instance {
    char pad0[0xc8 - 4];
    int userId;
public:
    int getUserID() const { return userId; }
    void rebuildBackpack();
};
struct PlayerSignal { void operator()(boost::shared_ptr<Instance> arg); };
class Players : public Instance {
    char pad[0xd4 - 4];
    CopyOnWrite<PtrVector<boost::shared_ptr<Instance> > > players;
    char pad2[0xec - 0xd5];
public:
    PlayerSignal playerAddedSignal;
    boost::shared_ptr<Instance> getPlayerByID(int userID);
    virtual void onChildAdded(Instance* child);
};
void Players::onChildAdded(Instance* child)
{
    Player* player = dynamic_cast<Player*>(child);
    if (!player)
        return;

    if (player->getUserID() > 0)
    {
        boost::shared_ptr<Instance> otherPlayer = getPlayerByID(player->getUserID());
        if (otherPlayer)
            otherPlayer->setParent(0);
    }

    const boost::shared_ptr<PtrVector<boost::shared_ptr<Instance> > >& myPlayers = players.write();
    myPlayers->push_back(shared_from(child));

    if (backendProcessing(this, true))
    {
        player->rebuildBackpack();

        if (Teams* teams = ServiceProvider::find<Teams>(this))
            teams->assignNewPlayerToTeam(player);

        playerAddedSignal(shared_from(player));
    }
}
}
}
