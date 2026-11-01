// from server: 100% by EspClaude
// from server: 97% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Complete 931-byte owned-builder grid emitter; RTTI proves ViewNew WedgeBuilder/BevelMesh::Builder/LevelBuilder.
// Native G3D ReferenceCount and the 36-byte by-value builder explain parameter cleanup.
// RTTI tables8270c8/827088/8270a8 prove the native three-level hierarchy.
// Native AtomicInt32 imports and weak-list invalidation account for every cleanup call.
// Remaining local storage/FP differences are retained as partial, not exact.
#include <stddef.h>
#include <math.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
namespace G3D {
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

struct Vector2 {float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}Vector2 operator*(float f)const{return Vector2(x*f,y*f);}Vector2&operator=(const Vector2&v){x=v.x;y=v.y;return *this;}float&operator[](int i){return (&x)[i];}const float&operator[](int i)const{return (&x)[i];}};
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector3 abs()const{return Vector3((float)fabs(x),(float)fabs(y),(float)fabs(z));}};
struct Vector2int16 {short x,y;Vector2int16(short a,short b):x(a),y(b){}};
struct Rect2D {Vector2 min,max;};
}
namespace RBX {namespace ViewNew {
using G3D::Vector2;using G3D::Vector3;using G3D::Rect2D;using G3D::Vector2int16;
class WedgeBuilder;
Vector3 __cdecl mapFace(const Vector3&);
const Vector2&__cdecl zeroVector2();
unsigned __cdecl allocVertex(const Vector3&,const Vector3&,const Vector2&,bool);
void __cdecl freeVertex(unsigned);
struct Level:G3D::ReferenceCountedObject {virtual ~Level();};
class LevelBuilder {
public:
 enum Purpose{Surface,Decal,Shadow};
 virtual void build(Purpose);virtual void buildTop(Purpose)=0;virtual void buildBottom(Purpose)=0;virtual void buildLeft(Purpose)=0;virtual void buildRight(Purpose)=0;virtual void buildFront(Purpose)=0;virtual void buildBack(Purpose)=0;
 const Vector3 halfSize;unsigned surfaceTypes;const G3D::ReferenceCountedPointer<Level>level;Vector2 textureScale;
 void appendQuadFromVertexIndices(unsigned,unsigned,unsigned,unsigned);
 void emit(WedgeBuilder,Rect2D,float,Vector2,Vector2,int,Vector2int16);
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
void LevelBuilder::emit(WedgeBuilder function,Rect2D rect,float depth,Vector2 origin,Vector2 extent,int axis,Vector2int16 grid){
 Vector3 size=mapFace(halfSize).abs();
 float pointX=0,uvX=0,pointY=0,uvY=0;
 float stepX=(rect.max.x-rect.min.x)/grid.x;float stepY=(rect.max.y-rect.min.y)/grid.y;
 float textureStepX=extent.x/grid.x;float textureStepY=extent.y/grid.y;
 unsigned count=(grid.x+1)*(grid.y+1);
 unsigned*indices=new unsigned[count];
 pointX=rect.min.x;
 uvX=origin.x;
 for(int j=0;j<=grid.x;++j){
  pointY=rect.min.y;uvY=origin.y;
  for(int i=0;i<=grid.y;++i){
   Vector3 vertex(pointX,pointY,depth);
   Vector2 texture;texture[1-axis]=uvX;texture[axis]=uvY;
   Vector3 normal(0,0,1);
   function(vertex,normal,texture,size,Vector2int16(j,i));
   const Vector2&zero=zeroVector2();
   float texU,texV;
   if(extent.x==zero.x&&extent.y==zero.y){texU=origin.x;texV=origin.y;}else{texU=texture.x;texV=texture.y;}
   Vector2 tex=Vector2(texU,texV)*.5f;
   Vector3 mappedNormal=mapFace(normal);Vector3 mappedVertex=mapFace(vertex);
   indices[(grid.y+1)*j+i]=allocVertex(mappedVertex,mappedNormal,tex,true);
   pointY+=stepY;uvY+=textureStepY;
  }
  pointX+=stepX;uvX+=textureStepX;
 }
 for(int j=0;j<grid.x;++j)for(int i=0;i<grid.y;++i){int k=(grid.y+1)*j+i;appendQuadFromVertexIndices(indices[k+1],indices[k],indices[k+grid.y+1],indices[k+grid.y+2]);}
 for(unsigned k=0;k<count;++k)freeVertex(indices[k]);
 delete[]indices;
}
}}
typedef char deformation_extent[sizeof(RBX::ViewNew::WedgeBuilder)==36?1:-1];
typedef char rectangle_extent[sizeof(G3D::Rect2D)==16?1:-1];
typedef char builder_extent[sizeof(RBX::ViewNew::LevelBuilder)==32?1:-1];
typedef char size_offset[offsetof(RBX::ViewNew::LevelBuilder,halfSize)==4?1:-1];

typedef char reference_extent[sizeof(G3D::ReferenceCountedPointer<RBX::ViewNew::Level>)==4?1:-1];
typedef char object_extent[sizeof(G3D::ReferenceCountedObject)==12?1:-1];
typedef char bevel_offset[offsetof(RBX::ViewNew::BevelMesh::Builder,bevel)==0x20?1:-1];
