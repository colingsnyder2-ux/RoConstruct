#undef OGRE_NONCLIENT_BUILD
#include "PlayerLighting.h"
#include <cmath>
#include <cstdio>
#undef main
static bool closeValue(float a,float b){return std::fabs(a-b)<.0001f;}
static bool color(const Ogre::ColourValue& value,float r,float g,float b){return closeValue(value.r,r)&&closeValue(value.g,g)&&closeValue(value.b,b);}
int main(){
    Ogre::Root root("","","p2-lighting.log");
    Ogre::SceneManager* manager=root.createSceneManager(Ogre::ST_GENERIC);
    PlayerLighting::Settings settings;
    G3D::LightingParameters sky;
    sky.lightDirection=G3D::Vector3::unitY();sky.lightColor=G3D::Color3(1,.5f,.25f);
    G3D::LightingRef preset=PlayerLighting::preset(sky,G3D::Color3(.1f,.2f,.3f),G3D::Color3(.4f,.5f,.6f));
    if(preset->shadowedLightArray.size()!=1 || preset->ambientTop!=G3D::Color3(.1f,.2f,.3f) || preset->ambientBottom!=G3D::Color3(.4f,.5f,.6f) || preset->shadowedLightArray[0].color!=sky.lightColor*.9f)return 1;
    G3D::LightingRef lighting=G3D::Lighting::create();
    lighting->shadowedLightArray.append(G3D::GLight::directional(G3D::Vector3::unitY(),G3D::Color3(1,.5f,.25f)));
    PlayerLighting::apply(*manager,lighting,settings,0,true);
    Ogre::Light* primary=manager->getLight("rbxlight0"),*fill=manager->getLight("rbxfl");
    if(primary->getType()!=Ogre::Light::LT_POINT || primary->getPosition()!=Ogre::Vector3(0,1000,0) || !primary->getCastShadows())return 2;
    if(!color(manager->getAmbientLight(),.5f,.5f,.5f) || !color(primary->getDiffuseColour(),1,.5f,.25f) || !color(primary->getSpecularColour(),1,.5f,.25f))return 3;
    if(fill->getPosition()!=Ogre::Vector3(0,-1000,0) || fill->getCastShadows() || !color(fill->getDiffuseColour(),.4f,.2f,.1f) || !color(fill->getSpecularColour(),0,0,0))return 4;
    Ogre::AxisAlignedBox bounds(Ogre::Vector3(-2,-3,-4),Ogre::Vector3(6,7,8));
    PlayerLighting::apply(*manager,lighting,settings,&bounds,false);
    if(!closeValue(primary->getPosition().y,10.3926f) || !closeValue(fill->getPosition().y,-16.3926f) || primary->getPosition().x!=2 || primary->getPosition().z!=2 || primary->getCastShadows())return 5;
    settings.brightness=100;
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    if(!color(primary->getDiffuseColour(),5,2.5f,1.25f))return 6;
    settings.brightness=-1;
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    if(!color(primary->getDiffuseColour(),.05f,.025f,.0125f))return 7;
    settings=PlayerLighting::Settings();settings.mainSpecular=G3D::Vector3::zero();
    lighting->shadowedLightArray[0].color=G3D::Color3(.1f,.2f,.25f);
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    if(!color(primary->getSpecularColour(),0,0,0))return 8;
    settings=PlayerLighting::Settings();settings.mainTint=G3D::Vector3(1,0,0);settings.fillTint=G3D::Vector3(0,1,0);
    lighting->shadowedLightArray[0].color=G3D::Color3(1,0,0);
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    if(!color(primary->getDiffuseColour(),1.6667f,-.3333f,-.3333f) || !color(fill->getDiffuseColour(),.26668f,.26668f,-.13332f))return 12;
    lighting->shadowedLightArray.append(lighting->shadowedLightArray[0]);
    lighting->shadowedLightArray.append(lighting->shadowedLightArray[0]);
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    if(!manager->hasLight("rbxlight2"))return 9;
    lighting->shadowedLightArray.resize(1);
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    if(manager->hasLight("rbxlight1") || manager->hasLight("rbxlight2"))return 10;
    lighting->shadowedLightArray.clear();
    PlayerLighting::apply(*manager,lighting,settings,0,false);
    // Original leaves the fill light when count differs from one.
    if(manager->hasLight("rbxlight0") || !manager->hasLight("rbxfl"))return 11;
    root.destroySceneManager(manager);
    std::printf("PASS: recovered lighting preset/defaults, point/fill setup, bounds, clamps, specular, cleanup\n");
    return 0;
}
