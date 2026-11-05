// from server: 100% by EspClaude
// from server: 99% by king_originala_sol_native
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob1 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_069d389152c04cf5.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/Ogre.h"
#include <GLG3D/LightingParameters.h>
#include <G3D/Color4.h>
#include <algorithm>
#include <cmath>
class SkySunRecovery {
public:
 template<class T> T& field(unsigned offset) {return *reinterpret_cast<T*>(reinterpret_cast<char*>(this)+offset);}
 void drawSun(void*, const G3D::LightingParameters&);
};
void SkySunRecovery::drawSun(void*,const G3D::LightingParameters& lighting) {
 G3D::Vector3 sun=lighting.physicallyCorrect?lighting.trueSunPosition:lighting.sunPosition;
 G3D::Color3 color=lighting.emissiveScale*0.8f;
 if(sun.y<0) {float factor=G3D::max(0.0f,(sun.y+0.1f)*10.0f);color*=factor;}
 sun*=2700.0f;
 field<Ogre::SceneNode*>(0x40)->setPosition(sun.x,sun.y,sun.z);
 field<Ogre::BillboardSet*>(0x34)->getBillboard(0)->setColour(Ogre::ColourValue(color.r,color.g,color.b));
 field<Ogre::BillboardSet*>(0x34)->getBillboard(1)->setColour(Ogre::ColourValue(color.r,color.g,color.b));
 field<Ogre::BillboardSet*>(0x34)->getBillboard(2)->setColour(Ogre::ColourValue(color.r,color.g,color.b));
 field<G3D::Vector3>(0xbc)=sun;
 if(0<sun.x && sun.y>=-0.1) {
  float brightness=static_cast<float>(0.25599999237060506*G3D::max(0.0f,G3D::min(1.0f,1.0f-sun.y/static_cast<float>(sqrt(2.0))*2.0f)));
  G3D::Color4 rays=G3D::Color4(1,1,1,1)*brightness;
  field<Ogre::BillboardSet*>(0x3c)->getBillboard(0)->setColour(Ogre::ColourValue(rays.r,rays.g,rays.b,rays.a));
  field<bool>(0x84)=true;
 } else field<bool>(0x84)=false;
}

