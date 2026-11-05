// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) const double _Inf;
namespace G3D {
inline double inf(){static double value=_Inf;return value;}
struct RefObject {virtual ~RefObject();long references;void zeroWeakPointers();};
template<class T>struct ReferenceCountedPointer {
 T*pointer;
 ReferenceCountedPointer():pointer(0){}
 ~ReferenceCountedPointer(){if(pointer){if(InterlockedDecrement(&pointer->references)==0){pointer->zeroWeakPointers();delete pointer;}pointer=0;}}
 void setPointer(T*);
 const ReferenceCountedPointer&operator=(const ReferenceCountedPointer&r){setPointer(r.pointer);return *this;}
};
struct Lighting:RefObject {static ReferenceCountedPointer<Lighting>create();};
struct VARArea:RefObject {};
struct VAR {char opaque[32];VAR();~VAR();};
struct LightingParameters {char opaque[0xf8];LightingParameters();};
template<class T>struct Array {
 T*data;int num,numAllocated;
 Array(){num=0;numAllocated=0;data=0;}
 ~Array();
};
}
namespace Ogre {
struct __declspec(dllimport) MaterialPtr {char opaque[12];MaterialPtr();~MaterialPtr()throw();};
struct __declspec(dllimport) MeshPtr {char opaque[12];MeshPtr();~MeshPtr()throw();};
}
struct ClearValue {
 float x,y,z,w;
 ClearValue(float a,float b,float c,float d):x(a),y(b),z(c),w(d){}
 ClearValue(const ClearValue&);
};
namespace RBX {
namespace RenderBase {
struct RenderSceneBase {
 virtual ~RenderSceneBase();
 char reserved[0x14-4];float clearX,clearY,clearZ,clearW;char rest[0x268-0x24];
 RenderSceneBase();
 void setClear(ClearValue v){clearX=v.x;clearY=v.y;clearZ=v.z;clearW=v.w;}
};
}
namespace RenderNew {
struct RenderSurface;struct Chunk;struct Sky;
struct EffectSettings {bool flags[7];float farCull,groundLod,lodShift;};
struct FloatStats {float values[15];FloatStats(){values[0]=0.0f;values[1]=0.0f;values[2]=0.0f;values[3]=0.0f;values[4]=0.0f;values[5]=0.0f;values[6]=0.0f;values[7]=0.0f;values[8]=0.0f;values[9]=0.0f;values[10]=0.0f;values[11]=0.0f;values[12]=0.0f;values[13]=0.0f;values[14]=0.0f;}};
struct RenderScene:RenderBase::RenderSceneBase {
 Sky*sky;void*cachedSky;
 Ogre::MaterialPtr skyMaterial;Ogre::MeshPtr skyMesh;
 G3D::Array<RenderSurface>proxyArray;
 G3D::Array<RenderSurface*>diffuseArray,reflectArray,transparentArray;
 G3D::Array<RenderSurface>shadowArray;
 G3D::Array<G3D::ReferenceCountedPointer<Chunk> >shadowCaching;
 G3D::VAR shadowVAR;G3D::ReferenceCountedPointer<G3D::VARArea>shadowVARArea;
 EffectSettings effects;
 G3D::ReferenceCountedPointer<G3D::Lighting>desiredLighting,lighting;
 bool shadows;float cameraDistance;
 G3D::Array<G3D::ReferenceCountedPointer<Chunk> >chunks;
 bool debugShadowVolumes;char unchanged[0x360-0x325];
 FloatStats stats;char padding[4];
 G3D::LightingParameters desiredSkyParameters,skyParameters;
 RenderScene();
};
RenderScene::RenderScene():cachedSky(0),shadows(false),cameraDistance(static_cast<float>(G3D::inf())),debugShadowVolumes(false){
 desiredLighting=lighting=G3D::Lighting::create();
 sky=0;
 ClearValue input(0.5f,0.5f,1.0f,1.0f);
 setClear(input);
}
}
}
