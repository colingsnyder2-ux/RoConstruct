// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
    T* get() const { return px; }
    T* operator->() const { return px; }
    void reset();
    operator bool() const { return px != 0; }
};

namespace RBX {
class Instance {
public:
    virtual ~Instance();
    virtual void setName(const std::string& name);
    void setParent(Instance* parent);
};

class InstancePad { public: virtual ~InstancePad(); char pad[0xe0]; };
class Container : public InstancePad, public Instance {};

class Listener {
public:
    virtual void onEvent();
};

class ListenerList {
public:
    void addListener(Listener* l);
    void removeListener(Listener* l);
};

class World {
public:
    char pad[0x130];
    ListenerList listeners;
};

class Root : public Instance {
public:
    Container* findFirstChildByName(const std::string& name);
};

class ServiceProvider {
public:
    World* findWorld();
    Root* findRoot();
};

shared_ptr<Instance> __cdecl shared_from(Instance* instance);

class Marker : public Instance {
public:
    void setOwner(void* owner);
};
shared_ptr<Marker> __cdecl createMarker();

class ClientBase {
public:
    virtual ~ClientBase();
    char pad[0x134 - 4];
};

class Client : public ClientBase, public Listener {
public:
    char pad2[0x13c - 0x138];
    void* owner;
    void onServiceProvider(ServiceProvider* oldProvider, ServiceProvider* newProvider);
};

void Client::onServiceProvider(ServiceProvider* oldProvider, ServiceProvider* newProvider)
{
    if (oldProvider)
    {
        if (Root* root = oldProvider->findRoot())
        {
            shared_ptr<Instance> network = shared_from(root->findFirstChildByName("Network"));
            if (network)
                network->setParent(0);
        }
    }
    Listener* listener = this;
    if (oldProvider)
    {
        if (World* world = oldProvider->findWorld())
            world->listeners.removeListener(listener);
    }
    Listener* listener2 = this;
    if (newProvider)
    {
        if (World* world = newProvider->findWorld())
            world->listeners.addListener(listener2);
        if (Root* root = newProvider->findRoot())
        {
            shared_ptr<Marker> marker = createMarker();
            marker->setName("Network");
            marker->setParent(root);
            marker->setOwner(owner);
        }
    }
}
}
