// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_materialappend65af826264b10af9.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Array.h>
#include "RenderLib/TextureProxy.h"
#include "G3D/Color3.h"
struct LevelBase {virtual ~LevelBase();};
struct Level:LevelBase {
 Level();
 virtual ~Level();
 bool enabled;
 G3D::ReferenceCountedPointer<RBX::TextureProxyBase> texture,proxy;
 G3D::Color3 color;
 float d,e,f,g;
 Level(G3D::ReferenceCountedPointer<RBX::TextureProxyBase>,G3D::Color3,float,float,float,float);
};

struct Material{char pad[12];G3D::Array<Level> levels;Level* addPass(G3D::Color3,float,float,float,float);};
Level* Material::addPass(G3D::Color3 color,float a,float b,float c,float d){
 levels.append(Level(G3D::ReferenceCountedPointer<RBX::TextureProxyBase>(),color,a,b,c,d));
 return &levels.last();
}
