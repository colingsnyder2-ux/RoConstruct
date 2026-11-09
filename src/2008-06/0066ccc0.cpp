// from server: 100% by king_originala_sol_native
// from server: 95% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// RunDragger contact search: actual SDK SnapInfo/Array/member-pointer contracts.
#include <stddef.h>
#include <intrin.h>
namespace G3D {
class Vector3 {public:float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3&operator=(const Vector3&v){x=v.x;y=v.y;z=v.z;return*this;}static const Vector3&inf();};
// Borrowed array: only original12-byte layout/find/end are consumed.
// No allocation, container ownership operation, or by-value Array API is used.
template<class T>class Array {T*data;int num,numAllocated;public:typedef const T*ConstIterator;ConstIterator end()const{return data+num;}ConstIterator find(const T&value)const{for(int i=0;i<num;++i)if(data[i]==value)return data+i;return end();}};
}
namespace RBX {
class Primitive;class Contact;class Kernel;class IStage;
enum NormalId {NORM_X=0,NORM_Y=1,NORM_Z=2,NORM_X_NEG=3,NORM_Y_NEG=4,NORM_Z_NEG=5,NORM_UNDEFINED=6};
class __declspec(novtable) IPipelined {IStage*currentStage;public:virtual~IPipelined(){}virtual void putInKernel(Kernel*);virtual void removeFromKernel();};
namespace Sim {enum EdgeState {UNDEFINED,STEPPING,SLEEPING,TOUCHING,TOUCHING_SLEEPING};}
class __declspec(novtable) Edge:public IPipelined {Sim::EdgeState edgeState;Primitive*prim0;Primitive*prim1;Edge*next0;Edge*next1;bool inEdgeList;public:enum EdgeType {JOINT,CONTACT};virtual~Edge(){}virtual EdgeType getEdgeType()const=0;virtual void setPrimitive(int,Primitive*);Primitive*otherPrimitive(const Primitive*p)const{return p==prim0?prim1:prim0;}};
class __declspec(novtable) Contact:public Edge {int lastContactStep,steppingIndex;float jointK,elasticJointK,kFriction;private:virtual void putInKernel(Kernel*);virtual void removeFromKernel();virtual EdgeType getEdgeType()const{return CONTACT;}protected:virtual void deleteAllConnectors()=0;virtual bool stepContact()=0;public:virtual~Contact(){}virtual bool computeIsColliding(float)=0;bool computeIsAdjacent(float);};
class Primitive {public:Contact*getFirstContact();Contact*getNextContact(Contact*);};
class RunDragger {public:class SnapInfo {public:Primitive*snap;NormalId surface;G3D::Vector3 hitWorld,lastDragSnap;SnapInfo():surface(NORM_UNDEFINED),hitWorld(G3D::Vector3::inf()),lastDragSnap(G3D::Vector3::inf()),snap(NULL){}float hitOutsideExtents();};
private:// Borrowed existing owner prefix; no construction or whole native-size claim.
 char beforeDrag[0x14];Primitive*drag;
 SnapInfo createSnapSurface(Primitive*,G3D::Array<NormalId>*);
 bool notTried(Primitive*,const G3D::Array<Primitive*>&);
 SnapInfo bestProximatePart(const G3D::Array<Primitive*>&,bool(Contact::*)(float));
};
}
namespace RBX {
bool RunDragger::notTried(Primitive*check,const G3D::Array<Primitive*>&tried){return check&&tried.find(check)==tried.end();}
RunDragger::SnapInfo RunDragger::bestProximatePart(const G3D::Array<Primitive*>&triedSnap,bool(Contact::*proximityTest)(float)){
 SnapInfo answer;
 for(Contact*current=drag->getFirstContact();current!=NULL;current=drag->getNextContact(current)){
  if((current->*proximityTest)(0.01f)){
   Primitive*otherPrimitive=current->otherPrimitive(drag);
   _ReadWriteBarrier();
   if(notTried(otherPrimitive,triedSnap)){
    SnapInfo testInfo=createSnapSurface(otherPrimitive,NULL);
    if(testInfo.snap&&testInfo.hitOutsideExtents()<1e+10)answer=testInfo;
   }
  }
 }
 return answer;
}
}
