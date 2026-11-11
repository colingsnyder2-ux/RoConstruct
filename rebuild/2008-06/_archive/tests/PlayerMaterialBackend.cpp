// Material creation block from original007ab0a0, using measured Material/Level types.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerNativeMaterial.h"
#include <cstdio>

namespace PlayerNativeMaterial {
namespace {
int nextMaterialId;
void reflectionPass(Material::Level& level,const std::string& skySphereFile){
    Ogre::TexturePtr texture=Ogre::TextureManager::getSingleton().getByName("skysphmap");
    if(texture.isNull()){
        texture=Ogre::TextureManager::getSingleton().create("skysphmap","General");
        Ogre::Image image;image.load(skySphereFile,"General");texture->loadImage(image);
    }
    Ogre::Pass* pass=level.backend->getTechnique(0)->createPass();
    float reflect=level.reflect();
    pass->setDiffuse(reflect,reflect,reflect,reflect*.8f);
    pass->setAmbient(reflect,reflect,reflect);
    pass->setSceneBlending(static_cast<Ogre::SceneBlendFactor>(0),static_cast<Ogre::SceneBlendFactor>(9));
    Ogre::TextureUnitState* unit=pass->createTextureUnitState();
    unit->setTextureName(texture->getName(),static_cast<Ogre::TextureType>(2));
    unit->setEnvironmentMap(true,static_cast<Ogre::TextureUnitState::EnvMapType>(1));
}
}
Ogre::MaterialPtr prepareBackend(MaterialBase& source,void* context,int kind,int primitive,
                                float depthBias,const std::string& skySphereFile){
    Material::Level* material=dynamic_cast<Material::Level*>(&source.getLevel(0));
    if(!material)return Ogre::MaterialPtr();
    if(!material->backend.isNull())return material->backend;
    char name[8];_snprintf(name,8,"m%d",nextMaterialId++);
    material->backend=Ogre::MaterialManager::getSingleton().create(name,"General");
    for(int i=0;i<source.levelCount();++i){
        Material::Level* level=dynamic_cast<Material::Level*>(&source.getLevel(i));
        if(!level)continue;
        level->baseTexture(context);
        Ogre::Pass* pass=i==0?material->backend->getTechnique(0)->getPass(0):material->backend->getTechnique(0)->createPass();
        const G3D::Color3& color=level->color();
        pass->setDiffuse(color.r,color.g,color.b,1-level->transparent());
        pass->setAmbient(color.r,color.g,color.b);
        if(kind==1 || kind==2 || kind==3){
            pass->setSpecular(level->specular(),level->specular(),level->specular(),1);
            pass->setShininess(kind==2?40.0f:18.0f);
        }else{
            pass->setSpecular(.75f,.75f,.75f,1);pass->setShininess(10);
        }
        pass->setDepthBias(depthBias*-16,0);
        if(level->transparent()>0 || kind==4){
            pass->setSceneBlending(static_cast<Ogre::SceneBlendFactor>(7),static_cast<Ogre::SceneBlendFactor>(9));
            pass->setDepthWriteEnabled(false);
        }
        if(level->baseTexture().notNull()){
            Ogre::TexturePtr texture=dynamic_cast<TextureProxy*>(level->baseTexture().getPointer())->ogreTexture;
            if(!texture.isNull()){
                Ogre::TextureUnitState* unit=pass->createTextureUnitState();
                unit->setColourOperation(static_cast<Ogre::LayerBlendOperation>(2));
                unit->setTextureFiltering(static_cast<Ogre::FilterOptions>(2),static_cast<Ogre::FilterOptions>(2),static_cast<Ogre::FilterOptions>(2));
                unit->setTextureAddressingMode(static_cast<Ogre::TextureUnitState::TextureAddressingMode>(0),static_cast<Ogre::TextureUnitState::TextureAddressingMode>(0),static_cast<Ogre::TextureUnitState::TextureAddressingMode>(0));
                unit->setTextureBorderColour(Ogre::ColourValue(color.r,color.g,color.b));
                unit->setTextureName(texture->getName(),static_cast<Ogre::TextureType>(2));
            }
            if(level->transparent()<=0 && !texture.isNull() && texture->hasAlpha() && primitive==2){
                pass->setSceneBlending(static_cast<Ogre::SceneBlendType>(4));
                pass->setDepthWriteEnabled(true);
                pass->setAlphaRejectSettings(static_cast<Ogre::CompareFunction>(6),1);
            }
        }
    }
    if(material->reflect()>0)reflectionPass(*material,skySphereFile);
    return material->backend;
}
}
