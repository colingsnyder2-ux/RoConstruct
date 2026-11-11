// Existing 007add10 shading and 007ae4e0 palette expansion/upload bodies.
// Only receiver/declaration bindings change; original proxy layout is not claimed.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerTextureAtlas.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/g3dmath.h>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstddef>

typedef char GImageSize[sizeof(G3D::GImage)==0x14?1:-1];
typedef char GImageWidth[offsetof(G3D::GImage,width)==8?1:-1];
typedef char GImageHeight[offsetof(G3D::GImage,height)==0x0c?1:-1];
typedef char GImageChannels[offsetof(G3D::GImage,channels)==0x10?1:-1];
typedef char PackedColour[sizeof(G3D::Color3uint8)==3?1:-1];
namespace PlayerTextureAtlas {
void shadePixel(const G3D::Color3uint8& base,G3D::Color3uint8& lighting){
    for(int i=0;i<3;++i){
        const int shade=lighting[i];
        float color=base[i];
        if(shade>130){
            float a=std::min(float((shade-128.0f)/128.0f),1.0f);
            color=(1.0-a)*color+255.0f*a;
        }else if(shade<126){
            float a=shade/128.0f;
            a=0.5+a*0.5;
            color=color*a;
        }
        lighting[i]=std::min(255,std::max(0,G3D::iRound(255.0*pow(color/255.0,1.0))));
    }
}
void build(const G3D::GImage& strip,G3D::GImage& atlas){
    const size_t strips=32; // 007ae4e0 multiplies source width by 0x20.
    size_t count=std::min(strips,RBX::BrickColor::colorPalette().size());
    atlas.resize(strip.width*strips,strip.height,3);
    for(size_t i=0;i<count;++i){
        G3D::Color3uint8 color(RBX::BrickColor::colorPalette()[i].color3());
        G3D::Color3uint8 table[256];
        for(size_t j=0;j<256;++j){table[j]=G3D::Color3uint8(j,j,j);shadePixel(color,table[j]);}
        for(int x=0;x<strip.width;++x)
            for(int y=0;y<strip.height;++y)
                atlas.pixel3(x+i*strip.width,y)=table[strip.pixel3(x,y).r];
    }
}
Ogre::TexturePtr load(const std::string& filename){
    G3D::GImage strip(filename,G3D::GImage::AUTODETECT),atlas;
    build(strip,atlas);
    Ogre::TexturePtr texture=Ogre::TextureManager::getSingleton().getByName("TextureAtlas");
    if(texture.isNull()){
        Ogre::Image image;
        image.loadDynamicImage(atlas.byte(),atlas.width,atlas.height,1,Ogre::PF_BYTE_RGB,false);
        while(true){
            try{
                texture=Ogre::TextureManager::getSingleton().create("TextureAtlas","General");
                texture->loadImage(image);
                break;
            }catch(...){ // Recovered GPU allocation boundary, 007ae4e0.
                if(image.getWidth()>512 || image.getHeight()>512){
                    Ogre::TextureManager::getSingleton().remove(texture->getHandle());
                    image.resize(image.getWidth()/2,image.getHeight()/2);
                    std::ostringstream message;
                    message<<"Error loading texture. Reduce size to "<<atlas.width<<"x"<<atlas.height<<" and try again\n";
                    Ogre::LogManager::getSingleton().logMessage(message.str());
                }else{
                    Ogre::LogManager::getSingleton().logMessage("Give up on loading texture TextureAtlas");
                    break;
                }
            }
        }
    }
    return texture;
}
}
