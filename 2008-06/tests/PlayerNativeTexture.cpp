// Existing 00551bf0/00551e30/007ade10/007aded0/007aec70/007ae4e0 bodies.
#undef OGRE_NONCLIENT_BUILD
#include "PlayerNativeMaterial.h"
#include "PlayerTextureAtlas.h"
#include "util/StandardOut.h"
#include <OgreHardwarePixelBuffer.h>
#include <OgreBitwise.h>
#include <windows.h>
#include <GL/gl.h>
#include <G3D/GImage.h>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstddef>
#include <vector>
#include <cassert>

typedef char TextureBaseSize[sizeof(PlayerNativeMaterial::TextureProxyBase)==0x30?1:-1];
typedef char TextureBaseName[offsetof(PlayerNativeMaterial::TextureProxyBase,filename)==0x0c?1:-1];
typedef char TextureBaseInt[offsetof(PlayerNativeMaterial::TextureProxyBase,value28)==0x28?1:-1];
typedef char TextureBaseFloat[offsetof(PlayerNativeMaterial::TextureProxyBase,value2c)==0x2c?1:-1];
typedef char TextureSize[sizeof(PlayerNativeMaterial::TextureProxy)==0x60?1:-1];
typedef char TextureLegacy[offsetof(PlayerNativeMaterial::TextureProxy,texture)==0x30?1:-1];
typedef char TextureLoaded[offsetof(PlayerNativeMaterial::TextureProxy,loaded)==0x34?1:-1];
typedef char TextureContext[offsetof(PlayerNativeMaterial::TextureProxy,context)==0x38?1:-1];
typedef char TextureTiled[offsetof(PlayerNativeMaterial::TextureProxy,tiled)==0x3c?1:-1];
typedef char TextureRoot[offsetof(PlayerNativeMaterial::TextureProxy,root)==0x40?1:-1];
typedef char TextureShade[offsetof(PlayerNativeMaterial::TextureProxy,shadeTexture)==0x44?1:-1];
typedef char TextureColour[offsetof(PlayerNativeMaterial::TextureProxy,shadeColor)==0x48?1:-1];
typedef char TextureBackend[offsetof(PlayerNativeMaterial::TextureProxy,ogreTexture)==0x54?1:-1];
typedef char MegaSize[sizeof(PlayerNativeMaterial::MegaTextureProxy)==0x64?1:-1];
typedef char MegaWidth[offsetof(PlayerNativeMaterial::MegaTextureProxy,stripWidth)==0x60?1:-1];

static void halve1Dimage_ubyte(GLint components, GLuint width, GLuint height,
			       const GLubyte *dataIn, GLubyte *dataOut,
			       GLint element_size, GLint ysize,
			       GLint group_size)
{
   GLint halfWidth= width / 2;
   GLint halfHeight= height / 2;
   const char *src= (const char *) dataIn;
   GLubyte *dest= dataOut;
   int jj;

   assert(width == 1 || height == 1); /* must be 1D */
   assert(width != height);	/* can't be square */

   if (height == 1) {		/* 1 row */
      assert(width != 1);	/* widthxheight can't be 1x1 */
      halfHeight= 1;

      for (jj= 0; jj< halfWidth; jj++) {
	 int kk;
	 for (kk= 0; kk< components; kk++) {
	    *dest= (*(const GLubyte*)src +
		 *(const GLubyte*)(src+group_size)) / 2;

	    src+= element_size;
	    dest++;
	 }
	 src+= group_size;	/* skip to next 2 */
      }
      {
	 int padBytes= ysize - (width*group_size);
	 src+= padBytes;	/* for assertion only */
      }
   }
   else if (width == 1) {	/* 1 column */
      int padBytes= ysize - (width * group_size);
      assert(height != 1);	/* widthxheight can't be 1x1 */
      halfWidth= 1;
      /* one vertical column with possible pad bytes per row */
      /* average two at a time */

      for (jj= 0; jj< halfHeight; jj++) {
	 int kk;
	 for (kk= 0; kk< components; kk++) {
	    *dest= (*(const GLubyte*)src + *(const GLubyte*)(src+ysize)) / 2;

	    src+= element_size;
	    dest++;
	 }
	 src+= padBytes; /* add pad bytes, if any, to get to end to row */
	 src+= ysize;
      }
   }

   assert(src == &((const char *)dataIn)[ysize*height]);
   assert((char *)dest == &((char *)dataOut)
	  [components * element_size * halfWidth * halfHeight]);
} /* halve1Dimage_ubyte() */

/* Existing GLU halveImage_ubyte algorithm, including the 1D branch. This integration
   uses ordinary compiler-generated calls; no original register ABI credit claimed. */
