// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace Ogre {
struct Math {static inline float Sqrt(float value){return static_cast<float>(sqrt(value));}};
struct Vector3 {
 float x,y,z;
 Vector3(){}
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3 operator-(const Vector3&v)const{Vector3 result;result.z=z-v.z;result.y=y-v.y;result.x=x-v.x;return result;}
 float length()const{float xx=x*x;return Math::Sqrt((xx+y*y)+z*z);}
};
struct __declspec(dllimport) VertexData {~VertexData()throw();};
struct AxisAlignedBox {
 Vector3 minimum,maximum;unsigned extent;void*corners;
 AxisAlignedBox(float ax,float ay,float az,float bx,float by,float bz):corners(0){setExtents(ax,ay,az,bx,by,bz);}
 void setExtents(float ax,float ay,float az,float bx,float by,float bz){extent=1;minimum.x=ax;minimum.y=ay;minimum.z=az;maximum.x=bx;maximum.y=by;maximum.z=bz;}
 __declspec(dllimport) ~AxisAlignedBox()throw();
};
struct __declspec(dllimport) Mesh {
 char opaque[0x1e4];VertexData*sharedVertexData;
 void _setBounds(const AxisAlignedBox&,bool);void _setBoundingSphereRadius(float);
};
struct MeshHandle {void*opaque;Mesh*pointer;Mesh*operator->()const{return pointer;}};
struct GeometryBuilder {
 VertexData*createVertexData(const float*,unsigned,const float*,const float*,const float*);
 void update(MeshHandle&,const float*,unsigned,const float*,const float*,const float*,const Vector3*,const Vector3*);
};
void GeometryBuilder::update(MeshHandle&mesh,const float*vertices,unsigned vertexCount,const float*normals,const float*colours,const float*texCoords,const Vector3*minimum,const Vector3*maximum){
 if(mesh->sharedVertexData){delete mesh->sharedVertexData;mesh->sharedVertexData=0;}
 mesh->sharedVertexData=createVertexData(vertices,vertexCount,normals,colours,texCoords);
 if(minimum&&maximum){
  mesh->_setBounds(AxisAlignedBox(minimum->x,minimum->y,minimum->z,maximum->x,maximum->y,maximum->z),true);
  mesh->_setBoundingSphereRadius((*maximum-*minimum).length()*0.5f);
 }else{
  Vector3 low(1.0e9f,1.0e9f,1.0e9f),high(-1.0e9f,-1.0e9f,-1.0e9f);
  for(unsigned i=0;i<3*vertexCount;i+=3){
   if(low.x>vertices[i])low.x=vertices[i];if(low.y>vertices[i+1])low.y=vertices[i+1];if(low.z>vertices[i+2])low.z=vertices[i+2];
   if(high.x<vertices[i])high.x=vertices[i];if(high.y<vertices[i+1])high.y=vertices[i+1];if(high.z<vertices[i+2])high.z=vertices[i+2];
  }
  mesh->_setBounds(AxisAlignedBox(low.x,low.y,low.z,high.x,high.y,high.z),true);
  mesh->_setBoundingSphereRadius((high-low).length()*0.5f);
 }
}
}
