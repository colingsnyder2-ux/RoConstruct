// from server: 100% by EspClaude
// from server: 97% by king_originala_sol_native
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_26d965918fecb544.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/g3dmath.h>
#include <math.h>
#include <stddef.h>
namespace G3D {
struct System {static double getTick();};
template<class T>struct Array {T*data;int num,capacity;void resize(int,bool);void fastClear(){resize(0,false);}};

}
namespace RBX {
struct Primitive;struct World;struct Kernel;struct Edge;
namespace Profiling {
struct CodeProfiler;
template<class T> class scoped_ptr { T* px; public: T& operator*() const { return *px; } T* get() const { return px; } };
struct Mark {CodeProfiler*section;Mark*enclosing;bool frameTick;double startTime;Mark(CodeProfiler&,bool);~Mark();};
}
struct Constants {static int worldStepsPerSec();static int worldStepsPerUiStep();static float worldDt();};
struct IStage {
 IStage*upstream;IStage*downstream;
 enum StageType{CLUMP_STAGE=2,SIMJOB_STAGE=6};
 virtual ~IStage();virtual StageType getStageType()=0;virtual void stepWorld(int,int,bool,bool);virtual Kernel*getKernel();
 IStage*findStage(StageType type){IStage*s=this;while(s->getStageType()!=type)s=s->downstream;return s;}
};
struct IWorldStage:IStage {World*world;virtual void onEdgeAdded(Edge*);virtual void onEdgeRemoving(Edge*);virtual int getMetric(int);};
struct ClumpStage:IWorldStage {void process();void stepUi(int);};
struct SimJobStage:IWorldStage {void notifyMovingPrimitives();};
struct ContactManager {void stepWorld(const G3D::Array<Primitive*>&);};
extern int environmentalThrottleMode;
struct World {
 char opaque[0x80];float environmentThrottle;ContactManager*contactManager;IStage*jointStage;
 G3D::Array<Primitive*>touch,touchOther;
 bool inStepCode;char opaqueA5[3];int worldStepId;char opaqueAC[12];G3D::Array<Primitive*>activePrimitives;
 char opaqueC4[0xfc-0xc4];
 Profiling::scoped_ptr<Profiling::CodeProfiler> profilingWorldStep,profilingPrepare,profilingClump,profilingUi,profilingUpdate,profilingBroadphase;
 ClumpStage*getClumpStage(){return static_cast<ClumpStage*>(jointStage->findStage(IStage::CLUMP_STAGE));}
 SimJobStage&getSimJobStage(){return *static_cast<SimJobStage*>(jointStage->findStage(IStage::SIMJOB_STAGE));}
 void doBreakJoints();void preparePrimitives(unsigned);void gatherActivePrimitives();
 float step(float,unsigned,bool);
};
typedef char VerifiedLayout[(sizeof(Profiling::Mark)==24&&sizeof(G3D::Array<Primitive*>)==12&&offsetof(World,worldStepId)==0xa8&&offsetof(World,activePrimitives)==0xb8&&offsetof(World,profilingWorldStep)==0xfc)?1:-1];
float World::step(float desiredInterval,unsigned updateArgument,bool skipBroadphase){
 inStepCode=true;
 Profiling::Mark mark(*profilingWorldStep,true);
 double startTick=G3D::System::getTick();
 int steps=G3D::max(1,G3D::iRound(floorf(desiredInterval*Constants::worldStepsPerSec())));
 int uiStep=worldStepId/Constants::worldStepsPerUiStep();
 {Profiling::Mark prepare(*profilingClump,false);getClumpStage()->process();}
 {Profiling::Mark ui(*profilingUi,false);
  inStepCode=false;doBreakJoints();inStepCode=true;
  touch.fastClear();touchOther.fastClear();getClumpStage()->stepUi(uiStep);getSimJobStage().notifyMovingPrimitives();
 }
 {Profiling::Mark prepare(*profilingPrepare,false);preparePrimitives(updateArgument);}
 bool throttling=false;int unthrottled=0;
 for(int i=0;i<steps;++i){
  {Profiling::Mark update(*profilingUpdate,false);gatherActivePrimitives();}
  {Profiling::Mark broadphase(*profilingBroadphase,false);if(!skipBroadphase)contactManager->stepWorld(activePrimitives);}
  jointStage->stepWorld(worldStepId,uiStep,throttling,skipBroadphase);
  unthrottled+=!throttling;
  switch(environmentalThrottleMode){
   case 0:{double elapsed=G3D::System::getTick()-startTick;throttling=elapsed>(i+1)*Constants::worldDt();break;}
   case 2:throttling=i%2==0;break;
   case 3:throttling=true;break;
   default:throttling=false;
  }
  ++worldStepId;
 }
 inStepCode=false;
 environmentThrottle=(float)unthrottled/(float)steps;
 return Constants::worldDt()*steps;
}
}