static __declspec(noinline) void halveImage_ubyte(GLint components, GLuint width, GLuint height,
			const GLubyte *datain, GLubyte *dataout,
			GLint element_size, GLint ysize, GLint group_size)
{
    int i, j, k;
    int newwidth, newheight;
    int padBytes;
    GLubyte *s;
    const char *t;

    /* handle case where there is only 1 column/row */
    if (width == 1 || height == 1) {
       assert( !(width == 1 && height == 1) ); /* can't be 1x1 */
       halve1Dimage_ubyte(*(volatile GLint*)&components,width,height,*(const GLubyte* volatile*)&datain,*(GLubyte* volatile*)&dataout,
			  *(volatile GLint*)&element_size,*(volatile GLint*)&ysize,*(volatile GLint*)&group_size);
       return;
    }

    newwidth = width / 2;
    newheight = height / 2;
    padBytes = ysize - (width*group_size);
    s = dataout;
    t = (const char *)datain;

    /* Piece o' cake! */
    for (i = 0; i < newheight; i++) {
	for (j = 0; j < newwidth; j++) {
	    for (k = 0; k < components; k++) {
		s[0] = (*(const GLubyte*)t +
			*(const GLubyte*)(t+group_size) +
			*(const GLubyte*)(t+ysize) +
			*(const GLubyte*)(t+ysize+group_size) + 2) / 4;
		s++; t += element_size;
	    }
	    t += group_size;
	}
	t += padBytes;
	t += ysize;
    }
}



namespace Ogre {
void releaseUnusedResources(ResourceManager& manager, const String& type,
                            const StringVector& keepPatterns) {
    StringVector names;
    ResourceManager::ResourceMapIterator it = manager.getResourceIterator();
    while (it.hasMoreElements()) {
        ResourcePtr resource = it.getNext();
        const String& name = resource->getName();
        if (resource.useCount() == ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS + 1
                && resource->getGroup() != ResourceGroupManager::INTERNAL_RESOURCE_GROUP_NAME) {
            for (int i = 0; i < static_cast<int>(keepPatterns.size()); ++i) {
                if (StringUtil::match(name, keepPatterns[i], true))
                    goto nextResource;
            }
            names.push_back(name);
        } else if (resource.useCount() <= ResourceGroupManager::RESOURCE_SYSTEM_NUM_REFERENCE_COUNTS) {
            LogManager::getSingleton().logMessage("Strange rc: " + StringConverter::toString(resource.useCount())
                                                  + "for " + name);
        }
    nextResource:;
    }
    for (int i = 0; i < static_cast<int>(names.size()); ++i) {
        ResourcePtr resource = manager.getByName(names[i]);
        manager.remove(resource);
        if (resource.useCount() != 1)
            LogManager::getSingleton().logMessage(String("Wrong ref count ")
                + StringConverter::toString(resource.useCount()) + " for " + type + " " + resource->getName());
        else
            LogManager::getSingleton().logMessage(String("delete: ") + type + " " + resource->getName());
    }
}
}

