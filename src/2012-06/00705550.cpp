// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace boost {
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0) destroy();
        }
    }
};
struct shared_count {
    sp_counted_base* pi;
    ~shared_count() { if (pi) pi->release(); }
};
template<class T> struct shared_ptr {
    T* px;
    shared_count pn;
    T* operator->() const { return px; }
};
}

namespace RBX {
struct BrickColor {
    int number;
    const std::string& name() const;
};
class Instance {
public:
    virtual ~Instance();
    virtual void setName(const std::string& value);
    void setParent2(Instance* parent, bool flag);
    void setParent(Instance* parent) { setParent2(parent, false); }
};
class Team : public Instance {
public:
    void setTeamColor(BrickColor color);
};
class Teams : public Instance {
public:
    bool teamExists(BrickColor color);
};
class SpawnLocation {
public:
    char pad[0x2dc];
    bool neutral;
    BrickColor getTeamColor() const;
};
class ServiceProvider {
public:
    template<class T> static T* create(ServiceProvider* context);
};
template<class B> struct Creatable {
    template<class T> static boost::shared_ptr<T> create();
};
class RootInstance : public ServiceProvider {
public:
    void insertSpawnLocation(SpawnLocation* s);
};

void RootInstance::insertSpawnLocation(SpawnLocation* s)
{
    if (!s->neutral)
    {
        Teams* teams = ServiceProvider::create<Teams>(this);
        if (!teams->teamExists(s->getTeamColor()))
        {
            boost::shared_ptr<Team> team = Creatable<Instance>::create<Team>();
            team->setParent(teams);
            team->setTeamColor(s->getTeamColor());
            team->setName(s->getTeamColor().name() + " Team");
        }
    }
}
}
