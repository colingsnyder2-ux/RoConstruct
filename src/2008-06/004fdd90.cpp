// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// Real SDK geometry/LevelBuilder contracts; native grid and coordinate transforms.
#include <math.h>
#include <new>
#include <stddef.h>
namespace G3D {
class Vector2 {public:float x,y;Vector2():x(0),y(0){}Vector2(float a,float b):x(a),y(b){}Vector2(const Vector2&v):x(v.x),y(v.y){}float&operator[](int i){return ((float*)this)[i];}const float&operator[](int i)const{return ((const float*)this)[i];}bool operator==(const Vector2&v)const{return x==v.x&&y==v.y;}float length()const{return sqrtf(x*x+y*y);}static const Vector2&zero();};
class Vector3 {public:float x,y,z;Vector3():x(0),y(0),z(0){}Vector3(float a,float b,float c):x(a),y(b),z(c){}Vector3(const Vector3&v):x(v.x),y(v.y),z(v.z){}Vector2 xy()const;};
class Vector2int16 {public:short x,y;Vector2int16():x(0),y(0){}Vector2int16(short a,short b):x(a),y(b){}short&operator[](int i){return ((short*)this)[i];}const short&operator[](int i)const{return ((const short*)this)[i];}};
class Rect2D {Vector2 min,max;public:Rect2D():min(0,0),max(0,0){}float x0()const{return min.x;}float x1()const{return max.x;}float y0()const{return min.y;}float y1()const{return max.y;}};
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
 positionStep.x=(rectangle.x1()-rectangle.x0())/divisions.x;
 positionStep.y=(rectangle.y1()-rectangle.y0())/divisions.y;
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
   float tx,ty;if(textureExtent==G3D::Vector2::zero()){tx=textureOrigin.x;ty=textureOrigin.y;}else{tx=texture.x;ty=texture.y;}
   G3D::Vector2 scaledTexture(tx*0.5f,ty*0.5f);
   G3D::Vector3 mappedNormal=uvwToObject<id>(normal);
   G3D::Vector3 mappedPosition=uvwToObject<id>(position);
   vertices[i*(divisions.y+1)+j]=Render::Mesh::allocVertex(mappedPosition,mappedNormal,scaledTexture,true);
   y+=positionStep.y;v+=textureStep.y;
  }
  x+=positionStep.x;u+=textureStep.x;
 }
 for(int i=0;i<divisions.x;++i)for(int j=0;j<divisions.y;++j){int index=(divisions.y+1)*i+j;int next=index+divisions.y;appendQuadFromVertexIndices(vertices[index+1],vertices[index],vertices[next+1],vertices[next+2]);}
 for(unsigned i=0;i<count;++i)Render::Mesh::freeVertex(vertices[i]);
 delete[]vertices;
}
template void LevelBuilder::buildFace<NORM_Y,EndcapTransform>(EndcapTransform,G3D::Rect2D,const float,G3D::Vector2,G3D::Vector2,const int,G3D::Vector2int16);

}}
