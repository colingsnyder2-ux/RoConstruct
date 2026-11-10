#undef OGRE_NONCLIENT_BUILD
#include "PlayerNativeMaterial.h"
#include <OgreHardwarePixelBuffer.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#undef main
int main(){
    std::setvbuf(stdout,0,_IONBF,0);
    const char* strip=getenv("ROC_TEXTURE_STRIP");if(!strip)return 1;
    Ogre::Root root("","","p2-native-material.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 2;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P2NativeMaterial",64,64,false,&options);
    using namespace PlayerNativeMaterial;
    {
        TextureRef proxy=new MegaTextureProxy(0,strip);
        if(proxy->getValue28()!=1 || proxy->getValue2c()!=1.0f || proxy->getSize()!=G3D::Vector2(0,0))return 3;
        proxy->setValue28(2);proxy->setValue2c(.5f);
        if(proxy->getValue28()!=2 || proxy->getValue2c()!=.5f)return 4;
        G3D::TextureRef legacy=proxy->resolve(0);
        MegaTextureProxy* concrete=dynamic_cast<MegaTextureProxy*>(proxy.getPointer());
        if(legacy.notNull() || !concrete || !concrete->loaded || concrete->ogreTexture.isNull() || proxy->getSize()!=G3D::Vector2(2048,256))return 5;
        TextureRef shaded=proxy->shade(G3D::Color3(.2f,.3f,.4f),TextureRef());
        TextureProxy* shading=dynamic_cast<TextureProxy*>(shaded.getPointer());
        if(!shading || shading->shadeTexture.getPointer()!=proxy.getPointer() || shading->context!=concrete->context)return 6;
    }
    for(int cycle=0;cycle<32;++cycle){
        MaterialFactory factory(0,strip,strip,strip);
        Attributes red={RBX::BrickColor(21),0,0},blue={RBX::BrickColor(23),0,0};
        MaterialRef material=factory.getMegaMaterial(red),same=factory.getMegaMaterial(blue);
        if(material.getPointer()!=same.getPointer() || material->levelCount()!=1 || !material->detailLevel(0) || material->veryTransparent())return 7;
        Material::Level* level=dynamic_cast<Material::Level*>(&material->getLevel(0));
        if(!level || level->matteTexture.notNull() || level->isEmptyLevel() || level->color()!=G3D::Color3::white() || level->specular()!=.9f || level->shiny()!=50)return 8;
        if(level->baseTexture(0).notNull() || level->matte(0).notNull())return 9;
        // Check original slots independently of this header's virtual dispatch.
        void** levelSlots=*reinterpret_cast<void***>(level);
        // Native member class-return ABI: ECX=this, explicit output on stack.
        // A free-function aggregate return would put output in ECX instead.
        typedef G3D::TextureRef* (__thiscall *ResolveSlot)(const MaterialBase::Level*,G3D::TextureRef*,void*);
        typedef TextureRef* (__thiscall *ProxySlot)(const MaterialBase::Level*,TextureRef*);
        G3D::TextureRef legacyFromSlot;
        TextureRef proxyFromSlot;
        reinterpret_cast<ResolveSlot>(levelSlots[2])(level,&legacyFromSlot,0);
        reinterpret_cast<ProxySlot>(levelSlots[3])(level,&proxyFromSlot);
        if(legacyFromSlot.notNull() || proxyFromSlot.isNull())return 18;
        TextureProxy* texture=dynamic_cast<TextureProxy*>(level->baseTexture().getPointer());
        if(!texture || texture->ogreTexture.isNull())return 10;
        // Native factory completes levels before renderer attaches backend resources.
        for(int i=0;i<12;++i)material->appendEmptyLevel();
        if(!material->detailLevel(-1) || material->detailLevel(1)!=0)return 11;
        level=dynamic_cast<Material::Level*>(&material->getLevel(0));
        Ogre::String name="native_material_"+Ogre::StringConverter::toString(cycle);
        level->backend=Ogre::MaterialManager::getSingleton().create(name,"General");
        Ogre::MaterialPtr retained=level->backend;
        G3D::WeakReferenceCountedPointer<MaterialBase> weak=material;
        material=MaterialRef();
        if(weak.createStrongPtr().isNull())return 12;
        same=MaterialRef();
        if(weak.createStrongPtr().notNull() || !Ogre::MaterialManager::getSingleton().getByName(name).isNull() || retained->getName()!=name)return 13;
        retained.setNull();
        Attributes invisible={RBX::BrickColor(),1,0},translucent={RBX::BrickColor(),.3f,.5f};
        MaterialRef hidden=factory.getMegaMaterial(invisible),alpha=factory.getMegaMaterial(translucent);
        if(hidden->detailLevel(0) || !alpha->veryTransparent() || alpha->getLevel(0).reflect()!=.5f)return 14;
    }
    {
        MaterialRef probe=new Material;
        void** slots=*reinterpret_cast<void***>(probe.getPointer());
        typedef const MaterialBase::Level& (__thiscall *PlainSlot)(MaterialBase*,G3D::Color3,float,float,float,float);
        typedef const MaterialBase::Level& (__thiscall *TexturedSlot)(MaterialBase*,TextureRef,G3D::Color3,float,float,float,float);
        TextureRef proxy=new MegaTextureProxy(0,strip);
        reinterpret_cast<PlainSlot>(slots[2])(probe.getPointer(),G3D::Color3::white(),.9f,50,0,0);
        reinterpret_cast<TexturedSlot>(slots[3])(probe.getPointer(),proxy,G3D::Color3::white(),.9f,50,0,0);
        if(probe->levelCount()!=2 || probe->getLevel(0).baseTexture().notNull() || probe->getLevel(1).baseTexture().getPointer()!=proxy.getPointer())return 19;
    }
    // Original renderer state: all levels are created before backend binding.
    for(int kind=0;kind<=4;++kind){
        MaterialRef probe=new Material;
        TextureRef proxy=new MegaTextureProxy(0,strip);
        probe->appendLevel(proxy,G3D::Color3(.2f,.3f,.4f),.9f,50,0,0);
        probe->appendLevel(G3D::Color3::white(),.6f,30,0,.3f);
        Ogre::MaterialPtr backend=prepareBackend(*probe,0,kind,2,.125f,"");
        if(backend.isNull() || prepareBackend(*probe,0,kind,2,.125f,"").getPointer()!=backend.getPointer())return 20;
        Ogre::Technique* technique=backend->getTechnique(0);
        if(technique->getNumPasses()!=2)return 21;
        Ogre::Pass* opaque=technique->getPass(0),*alpha=technique->getPass(1);
        if(!opaque->getLightingEnabled() || opaque->getDiffuse()!=Ogre::ColourValue(.2f,.3f,.4f,1) || opaque->getAmbient()!=Ogre::ColourValue(.2f,.3f,.4f))return 22;
        if(opaque->getShininess()!=(kind==2?40.0f:kind==1 || kind==3?18.0f:10.0f) || opaque->getDepthWriteEnabled()!=(kind!=4))return 23;
        if(opaque->getNumTextureUnitStates()!=1 || opaque->getTextureUnitState(0)->getTextureName()!="TextureAtlas" || opaque->getDepthBiasConstant()!=-2)return 24;
        if(alpha->getDepthWriteEnabled() || alpha->getSourceBlendFactor()!=static_cast<Ogre::SceneBlendFactor>(7) || alpha->getDestBlendFactor()!=static_cast<Ogre::SceneBlendFactor>(9) || alpha->getDiffuse().a!=.7f)return 25;
    }
    // 007ace40 copies backend refs; 007ad310 still unregisters on each destructor.
    // Preserve this target behavior instead of inventing move/last-ref semantics.
    {
        Material::Level original;
        original.backend=Ogre::MaterialManager::getSingleton().create("native_copy_contract","General");
        {Material::Level copy(original);if(copy.backend.getPointer()!=original.backend.getPointer())return 16;}
        if(!Ogre::MaterialManager::getSingleton().getByName("native_copy_contract").isNull() || original.backend->getName()!="native_copy_contract")return 17;
    }
    for(int i=0;i<32;++i)collectUnusedTextures();
    if(!Ogre::TextureManager::getSingleton().getByName("TextureAtlas").isNull())return 15;
    std::printf("PASS: native proxy/Level dispatch, real atlas resolution, 32 weak-cache/backend lifetimes, resource GC\n");
    return 0;
}
