// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_owned_native_math_a3c3f2acdcf92a0a.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/Rect2D.h>
#include <G3D/Vector2int16.h>
// from server: 98% by king_originala
// Complete owned-builder face preparation; RTTI proves ViewNew WedgeBuilder/BevelMesh::Builder/LevelBuilder.
// Native G3D ReferenceCount and the 36-byte by-value builder explain parameter cleanup.
// RTTI tables8270c8/827088/8270a8 prove the native three-level hierarchy.
// Native AtomicInt32 imports and weak-list invalidation account for every cleanup call.
// Remaining local storage/FP differences are retained as partial, not exact.

namespace G3D {inline int iRound(float);}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace MeshOwned {
extern "C" __declspec(dllimport) double __cdecl ceil(double);
extern "C" __declspec(dllimport) double __cdecl fabs(double);
struct AtomicInt32 {volatile long value;void increment(){InterlockedIncrement(&value);}unsigned decrement(){return InterlockedDecrement(&value)!=0;}};
struct ReferenceCountedObject;
struct _WeakPtr {virtual ~_WeakPtr(){}protected:friend struct ReferenceCountedObject;virtual void objectCollected()=0;};
struct _WeakPtrLinkedList {_WeakPtr*weakPtr;_WeakPtrLinkedList*next;};
struct ReferenceCountedObject {
 AtomicInt32 ReferenceCountedObject_refCount;_WeakPtrLinkedList*ReferenceCountedObject_weakPointer;
 virtual ~ReferenceCountedObject(){}
 void ReferenceCountedObject_zeroWeakPointers(){_WeakPtrLinkedList*node=ReferenceCountedObject_weakPointer;while(node){node->weakPtr->objectCollected();_WeakPtrLinkedList*tmp=node;node=node->next;delete tmp;}}
};
template<class T>class ReferenceCountedPointer {
 T*m_pointer;
 void zeroPointer(){if(m_pointer){if(m_pointer->ReferenceCountedObject_refCount.decrement()==0){m_pointer->ReferenceCountedObject_zeroWeakPointers();delete m_pointer;}m_pointer=0;}}
 void setPointer(T*x){if(x!=m_pointer){zeroPointer();if(x){m_pointer=x;m_pointer->ReferenceCountedObject_refCount.increment();}}}
public:
 ReferenceCountedPointer():m_pointer(0){}ReferenceCountedPointer(const ReferenceCountedPointer&p):m_pointer(0){setPointer(p.m_pointer);}~ReferenceCountedPointer(){zeroPointer();}
};

typedef G3D::Vector2 Vector2;
typedef G3D::Vector3 Vector3;
typedef G3D::Vector2int16 Vector2int16;
typedef G3D::Rect2D Rect2D;
template<class T>const T&maximum(const T&a,const T&b){return a<b?b:a;}
}
namespace RBX {namespace ViewNew {
using MeshOwned::Vector2;using MeshOwned::Vector3;using MeshOwned::Rect2D;using MeshOwned::Vector2int16;
class WedgeBuilder;
Vector3 __cdecl mapFace(const Vector3&);
const Vector2&__cdecl zeroVector2();
unsigned __cdecl allocVertex(const Vector3&,const Vector3&,const Vector2&,bool);
void __cdecl freeVertex(unsigned);
struct Level:MeshOwned::ReferenceCountedObject {virtual ~Level();};
class LevelBuilder {
public:
 enum Purpose{Surface,Decal,Shadow};
 virtual void build(Purpose);virtual void buildTop(Purpose)=0;virtual void buildBottom(Purpose)=0;virtual void buildLeft(Purpose)=0;virtual void buildRight(Purpose)=0;virtual void buildFront(Purpose)=0;virtual void buildBack(Purpose)=0;
 const Vector3 halfSize;unsigned surfaceTypes;const MeshOwned::ReferenceCountedPointer<Level>level;Vector2 textureScale;
 void appendQuadFromVertexIndices(unsigned,unsigned,unsigned,unsigned);
 void emit(WedgeBuilder,Rect2D,float,Vector2,Vector2,int,Vector2int16);
 void prepare(WedgeBuilder,Vector2int16,int);
};
struct BevelMesh {class Builder:public LevelBuilder {
public:
 const float bevel;virtual void build(Purpose);
 void operator()(Vector3&vertex,Vector3&,Vector2&,const Vector3&,const Vector2int16&){
  if(vertex.x>0)vertex.x-=bevel;else vertex.x+=bevel;
  if(vertex.y>0)vertex.y-=bevel;else vertex.y+=bevel;
 }
};};
class WedgeBuilder:public BevelMesh::Builder {
public:virtual void buildTop(Purpose);virtual void buildBottom(Purpose);virtual void buildLeft(Purpose);virtual void buildRight(Purpose);virtual void buildFront(Purpose);virtual void buildBack(Purpose);
};

float __cdecl surfaceOffset(int);
static __forceinline bool useFirstAxis(int purpose,const Vector3&size){if(purpose==0&&size.x<size.y)return true;return false;}
static __forceinline Vector3 absoluteSize(const Vector3&v){Vector3 mapped=mapFace(v);float z=(float)MeshOwned::fabs(mapped.z);float y=(float)MeshOwned::fabs(mapped.y);float x=(float)MeshOwned::fabs(mapped.x);return Vector3(x,y,z);}
void LevelBuilder::prepare(WedgeBuilder function,Vector2int16 grid,int purpose){
 int surface=(surfaceTypes>>12)&7;
 Vector3 size=absoluteSize(halfSize);
 int axis=!useFirstAxis(purpose,size);
 int steps=(purpose==0 && surface)?G3D::iRound((float)MeshOwned::ceil((double)(size[axis]*0.5f))):1;
 Vector2int16 divisions;
 short n=grid[1-axis];
 divisions[axis]=MeshOwned::maximum<short>(1,(short)(n/steps));
 divisions[1-axis]=n;
 float depth=size.z;
 Vector2 begin=-size.xy();
 Vector2 end=size.xy();
 Vector2 origin,extent;
 switch(purpose){
  case 0:
   if(!surface){origin=Vector2(0.25f,0.5f);extent[1-axis]=0;extent[axis]=0;}
   else {origin[1-axis]=0;origin[axis]=surfaceOffset(surface);extent[1-axis]=size[1-axis]*2.0f;extent[axis]=0.5f;if(axis==1)extent.x=-extent.x;}
   break;
  case 1:origin.x=0;origin.y=textureScale.y;extent.x=textureScale.x;extent.y=-textureScale.y;break;
  case 2:origin=Vector2(0,0);extent=Vector2(0,0);break;
 }
 for(int i=0;i<steps;++i){
  if(i==steps-1){end[axis]=size[axis];if(purpose==0 && surface)extent[axis]=(end[axis]-begin[axis])*extent[axis]*0.25f;}
  else end[axis]=begin[axis]+4.0f;
  emit(function,Rect2D::xyxy(begin,end),depth,origin,extent,axis,divisions);
  begin[axis]=end[axis];
 }
}
}}
typedef char deformation_extent[sizeof(RBX::ViewNew::WedgeBuilder)==36?1:-1];
typedef char rectangle_extent[sizeof(MeshOwned::Rect2D)==16?1:-1];
typedef char builder_extent[sizeof(RBX::ViewNew::LevelBuilder)==32?1:-1];

typedef char reference_extent[sizeof(MeshOwned::ReferenceCountedPointer<RBX::ViewNew::Level>)==4?1:-1];
typedef char object_extent[sizeof(MeshOwned::ReferenceCountedObject)==12?1:-1];
