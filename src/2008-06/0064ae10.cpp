// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
namespace RBX {
namespace Sim { enum EdgeState { STEPPING = 1 }; }
class Edge {
public:
    char pad[8];
    Sim::EdgeState edgeState;
    Sim::EdgeState getEdgeState() const { return edgeState; }
    void setEdgeState(Sim::EdgeState s) { edgeState = s; }
};
class Joint : public Edge {};
class IWorldStage {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void onEdgeAdded(Edge*);
    virtual void onEdgeRemoving(Edge*);
};
class IStage {
public:
    virtual ~IStage();
    char pad0[4];
    IWorldStage* downstream;
};
class SleepStage : public IStage {
public:
    char pad1[0x1b8 - 12];
    std::set<Joint*> steppingJoints;
    IWorldStage* getDownstreamWS() { return downstream; }
    void changeJointState(Joint* j, Sim::EdgeState newState);
};
void SleepStage::changeJointState(Joint* j, Sim::EdgeState newState)
{
    bool wasStepping = j->getEdgeState() == Sim::STEPPING, isStepping = newState == Sim::STEPPING;
    if (wasStepping != isStepping) {
        if (wasStepping) {
            steppingJoints.erase(j);
            getDownstreamWS()->onEdgeRemoving(j);
        } else {
            steppingJoints.insert(j);
            getDownstreamWS()->onEdgeAdded(j);
        }
    }
    j->setEdgeState(newState);
}
}
