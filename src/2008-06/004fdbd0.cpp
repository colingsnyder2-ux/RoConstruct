// from server: 100% by EspClaude
// from server: 97% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
struct Vector2 {float x,y;};
struct Vector2int16 {short x,y;};
struct Vector3 {
 float x,y,z;
 Vector3(float a,float b,float c):x(a),y(b),z(c){}
 Vector3& operator=(const Vector3& a){x=a.x;y=a.y;z=a.z;return *this;}
};
}
struct CylinderTransform {
 const float bevel;const int steps;
 void operator()(G3D::Vector3&,G3D::Vector3&,G3D::Vector2&,const G3D::Vector3&,const G3D::Vector2int16&)const;
};
void CylinderTransform::operator()(G3D::Vector3& vertex,G3D::Vector3& normal,G3D::Vector2& tex,const G3D::Vector3& radius,const G3D::Vector2int16& index)const{
 float angleX=vertex.x/radius.x*0.7853981852531433f;
 float angleY=float(index.y-steps+1)*1.5707963705062866f/float(steps-1);
 vertex.x=(radius.x-(1-cosf(angleY))*bevel)*sinf(angleX);
 if(index.y>=steps)vertex.y=radius.y-(1-sinf(angleY))*bevel;
 else vertex.y=(sinf(angleY)+1)*bevel-radius.y;
 vertex.z=(radius.z-(1-cosf(angleY))*bevel)*cosf(angleX);
 normal.x=cosf(angleY)*sinf(angleX);
 normal.y=sinf(angleY);
 normal.z=cosf(angleY)*cosf(angleX);
 float arc=1.5707963705062866f*bevel;float factor=arc/(radius.y+arc-bevel);
 if(index.y>=steps)tex.y*=factor;
 else tex.y=2*radius.y-(1-(tex.y-radius.y)/radius.y)*radius.y*factor;
}
