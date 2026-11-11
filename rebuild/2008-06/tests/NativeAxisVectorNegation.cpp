// Standalone math regression only; never loads the native client.
#include <G3D/Vector3.h>
#include <cstring>
#include <cstddef>
#include <cstdio>
typedef char VectorSize[sizeof(G3D::Vector3)==12?1:-1];
typedef char VectorAlign[__alignof(G3D::Vector3)==4?1:-1];
typedef char VectorX[offsetof(G3D::Vector3,x)==0?1:-1];
typedef char VectorY[offsetof(G3D::Vector3,y)==4?1:-1];
typedef char VectorZ[offsetof(G3D::Vector3,z)==8?1:-1];
__declspec(noinline) G3D::Vector3 reference(const G3D::Vector3& v) { return G3D::Vector3(-v.x,-v.y,-v.z); }
__declspec(noinline) G3D::Vector3 candidate(const G3D::Vector3& v) { return -v; }
float value(unsigned bits) { float f; std::memcpy(&f,&bits,4); return f; }
int main() {
 const unsigned samples[]={0,0x80000000u,0x3f800000u,0xbf800000u,0x7f800000u,0xff800000u,0x7fc00001u,0xffc12345u,0x7f800001u,0xff800001u,1,0x80000001u,0x007fffffu,0x00800000u,0x7f7fffffu,0xff7fffffu};
 G3D::Vector3 zero; unsigned words[3]; std::memcpy(words,&zero,12); if(words[0]||words[1]||words[2])return 1;
 unsigned cases=0;
 for(unsigned x=0;x<16;++x)for(unsigned y=0;y<16;++y)for(unsigned z=0;z<16;++z){
  G3D::Vector3 v(value(samples[x]),value(samples[y]),value(samples[z]));
  G3D::Vector3 expected=reference(v),actual=candidate(v),copied(v);
  unsigned bits[3]; std::memcpy(bits,&v,12);
  bool nan=false; for(unsigned i=0;i<3;++i) nan=nan||((bits[i]&0x7fffffffu)>0x7f800000u);
  if(std::memcmp(&expected,&actual,12)||(!nan&&std::memcmp(&v,&copied,12))) {
   std::printf("FAIL samples %x %x %x\n",samples[x],samples[y],samples[z]); return 2;
  }
  ++cases;
 }
 std::printf("PASS %u vectors: bitwise unary (incl NaNs), non-NaN copy, zero default, size12 alignment4 offsets0/4/8\n",cases);return 0;
}
