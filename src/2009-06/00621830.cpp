// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
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
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    ~shared_ptr() { if (pn) pn->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};
}
namespace RBX {
class BrickColor {
public:
    int number;
    BrickColor(int n);
    const std::string& name() const;
};
class Instance {
public:
    virtual ~Instance();
    virtual void setName(const std::string& name);
    void setParent(Instance* p);
};
class Team : public Instance {
public:
    void setTeamColor(BrickColor c);
};
class Teams : public Instance {
public:
    bool teamExists(BrickColor c);
};
template<class B> class Creatable {
public:
    template<class T> static boost::shared_ptr<T> create();
};
class ServiceProvider : public Instance {
public:
    template<class T> static T* create(const Instance* context);
};
class SpawnLocation : public Instance {
public:
    char pad[0x240];
    bool neutral;
    BrickColor getTeamColor() const;
};
class RootInstance : public ServiceProvider {
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
