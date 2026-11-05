// from server: 100% by EspClaude
// from server: 98% by EspClaude
// from server: 75% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_53171ee6428e5165.cpp

// Candidate translation unit (score above; library headers required).
#define _CPPUNWIND 1
#define NDEBUG 1
#include "roc_espeon_ogreinstalledaliases009c47fc2fe0bc1c.cpp"
#include <OgreSceneManager.h>
#include <OgreLight.h>
#include <OgreLogManager.h>
#include <GLG3D/LightingParameters.h>
#include <util/Utilities.h>
#include <stddef.h>

// All opaque ranges below are determined by the addressed member accesses
// in 007a9d30, recorded in 007a9d30-annotated.asm.
Ogre::ColourValue convertColour(const G3D::Color4&);
struct BoundsOwner {
 char prefix[0x27c];
 Ogre::AxisAlignedBox bounds;
};
struct RenderContext { void* first; Ogre::SceneManager* manager; };
struct NativeLightingScene {
 char prefix[0x26c];
 BoundsOwner* owner;
 char toShadows[0x2f4-0x270];
 unsigned char shadows;
 char toLighting[0x30c-0x2f5];
 G3D::LightingRef lighting;
 char toTint[0x338-0x310];
 G3D::Vector3 mainTint;
 G3D::Vector3 fillTint;
 float brightness;
 G3D::Vector3 ambient;
 G3D::Vector3 mainDiffuse;
 G3D::Vector3 mainSpecular;
 G3D::Vector3 fillDiffuse;
 G3D::Vector3 fillSpecular;
 G3D::Vector3 fillScale;
 void apply(RenderContext*, bool);
};
typedef char checkSceneLighting[offsetof(NativeLightingScene,lighting)==0x30c?1:-1];
typedef char checkSceneTint[offsetof(NativeLightingScene,mainTint)==0x338?1:-1];
typedef char checkLightSize[sizeof(G3D::GLight)==80?1:-1];

static inline float maxf(float a,float b){return a>b?a:b;}
void NativeLightingScene::apply(RenderContext* context, bool unused) {
 float radius=1000.0f;
 Ogre::Vector3 center(0,0,0);
 Ogre::SceneManager* manager=context->manager;
 manager->setAmbientLight(Ogre::ColourValue(ambient.x,ambient.y,ambient.z));
 const G3D::Vector3& fillSum=fillTint;
 float fillAverage=(fillSum.z+fillSum.y+fillSum.x)*0.3333f;
 G3D::Color3 bottom(fillTint.x-fillAverage,fillTint.y-fillAverage,fillTint.z-fillAverage);
 const G3D::Vector3& mainSum=mainTint;
 float mainAverage=(mainSum.z+mainSum.y+mainSum.x)*0.3333f;
 G3D::Color3 top(mainTint.x-mainAverage,mainTint.y-mainAverage,mainTint.z-mainAverage);
 float intensity=brightness;
 if(intensity>5.0f)intensity=5.0f;
 else if(intensity<0.05f)intensity=0.05f;
 int i;
 for(i=0;i<lighting->shadowedLightArray.size();++i) {
  const G3D::GLight& source=lighting->shadowedLightArray[i];
  std::string name=std::string("rbxlight")+RBX::StringConverter<int>::convertToString(i);
  Ogre::Light* light;
  if(!manager->hasLight(name)) {
   light=manager->createLight(name);
   if(light) Ogre::LogManager::getSingleton().logMessage(std::string("RbxGfx: created light")+name);
   else Ogre::LogManager::getSingleton().logMessage(std::string("RbxGfx : FAILED to create light")+name);
  } else light=manager->getLight(name);
  if(shadows) light->setCastShadows(true); else light->setCastShadows(false);
  if(owner) {
   const Ogre::AxisAlignedBox& box=owner->bounds;
   if(!box.isNull()) {
    Ogre::Vector3 size=box.getSize();
    radius=maxf(size.z,maxf(size.x,size.y))*0.8585f;
    radius*=1.3f;
    center=box.getCenter();
    center.y=box.getMinimum().y;
   }
  }
  light->setType(Ogre::Light::LT_POINT);
  G3D::Color3 mainFactor(mainDiffuse);
  G3D::Color3 diffuse=source.color; diffuse=diffuse*intensity*mainFactor;
  float len=diffuse.length(); diffuse+=top*len;
  light->setDiffuseColour(diffuse.r,diffuse.g,diffuse.b);
  light->setPosition(source.position.x*radius+center.x,source.position.y*radius+center.y,source.position.z*radius+center.z);
  G3D::Color3 specular=source.color;
  if(mainSpecular==G3D::Color3()) {
   float peak=std::max(specular.r,std::max(specular.g,specular.b));
   if(peak<0.5f) { float scale=0.5f/peak; specular*=scale; }
  } else { G3D::Color3 specularFactor(mainSpecular); specular=specular*specularFactor; }
  light->setSpecularColour(specular.r,specular.g,specular.b);
 }
 for(;;++i) {
  std::string name=std::string("rbxlight")+RBX::StringConverter<int>::convertToString(i);
  if(!manager->hasLight(name))break;
  manager->destroyLight(manager->getLight(name));
 }
 if(lighting->shadowedLightArray.size()==1) {
  const G3D::GLight& source=lighting->shadowedLightArray[0];
  int zero=0;
  std::string name=std::string("rbxlight")+RBX::StringConverter<int>::convertToString(zero);
  Ogre::Light* primary=manager->getLight(name);
  Ogre::Vector3 position;
  if(primary->getType()==Ogre::Light::LT_DIRECTIONAL)position=-primary->getDirection()*2000.0f;
  else position=primary->getPosition();
  std::string fillName="rbxfl";
  Ogre::Light* light;
  if(manager->hasLight(fillName))light=manager->getLight(fillName);
  else {light=manager->createLight(fillName);light->setCastShadows(false);light->setType(Ogre::Light::LT_POINT);}
  Ogre::Vector3 fillPos=center*2.0f-position; light->setPosition(fillPos);
  G3D::Color3 diffuse;
  { G3D::Color3 baseColour=source.color; baseColour=baseColour*intensity;
  G3D::Color3 scaleFactor(fillScale);
  G3D::Color3 diffuseFactor(fillDiffuse);
  diffuse=baseColour*0.4f*diffuseFactor*scaleFactor; }
  float len=diffuse.length(); diffuse+=bottom*len;
  light->setDiffuseColour(convertColour(diffuse));
  { G3D::Color3 specularFactor(fillSpecular);
  G3D::Color3 specular=specularFactor*diffuse;
  light->setSpecularColour(specular.r,specular.g,specular.b); }
 }
 {
 G3D::Color3 average = (lighting->ambientTop + lighting->ambientBottom) / 2.0f;
 int runningTotal = lighting->shadowedLightArray.size() * 2;
 if (lighting->shadowedLightArray.size() > 0)
 {
  G3D::Vector3 direction = lighting->shadowedLightArray.front().position.xyz();
 }
 }
}
