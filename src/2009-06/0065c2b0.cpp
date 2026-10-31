// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Primitive;
class World {
public:
    void destroyJoints(Primitive* p);
    void createJoints(Primitive* p);
};
class Instance;
template<class T> class scoped_ptr { T* px; public: T* get() const { return px; } };
class PartInstance {
public:
    virtual ~PartInstance();
    char pad[0x118 - 4];
    scoped_ptr<Primitive> primitive;
    void destroyJoints();
    void join();
};
class Workspace {
public:
    static World* getWorldIfInWorkspace(Instance* i);
};
void PartInstance::join()
{
    World* world = Workspace::getWorldIfInWorkspace((Instance*)this);
    if (world)
        world->createJoints(primitive.get());
}
}
