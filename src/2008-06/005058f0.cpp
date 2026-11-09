// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// Consumed G3D GLight/Color3 fields and real inline arithmetic APIs.
// Only existing light pointers are read; no light is constructed here.
#include <stddef.h>
namespace G3D {
class Vector4 {public:float x,y,z,w;};
class Vector3 {public:float x,y,z;};
class Color3 {public:float r,g,b;
 inline double sum()const{return r+g+b;}
 inline double average()const{return sum()/3.0;}
};
class GLight {public:
 Vector4 position;Vector3 spotDirection;
 double spotCutoff;double attenuation[3];Color3 color;
 bool enabled,specular,diffuse;
 GLight();
};
}
int __cdecl compareLights(const G3D::GLight*a,const G3D::GLight*b){
 return a->color.average()*(1.2-a->position.w)>b->color.average()*(1.2-b->position.w);
}
typedef char NativeLightSize[sizeof(G3D::GLight)==80?1:-1];
typedef char NativeLightColor[offsetof(G3D::GLight,color)==64?1:-1];
typedef char NativeLightPosition[offsetof(G3D::GLight,position)==0?1:-1];
typedef char NativeLightDirection[offsetof(G3D::GLight,spotDirection)==16?1:-1];
typedef char NativeLightCutoff[offsetof(G3D::GLight,spotCutoff)==32?1:-1];
typedef char NativeLightAttenuation[offsetof(G3D::GLight,attenuation)==40?1:-1];
typedef char NativeLightFlags[offsetof(G3D::GLight,enabled)==76?1:-1];
