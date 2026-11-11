// Original007aacc0 lighting preset and007a9d30 Ogre light setup.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerLighting.h"
#include <algorithm>
#include <cstddef>

namespace PlayerLighting {
typedef char LightSize[sizeof(G3D::GLight)==80?1:-1];
typedef char SettingsSize[sizeof(Settings)==0x64?1:-1];
typedef char BrightnessOffset[offsetof(Settings,brightness)==0x18?1:-1];
typedef char AmbientOffset[offsetof(Settings,ambient)==0x1c?1:-1];
typedef char MainDiffuseOffset[offsetof(Settings,mainDiffuse)==0x28?1:-1];
typedef char MainSpecularOffset[offsetof(Settings,mainSpecular)==0x34?1:-1];
typedef char FillDiffuseOffset[offsetof(Settings,fillDiffuse)==0x40?1:-1];
typedef char FillSpecularOffset[offsetof(Settings,fillSpecular)==0x4c?1:-1];
typedef char FillScaleOffset[offsetof(Settings,fillScale)==0x58?1:-1];
Settings::Settings():mainTint(0,0,0),fillTint(0,0,0),brightness(1),ambient(.5f,.5f,.5f),
    mainDiffuse(1,1,1),mainSpecular(1,1,1),fillDiffuse(1,1,1),fillSpecular(0,0,0),fillScale(1,1,1){}
G3D::LightingRef preset(const G3D::LightingParameters& sky,const G3D::Color3& top,const G3D::Color3& bottom){
    G3D::LightingRef lighting=G3D::Lighting::create();
    lighting->ambientTop=top;lighting->ambientBottom=bottom;
    lighting->shadowedLightArray.append(G3D::GLight::directional(sky.lightDirection,sky.lightColor*.9f));
    return lighting;
}
void apply(Ogre::SceneManager& manager,const G3D::LightingRef& lighting,const Settings& settings,
           const Ogre::AxisAlignedBox* bounds,bool shadows){
    float radius=1000;
    Ogre::Vector3 center(0,0,0);
    manager.setAmbientLight(Ogre::ColourValue(settings.ambient.x,settings.ambient.y,settings.ambient.z));
    float fillAverage=(settings.fillTint.z+settings.fillTint.y+settings.fillTint.x)*.3333f;
    G3D::Color3 bottom(settings.fillTint.x-fillAverage,settings.fillTint.y-fillAverage,settings.fillTint.z-fillAverage);
    float mainAverage=(settings.mainTint.z+settings.mainTint.y+settings.mainTint.x)*.3333f;
    G3D::Color3 top(settings.mainTint.x-mainAverage,settings.mainTint.y-mainAverage,settings.mainTint.z-mainAverage);
    float intensity=settings.brightness;
    if(intensity>5)intensity=5;else if(intensity<.05f)intensity=.05f;
    int i;
    for(i=0;i<lighting->shadowedLightArray.size();++i){
        const G3D::GLight& source=lighting->shadowedLightArray[i];
        std::string name="rbxlight"+Ogre::StringConverter::toString(i);
        Ogre::Light* light=0;
        if(!manager.hasLight(name)){
            light=manager.createLight(name);
            if(light)Ogre::LogManager::getSingleton().logMessage("RbxGfx: created light"+name);
            else {Ogre::LogManager::getSingleton().logMessage("RbxGfx : FAILED to create light"+name); continue;}
        }else light=manager.getLight(name);
        if(!light) continue;
        light->setCastShadows(shadows);
        if(bounds && !bounds->isNull()){
            Ogre::Vector3 size=bounds->getSize();
            radius=std::max(size.z,std::max(size.x,size.y))*.8585f;
            radius*=1.3f;
            center=bounds->getCenter();center.y=bounds->getMinimum().y;
        }
        light->setType(Ogre::Light::LT_POINT);
        G3D::Color3 diffuse=source.color;
        diffuse=diffuse*intensity*G3D::Color3(settings.mainDiffuse);
        float length=diffuse.length();diffuse+=top*length;
        light->setDiffuseColour(diffuse.r,diffuse.g,diffuse.b);
        light->setPosition(source.position.x*radius+center.x,source.position.y*radius+center.y,source.position.z*radius+center.z);
        G3D::Color3 specular=source.color;
        // 007aa1a6/007aa1c0 compares the field address with an automatic object's
        // address, not RGB components. The mined analog's == hides that fact.
        G3D::Color3 automaticSpecular;
        if(static_cast<const void*>(&settings.mainSpecular)==static_cast<const void*>(&automaticSpecular)){
            float peak=std::max(specular.r,std::max(specular.g,specular.b));
            if(peak<.5f)specular*=.5f/peak;
        }else specular=specular*G3D::Color3(settings.mainSpecular);
        light->setSpecularColour(specular.r,specular.g,specular.b);
    }
    for(;;++i){
        std::string name="rbxlight"+Ogre::StringConverter::toString(i);
        if(!manager.hasLight(name))break;
        manager.destroyLight(manager.getLight(name));
    }
    if(lighting->shadowedLightArray.size()==1){
        const G3D::GLight& source=lighting->shadowedLightArray[0];
        Ogre::Light* primary=manager.hasLight("rbxlight0")?manager.getLight("rbxlight0"):0;
        if(primary){
            Ogre::Vector3 position=primary->getType()==Ogre::Light::LT_DIRECTIONAL?-primary->getDirection()*2000:primary->getPosition();
            Ogre::Light* light=0;
            if(manager.hasLight("rbxfl"))light=manager.getLight("rbxfl");
            else{light=manager.createLight("rbxfl"); if(light){light->setCastShadows(false);light->setType(Ogre::Light::LT_POINT);} }
            if(light){
                light->setPosition(center*2-position);
                G3D::Color3 diffuse=source.color*intensity;
                diffuse=diffuse*.4f*G3D::Color3(settings.fillDiffuse)*G3D::Color3(settings.fillScale);
                float length=diffuse.length();diffuse+=bottom*length;
                light->setDiffuseColour(Ogre::ColourValue(diffuse.r,diffuse.g,diffuse.b));
                G3D::Color3 specular=G3D::Color3(settings.fillSpecular)*diffuse;
                light->setSpecularColour(specular.r,specular.g,specular.b);
            }
        }
    }
}
}
