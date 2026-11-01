// from server: 100% by king_originala
// from server: 96% by Espeon
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <vector>
#include <set>
#include <map>
#include <intrin.h>
namespace RBX {
struct Primitive;
struct Edge;
struct World;
struct Kernel;
struct IStage {
 enum StageType {JOINT_STAGE=0,CLUMP_STAGE=1,KERNEL_STAGE=8};
 virtual ~IStage();
 virtual StageType getStageType()=0;
 virtual void stepWorld(int,int,bool);
 virtual Kernel* getKernel();
 IStage* upstream;
 IStage* downstream;
 IStage* getDownstream(){return downstream;}
};
struct IWorldStage:IStage {
 virtual void onEdgeAdded(Edge*);
 virtual void onEdgeRemoving(Edge*);
 virtual int getMetric(int);
 World* world;
 IWorldStage* getDownstreamWS(){return static_cast<IWorldStage*>(getDownstream());}
};
struct IPipelined {
 virtual ~IPipelined();
 virtual void putInKernel(Kernel*);
 virtual void removeFromKernel();
 IStage* currentStage;
 bool inPipeline()const{return currentStage!=0;}
 void putInPipeline(IStage*);
 bool downstreamOfStage(IStage* s)const{return currentStage->getStageType()>s->getStageType();}
};
struct Primitive:IPipelined {};
struct Edge:IPipelined {
 virtual int getEdgeType()const=0;
 virtual void setPrimitive(int,Primitive*);
 int edgeState;
 Primitive* prim0;
 Primitive* prim1;
 Edge* next0;
 Edge* next1;
 bool inEdgeList;
 Primitive* getPrimitive(int n)const{return (&prim0)[n];}
 Primitive* otherPrimitive(const Primitive*p)const{return p==prim0?prim1:prim0;}
};
struct Joint:Edge {};
struct ClumpStage:IWorldStage {void onPrimitiveAdded(Primitive*);};
struct JointStage:IWorldStage {
 struct JointMap:std::multimap<Primitive*,Joint*> {
  typedef std::multimap<Primitive*,Joint*> Base;
  __declspec(noinline) iterator lower_bound(Primitive* const& p){return Base::lower_bound(p);}
 };
 std::set<Joint*> incompleteJoints;
 JointMap jointMap;
 virtual ~JointStage();
 virtual StageType getStageType(){return JOINT_STAGE;}
 virtual void onEdgeAdded(Edge*);
 virtual void onEdgeRemoving(Edge*);
 ClumpStage* getClumpStage(){return static_cast<ClumpStage*>(getDownstream());}
 void removeFromList(Joint*j){incompleteJoints.erase(j);}
 void removeFromMap(Joint*,Primitive*);
 void moveEdgeToDownstream(Edge*e){getDownstreamWS()->onEdgeAdded(e);}
 bool edgeHasPrimitivesDownstream(Edge*);
 void onPrimitiveAdded(Primitive*);
};

void JointStage::removeFromMap(Joint* j, Primitive* p){
 do {
  if(p==0) break;
  JointMap::iterator pos;
  for(pos=jointMap.lower_bound(p);pos!=jointMap.upper_bound(p);++pos){
   if(pos->second==j){jointMap.erase(pos);return;}
  }
 }while(0);
}
}
