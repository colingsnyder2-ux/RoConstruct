// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2007-08 004eb8a0  unit: CylinderBuilder  size: 821 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004eb8a0
//
// 004eb8a0  55                   push ebp
// 004eb8a1  8bec                 mov ebp, esp
// 004eb8a3  83e4f8               and esp, 0xfffffff8
// 004eb8a6  81ec94000000         sub esp, 0x94
// 004eb8ac  53                   push ebx
// 004eb8ad  56                   push esi
// 004eb8ae  894c2458             mov dword ptr [esp + 0x58], ecx
// 004eb8b2  57                   push edi
// 004eb8b3  83c104               add ecx, 4
// 004eb8b6  51                   push ecx
// 004eb8b7  8d442444             lea eax, [esp + 0x44]
// 004eb8bb  50                   push eax
// 004eb8bc  e8cfe00c00           call 0x5b9990
// 004eb8c1  d9442448             fld dword ptr [esp + 0x48]
// 004eb8c5  d9e1                 fabs 
// 004eb8c7  0fbf7534             movsx esi, word ptr [ebp + 0x34]
// 004eb8cb  d95c2418             fstp dword ptr [esp + 0x18]
// 004eb8cf  8974243c             mov dword ptr [esp + 0x3c], esi
// 004eb8d3  d9442418             fld dword ptr [esp + 0x18]
// 004eb8d7  0fbf5d36             movsx ebx, word ptr [ebp + 0x36]
// 004eb8db  d99c2484000000       fstp dword ptr [esp + 0x84]
// 004eb8e2  d944244c             fld dword ptr [esp + 0x4c]
// 004eb8e6  d9e1                 fabs 
// 004eb8e8  895c2454             mov dword ptr [esp + 0x54], ebx
// 004eb8ec  d95c2418             fstp dword ptr [esp + 0x18]
// 004eb8f0  8d4e01               lea ecx, [esi + 1]
// 004eb8f3  d9442418             fld dword ptr [esp + 0x18]
// 004eb8f7  8d7b01               lea edi, [ebx + 1]
// 004eb8fa  d99c2488000000       fstp dword ptr [esp + 0x88]
// 004eb901  0faff9               imul edi, ecx
// 004eb904  d9442450             fld dword ptr [esp + 0x50]
// 004eb908  d9e1                 fabs 
// 004eb90a  d95c2418             fstp dword ptr [esp + 0x18]
// 004eb90e  d9442418             fld dword ptr [esp + 0x18]
// 004eb912  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 004eb919  db44243c             fild dword ptr [esp + 0x3c]
// 004eb91d  d94514               fld dword ptr [ebp + 0x14]
// 004eb920  d8650c               fsub dword ptr [ebp + 0xc]
// 004eb923  33c9                 xor ecx, ecx
// 004eb925  d95c2418             fstp dword ptr [esp + 0x18]
// 004eb929  8bc7                 mov eax, edi
// 004eb92b  d9442418             fld dword ptr [esp + 0x18]
// 004eb92f  ba04000000           mov edx, 4
// 004eb934  d8f1                 fdiv st(1)
// 004eb936  f7e2                 mul edx
// 004eb938  0f90c1               seto cl
// 004eb93b  897c2444             mov dword ptr [esp + 0x44], edi
// 004eb93f  f7d9                 neg ecx
// 004eb941  0bc8                 or ecx, eax
// 004eb943  51                   push ecx
// 004eb944  d95c246c             fstp dword ptr [esp + 0x6c]
// 004eb948  db442458             fild dword ptr [esp + 0x58]
// 004eb94c  d94518               fld dword ptr [ebp + 0x18]
// 004eb94f  d86510               fsub dword ptr [ebp + 0x10]
// 004eb952  d95c241c             fstp dword ptr [esp + 0x1c]
// 004eb956  d944241c             fld dword ptr [esp + 0x1c]
// 004eb95a  d8f1                 fdiv st(1)
// 004eb95c  d95c2470             fstp dword ptr [esp + 0x70]
// 004eb960  d94528               fld dword ptr [ebp + 0x28]
// 004eb963  def2                 fdivrp st(2)
// 004eb965  d9c9                 fxch st(1)
// 004eb967  d95c2460             fstp dword ptr [esp + 0x60]
// 004eb96b  d87d2c               fdivr dword ptr [ebp + 0x2c]
// 004eb96e  d95c2464             fstp dword ptr [esp + 0x64]
// 004eb972  e8bb451400           call 0x62ff32
// 004eb977  d9450c               fld dword ptr [ebp + 0xc]
// 004eb97a  d95c2438             fstp dword ptr [esp + 0x38]
// 004eb97e  83c40c               add esp, 0xc
// 004eb981  85f6                 test esi, esi
// 004eb983  d94520               fld dword ptr [ebp + 0x20]
// 004eb986  8bf8                 mov edi, eax
// 004eb988  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb98c  897c2410             mov dword ptr [esp + 0x10], edi
// 004eb990  0f8c0a020000         jl 0x4ebba0
// 004eb996  d9ee                 fldz 
// 004eb998  8d4601               lea eax, [esi + 1]
// 004eb99b  897c2418             mov dword ptr [esp + 0x18], edi
// 004eb99f  8944241c             mov dword ptr [esp + 0x1c], eax
// 004eb9a3  85db                 test ebx, ebx
// 004eb9a5  d94510               fld dword ptr [ebp + 0x10]
// 004eb9a8  d95c2430             fstp dword ptr [esp + 0x30]
// 004eb9ac  d94524               fld dword ptr [ebp + 0x24]
// 004eb9af  d95c2428             fstp dword ptr [esp + 0x28]
// 004eb9b3  0f8c55010000         jl 0x4ebb0e
// 004eb9b9  8b4530               mov eax, dword ptr [ebp + 0x30]
// 004eb9bc  8b742418             mov esi, dword ptr [esp + 0x18]
// 004eb9c0  03c0                 add eax, eax
// 004eb9c2  03c0                 add eax, eax
// 004eb9c4  8d7c2424             lea edi, [esp + 0x24]
// 004eb9c8  8d4c0420             lea ecx, [esp + eax + 0x20]
// 004eb9cc  8d5301               lea edx, [ebx + 1]
// 004eb9cf  2bf8                 sub edi, eax
// 004eb9d1  894c2450             mov dword ptr [esp + 0x50], ecx
// 004eb9d5  89542438             mov dword ptr [esp + 0x38], edx
// 004eb9d9  8da42400000000       lea esp, [esp]
// 004eb9e0  d944242c             fld dword ptr [esp + 0x2c]
// 004eb9e4  8b442450             mov eax, dword ptr [esp + 0x50]
// 004eb9e8  d95c2440             fstp dword ptr [esp + 0x40]
// 004eb9ec  8d4c243c             lea ecx, [esp + 0x3c]
// 004eb9f0  d9442430             fld dword ptr [esp + 0x30]
// 004eb9f4  51                   push ecx
// 004eb9f5  d95c2448             fstp dword ptr [esp + 0x48]
// 004eb9f9  8d942480000000       lea edx, [esp + 0x80]
// 004eba00  d9451c               fld dword ptr [ebp + 0x1c]
// 004eba03  52                   push edx
// 004eba04  d95c2450             fstp dword ptr [esp + 0x50]
// 004eba08  8d4c2470             lea ecx, [esp + 0x70]
// 004eba0c  8d542448             lea edx, [esp + 0x48]
// 004eba10  d9542428             fst dword ptr [esp + 0x28]
// 004eba14  d954242c             fst dword ptr [esp + 0x2c]
// 004eba18  d944241c             fld dword ptr [esp + 0x1c]
// 004eba1c  d91f                 fstp dword ptr [edi]
// 004eba1e  d9442430             fld dword ptr [esp + 0x30]
// 004eba22  d918                 fstp dword ptr [eax]
// 004eba24  8d442428             lea eax, [esp + 0x28]
// 004eba28  50                   push eax
// 004eba29  d9542474             fst dword ptr [esp + 0x74]
// 004eba2d  51                   push ecx
// 004eba2e  d95c247c             fstp dword ptr [esp + 0x7c]
// 004eba32  52                   push edx
// 004eba33  d9e8                 fld1 
// 004eba35  8d4d08               lea ecx, [ebp + 8]
// 004eba38  d99c2484000000       fstp dword ptr [esp + 0x84]
// 004eba3f  e83cfdffff           call 0x4eb780
// 004eba44  e8275b0100           call 0x501570
// 004eba49  d94528               fld dword ptr [ebp + 0x28]
// 004eba4c  8bc8                 mov ecx, eax
// 004eba4e  d901                 fld dword ptr [ecx]
// 004eba50  dae9                 fucompp 
// 004eba52  dfe0                 fnstsw ax
// 004eba54  f6c444               test ah, 0x44
// 004eba57  7a1d                 jp 0x4eba76
// 004eba59  d9452c               fld dword ptr [ebp + 0x2c]
// 004eba5c  d94104               fld dword ptr [ecx + 4]
// 004eba5f  dae9                 fucompp 
// 004eba61  dfe0                 fnstsw ax
// 004eba63  f6c444               test ah, 0x44
// 004eba66  7a0e                 jp 0x4eba76
// 004eba68  d94520               fld dword ptr [ebp + 0x20]
// 004eba6b  d95c2420             fstp dword ptr [esp + 0x20]
// 004eba6f  d94524               fld dword ptr [ebp + 0x24]
// 004eba72  d95c2424             fstp dword ptr [esp + 0x24]
// 004eba76  d9442420             fld dword ptr [esp + 0x20]
// 004eba7a  8d442468             lea eax, [esp + 0x68]
// 004eba7e  dd05485b7900         fld qword ptr [0x795b48]
// 004eba84  50                   push eax
// 004eba85  dcc9                 fmul st(1), st(0)
// 004eba87  8d8c248c000000       lea ecx, [esp + 0x8c]
// 004eba8e  d9c9                 fxch st(1)
// 004eba90  51                   push ecx
// 004eba91  d95c247c             fstp dword ptr [esp + 0x7c]
// 004eba95  d84c242c             fmul dword ptr [esp + 0x2c]
// 004eba99  d99c2480000000       fstp dword ptr [esp + 0x80]
// 004ebaa0  e8ebde0c00           call 0x5b9990
// 004ebaa5  8d542448             lea edx, [esp + 0x48]
// 004ebaa9  52                   push edx
// 004ebaaa  8d8424a0000000       lea eax, [esp + 0xa0]
// 004ebab1  50                   push eax
// 004ebab2  e8d9de0c00           call 0x5b9990
// 004ebab7  6a01                 push 1
// 004ebab9  8d8c2488000000       lea ecx, [esp + 0x88]
// 004ebac0  51                   push ecx
// 004ebac1  8d9424a0000000       lea edx, [esp + 0xa0]
// 004ebac8  52                   push edx
// 004ebac9  8d8424b0000000       lea eax, [esp + 0xb0]
// 004ebad0  50                   push eax
// 004ebad1  e88a980000           call 0x4f5360
// 004ebad6  d9842484000000       fld dword ptr [esp + 0x84]
// 004ebadd  d8442450             fadd dword ptr [esp + 0x50]
// 004ebae1  8906                 mov dword ptr [esi], eax
// 004ebae3  83c420               add esp, 0x20
// 004ebae6  83c604               add esi, 4
// 004ebae9  836c243801           sub dword ptr [esp + 0x38], 1
// 004ebaee  d95c2430             fstp dword ptr [esp + 0x30]
// 004ebaf2  d9442458             fld dword ptr [esp + 0x58]
// 004ebaf6  d8442428             fadd dword ptr [esp + 0x28]
// 004ebafa  d95c2428             fstp dword ptr [esp + 0x28]
// 004ebafe  d9ee                 fldz 
// 004ebb00  0f85dafeffff         jne 0x4eb9e0
// 004ebb06  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ebb0a  8b742434             mov esi, dword ptr [esp + 0x34]
// 004ebb0e  d9442460             fld dword ptr [esp + 0x60]
// 004ebb12  8d049d04000000       lea eax, [ebx*4 + 4]
// 004ebb19  d844242c             fadd dword ptr [esp + 0x2c]
// 004ebb1d  01442418             add dword ptr [esp + 0x18], eax
// 004ebb21  836c241c01           sub dword ptr [esp + 0x1c], 1
// 004ebb26  d95c242c             fstp dword ptr [esp + 0x2c]
// 004ebb2a  d9442454             fld dword ptr [esp + 0x54]
// 004ebb2e  d8442414             fadd dword ptr [esp + 0x14]
// 004ebb32  d95c2414             fstp dword ptr [esp + 0x14]
// 004ebb36  0f8567feffff         jne 0x4eb9a3
// 004ebb3c  85f6                 test esi, esi
// 004ebb3e  ddd8                 fstp st(0)
// 004ebb40  7e5e                 jle 0x4ebba0
// 004ebb42  8d4c9f08             lea ecx, [edi + ebx*4 + 8]
// 004ebb46  897c2418             mov dword ptr [esp + 0x18], edi
// 004ebb4a  894c2414             mov dword ptr [esp + 0x14], ecx
// 004ebb4e  8974241c             mov dword ptr [esp + 0x1c], esi
// 004ebb52  85db                 test ebx, ebx
// 004ebb54  7e34                 jle 0x4ebb8a
// 004ebb56  8b742418             mov esi, dword ptr [esp + 0x18]
// 004ebb5a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004ebb5e  8bff                 mov edi, edi
// 004ebb60  8b17                 mov edx, dword ptr [edi]
// 004ebb62  8b47fc               mov eax, dword ptr [edi - 4]
// 004ebb65  8b0e                 mov ecx, dword ptr [esi]
// 004ebb67  52                   push edx
// 004ebb68  8b5604               mov edx, dword ptr [esi + 4]
// 004ebb6b  50                   push eax
// 004ebb6c  51                   push ecx
// 004ebb6d  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 004ebb71  52                   push edx
// 004ebb72  e8b9320000           call 0x4eee30
// 004ebb77  83c704               add edi, 4
// 004ebb7a  83c604               add esi, 4
// 004ebb7d  83eb01               sub ebx, 1
// 004ebb80  75de                 jne 0x4ebb60
// 004ebb82  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 004ebb86  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ebb8a  8d049d04000000       lea eax, [ebx*4 + 4]
// 004ebb91  01442418             add dword ptr [esp + 0x18], eax
// 004ebb95  01442414             add dword ptr [esp + 0x14], eax
// 004ebb99  836c241c01           sub dword ptr [esp + 0x1c], 1
// 004ebb9e  75b2                 jne 0x4ebb52
// 004ebba0  8b5c243c             mov ebx, dword ptr [esp + 0x3c]
// 004ebba4  33f6                 xor esi, esi
// 004ebba6  85db                 test ebx, ebx
// 004ebba8  7619                 jbe 0x4ebbc3
// 004ebbaa  8d9b00000000         lea ebx, [ebx]
// 004ebbb0  8b04b7               mov eax, dword ptr [edi + esi*4]
// 004ebbb3  50                   push eax
// 004ebbb4  e827990000           call 0x4f54e0
// 004ebbb9  83c601               add esi, 1
// 004ebbbc  83c404               add esp, 4
// 004ebbbf  3bf3                 cmp esi, ebx
// 004ebbc1  72ed                 jb 0x4ebbb0
// 004ebbc3  57                   push edi
// 004ebbc4  e85d431400           call 0x62ff26
// 004ebbc9  83c404               add esp, 4
// 004ebbcc  5f                   pop edi
// 004ebbcd  5e                   pop esi
// 004ebbce  5b                   pop ebx
// 004ebbcf  8be5                 mov esp, ebp
// 004ebbd1  5d                   pop ebp
// 004ebbd2  c23000               ret 0x30

