// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_41bb54d950cc8912.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include "util/TextureId.h"
namespace RBX {
ContentId contentFromAssets(const char* path);
struct S0 { virtual ~S0(); char p[0xc]; };
struct S10 { virtual ~S10(); };
struct S14 { virtual ~S14(); char p[8]; };
struct S20 { virtual ~S20(); };
struct S24 { virtual ~S24(); char p[0x1c]; };
struct S44 { virtual ~S44(); char p[0x1c]; };
struct S64 { virtual ~S64(); char p[0x1c]; };
struct S84 { virtual ~S84(); char p[0x1c]; };
struct Sa4 { virtual ~Sa4(); char p[0x1c]; };
struct Sc4 { virtual ~Sc4(); char p[0x68]; };
class SkyBase : public S0, public S10, public S14, public S20, public S24, public S44, public S64, public S84, public Sa4, public Sc4 {
public:
    SkyBase();
    virtual ~SkyBase();
    void setName(const std::string& name);
};
class Sky : public SkyBase {
public:
    TextureId skyUp;
    TextureId skyLf;
    TextureId skyRt;
    TextureId skyBk;
    TextureId skyFt;
    TextureId skyDn;
    bool drawCelestialBodies;
    int numStars;
    Sky();
    virtual ~Sky();
};
Sky::Sky()
    : drawCelestialBodies(true),
      numStars(3000)
{
    setName("Sky");
    skyUp = contentFromAssets("Sky\\null_plainsky512_up.jpg");
    skyLf = contentFromAssets("Sky\\null_plainsky512_lf.jpg");
    skyRt = contentFromAssets("Sky\\null_plainsky512_rt.jpg");
    skyBk = contentFromAssets("Sky\\null_plainsky512_bk.jpg");
    skyFt = contentFromAssets("Sky\\null_plainsky512_ft.jpg");
    skyDn = contentFromAssets("Sky\\null_plainsky512_dn.jpg");
}
}
