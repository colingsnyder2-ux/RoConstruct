// from server: 100% by king_originala_sol_native
// from server: 52% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Complete 884-byte face grid emitter; native LevelBuilder and PBB Face12 contracts.
// Descriptive deformation/global labels identify observed ABI and arithmetic.
// Native PBBMesh.cpp establishes Face12 (Vector2 perturbation,bool[2]).
// Measured zero-valued inset global and sign comparison at zero replace the earlier unproved scratch.
// Loop barrier preserves the target per-iteration memory ordering; absoluteSize scopes mapped storage.
// Face-specific deformation shrinks point.x/point.y; depth is preserved.
#include <stddef.h>
#include <intrin.h>
#include <math.h>
namespace G3D {
struct Vector2 {float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}Vector2&operator=(const Vector2&v){x=v.x;y=v.y;return *this;}float&operator[](int i){return ((float*)this)[i];}const float&operator[](int i)const{return ((const float*)this)[i];}};
struct Vector3 {float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}float&operator[](int i){return ((float*)this)[i];}const float&operator[](int i)const{return ((const float*)this)[i];}Vector3 abs()const{return Vector3((float)fabs(x),(float)fabs(y),(float)fabs(z));}};
struct Vector2int16 {short x,y;Vector2int16(short a,short b):x(a),y(b){}};
struct Rect2D {Vector2 min,max;};
}
namespace RBX {namespace View {
using G3D::Vector2;using G3D::Vector3;using G3D::Rect2D;using G3D::Vector2int16;
extern const float inset;
struct Face {Vector2 perturbation;bool bulge[2];void operator()(Vector3&,Vector3&,Vector2&,const Vector3&,const Vector2int16&);};
typedef Face Deformation;
__forceinline void Face::operator()(Vector3&vertex,Vector3&normal,Vector2&,const Vector3&size,const Vector2int16&){
 if(vertex.x>0)vertex.x-=inset;else vertex.x+=inset;
 if(vertex.y>0)vertex.y-=inset;else vertex.y+=inset;
 for(int k=0;k<2;++k){normal[k]=bulge[k]?vertex[k]/size[k]*perturbation[k]:perturbation[k];_ReadWriteBarrier();}
}
Vector3 __cdecl mapFace(const Vector3&);
static __forceinline Vector3 absoluteSize(const Vector3&v){Vector3 mapped=mapFace(v);return mapped.abs();}
const Vector2&__cdecl zeroVector2();
unsigned __cdecl allocVertex(const Vector3&,const Vector3&,const Vector2&,bool);
void __cdecl freeVertex(unsigned);
struct Level;
class LevelBuilder {
public:
 enum Purpose{Surface,Decal,Shadow};
 virtual void build(Purpose);virtual void buildTop(Purpose)=0;virtual void buildBottom(Purpose)=0;virtual void buildLeft(Purpose)=0;virtual void buildRight(Purpose)=0;virtual void buildFront(Purpose)=0;virtual void buildBack(Purpose)=0;
 const Vector3 halfSize;unsigned surfaceTypes;Level*level;Vector2 textureScale;
 void appendQuadFromVertexIndices(unsigned,unsigned,unsigned,unsigned);
 void emit(Deformation,Rect2D,float,Vector2,Vector2,int,Vector2int16);
};
void LevelBuilder::emit(Deformation function,Rect2D rect,float depth,Vector2 origin,Vector2 extent,int axis,Vector2int16 grid){
 Vector3 size=absoluteSize(halfSize);
 Vector2 step((rect.max.x-rect.min.x)/grid.x,(rect.max.y-rect.min.y)/grid.y);
 Vector2 textureStep(extent.x/grid.x,extent.y/grid.y);
 unsigned count=(grid.x+1)*(grid.y+1);
 unsigned*indices=new unsigned[count];
 float pointX=rect.min.x;
 float uvX=origin.x;
 for(int j=0;j<=grid.x;++j){
  float pointY=rect.min.y;float uvY=origin.y;
  for(int i=0;i<=grid.y;++i){
   Vector3 vertex(pointX,pointY,depth);
   Vector2 texture;texture[1-axis]=uvX;texture[axis]=uvY;
   Vector3 normal(0,0,1);
   function(vertex,normal,texture,size,Vector2int16(j,i));
   const Vector2&zero=zeroVector2();
   float texU,texV;
   if(extent.x==zero.x&&extent.y==zero.y){texU=origin.x;texV=origin.y;}else{texU=texture.x;texV=texture.y;}
   Vector2 tex(texU*.5f,texV*.5f);
   Vector3 mappedNormal=mapFace(normal);Vector3 mappedVertex=mapFace(vertex);
   indices[(grid.y+1)*j+i]=allocVertex(mappedVertex,mappedNormal,tex,true);
   pointY+=step.y;uvY+=textureStep.y;
  }
  pointX+=step.x;uvX+=textureStep.x;
 }
 for(int j=0;j<grid.x;++j)for(int i=0;i<grid.y;++i){int k=(grid.y+1)*j+i;appendQuadFromVertexIndices(indices[k+1],indices[k],indices[k+grid.y+1],indices[k+grid.y+2]);}
 for(unsigned k=0;k<count;++k)freeVertex(indices[k]);
 delete[]indices;
}
}}
typedef char deformation_extent[sizeof(RBX::View::Deformation)==12?1:-1];
typedef char rectangle_extent[sizeof(G3D::Rect2D)==16?1:-1];
typedef char builder_extent[sizeof(RBX::View::LevelBuilder)==32?1:-1];
typedef char size_offset[offsetof(RBX::View::LevelBuilder,halfSize)==4?1:-1];

typedef char perturbation_offset[offsetof(RBX::View::Face,perturbation)==0?1:-1];
typedef char bulge_offset[offsetof(RBX::View::Face,bulge)==8?1:-1];
