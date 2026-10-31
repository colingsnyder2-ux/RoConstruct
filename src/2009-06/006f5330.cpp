// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Kernel;
class World;
class __declspec(novtable) IStage
{
public:
    IStage(IStage* upstream, IStage* downstream) : upstream(upstream), downstream(downstream) {}
    virtual ~IStage() { delete downstream; }
    virtual int getStageType() = 0;
private:
    IStage* upstream;
    IStage* downstream;
};
class __declspec(novtable) IWorldStage : public IStage
{
public:
    IWorldStage(IStage* u, IStage* d, World* w);
    virtual ~IWorldStage() {}
    World* world;
    int extra[2];
};
struct JointMap { ~JointMap(); int d[8]; };
struct JointSet { ~JointSet(); int d[8]; };
class JointStage : public IWorldStage
{
public:
    JointStage(IStage* upstream, World* world);
    virtual ~JointStage();
    virtual int getStageType() { return 0; }
    JointSet a;
    JointMap b;
    JointMap c;
};
JointStage::~JointStage() {}
}
