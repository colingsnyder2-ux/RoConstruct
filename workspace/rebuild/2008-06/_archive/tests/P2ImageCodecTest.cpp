#include <G3D/GImage.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int main(){
 const char* path=std::getenv("ROC_TEXTURE_STRIP");
 if(!path)return 1;
 try{
  G3D::GImage source(path);
  source.save("image-codec-roundtrip.png",G3D::GImage::PNG);
  G3D::GImage back("image-codec-roundtrip.png");
  bool same=source.width==back.width && source.height==back.height && source.channels==back.channels &&
   !std::memcmp(source.byte(),back.byte(),source.width*source.height*source.channels);
  std::printf("G3D PNG %dx%dx%d lossless=%d\n",source.width,source.height,source.channels,same);
  return same?0:2;
 }catch(const G3D::GImage::Error& e){std::printf("GImage error: %s\n",e.reason.c_str());return 3;}
}
