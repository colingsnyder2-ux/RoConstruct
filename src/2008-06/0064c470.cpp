// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
#include <deque>
#include <stddef.h>
#include <intrin.h>
namespace RBX {
class Assembly;
class Edge;
template<class T> class Array { public: T* data; int num; int size() const { return num; } const T& operator[](int n) const { return data[n]; } };
typedef Array<Edge*> G3DArr;
namespace Sim { enum AssemblyState { ANCHORED = 0, RECURSIVE_WAKE_PENDING = 1, WAKE_PENDING = 2, AWAKE = 3, SLEEPING_CHECKING = 4, SLEEPING_DEEPLY = 5, REMOVING = 6 };
  enum EdgeState { STEPPING = 0, SLEEPING = 1, TOUCHING = 3, TOUCHING_SLEEPING = 4 }; }
class __declspec(novtable) IStage {
public:
    enum StageType { JOINT_STAGE, CLUMP_STAGE, TREE_STAGE, ASSEMBLY_STAGE, COLLISION_STAGE, SLEEP_STAGE, SEPARATE_STAGE, SIMJOB_STAGE, KERNEL_STAGE };
    virtual ~IStage() {}
    virtual StageType getStageType() = 0;
    bool atLeast(IStage* s) { return s->getStageType() >= getStageType(); }
    IStage* getUpstream() { return upstream; }
    IStage* getDownstream() { return downstream; }
private:
    IStage* upstream;
    IStage* downstream;
};
class __declspec(novtable) IPipelined {
public:
    virtual ~IPipelined() {}
    IStage* readStage() const { _ReadWriteBarrier(); return currentStage; }
    bool inPipeline() const { return currentStage != 0; }
    IStage* stageNB() const { return currentStage; }
    bool downstreamOfStage(IStage* stage) const;
    bool inOrDownstreamOfStage(IStage* stage) const;
    virtual void putInKernel(void*);
    virtual void removeFromKernel();
private:
    IStage* currentStage;
};
inline bool IPipelined::downstreamOfStage(IStage* iStage) const
{
    IStage* s = readStage(); return s->getStageType() > iStage->getStageType();
}
inline bool IPipelined::inOrDownstreamOfStage(IStage* stage) const
{
    return currentStage->getStageType() >= stage->getStageType();
}
class Edge : public IPipelined {
public:
    enum EdgeType { JOINT = 0, CONTACT = 1 };
    virtual EdgeType getEdgeType() const = 0;
    Sim::EdgeState getEdgeState() const { return edgeState; }
private:
    Sim::EdgeState edgeState;
};
class Velocity {
public:
    float linear[3], rotational[3];
    Velocity() throw();
    static const Velocity& zero() { static Velocity v; return v; }
};
class Kernel13 { public: void method(); };
class Holder10 { public: char pad[0x2c]; Kernel13* thing; };
class Body { public: char pad[0x10]; Holder10* holder; void setVelocity(const Velocity&);
    void resetAccumulators() { if (Kernel13* t = holder->thing) t->method(); } };
class Primitive { public: char prefix[0xa0]; Body* body; Body* getBody() const { return body; } };
class Clump { public: char prefix[0x1c]; Primitive* rootPrimitive; };
class SleepInfo { public: Sim::AssemblyState state; int sleepCount; };
class Assembly : public IPipelined {
public:
    char prefix[0x18 - 8];
    SleepInfo* sleepInfo;
    char reserved[0x24 - 0x1c];
    Clump* rootClump;
    char reserved28[0x44 - 0x28];
    int visitStamp, depth;
    SleepInfo* getSleepInfo() const { return sleepInfo; }
    const Primitive* getAssemblyPrimitiveConst() const { return rootClump->rootPrimitive; }
    const G3DArr& getExternalEdges() const;
    Assembly* otherAssembly(Edge*) const;
};

inline Assembly* idc(Assembly* x) { return x ? x : 0; }
class SimJobStage : public IStage { public: void onAssemblyAdded(Assembly*); void onAssemblyRemoving(Assembly*); };
typedef std::set<Assembly*> AssemblySet;
class SleepStage : public IStage {
public:
    char prefix[0xe0 - 12];
    AssemblySet set1, set2, set3, set4, set5, set6;
    char reserved[0x1d8 - 0x1a0];
    int visitStamp;
    bool throttling;
    virtual StageType getStageType() { return SLEEP_STAGE; }
    Sim::AssemblyState getState(Assembly* assembly);
    AssemblySet* stateToSet(Sim::AssemblyState state);
    void resetSleepCount(Assembly* assembly);
    bool isAffecting(Edge* edge);
    bool edgeIsAwake(Edge* edge);
    void changeAssemblyState(Assembly* a, Sim::AssemblyState newState);
    void wakeEdge(Edge* e);
    void wakeNeighbors(Assembly* assembly, std::deque<Assembly*>& pending, int maxDepth);
};
Sim::AssemblyState SleepStage::getState(Assembly* assembly)
{
    return assembly->inPipeline() && assembly->inOrDownstreamOfStage(this) ? assembly->getSleepInfo()->state : Sim::ANCHORED;
}
AssemblySet* SleepStage::stateToSet(Sim::AssemblyState state)
{
    switch (state) {
    case Sim::RECURSIVE_WAKE_PENDING: return &set1;
    case Sim::WAKE_PENDING: return &set2;
    case Sim::SLEEPING_CHECKING: return &set4;
    case Sim::SLEEPING_DEEPLY: return &set5;
    case Sim::REMOVING: return &set6;
    default: return &set3;
    }
}
void SleepStage::resetSleepCount(Assembly* assembly)
{
    assembly->getSleepInfo()->sleepCount = 0;
}
bool SleepStage::isAffecting(Edge* edge)
{
    Sim::EdgeState state = edge->getEdgeState();
    return edge->getEdgeType() != Edge::CONTACT || state == Sim::TOUCHING || state == Sim::TOUCHING_SLEEPING;
}
bool SleepStage::edgeIsAwake(Edge* edge)
{
    return atLeast(edge->readStage());
}
void SleepStage::changeAssemblyState(Assembly* a, Sim::AssemblyState newState)
{
    Sim::AssemblyState oldState = getState(a);
    AssemblySet* oldSet = stateToSet(oldState);
    AssemblySet* newSet = stateToSet(newState);
    oldSet->erase(a);
    newSet->insert(a);
    if ((oldState == Sim::SLEEPING_CHECKING || oldState == Sim::SLEEPING_DEEPLY) &&
        newState != Sim::SLEEPING_CHECKING && newState != Sim::SLEEPING_DEEPLY) {
        a->getAssemblyPrimitiveConst()->getBody()->resetAccumulators();
    }
    if (newState == Sim::AWAKE) {
        if (!a->downstreamOfStage(this))
            static_cast<SimJobStage*>(getDownstream())->onAssemblyAdded(a);
    }
    else if (newState == Sim::SLEEPING_CHECKING || newState == Sim::SLEEPING_DEEPLY) {
        a->getAssemblyPrimitiveConst()->getBody()->setVelocity(Velocity::zero());
    }
    if (newState == Sim::SLEEPING_CHECKING || newState == Sim::SLEEPING_DEEPLY || newState == Sim::REMOVING) {
        if (a->downstreamOfStage(this))
            static_cast<SimJobStage*>(getDownstream())->onAssemblyRemoving(a);
    }
    resetSleepCount(a);
    a->getSleepInfo()->state = newState;
}
void SleepStage::wakeNeighbors(Assembly* assembly, std::deque<Assembly*>& pending, int maxDepth)
{
    Sim::AssemblyState state = getState(assembly);
    int depth = assembly->depth;
    if (state != Sim::ANCHORED) {
        if (state != Sim::AWAKE)
            changeAssemblyState(assembly, Sim::AWAKE);
        const G3DArr& edges = assembly->getExternalEdges();
        for (int i = 0; i < edges.size(); ++i) {
            Edge* edge = edges[i];
            if (edgeIsAwake(edge)) {
                wakeEdge(edge);
                if (isAffecting(edge)) {
                    Assembly* other = idc(idc(idc(idc(idc(idc(idc(assembly->otherAssembly(edge))))))));
                    if (depth < maxDepth) {
                        bool wake = throttling ? true : getState(other) != Sim::AWAKE;
                        if (wake) {
                            if (other->visitStamp != visitStamp) {
                                other->visitStamp = visitStamp;
                                other->depth = depth + 1;
                                pending.push_back(other);
                            }
                        }
                    }
                    else if (other->inPipeline() && atLeast(other->readStage()) && other->getSleepInfo()->state == Sim::SLEEPING_DEEPLY) {
                        changeAssemblyState(other, Sim::SLEEPING_CHECKING);
                    }
                }
            }
        }
    }
}
}
typedef char chk1[offsetof(RBX::SleepStage, set4) == 0x140 ? 1 : -1];
typedef char chk2[offsetof(RBX::SleepStage, visitStamp) == 0x1d8 ? 1 : -1];
