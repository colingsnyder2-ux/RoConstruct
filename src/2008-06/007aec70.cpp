// from server: 100% by EspClaude
// from server: 74% by EspClaude
// from server: 72% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_98050a82ffd411bb.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG 1
#include <assert.h>
#include <windows.h>
#include <GL/gl.h>
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

/* Stand-in for GLU halveImage_ubyte (exe 007ada80, separate TU built with /arch:SSE2; its
   custom register convention is eax=width, edx=height). The 1D branch is omitted here so this
   x87 TU derives the same convention at the call site; 007ada80 itself is matched separately. */
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


#undef OGRE_NONCLIENT_BUILD
#include <RbxGraphics/TextureProxyBase.h>
#include <G3D/Color3uint8.h>
#include <G3D/Color3.h>
#include <G3D/GImage.h>
#include <GLG3D/Texture.h>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreImage.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreTextureManager.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreResourceGroupManager.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreBitwise.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreLogManager.h"
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreStringConverter.h"
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <exception>
#include "../../../libs/ogre-1.4.5/ogrenew/OgreMain/include/OgreException.h"

namespace RBX { namespace RenderNew {
class VisualEngine;
extern bool shadeGroupCreated;
extern Ogre::String shadeResourceGroup;
bool loadTexture(const std::string&, Ogre::Image&);
int __fastcall nextPowerOfTwo(int);
void collectUnusedTextures();

// Actual native TextureProxyBase ancestry and intrusive reference prefix.
// Native-only members are accessed by observed typed views, not invented layout.
class TextureProxy : public TextureProxyBase {
public:
    G3D::TextureRef resolve(VisualEngine*);
    static void shadePixel(const G3D::Color3uint8&, G3D::Color3uint8&);
};

G3D::TextureRef TextureProxy::resolve(VisualEngine* engine) {
#define loaded (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this)+0x34))
#define texture (*reinterpret_cast<G3D::TextureRef*>(reinterpret_cast<char*>(this)+0x30))
#define root (*reinterpret_cast<G3D::ReferenceCountedPointer<TextureProxy>*>(reinterpret_cast<char*>(this)+0x40))
#define shadeTexture (*reinterpret_cast<G3D::ReferenceCountedPointer<TextureProxy>*>(reinterpret_cast<char*>(this)+0x44))
#define shadeColor (*reinterpret_cast<const G3D::Color3*>(reinterpret_cast<char*>(this)+0x48))
#define ogreTexture (*reinterpret_cast<Ogre::TexturePtr*>(reinterpret_cast<char*>(this)+0x54))
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
            // Observed virtual slot 0x18; class-return calling convention.
            struct ResolveView {
                virtual void slot0()=0; virtual void slot1()=0; virtual void slot2()=0;
                virtual void slot3()=0; virtual void slot4()=0; virtual void slot5()=0;
                virtual G3D::TextureRef resolve(VisualEngine*)=0;
            };
            G3D::TextureRef resolved=reinterpret_cast<ResolveView*>(root.getPointer())->resolve(engine);
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
} }

#undef loaded
#undef texture
#undef root
#undef shadeTexture
#undef shadeColor
#undef ogreTexture