namespace PlayerNativeMaterial {
namespace {
bool shadeGroupCreated;
Ogre::String shadeResourceGroup="shadetex"; // Native initializer007f9f80.
int nextPowerOfTwo(int n){if(n<2)return 2;int out=1;while(out<n)out+=out;return out;}
}
TextureProxyBase::TextureProxyBase():value28(1),value2c(1.0f){}
TextureProxyBase::~TextureProxyBase(){} // Interface owns only its real string/ref base.
void TextureProxyBase::setValue28(int value){value28=value;}
int TextureProxyBase::getValue28() const{return value28;}
void TextureProxyBase::setValue2c(float value){value2c=value;}
float TextureProxyBase::getValue2c() const{return value2c;}
TextureProxy::TextureProxy(void* engine,const std::string& file,bool tile):loaded(false),context(engine),tiled(tile){filename=file;}
TextureProxy::TextureProxy(TextureRef parent):loaded(false),context(0),root(parent){filename="";}
TextureProxy::~TextureProxy(){} // 007ae3b0: genuine member/base destructors do the release.
G3D::Vector2 TextureProxy::getSize(){return ogreTexture.isNull()?G3D::Vector2(0,0):G3D::Vector2(ogreTexture->getWidth(),ogreTexture->getHeight());}
TextureRef TextureProxy::shade(const G3D::Color3& color,const TextureRef& parent){
    TextureProxy* nativeParent=dynamic_cast<TextureProxy*>(parent.getPointer());
    G3D::ReferenceCountedPointer<TextureProxy> out=new TextureProxy(TextureRef(nativeParent));
    out->context=context;out->root=nativeParent;out->shadeTexture=this;out->shadeColor=color;
    return TextureRef(out.getPointer());
}
void TextureProxy::shadePixel(const G3D::Color3uint8& base,G3D::Color3uint8& pixel){PlayerTextureAtlas::shadePixel(base,pixel);}
void collectUnusedTextures(){
    static int count=0;
    if(++count%32==0){
        int before=Ogre::TextureManager::getSingleton().getMemoryUsage();
        Ogre::StringVector keep;keep.push_back("*\\content\\*");
        Ogre::releaseUnusedResources(Ogre::TextureManager::getSingleton(),"Texture",keep);
        int after=Ogre::TextureManager::getSingleton().getMemoryUsage();
        Ogre::LogManager::getSingleton().logMessage("Tex usage: "+Ogre::StringConverter::toString(before)+" => "+Ogre::StringConverter::toString(after));
    }
}
MegaTextureProxy::MegaTextureProxy(void* engine,const std::string& file):TextureProxy(engine,file,false),stripWidth(0){}
G3D::TextureRef MegaTextureProxy::resolve(void*){
    if(!loaded){ogreTexture=PlayerTextureAtlas::load(filename);root=0;loaded=true;}
    return texture; // Native Ogre resolution has a side effect; legacy GL ref stays null.
}

bool loadTexture(const Ogre::String& filename, Ogre::Image& image)
{
    const char* extensions[] = {"png","jpg","gif","bmp","tif","tiff","pbm","pgm","tga","dds","xpm","jig","ico"};
    bool success;
    int i = 0;
    do {
        const char* extension = extensions[i];
        unsigned length = strlen(extension);
        success = filename.substr(filename.length() - length - 1).find(Ogre::String(".") + extension) != Ogre::String::npos;
        if (success)
            break;
    } while (++i < 13);
    if (success) {
        success = true;
        try {
            image.load(filename, "General");
        } catch (...) {
            success = false;
        }
    } else {
    int type = G3D::GImage::resolveFormat(filename);
    if (type == 9) {
        RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "Failed to load texture '%s': unknown format", filename.c_str());
        success = false;
    } else {
        const char* ext;
        switch (type) {
        case 0: ext = "jpg"; break;
        case 1: ext = "bmp"; break;
        case 5: ext = "png"; break;
        case 2: ext = "tga"; break;
        case 4: ext = "ico"; break;
        case 3: ext = "pcx"; break;
        case 6: case 7: ext = "ppm"; break;
        }
        try {
            std::ifstream stream;
            stream.open(filename.c_str(), std::ios::in | std::ios::binary);
            Ogre::DataStreamPtr data(new Ogre::FileStreamDataStream(&stream, false));
            image.load(data, ext);
            success = true;
        } catch (...) {
            RBX::StandardOut::singleton()->print(RBX::MESSAGE_ERROR, "Failed to load texture '%s'", filename.c_str());
            success = false;
        }
    }
    }
    return success;
}

