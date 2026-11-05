// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_assembly_step_a8004a142beaf504.cpp

// Candidate translation unit (score above; library headers required).
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <set>
#include <G3D/CoordinateFrame.h>
#include "util/NormalId.h"
namespace RBX {
class Kernel;
class Primitive;
// Borrowed virtual interfaces. No owner is allocated or constructed here.
class IStage {
public:
    enum StageType {JOINT_STAGE,CLUMP_STAGE,TREE_STAGE,ASSEMBLY_STAGE,COLLISION_STAGE,SLEEP_STAGE,SEPARATE_STAGE,SIMJOB_STAGE,KERNEL_STAGE};
    virtual ~IStage();
    virtual StageType getStageType()=0;
    // Native World caller pushes four words; Kernel and SleepStage clean16.
    virtual void stepWorld(int worldStepId,int uiStepId,bool throttling,bool alternate);
    virtual Kernel* getKernel();
};
class IPipelined {
public:
    virtual ~IPipelined();
    virtual void putInKernel(Kernel*);
    virtual void removeFromKernel();
};
class Edge:public IPipelined {
public:
    enum EdgeType {JOINT,CONTACT};
    virtual ~Edge();
    virtual EdgeType getEdgeType()const=0;
    virtual void setPrimitive(int,Primitive*);
};
class Joint:public Edge {
public:
    enum JointType {NO_JOINT,ROTATE_JOINT,ROTATE_P_JOINT,ROTATE_V_JOINT,GLUE_JOINT,ANCHOR_JOINT,WELD_JOINT,SNAP_JOINT,MOTOR_JOINT,FREE_JOINT};
    virtual ~Joint();
    virtual JointType getJointType()const;
    virtual bool isBreakable()const;
    virtual bool isBroken()const;
    virtual bool joinsFace(Primitive*,NormalId)const;
    virtual bool isAligned();
    virtual G3D::CoordinateFrame align(Primitive*,Primitive*);
    // Native admission tests2c before set30 insertion; stepWorld dispatch is34.
    virtual bool canStepWorld()const;
    virtual bool canStepUi()const;
    virtual void stepWorld();
    virtual void stepUi(int);
};
// Only observed fields of an existing AssemblyStage pointer are accessed.
struct AssemblyStageView {
    char prefix[8];
    IStage* downstream;
    char unknown[0x24];
    std::set<Joint*> joints;
    void stepWorld(int worldStepId,int uiStepId,bool throttling,bool alternate);
};
void AssemblyStageView::stepWorld(int worldStepId,int uiStepId,bool throttling,bool alternate) {
    for(std::set<Joint*>::iterator it=joints.begin();it!=joints.end();++it)
        (*it)->stepWorld();
    downstream->stepWorld(worldStepId,uiStepId,throttling,alternate);
}
}
