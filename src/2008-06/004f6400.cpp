// from server: 100% by king_originala_sol_native
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_sol_native_builder_004f6400_9913415c6a5ee6d0.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
#include <G3D/Vector3.h>
#include <G3D/Rect2D.h>

extern "C" __declspec(dllimport) double __cdecl fabs(double);
namespace G3D {inline int iRound(float);}
namespace MeshTypes {
extern "C" __declspec(dllimport) double __cdecl ceil(double);
typedef G3D::Vector2 Vector2;
typedef G3D::Vector3 Vector3;
struct Vector2int16 {short x,y;Vector2int16():x(0),y(0){}short&operator[](int i){return (&x)[i];}const short&operator[](int i)const{return (&x)[i];}};
typedef G3D::Rect2D Rect2D;
template<class T>const T& maximum(const T&a,const T&b){return a<b?b:a;}
}
namespace RBX {namespace View {
using MeshTypes::Vector2;using MeshTypes::Vector3;using MeshTypes::Vector2int16;using MeshTypes::Rect2D;
struct Function {char opaque[4];};
Vector3 __cdecl mapFace(const Vector3&);
float __cdecl surfaceOffset(int);
static __forceinline bool useFirstAxis(int purpose,const Vector3& size){if(purpose==0 && size.x<size.y)return true;return false;}
static __forceinline Vector3 absoluteSize(const Vector3& v){Vector3 mapped=mapFace(v);float z=(float)fabs(mapped.z);float y=(float)fabs(mapped.y);float x=(float)fabs(mapped.x);return Vector3(x,y,z);}
struct Builder {
 enum Purpose{Surface,Decal,Shadow};
 virtual void build(Purpose);virtual void buildTop(Purpose)=0;virtual void buildBottom(Purpose)=0;virtual void buildLeft(Purpose)=0;virtual void buildRight(Purpose)=0;virtual void buildFront(Purpose)=0;virtual void buildBack(Purpose)=0;
 const Vector3 halfSize;unsigned surfaceTypes;void* level;Vector2 textureScale;
 void build(Function,Vector2int16,int);
 void emit(Function,Rect2D,float,Vector2,Vector2,int,Vector2int16);
};
void Builder::build(Function function,Vector2int16 grid,int purpose){
 int surface=(surfaceTypes>>15)&7;
 Vector3 size=absoluteSize(halfSize);
 int axis=!useFirstAxis(purpose,size);
 int steps=(purpose==0 && surface)?G3D::iRound((float)MeshTypes::ceil((double)(size[axis]*0.5f))):1;
 Vector2int16 divisions;
 short n=grid[1-axis];
 divisions[axis]=MeshTypes::maximum<short>(1,(short)(n/steps));
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
typedef char native_rect_size[sizeof(G3D::Rect2D)==16?1:-1];
typedef char native_vec2_size[sizeof(G3D::Vector2)==8?1:-1];
typedef char native_vec3_size[sizeof(G3D::Vector3)==12?1:-1];
