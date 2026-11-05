// from server: 100% by EspClaude
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
#include <algorithm>
namespace boost {
struct lock_error { lock_error(); };
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    void reset();
    T* get() const { return px; }
    T* operator->() const { return px; }
    T& operator*() const { return *px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
};

template<class T> class weak_ptr { public: T* px; detail::shared_count pn; };
}

namespace RBX {
class Base1 { public: virtual ~Base1(); };
class Base2 { public: virtual ~Base2(); };
class Instance : public Base1, public Base2 {
public:
    virtual ~Instance();
    void setParent(Instance* parent);
    bool isAncestorOf(const Instance* other) const;
};
class Sky : public Instance {};
class Team : public Instance {};
class HopperBin : public Instance {};
class SpawnLocation : public Instance {};
class Decal : public Instance {};
class PartInstance;
class Lighting : public Instance { public: void replaceSky(Sky* sky); };
class Teams : public Instance {};
class StarterPack : public Instance {};
class Players : public Instance { public: Instance* getBackpackParent(); };
class DecalTool : public Instance { public: void startDrag(Decal* decal); };
class ServiceProvider : public Instance {};
template<class T> T* createService(const ServiceProvider* sp);
template<class T> T* findService(const ServiceProvider* sp);
enum InsertMode { INSERT_RAW, INSERT_TO_TREE, INSERT_TO_3D_VIEW };
enum PromptMode { PROMPT_NONE };
void __cdecl requestWaypoint(const char* name, const Instance* context);

template<int I> struct arg {};
static arg<1> _1;
struct bind_t {
    typedef void (Instance::*F)(Instance*);
    F f;
    Instance* p;
    arg<1> a;
    bind_t(F f_, arg<1> a_, Instance* p_) : f(f_), p(p_), a(a_) {}
    void operator()(const boost::shared_ptr<Instance>& i) { (i.get()->*f)(p); }
};
inline bind_t bind(void (Instance::*f)(Instance*), arg<1> a1, Instance* p) { return bind_t(f, a1, p); }

class RootInstance : public ServiceProvider {
public:
    void insertSpawnLocation(SpawnLocation* s);
    void insertRaw(const std::vector<boost::shared_ptr<Instance> >& instances, Instance* parent, std::vector<boost::weak_ptr<PartInstance> >& parts);
    void insertToTree(const std::vector<boost::shared_ptr<Instance> >& instances, Instance* parent);
    void insert3dView(const std::vector<boost::shared_ptr<Instance> >& instances, PromptMode promptMode);
    void insertInstances(const std::vector<boost::shared_ptr<Instance> >& instances, Instance* requestedParent, InsertMode insertMode, PromptMode promptMode);
};

void RootInstance::insertInstances(const std::vector<boost::shared_ptr<Instance> >& instances, Instance* requestedParent, InsertMode insertMode, PromptMode promptMode)
{
    if (requestedParent && !isAncestorOf(requestedParent)) {
        std::for_each(instances.begin(), instances.end(), bind(&Instance::setParent, _1, requestedParent));
        return;
    }
    std::vector<boost::shared_ptr<Instance> > remaining;
    for (size_t i = 0; i < instances.size(); ++i) {
        Instance* instance = instances[i].get();
        if (Sky* sky = dynamic_cast<Sky*>(instance)) {
            Lighting* lighting = createService<Lighting>(this);
            lighting->replaceSky(sky);
        } else if (dynamic_cast<Team*>(instance)) {
            instance->setParent(createService<Teams>(this));
        } else if (HopperBin* hopperBin = dynamic_cast<HopperBin*>(instance)) {
            if (Players* players = findService<Players>(this))
                hopperBin->setParent(players->getBackpackParent());
            else
                hopperBin->setParent(createService<StarterPack>(this));
        } else if (SpawnLocation* spawn = dynamic_cast<SpawnLocation*>(instance)) {
            insertSpawnLocation(spawn);
            remaining.push_back(instances[i]);
        } else if (Decal* decal = dynamic_cast<Decal*>(instance)) {
            if (insertMode == INSERT_TO_3D_VIEW) {
                if (DecalTool* tool = findService<DecalTool>(this))
                    tool->startDrag(decal);
                return;
            }
        } else {
            remaining.push_back(instances[i]);
        }
    }
    if (!remaining.empty()) {
        if (!requestedParent)
            requestedParent = this;
        switch (insertMode) {
        case INSERT_RAW:
            {
                std::vector<boost::weak_ptr<PartInstance> > parts;
                insertRaw(remaining, requestedParent, parts);
            }
            break;
        case INSERT_TO_TREE:
            insertToTree(remaining, requestedParent);
            break;
        case INSERT_TO_3D_VIEW:
            insert3dView(remaining, promptMode);
            break;
        }
        requestWaypoint("Insert", this);
    }
}
}
