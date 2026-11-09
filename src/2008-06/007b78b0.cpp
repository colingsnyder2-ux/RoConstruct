// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_materialbase4a0a4d7cb410e784.cpp

// Candidate translation unit (score above; library headers required).
#include "RenderLib/TextureProxy.h"
#include "G3D/Color3.h"
struct LevelBase {virtual ~LevelBase();};
struct Level:LevelBase {
 virtual ~Level();
 bool enabled;
 G3D::ReferenceCountedPointer<RBX::TextureProxyBase> texture,proxy;
 G3D::Color3 color;
 float d,e,f,g;
 Level(G3D::ReferenceCountedPointer<RBX::TextureProxyBase>,G3D::Color3,float,float,float,float);
};
Level::Level(G3D::ReferenceCountedPointer<RBX::TextureProxyBase> value,G3D::Color3 c,float dd,float ee,float ff,float gg):enabled(false),proxy(value),color(c),d(dd),e(ee),f(ff),g(gg){
 if(value.notNull())texture=dynamic_cast<RBX::Render::TextureProxy*>(value.operator->())->alphaOnlyVersion();
 if(g>0)f=0;
}
