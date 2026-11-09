// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_e9f9dfe69397faf1.cpp

// Candidate translation unit (score above; library headers required).
// Binary-derived legacy atlas migration; API/layout from authentic headers.
// Coordinates are observed call arguments, not raw target bytes.
#include <G3D/GImage.h>
#include <util/Name.h>
#include <string>
using namespace G3D;
namespace G3D { void setPixel(GImage&,int,int,Color4uint8); }
extern bool compareFiles(const std::string&,const std::string&);
// Native cdecl calls have nine and six stack arguments, respectively.
extern bool rotatedPaste(GImage&,const GImage&,int,int,int,int,int,int,int);
extern void rotateRegion(GImage&,int,int,int,int,int);
static inline int box4(const unsigned char* a,const unsigned char* b,int ch){ return a[0]+a[ch]+b[0]+b[ch]; }
std::string migrateAtlas(std::string filename,const RBX::Name& mime,bool,float scale) {
    GImage original;
    std::string cache=filename+"0xdecafbad";
    if(compareFiles(cache,filename)) return cache;
    GImage::Format format=GImage::UNKNOWN;
    if(mime.toString().compare("image/png") == 0) format=GImage::PNG;
    if(mime.toString().compare("image/jpeg") == 0) format=GImage::JPEG;
    if(mime.toString().compare("image/tga") == 0) format=GImage::TGA;
    if(mime.toString().compare("image/bmp") == 0) format=GImage::BMP;
    if(format==GImage::UNKNOWN) format=GImage::resolveFormat(filename);
    if(format!=GImage::UNKNOWN) original=GImage(filename,format);
    if(format==GImage::UNKNOWN || original.width!=585 || original.height!=559) {

        original=GImage(8,8,4);
        Color4uint8 blank(0,0,0,0);
        for(int x=0;x<8;++x)
            for(int y=0;y<8;++y) setPixel(original,x,y,blank);
        original.save(cache+"blank",GImage::PNG);
        return cache+"blank";
    }

    GImage atlas(408,408,4);
    original.convertToRGBA();
    GImage::pasteSubImage(atlas,original,138,4,165,74,64,128);
    rotatedPaste(atlas,atlas,0,70,138,4,64,4,90);
    rotatedPaste(atlas,atlas,0,2,138,128,64,4,90);
    GImage::pasteSubImage(atlas,atlas,404,4,138,4,4,128);
    GImage::pasteSubImage(atlas,atlas,0,140,198,4,4,128);
    GImage::pasteSubImage(atlas,original,4,140,231,74,128,128);
    GImage::pasteSubImage(atlas,atlas,4,134,4,142,128,2);
    GImage::pasteSubImage(atlas,atlas,4,0,4,266,128,2);
    GImage::pasteSubImage(atlas,atlas,202,4,4,140,2,128);
    GImage::pasteSubImage(atlas,atlas,204,4,130,140,2,128);
    GImage::pasteSubImage(atlas,original,206,4,361,74,64,128);
    rotatedPaste(atlas,atlas,132,70,206,4,64,4,90);
    rotatedPaste(atlas,atlas,132,2,206,128,64,4,90);
    GImage::pasteSubImage(atlas,atlas,132,140,206,4,4,128);
    GImage::pasteSubImage(atlas,atlas,272,4,266,4,4,128);
    GImage::pasteSubImage(atlas,original,276,4,427,74,128,128);
    GImage strip2(128,2,4);
    GImage::pasteSubImage(strip2,atlas,0,0,276,4,128,2);
    GImage::flipRGBAVertical(strip2.byte(),strip2.byte(),128,2);
    GImage::pasteSubImage(atlas,strip2,4,68,0,0,128,2);
    rotatedPaste(atlas,atlas,4,66,276,130,128,2,180);
    GImage::pasteSubImage(atlas,atlas,270,4,276,4,2,128);
    GImage::pasteSubImage(atlas,atlas,136,4,402,4,2,128);
    GImage::pasteSubImage(atlas,original,4,70,231,8,128,64);
    GImage strip4(128,4,4);
    GImage::pasteSubImage(strip4,atlas,0,0,4,70,128,4);
    GImage::flipRGBAVertical(strip4.byte(),strip4.byte(),128,4);
    GImage::pasteSubImage(atlas,strip4,276,0,0,0,128,4);
    GImage::pasteSubImage(atlas,atlas,4,136,4,128,128,4);
    rotatedPaste(atlas,atlas,138,0,4,70,4,64,90);
    rotatedPaste(atlas,atlas,206,0,128,70,4,64,-90);
    GImage::pasteSubImage(atlas,original,4,2,231,204,128,64);
    GImage::pasteSubImage(atlas,atlas,4,268,4,2,128,4);
    rotatedPaste(atlas,atlas,276,132,4,62,128,4,180);
    rotatedPaste(atlas,atlas,138,132,4,2,4,64,-90);
    rotatedPaste(atlas,atlas,206,132,128,2,4,64,90);
    GImage::pasteSubImage(atlas,original,138,140,19,355,64,128);
    rotatedPaste(atlas,atlas,66,274,138,140,64,2,90);
    rotatedPaste(atlas,atlas,66,342,138,266,64,2,-90);
    GImage::pasteSubImage(atlas,atlas,406,140,138,140,2,128);
    GImage::pasteSubImage(atlas,atlas,204,140,200,140,2,128);
    GImage::pasteSubImage(atlas,original,206,140,85,355,64,128);
    rotatedPaste(atlas,atlas,2,272,206,140,64,2,180);
    rotatedPaste(atlas,atlas,2,406,206,266,64,2,180);
    GImage::pasteSubImage(atlas,atlas,202,140,206,140,2,128);
    GImage::pasteSubImage(atlas,atlas,272,140,268,140,2,128);
    GImage::pasteSubImage(atlas,original,274,140,151,355,64,128);
    rotatedPaste(atlas,atlas,0,274,274,140,64,2,-90);
    rotatedPaste(atlas,atlas,0,342,274,266,64,2,90);
    GImage::pasteSubImage(atlas,atlas,270,140,274,140,2,128);
    GImage::pasteSubImage(atlas,atlas,340,140,336,140,2,128);
    GImage::pasteSubImage(atlas,original,342,140,217,355,64,128);
    GImage::pasteSubImage(atlas,atlas,2,338,342,140,64,2);
    GImage::pasteSubImage(atlas,atlas,2,340,342,266,64,2);
    GImage::pasteSubImage(atlas,atlas,338,140,342,140,2,128);
    GImage::pasteSubImage(atlas,atlas,136,140,404,140,2,128);
    GImage::pasteSubImage(atlas,original,2,274,217,289,64,64);
    rotatedPaste(atlas,atlas,206,136,2,274,64,4,180);
    GImage::pasteSubImage(atlas,atlas,342,136,2,334,64,4);
    rotatedPaste(atlas,atlas,274,136,2,274,4,64,90);
    rotatedPaste(atlas,atlas,138,136,62,274,4,64,-90);
    GImage::pasteSubImage(atlas,original,2,342,217,485,64,64);
    GImage::pasteSubImage(atlas,atlas,342,268,2,342,64,4);
    rotatedPaste(atlas,atlas,206,268,2,402,64,4,180);
    rotatedPaste(atlas,atlas,274,268,2,342,4,64,-90);
    rotatedPaste(atlas,atlas,138,268,62,342,4,64,-90);
    GImage::pasteSubImage(atlas,original,138,276,308,355,64,128);
    GImage::pasteSubImage(atlas,atlas,70,338,138,276,64,2);
    GImage::pasteSubImage(atlas,atlas,70,340,138,402,64,2);
    GImage::pasteSubImage(atlas,atlas,406,276,138,276,2,128);
    GImage::pasteSubImage(atlas,atlas,204,276,200,276,2,128);
    GImage::pasteSubImage(atlas,original,206,276,374,355,64,128);
    rotatedPaste(atlas,atlas,134,274,206,276,64,2,90);
    rotatedPaste(atlas,atlas,134,342,206,402,64,2,-90);
    GImage::pasteSubImage(atlas,atlas,202,276,206,276,2,128);
    GImage::pasteSubImage(atlas,atlas,272,276,268,276,2,128);
    GImage::pasteSubImage(atlas,original,274,276,440,355,64,128);
    rotatedPaste(atlas,atlas,70,272,274,276,64,2,180);
    rotatedPaste(atlas,atlas,70,406,274,402,64,2,180);
    GImage::pasteSubImage(atlas,atlas,270,276,274,276,2,128);
    GImage::pasteSubImage(atlas,atlas,340,276,336,276,2,128);
    GImage::pasteSubImage(atlas,original,342,276,506,355,64,128);
    rotatedPaste(atlas,atlas,68,274,342,276,64,2,-90);
    rotatedPaste(atlas,atlas,68,342,342,402,64,2,-90);
    GImage::pasteSubImage(atlas,atlas,338,276,342,276,2,128);
    GImage::pasteSubImage(atlas,atlas,136,276,404,276,2,128);
    GImage::pasteSubImage(atlas,original,70,274,308,289,64,64);
    rotatedPaste(atlas,atlas,274,272,70,274,64,4,180);
    GImage::pasteSubImage(atlas,atlas,138,272,70,334,64,4);
    rotatedPaste(atlas,atlas,342,272,70,274,4,64,-90);
    rotatedPaste(atlas,atlas,206,272,130,274,4,64,-90);
    GImage::pasteSubImage(atlas,original,70,342,308,485,64,64);
    GImage::pasteSubImage(atlas,atlas,138,404,70,342,64,4);
    rotatedPaste(atlas,atlas,274,404,70,402,64,4,180);
    rotatedPaste(atlas,atlas,342,404,70,342,4,64,-90);
    rotatedPaste(atlas,atlas,206,404,130,342,4,64,90);
    rotateRegion(atlas,201,0,3,5,0);
    rotateRegion(atlas,136,0,3,5,-90);
    rotateRegion(atlas,136,131,3,5,180);
    rotateRegion(atlas,201,131,3,5,90);
    rotateRegion(atlas,131,136,5,5,0);
    rotateRegion(atlas,0,136,5,5,-90);
    rotateRegion(atlas,0,267,5,5,180);
    rotateRegion(atlas,131,267,5,5,90);
    rotateRegion(atlas,269,0,3,5,0);
    rotateRegion(atlas,204,0,3,5,-90);
    rotateRegion(atlas,204,131,3,5,180);
    rotateRegion(atlas,269,131,3,5,90);
    rotateRegion(atlas,403,0,5,5,0);
    rotateRegion(atlas,272,0,5,5,-90);
    rotateRegion(atlas,272,131,5,5,180);
    rotateRegion(atlas,403,131,5,5,90);
    rotateRegion(atlas,131,68,5,3,0);
    rotateRegion(atlas,0,68,5,3,-90);
    rotateRegion(atlas,0,133,5,3,180);
    rotateRegion(atlas,131,133,5,3,90);
    rotateRegion(atlas,131,0,5,3,0);
    rotateRegion(atlas,0,0,5,3,-90);
    rotateRegion(atlas,0,65,5,3,180);
    rotateRegion(atlas,131,65,5,3,90);
    rotateRegion(atlas,201,136,3,5,0);
    rotateRegion(atlas,136,136,3,5,-90);
    rotateRegion(atlas,136,267,3,5,180);
    rotateRegion(atlas,201,267,3,5,90);
    rotateRegion(atlas,269,136,3,5,0);
    rotateRegion(atlas,204,136,3,5,-90);
    rotateRegion(atlas,204,267,3,5,180);
    rotateRegion(atlas,269,267,3,5,90);
    rotateRegion(atlas,337,136,3,5,0);
    rotateRegion(atlas,272,136,3,5,-90);
    rotateRegion(atlas,272,267,3,5,180);
    rotateRegion(atlas,337,267,3,5,90);
    rotateRegion(atlas,405,136,3,5,0);
    rotateRegion(atlas,340,136,3,5,-90);
    rotateRegion(atlas,340,267,3,5,180);
    rotateRegion(atlas,405,267,3,5,90);
    rotateRegion(atlas,65,272,3,3,0);
    rotateRegion(atlas,0,272,3,3,-90);
    rotateRegion(atlas,0,337,3,3,180);
    rotateRegion(atlas,65,337,3,3,90);
    rotateRegion(atlas,65,340,3,3,0);
    rotateRegion(atlas,0,340,3,3,-90);
    rotateRegion(atlas,0,405,3,3,180);
    rotateRegion(atlas,65,405,3,3,90);
    rotateRegion(atlas,201,272,3,5,0);
    rotateRegion(atlas,136,272,3,5,-90);
    rotateRegion(atlas,136,403,3,5,180);
    rotateRegion(atlas,201,403,3,5,90);
    rotateRegion(atlas,269,272,3,5,0);
    rotateRegion(atlas,204,272,3,5,-90);
    rotateRegion(atlas,204,403,3,5,180);
    rotateRegion(atlas,269,403,3,5,90);
    rotateRegion(atlas,337,272,3,5,0);
    rotateRegion(atlas,272,272,3,5,-90);
    rotateRegion(atlas,272,403,3,5,180);
    rotateRegion(atlas,337,403,3,5,90);
    rotateRegion(atlas,405,272,3,5,0);
    rotateRegion(atlas,340,272,3,5,-90);
    rotateRegion(atlas,340,403,3,5,180);
    rotateRegion(atlas,405,403,3,5,90);
    rotateRegion(atlas,133,272,3,3,0);
    rotateRegion(atlas,68,272,3,3,-90);
    rotateRegion(atlas,68,337,3,3,180);
    rotateRegion(atlas,133,337,3,3,90);
    rotateRegion(atlas,133,340,3,3,0);
    rotateRegion(atlas,68,340,3,3,-90);
    rotateRegion(atlas,68,405,3,3,180);
    rotateRegion(atlas,133,405,3,3,90);
    if(scale!=1.0f) {
        GImage half(atlas.width/2,atlas.height/2,atlas.channels);
        int stride=atlas.width*atlas.channels;
        for(int y=0;y<half.height;++y)
            for(int x=0;x<half.width;++x)
                for(int c=0;c<half.channels;++c) {
                    unsigned char* dest=half.byte()+(x+y*half.width)*half.channels+c;
                    const unsigned char* src=atlas.byte()+(x+y*atlas.width)*2*atlas.channels+c;
                    int sum;
                    if(x*2+1>=atlas.width || y*2+1>=atlas.height)
                        sum=src[0];
                    else sum=box4(src,src+stride,atlas.channels);
                    *dest=(sum+2)>>2;
                }
        half.save(cache,GImage::PNG);
    } else atlas.save(cache,GImage::PNG);
    return cache;

}

