// from server: 84% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <set>
namespace RBX {
class Kernel;
class Edge;
class World;
class Joint;
class Primitive;
class __declspec(novtable) IStage {
public:
    IStage(IStage* upstream, IStage* downstream) : upstream(upstream), downstream(downstream) {}
    virtual ~IStage() { delete downstream; }
    virtual int getStageType() = 0;
    virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);
    virtual Kernel* getKernel();
private:
    IStage* upstream;
    IStage* downstream;
};
class __declspec(novtable) IWorldStage : public IStage {
public:
    IWorldStage(IStage* upstream, IStage* downstream, World* world)
        : IStage(upstream, downstream), world(world) {}
    virtual void onEdgeAdded(Edge* edge);
    virtual void onEdgeRemoving(Edge* edge);
    virtual int getMetric(int metricType);
private:
    World* world;
};
class ClumpStage : public IStage {
    int pad;
public:
    ClumpStage(IStage* upstream, World* world);
    virtual int getStageType();
};
class JointStage : public IWorldStage {
public:
    typedef std::multimap<Primitive*, Joint*> JointMap;
    JointStage(IStage* upstream, World* world);
    virtual ~JointStage() {}
    virtual int getStageType() { return 0; }
    virtual void onEdgeAdded(Edge* edge);
    virtual void onEdgeRemoving(Edge* edge);
private:
    int a;
    int b;
    JointMap jointMap;
    std::set<Joint*> incompleteJoints;
    std::set<Joint*> incompleteJoints2;
};
JointStage::JointStage(IStage* upstream, World* world)
    : IWorldStage(upstream, new ClumpStage(this, world), world), a(0), b(0)
    , jointMap(JointMap::key_compare(), JointMap::allocator_type())
{
}
}
