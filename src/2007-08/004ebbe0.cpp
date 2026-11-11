// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2007-08 004ebbe0  unit: CylinderBuilder  size: 821 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ebbe0
//
// 004ebbe0  55                   push ebp
// 004ebbe1  8bec                 mov ebp, esp
// 004ebbe3  83e4f8               and esp, 0xfffffff8
// 004ebbe6  81ec94000000         sub esp, 0x94
// 004ebbec  53                   push ebx
// 004ebbed  56                   push esi
// 004ebbee  894c2458             mov dword ptr [esp + 0x58], ecx
// 004ebbf2  57                   push edi
// 004ebbf3  83c104               add ecx, 4
// 004ebbf6  51                   push ecx
// 004ebbf7  8d442444             lea eax, [esp + 0x44]
// 004ebbfb  50                   push eax
// 004ebbfc  e8efdd0c00           call 0x5b99f0
// 004ebc01  d9442448             fld dword ptr [esp + 0x48]
// 004ebc05  d9e1                 fabs 
// 004ebc07  0fbf7534             movsx esi, word ptr [ebp + 0x34]
// 004ebc0b  d95c2418             fstp dword ptr [esp + 0x18]
// 004ebc0f  8974243c             mov dword ptr [esp + 0x3c], esi
// 004ebc13  d9442418             fld dword ptr [esp + 0x18]
// 004ebc17  0fbf5d36             movsx ebx, word ptr [ebp + 0x36]
// 004ebc1b  d99c2484000000       fstp dword ptr [esp + 0x84]
// 004ebc22  d944244c             fld dword ptr [esp + 0x4c]
// 004ebc26  d9e1                 fabs 
// 004ebc28  895c2454             mov dword ptr [esp + 0x54], ebx
// 004ebc2c  d95c2418             fstp dword ptr [esp + 0x18]
// 004ebc30  8d4e01               lea ecx, [esi + 1]
// 004ebc33  d9442418             fld dword ptr [esp + 0x18]
// 004ebc37  8d7b01               lea edi, [ebx + 1]
// 004ebc3a  d99c2488000000       fstp dword ptr [esp + 0x88]
// 004ebc41  0faff9               imul edi, ecx
// 004ebc44  d9442450             fld dword ptr [esp + 0x50]
// 004ebc48  d9e1                 fabs 
// 004ebc4a  d95c2418             fstp dword ptr [esp + 0x18]
// 004ebc4e  d9442418             fld dword ptr [esp + 0x18]
// 004ebc52  d99c248c000000       fstp dword ptr [esp + 0x8c]
// 004ebc59  db44243c             fild dword ptr [esp + 0x3c]
// 004ebc5d  d94514               fld dword ptr [ebp + 0x14]
// 004ebc60  d8650c               fsub dword ptr [ebp + 0xc]
// 004ebc63  33c9                 xor ecx, ecx
// 004ebc65  d95c2418             fstp dword ptr [esp + 0x18]
// 004ebc69  8bc7                 mov eax, edi
// 004ebc6b  d9442418             fld dword ptr [esp + 0x18]
// 004ebc6f  ba04000000           mov edx, 4
// 004ebc74  d8f1                 fdiv st(1)
// 004ebc76  f7e2                 mul edx
// 004ebc78  0f90c1               seto cl
// 004ebc7b  897c2444             mov dword ptr [esp + 0x44], edi
// 004ebc7f  f7d9                 neg ecx
// 004ebc81  0bc8                 or ecx, eax
// 004ebc83  51                   push ecx
// 004ebc84  d95c246c             fstp dword ptr [esp + 0x6c]
// 004ebc88  db442458             fild dword ptr [esp + 0x58]
// 004ebc8c  d94518               fld dword ptr [ebp + 0x18]
// 004ebc8f  d86510               fsub dword ptr [ebp + 0x10]
// 004ebc92  d95c241c             fstp dword ptr [esp + 0x1c]
// 004ebc96  d944241c             fld dword ptr [esp + 0x1c]
// 004ebc9a  d8f1                 fdiv st(1)
// 004ebc9c  d95c2470             fstp dword ptr [esp + 0x70]
// 004ebca0  d94528               fld dword ptr [ebp + 0x28]
// 004ebca3  def2                 fdivrp st(2)
// 004ebca5  d9c9                 fxch st(1)
// 004ebca7  d95c2460             fstp dword ptr [esp + 0x60]
// 004ebcab  d87d2c               fdivr dword ptr [ebp + 0x2c]
// 004ebcae  d95c2464             fstp dword ptr [esp + 0x64]
// 004ebcb2  e87b421400           call 0x62ff32
// 004ebcb7  d9450c               fld dword ptr [ebp + 0xc]
// 004ebcba  d95c2438             fstp dword ptr [esp + 0x38]
// 004ebcbe  83c40c               add esp, 0xc
// 004ebcc1  85f6                 test esi, esi
// 004ebcc3  d94520               fld dword ptr [ebp + 0x20]
// 004ebcc6  8bf8                 mov edi, eax
// 004ebcc8  d95c2414             fstp dword ptr [esp + 0x14]
// 004ebccc  897c2410             mov dword ptr [esp + 0x10], edi
// 004ebcd0  0f8c0a020000         jl 0x4ebee0
// 004ebcd6  d9ee                 fldz 
// 004ebcd8  8d4601               lea eax, [esi + 1]
// 004ebcdb  897c2418             mov dword ptr [esp + 0x18], edi
// 004ebcdf  8944241c             mov dword ptr [esp + 0x1c], eax
// 004ebce3  85db                 test ebx, ebx
// 004ebce5  d94510               fld dword ptr [ebp + 0x10]
// 004ebce8  d95c2430             fstp dword ptr [esp + 0x30]
// 004ebcec  d94524               fld dword ptr [ebp + 0x24]
// 004ebcef  d95c2428             fstp dword ptr [esp + 0x28]
// 004ebcf3  0f8c55010000         jl 0x4ebe4e
// 004ebcf9  8b4530               mov eax, dword ptr [ebp + 0x30]
// 004ebcfc  8b742418             mov esi, dword ptr [esp + 0x18]
// 004ebd00  03c0                 add eax, eax
// 004ebd02  03c0                 add eax, eax
// 004ebd04  8d7c2424             lea edi, [esp + 0x24]
// 004ebd08  8d4c0420             lea ecx, [esp + eax + 0x20]
// 004ebd0c  8d5301               lea edx, [ebx + 1]
// 004ebd0f  2bf8                 sub edi, eax
// 004ebd11  894c2450             mov dword ptr [esp + 0x50], ecx
// 004ebd15  89542438             mov dword ptr [esp + 0x38], edx
// 004ebd19  8da42400000000       lea esp, [esp]
// 004ebd20  d944242c             fld dword ptr [esp + 0x2c]
// 004ebd24  8b442450             mov eax, dword ptr [esp + 0x50]
// 004ebd28  d95c2440             fstp dword ptr [esp + 0x40]
// 004ebd2c  8d4c243c             lea ecx, [esp + 0x3c]
// 004ebd30  d9442430             fld dword ptr [esp + 0x30]
// 004ebd34  51                   push ecx
// 004ebd35  d95c2448             fstp dword ptr [esp + 0x48]
// 004ebd39  8d942480000000       lea edx, [esp + 0x80]
// 004ebd40  d9451c               fld dword ptr [ebp + 0x1c]
// 004ebd43  52                   push edx
// 004ebd44  d95c2450             fstp dword ptr [esp + 0x50]
// 004ebd48  8d4c2470             lea ecx, [esp + 0x70]
// 004ebd4c  8d542448             lea edx, [esp + 0x48]
// 004ebd50  d9542428             fst dword ptr [esp + 0x28]
// 004ebd54  d954242c             fst dword ptr [esp + 0x2c]
// 004ebd58  d944241c             fld dword ptr [esp + 0x1c]
// 004ebd5c  d91f                 fstp dword ptr [edi]
// 004ebd5e  d9442430             fld dword ptr [esp + 0x30]
// 004ebd62  d918                 fstp dword ptr [eax]
// 004ebd64  8d442428             lea eax, [esp + 0x28]
// 004ebd68  50                   push eax
// 004ebd69  d9542474             fst dword ptr [esp + 0x74]
// 004ebd6d  51                   push ecx
// 004ebd6e  d95c247c             fstp dword ptr [esp + 0x7c]
// 004ebd72  52                   push edx
// 004ebd73  d9e8                 fld1 
// 004ebd75  8d4d08               lea ecx, [ebp + 8]
// 004ebd78  d99c2484000000       fstp dword ptr [esp + 0x84]
// 004ebd7f  e8fcf9ffff           call 0x4eb780
// 004ebd84  e8e7570100           call 0x501570
// 004ebd89  d94528               fld dword ptr [ebp + 0x28]
// 004ebd8c  8bc8                 mov ecx, eax
// 004ebd8e  d901                 fld dword ptr [ecx]
// 004ebd90  dae9                 fucompp 
// 004ebd92  dfe0                 fnstsw ax
// 004ebd94  f6c444               test ah, 0x44
// 004ebd97  7a1d                 jp 0x4ebdb6
// 004ebd99  d9452c               fld dword ptr [ebp + 0x2c]
// 004ebd9c  d94104               fld dword ptr [ecx + 4]
// 004ebd9f  dae9                 fucompp 
// 004ebda1  dfe0                 fnstsw ax
// 004ebda3  f6c444               test ah, 0x44
// 004ebda6  7a0e                 jp 0x4ebdb6
// 004ebda8  d94520               fld dword ptr [ebp + 0x20]
// 004ebdab  d95c2420             fstp dword ptr [esp + 0x20]
// 004ebdaf  d94524               fld dword ptr [ebp + 0x24]
// 004ebdb2  d95c2424             fstp dword ptr [esp + 0x24]
// 004ebdb6  d9442420             fld dword ptr [esp + 0x20]
// 004ebdba  8d442468             lea eax, [esp + 0x68]
// 004ebdbe  dd05485b7900         fld qword ptr [0x795b48]
// 004ebdc4  50                   push eax
// 004ebdc5  dcc9                 fmul st(1), st(0)
// 004ebdc7  8d8c248c000000       lea ecx, [esp + 0x8c]
// 004ebdce  d9c9                 fxch st(1)
// 004ebdd0  51                   push ecx
// 004ebdd1  d95c247c             fstp dword ptr [esp + 0x7c]
// 004ebdd5  d84c242c             fmul dword ptr [esp + 0x2c]
// 004ebdd9  d99c2480000000       fstp dword ptr [esp + 0x80]
// 004ebde0  e80bdc0c00           call 0x5b99f0
// 004ebde5  8d542448             lea edx, [esp + 0x48]
// 004ebde9  52                   push edx
// 004ebdea  8d8424a0000000       lea eax, [esp + 0xa0]
// 004ebdf1  50                   push eax
// 004ebdf2  e8f9db0c00           call 0x5b99f0
// 004ebdf7  6a01                 push 1
// 004ebdf9  8d8c2488000000       lea ecx, [esp + 0x88]
// 004ebe00  51                   push ecx
// 004ebe01  8d9424a0000000       lea edx, [esp + 0xa0]
// 004ebe08  52                   push edx
// 004ebe09  8d8424b0000000       lea eax, [esp + 0xb0]
// 004ebe10  50                   push eax
// 004ebe11  e84a950000           call 0x4f5360
// 004ebe16  d9842484000000       fld dword ptr [esp + 0x84]
// 004ebe1d  d8442450             fadd dword ptr [esp + 0x50]
// 004ebe21  8906                 mov dword ptr [esi], eax
// 004ebe23  83c420               add esp, 0x20
// 004ebe26  83c604               add esi, 4
// 004ebe29  836c243801           sub dword ptr [esp + 0x38], 1
// 004ebe2e  d95c2430             fstp dword ptr [esp + 0x30]
// 004ebe32  d9442458             fld dword ptr [esp + 0x58]
// 004ebe36  d8442428             fadd dword ptr [esp + 0x28]
// 004ebe3a  d95c2428             fstp dword ptr [esp + 0x28]
// 004ebe3e  d9ee                 fldz 
// 004ebe40  0f85dafeffff         jne 0x4ebd20
// 004ebe46  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ebe4a  8b742434             mov esi, dword ptr [esp + 0x34]
// 004ebe4e  d9442460             fld dword ptr [esp + 0x60]
// 004ebe52  8d049d04000000       lea eax, [ebx*4 + 4]
// 004ebe59  d844242c             fadd dword ptr [esp + 0x2c]
// 004ebe5d  01442418             add dword ptr [esp + 0x18], eax
// 004ebe61  836c241c01           sub dword ptr [esp + 0x1c], 1
// 004ebe66  d95c242c             fstp dword ptr [esp + 0x2c]
// 004ebe6a  d9442454             fld dword ptr [esp + 0x54]
// 004ebe6e  d8442414             fadd dword ptr [esp + 0x14]
// 004ebe72  d95c2414             fstp dword ptr [esp + 0x14]
// 004ebe76  0f8567feffff         jne 0x4ebce3
// 004ebe7c  85f6                 test esi, esi
// 004ebe7e  ddd8                 fstp st(0)
// 004ebe80  7e5e                 jle 0x4ebee0
// 004ebe82  8d4c9f08             lea ecx, [edi + ebx*4 + 8]
// 004ebe86  897c2418             mov dword ptr [esp + 0x18], edi
// 004ebe8a  894c2414             mov dword ptr [esp + 0x14], ecx
// 004ebe8e  8974241c             mov dword ptr [esp + 0x1c], esi
// 004ebe92  85db                 test ebx, ebx
// 004ebe94  7e34                 jle 0x4ebeca
// 004ebe96  8b742418             mov esi, dword ptr [esp + 0x18]
// 004ebe9a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004ebe9e  8bff                 mov edi, edi
// 004ebea0  8b17                 mov edx, dword ptr [edi]
// 004ebea2  8b47fc               mov eax, dword ptr [edi - 4]
// 004ebea5  8b0e                 mov ecx, dword ptr [esi]
// 004ebea7  52                   push edx
// 004ebea8  8b5604               mov edx, dword ptr [esi + 4]
// 004ebeab  50                   push eax
// 004ebeac  51                   push ecx
// 004ebead  8b4c2468             mov ecx, dword ptr [esp + 0x68]
// 004ebeb1  52                   push edx
// 004ebeb2  e8792f0000           call 0x4eee30
// 004ebeb7  83c704               add edi, 4
// 004ebeba  83c604               add esi, 4
// 004ebebd  83eb01               sub ebx, 1
// 004ebec0  75de                 jne 0x4ebea0
// 004ebec2  8b5c244c             mov ebx, dword ptr [esp + 0x4c]
// 004ebec6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ebeca  8d049d04000000       lea eax, [ebx*4 + 4]
// 004ebed1  01442418             add dword ptr [esp + 0x18], eax
// 004ebed5  01442414             add dword ptr [esp + 0x14], eax
// 004ebed9  836c241c01           sub dword ptr [esp + 0x1c], 1
// 004ebede  75b2                 jne 0x4ebe92
// 004ebee0  8b5c243c             mov ebx, dword ptr [esp + 0x3c]
// 004ebee4  33f6                 xor esi, esi
// 004ebee6  85db                 test ebx, ebx
// 004ebee8  7619                 jbe 0x4ebf03
// 004ebeea  8d9b00000000         lea ebx, [ebx]
// 004ebef0  8b04b7               mov eax, dword ptr [edi + esi*4]
// 004ebef3  50                   push eax
// 004ebef4  e8e7950000           call 0x4f54e0
// 004ebef9  83c601               add esi, 1
// 004ebefc  83c404               add esp, 4
// 004ebeff  3bf3                 cmp esi, ebx
// 004ebf01  72ed                 jb 0x4ebef0
// 004ebf03  57                   push edi
// 004ebf04  e81d401400           call 0x62ff26
// 004ebf09  83c404               add esp, 4
// 004ebf0c  5f                   pop edi
// 004ebf0d  5e                   pop esi
// 004ebf0e  5b                   pop ebx
// 004ebf0f  8be5                 mov esp, ebp
// 004ebf11  5d                   pop ebp
// 004ebf12  c23000               ret 0x30

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
template void LevelBuilder::buildFace<NORM_Y_NEG,EndcapTransform>(EndcapTransform,G3D::Rect2D,const float,G3D::Vector2,G3D::Vector2,const int,G3D::Vector2int16);

}}
