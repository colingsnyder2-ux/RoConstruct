// from server: 100% by coldek
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
 typedef std::multimap<Primitive*,Joint*> JointMap;
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
 __forceinline bool exAbove(IStage*current){return current->getStageType()>getStageType();}
 void onPrimitiveAdded(Primitive*);
};
static __forceinline IStage* exCurrent(IPipelined*p){_ReadWriteBarrier();return p->currentStage;}
bool JointStage::edgeHasPrimitivesDownstream(Edge*e){
 Primitive* prim0=e->getPrimitive(0);
 Primitive* prim1=e->getPrimitive(1);
 return prim0->inPipeline()&&prim1->inPipeline()&&exAbove(exCurrent(prim0))&&prim1->downstreamOfStage(this);
}
void JointStage::onPrimitiveAdded(Primitive* p)
{
	p->putInPipeline(this);

	getClumpStage()->onPrimitiveAdded(p);

	std::vector<Joint*> jointsToPush;

	JointMap::iterator pos;

	for (pos = jointMap.lower_bound(p); pos != jointMap.upper_bound(p); ++pos) {
		if (edgeHasPrimitivesDownstream(pos->second)) {
			jointsToPush.push_back(pos->second);
		}
	}

	for (unsigned int i = 0; i < jointsToPush.size(); ++i) {
		Joint* j = jointsToPush[i];

		removeFromList(j);
		removeFromMap(j, j->getPrimitive(0));
		removeFromMap(j, j->getPrimitive(1));

		moveEdgeToDownstream(j);
	}
}


}
