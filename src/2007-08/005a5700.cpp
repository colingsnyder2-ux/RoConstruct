// from server: 92% by EspClaude
// roc 2007-08 005a5700  RBX::Humanoid::onAncestorChanged (rbxgs humanoid/Humanoid.cpp body).
// 2007 layout from the target: Connector base @+0xe8, world @+0x198, currentState auto_ptr @+0x19c,
// Running = 0x50 bytes; Kernel::insertConnector2ndPass inline (IndexArray connectors2ndPass @Kernel+0x40).
// roc-flags: /O2 /GS- /EHsc /MD
#include <memory>
namespace G3D {
template<class T> class Array {
public:
    T* data; int num; int numAllocated;
    void append(const T& value);
    int size() const { return num; }
};
}
namespace RBX {
class Connector {
public:
    virtual ~Connector();
    int& getKernelIndex();
};
template <typename tInstance, int& (tInstance::*getIndex)()>
class IndexArray {
    G3D::Array<tInstance*> array;
    int& indexOf(tInstance* instance) const { return (instance->*getIndex)(); }
public:
    void fastAppend(tInstance* item)
    {
        indexOf(item) = array.size();
        array.append(item);
    }
};
class Kernel {
    char pad[0x40];
    IndexArray<Connector, &Connector::getKernelIndex> connectors2ndPass;
public:
    void removeConnector2ndPass(Connector* c);
    void insertConnector2ndPass(Connector* c) { connectors2ndPass.fastAppend(c); }
};
class World {
public:
    Kernel& getKernel();
};
struct AncestorChanged;
class Instance {
public:
    virtual ~Instance();
    char pad[0xe4];
    virtual void onAncestorChanged(const AncestorChanged& event);
};
class Workspace {
public:
    static World* getWorldIfInWorkspace(Instance* context);
};
class Humanoid;
class HumanoidState {
public:
    virtual void unused0();
    virtual ~HumanoidState();
};
class Running : public HumanoidState {
public:
    Running(Humanoid* humanoid);
    char pad[0x4c];
};
class Humanoid : public Instance, public Connector {
    char pad2[0x198 - 0xec];
    World* world;
    std::auto_ptr<HumanoidState> currentState;
    void setState(HumanoidState* state)
    {
        if (state != currentState.get())
            currentState.reset(state);
    }
public:
    virtual void onAncestorChanged(const AncestorChanged& event);
};

void Humanoid::onAncestorChanged(const AncestorChanged& event)
{
    World* worldInWorkspace = Workspace::getWorldIfInWorkspace(this);
    if (worldInWorkspace != world)
    {
        currentState.reset();
        if (world)
        {
            world->getKernel().removeConnector2ndPass(this);
        }

        world = worldInWorkspace;
        if (world)
        {
            setState(new Running(this));
            world->getKernel().insertConnector2ndPass(this);
        }
    }

    Instance::onAncestorChanged(event);
}
}
