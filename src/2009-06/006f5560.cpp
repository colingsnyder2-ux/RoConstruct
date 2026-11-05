// from server: 97% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <set>
#include <map>

namespace RBX {
class Primitive;
class IStage {
public:
    virtual ~IStage();
    virtual int getStageType() const = 0;
    virtual void v2();
    virtual void v3();
    virtual void onEdgeRemoving(class Edge* e);
};
class Edge {
public:
    virtual ~Edge();
    IStage* currentStage;
    char pad8[8];
    Primitive* prim[2];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    bool downstreamOfStage(IStage* s) const
    {
        return currentStage && s && currentStage->getStageType() > s->getStageType();
    }
    Primitive* getPrimitive(int i) const { return prim[i]; }
};
class Joint : public Edge {
public:
    enum JointType { NO_JOINT = 0, FREE_JOINT = 8 };
    virtual JointType getJointType() const;
};
class Primitive {
public:
    Joint* getFirstJoint();
    Joint* getNextJoint(Joint* prev);
    void removeFromPipeline(IStage* stage);
};
}
namespace std {
template<> void _Distance2(std::set<RBX::Primitive*>::iterator, std::set<RBX::Primitive*>::iterator, size_t&, bidirectional_iterator_tag);
}
namespace RBX {
class ClumpStage : public IStage {
public:
    void onPrimitiveRemoving(Primitive* p);
};
class JointStage : public IStage {
public:
    IStage* upstream;
    IStage* downstream;
    char pad0c[0x18 - 0xc];
    std::multimap<Primitive*, Joint*> jointMap;
    std::set<Joint*> joints;
    std::set<Primitive*> primitives;
    IStage* getDownstreamWS() { return downstream; }
    ClumpStage* getClumpStage() { return static_cast<ClumpStage*>(downstream); }
    void onPrimitiveRemoving(Primitive* p);
    void onEdgeAdded(Edge* e)
    {
        Joint* j = static_cast<Joint*>(e);
        joints.insert(j);
        jointMap.insert(std::multimap<Primitive*, Joint*>::value_type(j->getPrimitive(0), j));
        jointMap.insert(std::multimap<Primitive*, Joint*>::value_type(j->getPrimitive(1), j));
    }
};

void JointStage::onPrimitiveRemoving(Primitive* p)
{
    std::vector<Joint*> removing;
    for (Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j)) {
        if (j->getJointType() != Joint::NO_JOINT && j->getJointType() != Joint::FREE_JOINT && j->downstreamOfStage(this))
            removing.push_back(j);
    }
    for (unsigned int i = 0; i < removing.size(); ++i) {
        Joint* j = removing[i];
        getDownstreamWS()->onEdgeRemoving(j);
        JointStage::onEdgeAdded(j);
    }
    getClumpStage()->onPrimitiveRemoving(p);
    p->removeFromPipeline(this);
    primitives.erase(p);
}
}