G3D::TextureRef TextureProxy::resolve(void* engine) {
    if (!loaded) {
        if (shadeTexture.notNull()) {
            if (!shadeGroupCreated) {
                Ogre::ResourceGroupManager::getSingleton().createResourceGroup(shadeResourceGroup);
                Ogre::ResourceGroupManager::getSingleton().initialiseResourceGroup(shadeResourceGroup);
                shadeGroupCreated = true;
            }
            if (!ogreTexture.isNull())
                Ogre::LogManager::getSingleton().logMessage("RBX Texture " + ogreTexture->getName() + " overwritten");
            char name[1024];
            sprintf(name, "%g%g%gshadeTex", shadeColor.r, shadeColor.g, shadeColor.b);
            ogreTexture = Ogre::TextureManager::getSingleton().getByName(name);
            if (ogreTexture.isNull()) {
                static std::string sourceFilename = shadeTexture->filename;
                static G3D::GImage sourceImage(sourceFilename, G3D::GImage::AUTODETECT);
                Ogre::Image image;
                image.load(shadeTexture->filename, "General");
                G3D::Color3uint8 lookup[256];
                for (int i = 0; i < 256; ++i) {
                    lookup[i].r = lookup[i].g = lookup[i].b = i;
                    shadePixel(shadeColor, lookup[i]);
                }
                int count = image.getHeight() * image.getWidth();
                for (int i = 0; i < count; ++i) {
                    unsigned char* pixel = image.getData() + i*3;
                    *reinterpret_cast<G3D::Color3uint8*>(pixel) = lookup[pixel[0]];
                }
                Ogre::Image finalImage;
                std::vector<unsigned char> mipData;
                if (!*reinterpret_cast<bool*>(reinterpret_cast<char*>(engine)+0x805)) {
                    int width = image.getWidth();
                    int height = image.getHeight();
                    int mipmaps = Ogre::Bitwise::getBitShift(Ogre::Bitwise::firstPO2From((width > height ? width : height)));
                    mipData.resize(Ogre::Image::calculateSize(mipmaps, 1, width, height, 1, Ogre::PF_B8G8R8));
                    unsigned char* output = &mipData[0];
                    unsigned char* previous = 0;
                    int previousWidth = -1, previousHeight = -1;
                    for (int level = 0; level <= mipmaps; ++level) {
                        if (level == 0)
                            memcpy(&mipData[0], image.getData(), width*height*3);
                        else
                            halveImage_ubyte(3, previousWidth, previousHeight, previous, output,
                                             1, previousWidth*3, 3);
                        previous = output;
                        output += width*height*3;
                        previousWidth = width;
                        previousHeight = height;
                        if (width > 1) width /= 2;
                        if (height > 1) height /= 2;
                    }
                    finalImage.loadDynamicImage(&mipData[0], image.getWidth(), image.getHeight(), 1,
                                                 Ogre::PF_B8G8R8, false, 1, mipmaps);
                } else {
                    size_t h = image.getHeight();
                    size_t w = image.getWidth();
                    unsigned char* d = image.getData();
                    finalImage.loadDynamicImage(d, w, h, 1, Ogre::PF_B8G8R8, false, 1, 0);
                }
                std::string textureName(name);
                ogreTexture = Ogre::TextureManager::getSingleton().create(textureName, shadeResourceGroup, false, 0, 0);
                ogreTexture->loadImage(finalImage);
                root = 0;
                loaded = true;
                Ogre::LogManager::getSingleton().logMessage(std::string("create shadetex=") + ogreTexture->getName() + "\n");
                collectUnusedTextures();
            }
        } else if (root.isNull()) {
          if (filename == "") {
            Ogre::LogManager::getSingleton().logMessage("filename is empty in resolve()\n");
        } else {
            Ogre::Image image;
            ogreTexture = Ogre::TextureManager::getSingleton().getByName(filename);
            if (ogreTexture.isNull()) {
                if (!loadTexture(filename, image)) {
                    ogreTexture.setNull();
                } else if (image.getFormat() && image.getWidth() > 0 && image.getHeight() > 0) {
                    int aaMode = *reinterpret_cast<int*>(reinterpret_cast<char*>(engine)+0x800);
                    if (aaMode == 1) {
                        int width = nextPowerOfTwo(image.getWidth());
                        int height = nextPowerOfTwo(image.getHeight());
                        if (width != image.getWidth() || height != image.getHeight()) {
                            Ogre::LogManager::getSingleton().logMessage("Texture resized (AA): ("
                                + Ogre::StringConverter::toString(image.getWidth()) + ","
                                + Ogre::StringConverter::toString(image.getHeight()) + ") -> ("
                                + Ogre::StringConverter::toString(width) + ","
                                + Ogre::StringConverter::toString(height) + ")");
                            image.resize(width, height, Ogre::Image::FILTER_BILINEAR);
                        }
                    }
                    // Native deliberately calls getWidth twice at 007af654/679.
                    float widthLimit = 512.0f / image.getWidth();
                    float heightLimit = 512.0f / image.getWidth();
                    float scale = std::min(heightLimit, widthLimit);
                    scale = std::min(scale, *reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x2c));
                    if (image.getWidth() > 128 && image.getHeight() > 128 && scale < 1.0f) {
                        int width = image.getWidth() * scale;
                        int height = image.getHeight() * scale;
                        Ogre::LogManager::getSingleton().logMessage("Texture resized (limit): ("
                            + Ogre::StringConverter::toString(image.getWidth()) + ","
                            + Ogre::StringConverter::toString(image.getHeight()) + ") -> ("
                            + Ogre::StringConverter::toString(width) + ","
                            + Ogre::StringConverter::toString(height) + ")");
                        image.resize(width, height, Ogre::Image::FILTER_BILINEAR);
                    }
                    try {
                        ogreTexture = Ogre::TextureManager::getSingleton().create(filename, "General", false, 0, 0);
                        ogreTexture->loadImage(image);
                        Ogre::LogManager::getSingleton().logMessage(std::string("create tex=") + ogreTexture->getName());
                    } catch (Ogre::Exception& error) {
                        ogreTexture.setNull();
                        // Preserve the observed name access after setNull; no
                        // invented fallback replaces the target's failure path.
                        Ogre::LogManager::getSingleton().logMessage(std::string("RBX failed to load ")
                            + ogreTexture->getName() + " what(): " + error.what());
                    }
                    collectUnusedTextures();
                }
            }
        }
        } else {
            G3D::TextureRef resolved=root->resolve(engine);
            if (resolved.notNull() && !resolved->opaque())
                texture=resolved->alphaOnlyVersion();
        }
        if (ogreTexture.isNull())
            Ogre::LogManager::getSingleton().logMessage("RBX texture not loaded in resolve()\n");
        root = 0;
        shadeTexture = 0;
        loaded = true;
    }
    return texture;
}
}
