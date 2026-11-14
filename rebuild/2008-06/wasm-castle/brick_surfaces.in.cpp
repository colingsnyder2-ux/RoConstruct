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

// Ogre's real cubic environment-map path. Reflectance mixes the sky with the
// lit BrickColor; no painted highlight or screen-space overlay is involved.
Ogre::ColourValue brickColour(int id);
void applyWindowReflectance(Ogre::MaterialPtr material,float reflectance) {
    Ogre::Pass* pass=material->getTechnique(0)->getPass(0);
    pass->removeAllTextureUnitStates();
    material->setDiffuse(brickColour(102));
    material->setAmbient(brickColour(102));
    Ogre::TextureUnitState* reflection=pass->createTextureUnitState();
    reflection->setCubicTextureName("null_plainsky512.jpg",true);
    reflection->setEnvironmentMap(true,Ogre::TextureUnitState::ENV_REFLECTION);
    reflection->setTextureAddressingMode(Ogre::TextureUnitState::TAM_CLAMP);
    reflection->setColourOperationEx(Ogre::LBX_BLEND_MANUAL,Ogre::LBS_TEXTURE,Ogre::LBS_CURRENT,
        Ogre::ColourValue::White,Ogre::ColourValue::White,reflectance);
    reflection->setAlphaOperation(Ogre::LBX_SOURCE1,Ogre::LBS_CURRENT);
}
