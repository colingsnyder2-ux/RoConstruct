#include "RenderLib/TextureShadeWasm.h"
#include <G3D/Color3uint8.h>
// Original surface atlas and recovered per-pixel BrickColor tint algorithm.
void applyBrickSurface(Ogre::MaterialPtr material,Ogre::ColourValue colour) {
    Ogre::Image atlas;atlas.load("Surfaces.png","General");
    Ogre::PixelBox source=atlas.getPixelBox();
    std::vector<unsigned char> data(source.getWidth()*source.getHeight()*3);
    G3D::Color3uint8 base;
    base.r=Ogre::Math::Floor(colour.r*255+0.5f);
    base.g=Ogre::Math::Floor(colour.g*255+0.5f);
    base.b=Ogre::Math::Floor(colour.b*255+0.5f);
    for(unsigned y=0;y<source.getHeight();++y) for(unsigned x=0;x<source.getWidth();++x) {
        Ogre::ColourValue pixel;
        Ogre::PixelUtil::unpackColour(&pixel,source.format,static_cast<unsigned char*>(source.data)+
            (y*source.rowPitch+x)*Ogre::PixelUtil::getNumElemBytes(source.format));
        G3D::Color3uint8 shade;
        shade.r=shade.g=shade.b=Ogre::Math::Floor(pixel.r*255+0.5f);
        RBX::RenderNew::TextureProxy::shadePixel(base,shade);
        unsigned offset=(y*source.getWidth()+x)*3;
        data[offset]=shade.r;data[offset+1]=shade.g;data[offset+2]=shade.b;
    }
    Ogre::Image tinted;
    tinted.loadDynamicImage(&data[0],source.getWidth(),source.getHeight(),1,Ogre::PF_BYTE_RGB,false);
    Ogre::TexturePtr texture=Ogre::TextureManager::getSingleton().loadImage(material->getName()+"/Surfaces","General",tinted);
    material->setDiffuse(Ogre::ColourValue::White);material->setAmbient(Ogre::ColourValue::White);
    material->setSpecular(0.9f,0.9f,0.9f,1);material->setShininess(50);
    Ogre::TextureUnitState* unit=material->getTechnique(0)->getPass(0)->createTextureUnitState(texture->getName());
    unit->setTextureAddressingMode(Ogre::TextureUnitState::TAM_WRAP);
    unit->setTextureFiltering(Ogre::TFO_TRILINEAR);
}

// Original Roblox RenderLibNew/RenderScene.cpp reflection material setup:
// skyspheremap.jpg + additive pass, ambient 2*reflectance, ENV_CURVED.
// This adapter binds that setup to the demo's existing Ogre material.
Ogre::ColourValue brickColour(int id);
void applyWindowReflectance(Ogre::MaterialPtr material,float reflectance) {
    Ogre::Technique* technique=material->getTechnique(0);
    while(technique->getNumPasses()>1) technique->removePass(1);
    Ogre::Pass* base=technique->getPass(0);
    base->removeAllTextureUnitStates();
    base->setDiffuse(brickColour(102)*(1-reflectance));base->setAmbient(brickColour(102)*(1-reflectance));
    material->setReceiveShadows(false);
    if(reflectance<=0) return;
    Ogre::TexturePtr sky=Ogre::TextureManager::getSingleton().getByName("skysphmap");
    if(sky.isNull()) {
        Ogre::Image image;image.load("skyspheremap.jpg","General");
        sky=Ogre::TextureManager::getSingleton().loadImage("skysphmap","General",image);
    }
    Ogre::Pass* reflection=technique->createPass();
    reflection->setDiffuse(0,0,0,1);
    reflection->setAmbient(Ogre::ColourValue(2,2,2,2)*reflectance);
    reflection->setSceneBlending(Ogre::SBF_ONE,Ogre::SBF_ONE);
    Ogre::TextureUnitState* unit=reflection->createTextureUnitState();
    unit->setTextureName(sky->getName(),Ogre::TEX_TYPE_2D);
    unit->setEnvironmentMap(true,Ogre::TextureUnitState::ENV_CURVED);
    // Keep Roblox's sphere texture / additive pass, but let the reflected sky
    // supply its own brightness rather than multiplying it by local ambient.
    reflection->setLightingEnabled(false);
    unit->setColourOperationEx(Ogre::LBX_MODULATE,Ogre::LBS_TEXTURE,Ogre::LBS_MANUAL,
        Ogre::ColourValue::White,Ogre::ColourValue(reflectance,reflectance,reflectance,1));
}