// from server: 100% by king_originala
// roc-cl: 50727
// Real SDK geometry/LevelBuilder contracts; native grid and coordinate transforms.
#include <math.h>
#include <new>
#include <stddef.h>
namespace G3D {
class Vector2 {public:float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}Vector2&operator=(const Vector2&v){x=v.x;y=v.y;return *this;}float&operator[](int i){return ((float*)this)[i];}const float&operator[](int i)const{return ((const float*)this)[i];}bool operator==(const Vector2&v)const{return x==v.x&&y==v.y;}float length()const{return sqrtf(x*x+y*y);}static const Vector2&zero();};
class Vector3 {public:float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector2 xy()const;};
class Vector2int16 {public:short x,y;Vector2int16():x(0),y(0){}Vector2int16(short a,short b):x(a),y(b){}short&operator[](int i){return ((short*)this)[i];}const short&operator[](int i)const{return ((const short*)this)[i];}};
class Rect2D {Vector2 min,max;public:Rect2D():min(0,0),max(0,0){}float x0()const{return min.x;}float x1()const{return max.x;}float y0()const{return min.y;}float y1()const{return max.y;}float width()const{return max.x-min.x;}float height()const{return max.y-min.y;}};
// Only membership layout is consumed below: no pointer ownership operations,
// owner construction, or by-value reference-pointer API is used by this function.
template<class T>class ReferenceCountedPointer {T*m_pointer;public:ReferenceCountedPointer();ReferenceCountedPointer(const ReferenceCountedPointer&);~ReferenceCountedPointer();};
}
namespace RBX {
enum NormalId {NORM_X=0,NORM_Y=1,NORM_Z=2,NORM_X_NEG=3,NORM_Y_NEG=4,NORM_Z_NEG=5,NORM_UNDEFINED=6};
template<NormalId faceId>G3D::Vector3 uvwToObject(const G3D::Vector3&);
namespace Render {class Mesh {public:class Level;static unsigned allocVertex(const G3D::Vector3&,const G3D::Vector3&,const G3D::Vector2&,bool);static void freeVertex(unsigned);};}
namespace View {
enum RenderSurfaceType {FLAT,STUDS,INLET,WELD,GLUE};
class RenderSurfaceTypes {public:size_t data;RenderSurfaceTypes():data(0){}};
class __declspec(novtable) LevelBuilder {
protected:const G3D::Vector3 halfSize;const RenderSurfaceTypes surfaceTypes;const G3D::ReferenceCountedPointer<Render::Mesh::Level>level;
public:G3D::Vector2 textureScale;enum Purpose {Surface,Decal,Shadow};
protected:LevelBuilder(G3D::ReferenceCountedPointer<Render::Mesh::Level>&,G3D::Vector3,RenderSurfaceTypes);
public:virtual void build(Purpose);void buildFace(NormalId,Purpose);virtual void buildTop(Purpose)=0;virtual void buildBottom(Purpose)=0;virtual void buildLeft(Purpose)=0;virtual void buildRight(Purpose)=0;virtual void buildFront(Purpose)=0;virtual void buildBack(Purpose)=0;
protected:void appendQuadFromVertexIndices(unsigned,unsigned,unsigned,unsigned);
template<NormalId id,class Function>void buildFace(Function,G3D::Rect2D,const float,G3D::Vector2,G3D::Vector2,const int,G3D::Vector2int16);
};
}}
class EndcapTransform {const float bevel;public:EndcapTransform(float v):bevel(v){}void operator()(G3D::Vector3&,G3D::Vector3&,G3D::Vector2&,const G3D::Vector3&,const G3D::Vector2int16&);};
void EndcapTransform::operator()(G3D::Vector3&v,G3D::Vector3&,G3D::Vector2&,const G3D::Vector3&size,const G3D::Vector2int16&){
 float scale;
 if(fabs(v.y)>=fabs(v.x)){
  if(v.y==0.0f)scale=0.0f;else{float magnitude=(float)fabs(v.y);scale=(magnitude/v.xy().length())*(1.0f-bevel/size.y);}
 }else{
  if(v.x==0.0f)scale=0.0f;else{float magnitude=(float)fabs(v.x);scale=(magnitude/v.xy().length())*(1.0f-bevel/size.x);}
 }
 v.x*=scale;v.y*=scale;
}
namespace RBX {namespace View {
template<NormalId id,class Function>
void LevelBuilder::buildFace(Function callback,G3D::Rect2D rectangle,const float depth,G3D::Vector2 textureOrigin,G3D::Vector2 textureExtent,const int axis,G3D::Vector2int16 divisions){
 float x=0,u=0,y=0,v=0;
 G3D::Vector3 absoluteDimensions;{G3D::Vector3 mapped=uvwToObject<id>(halfSize);absoluteDimensions.x=(float)fabs(mapped.x);absoluteDimensions.y=(float)fabs(mapped.y);absoluteDimensions.z=(float)fabs(mapped.z);}
 G3D::Vector2 positionStep;
 positionStep.x=rectangle.width()/divisions.x;
 positionStep.y=rectangle.height()/divisions.y;
 G3D::Vector2 textureStep;
 textureStep.x=textureExtent.x/divisions.x;textureStep.y=textureExtent.y/divisions.y;
 unsigned count=(divisions.x+1)*(divisions.y+1);
 unsigned*vertices=new unsigned[count];
 x=rectangle.x0();u=textureOrigin.x;
 for(int i=0;i<=divisions.x;++i){
  y=rectangle.y0();v=textureOrigin.y;
  for(int j=0;j<=divisions.y;++j){
   G3D::Vector3 position(x,y,depth);
   G3D::Vector2int16 index(i,j);
   G3D::Vector2 texture;
   texture[1-axis]=u;texture[axis]=v;
   G3D::Vector3 normal(0.0f,0.0f,1.0f);
   callback(position,normal,texture,absoluteDimensions,index);
   if(textureExtent==G3D::Vector2::zero())texture=textureOrigin;
   G3D::Vector2 scaledTexture(texture.x*0.5,texture.y*0.5);
   G3D::Vector3 mappedNormal=uvwToObject<id>(normal);
   G3D::Vector3 mappedPosition=uvwToObject<id>(position);
   vertices[i*(divisions.y+1)+j]=Render::Mesh::allocVertex(mappedPosition,mappedNormal,scaledTexture,true);
   y+=positionStep.y;v+=textureStep.y;
  }
  x+=positionStep.x;u+=textureStep.x;
 }
 for(int i=0;i<divisions.x;++i)for(int j=0;j<divisions.y;++j){int index=(divisions.y+1)*i+j;appendQuadFromVertexIndices(vertices[index+1],vertices[index],vertices[index+divisions.y+1],vertices[index+divisions.y+2]);}
 for(unsigned i=0;i<count;++i)Render::Mesh::freeVertex(vertices[i]);
 delete[]vertices;
}
template void LevelBuilder::buildFace<NORM_Y,EndcapTransform>(EndcapTransform,G3D::Rect2D,const float,G3D::Vector2,G3D::Vector2,const int,G3D::Vector2int16);

}}
