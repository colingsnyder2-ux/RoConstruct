// from server: 100% by king_originala
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <algorithm>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct __declspec(dllimport) ImportedString {char storage[28];ImportedString(const char*);~ImportedString()throw();};
namespace G3D {
struct WeakPtr {virtual ~WeakPtr(){} virtual void objectCollected()=0;};
struct WeakNode {WeakPtr*weakPtr;WeakNode*next;};
struct AtomicInt32 {volatile long value;void increment(){InterlockedIncrement(&value);}unsigned decrement(){return InterlockedDecrement(&value)!=0;}};
struct RefObject {
 AtomicInt32 references;WeakNode*weak;
 virtual ~RefObject(){}
 void zeroWeakPointers(){WeakNode*node=weak;while(node){node->weakPtr->objectCollected();WeakNode*tmp=node;node=node->next;delete tmp;}}
};
template<class T>struct ReferenceCountedPointer {
 T*pointer;
 ReferenceCountedPointer():pointer(0){}
 ReferenceCountedPointer(const ReferenceCountedPointer&r):pointer(0){setPointer(r.pointer);}
 ~ReferenceCountedPointer(){zeroPointer();}
 void zeroPointer(){if(pointer){if(pointer->references.decrement()==0){pointer->zeroWeakPointers();delete pointer;}pointer=0;}}
 void setPointer(T*p){if(p!=pointer){zeroPointer();if(p){pointer=p;pointer->references.increment();}}}
 const ReferenceCountedPointer&operator=(const ReferenceCountedPointer&r){setPointer(r.pointer);return *this;}
 ReferenceCountedPointer&operator=(T*p){setPointer(p);return *this;}
};
struct Color3 {float r,g,b;};
struct Color3uint8 {
 unsigned char r,g,b;
 Color3uint8():r(0),g(0),b(0){}
 Color3uint8(unsigned char a,unsigned char c,unsigned char d):r(a),g(c),b(d){}
 Color3uint8(const Color3&);
};
struct GImage {
 unsigned char*bytes;int width,height,channels;
 virtual ~GImage();
 enum Format {JPEG,BMP,TGA,PCX,ICO,PNG,PPM_ASCII,PPM,AUTODETECT,UNKNOWN};
 GImage(const ImportedString&,Format);
 GImage(int,int,int);
 Color3uint8*pixel3(){return (Color3uint8*)bytes;}
 Color3uint8&pixel3(int x,int y){return pixel3()[x+y*width];}
};
struct TextureFormat {static const TextureFormat*RGB8;};
struct Texture:RefObject {
 virtual ~Texture();
 enum Dimension {DIM_2D=2};
 struct Settings {int interpolateMode,wrapMode,depthReadMode;float maxAnisotropy;bool autoMipMap;int maxMipMap,minMipMap;Settings();};
 static ReferenceCountedPointer<Texture>fromGImage(const ImportedString&,const GImage&,const TextureFormat*,Dimension,const Settings&);
};
struct RenderDevice;
}
namespace RBX {
struct BrickColor {
 int number;
 static const unsigned paletteSize;
 static const std::vector<BrickColor>&colorPalette();
 G3D::Color3 color3()const;
};
const unsigned BrickColor::paletteSize=32;
namespace Render {
struct TextureProxy:G3D::RefObject {
 ImportedString filename;char measuredBaseTail[8];
 G3D::ReferenceCountedPointer<G3D::Texture>texture;
 bool loaded;char unaccessed[0x40-0x35];
 G3D::ReferenceCountedPointer<TextureProxy>root;
 virtual ~TextureProxy();
 static void shadePixel(const G3D::Color3uint8&,G3D::Color3uint8&);
};
struct MegaTextureProxy:TextureProxy {G3D::ReferenceCountedPointer<G3D::Texture>resolve(G3D::RenderDevice*);};
G3D::ReferenceCountedPointer<G3D::Texture>MegaTextureProxy::resolve(G3D::RenderDevice*){
 if(!loaded){
  unsigned count=std::min(BrickColor::paletteSize,static_cast<unsigned>(BrickColor::colorPalette().size()));
  G3D::GImage bumpImage(filename,G3D::GImage::AUTODETECT);
  int imageWidth=bumpImage.width*32;
  G3D::GImage megaImage(imageWidth,bumpImage.height,3);
  for(unsigned i=0;i<count;++i){
   G3D::Color3uint8 base(BrickColor::colorPalette()[i].color3());
   G3D::Color3uint8 colorTable[256];
   for(unsigned j=0;j<256;++j){
    colorTable[j]=G3D::Color3uint8((unsigned char)j,(unsigned char)j,(unsigned char)j);
    shadePixel(base,colorTable[j]);
   }
   for(int x=0;x<bumpImage.width;++x)
    for(int y=0;y<bumpImage.height;++y)
     {
      const G3D::Color3uint8&source=bumpImage.pixel3(x,y);
      G3D::Color3uint8&destination=megaImage.pixel3(x+i*bumpImage.width,y);
      destination=colorTable[source.r];
     }
  }
  {
  G3D::Texture::Settings settings;
  settings.wrapMode=0;
  ImportedString name("MegaTexture");
  texture=G3D::Texture::fromGImage(name,megaImage,G3D::TextureFormat::RGB8,G3D::Texture::DIM_2D,settings);
  }
  root=0;
  loaded=true;
 }
 return texture;
}
}
}
