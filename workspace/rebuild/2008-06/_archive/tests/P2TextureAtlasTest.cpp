#undef OGRE_NONCLIENT_BUILD
#include "PlayerTextureAtlas.h"
#include "v8datamodel/BrickColor.h"
#include <OgreHardwarePixelBuffer.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <float.h>
#undef main
int main(){
    std::setvbuf(stdout,0,_IONBF,0);
    const char* filename=getenv("ROC_TEXTURE_STRIP");
    if(!filename){std::printf("ROC_TEXTURE_STRIP must name a real SurfacesStrip.png dependency\n");return 1;}
    G3D::Color3uint8 base(80,120,200);
    const unsigned char shades[]={0,125,126,128,130,131,255};
    const unsigned char expected[][3]={{40,60,100},{79,119,198},{80,120,200},{80,120,200},{80,120,200},{84,123,201},{254,254,255}};
    for(int i=0;i<7;++i){
        G3D::Color3uint8 pixel(shades[i],shades[i],shades[i]);PlayerTextureAtlas::shadePixel(base,pixel);
        if(std::memcmp(&pixel,expected[i],3))return 2;
    }
    std::printf("shade anchors PASS; loading %s\n",filename);
    G3D::GImage strip(filename),atlas;
    std::printf("strip=%dx%dx%d palette=%u\n",strip.width,strip.height,strip.channels,static_cast<unsigned>(RBX::BrickColor::colorPalette().size()));
    PlayerTextureAtlas::build(strip,atlas);
    unsigned beforeDevice=_controlfp(0,0);
    if(RBX::BrickColor::colorPalette().size()!=32 || atlas.width!=32*strip.width || atlas.height!=strip.height || atlas.channels!=3)return 3;
    // A neutral source texel must reproduce each BrickColor palette entry.
    bool neutral=false;
    for(int y=0;y<strip.height && !neutral;++y)for(int x=0;x<strip.width && !neutral;++x)
        if(strip.pixel3(x,y).r==128){
            neutral=true;
            for(int i=0;i<32;++i){
                G3D::Color3uint8 color(RBX::BrickColor::colorPalette()[i].color3());
                if(std::memcmp(&atlas.pixel3(x+i*strip.width,y),&color,3))return 4;
            }
        }
    if(!neutral)return 5;
    Ogre::Root root("","","p2-texture-atlas.log");root.loadPlugin("rgdx.dll");
    Ogre::RenderSystemList* list=root.getAvailableRenderers();Ogre::RenderSystem* renderer=0;
    for(size_t i=0;i<list->size();++i)if((*list)[i]->getName().find("Direct3D9")!=std::string::npos)renderer=(*list)[i];
    if(!renderer)return 6;
    root.setRenderSystem(renderer);renderer->setConfigOption("Full Screen","No");root.initialise(false);
    Ogre::NameValuePairList options;options["hidden"]="true";root.createRenderWindow("P2TextureAtlas",64,64,false,&options);
    G3D::GImage runtimeAtlas;PlayerTextureAtlas::build(strip,runtimeAtlas);
    std::printf("FPU before=%08x after=%08x cpu_changed=%d\n",beforeDevice,_controlfp(0,0),std::memcmp(atlas.byte(),runtimeAtlas.byte(),atlas.width*atlas.height*3)!=0);
    Ogre::TexturePtr texture=PlayerTextureAtlas::load(filename),again=PlayerTextureAtlas::load(filename);
    if(texture.isNull() || texture.getPointer()!=again.getPointer() || texture->getWidth()!=atlas.width || texture->getHeight()!=atlas.height)return 7;
    std::vector<unsigned char> pixels(atlas.width*atlas.height*3);
    texture->getBuffer()->blitToMemory(Ogre::PixelBox(atlas.width,atlas.height,1,Ogre::PF_BYTE_RGB,&pixels[0]));
    if(std::memcmp(&pixels[0],runtimeAtlas.byte(),pixels.size())){
        for(size_t i=0;i<pixels.size();++i)if(pixels[i]!=runtimeAtlas.byte()[i]){
            std::printf("GPU format=%d first difference byte=%u cpu=%u gpu=%u\n",texture->getFormat(),static_cast<unsigned>(i),runtimeAtlas.byte()[i],pixels[i]);break;
        }
        return 8;
    }
    runtimeAtlas.save("texture-atlas-cpu.png",G3D::GImage::PNG);
    Ogre::Image readback;
    readback.loadDynamicImage(&pixels[0],atlas.width,atlas.height,1,Ogre::PF_BYTE_RGB,false);
    readback.save("texture-atlas-gpu.png");
    std::printf("GPU atlas=%ux%u format=%d bytes_equal=1\n",texture->getWidth(),texture->getHeight(),texture->getFormat());
    Ogre::ResourceHandle handle=texture->getHandle();texture.setNull();again.setNull();
    Ogre::TextureManager::getSingleton().remove(handle);
    if(!Ogre::TextureManager::getSingleton().getByName("TextureAtlas").isNull())return 9;
    bool failed=false;
    try{PlayerTextureAtlas::load("missing-required-atlas-strip.png");}catch(const G3D::GImage::Error&){failed=true;}
    if(!failed)return 10;
    std::printf("PASS: recovered shade anchors, 32 palette columns, GPU RGB readback, cache identity, teardown and missing file\n");
    return 0;
}
