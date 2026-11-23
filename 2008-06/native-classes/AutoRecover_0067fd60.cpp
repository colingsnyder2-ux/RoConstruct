// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: partial draft. The disassembly is truncated at 0x68065b, so this covers
// only the constructor prologue and the first part of the body. It is unverified.
// INFERRED: the Ogre headers are not on the include path (OgreTexture.h failed to
// open). The Ogre pointer types are therefore local 12-byte opaque stand-ins.
// INFERRED: the target looks like a sky-object constructor (vtable 0x84e56c).
#include <string>

extern "C" int fn_006a0920(int a1);

// INFERRED: Ogre::TexturePtr and Ogre::MaterialPtr are 12 bytes each (stride 0xc in the binary).
struct OgrePtr12 { void* vtbl; void* pRep; int* pUseCount; };

struct SkyList { void* head; int a, b, c; }; // INFERRED: 0x14-byte list header at +0x88 and +0xa0

struct SkyObj {
    void* vtbl;                 // +0x00
    OgrePtr12 tex0;             // +0x04, sun.jpg
    OgrePtr12 tex1;             // +0x10, moon.jpg
    OgrePtr12 tex2;             // +0x1c
    OgrePtr12 tex3;             // +0x28, sun-rays.jpg
    char pad0[0x54 - 0x34];
    OgrePtr12 matl0;            // +0x54 sunMatl
    OgrePtr12 matl1;            // +0x60 sunRaysMatl
    OgrePtr12 matl2;            // +0x6c moonMatl
    OgrePtr12 matl3;            // +0x78
    bool flag84;                // +0x84
    char pad1[3];
    SkyList listA;              // +0x88
    SkyList listB;              // +0xa0
    bool flagB8;                // +0xb8
};

extern "C" SkyObj* __fastcall fn_0067fd60(SkyObj* self, int unusedEdx, int ctx, bool flag, void* sm)
{
    // INFERRED: the three stack args are (ctx, flag, scene manager); their types are guesses.
    // The Ogre pointer ctors (TexturePtr/MaterialPtr default ctors) are not callable without headers.
    self->flag84 = false;

    SkyList* l = &self->listA;
    void* n = (void*)fn_006a0920(4);
    l->head = n ? (*(void**)n = l, n) : 0;
    l->a = 0; l->b = 0; l->c = 0;

    l = &self->listB;
    n = (void*)fn_006a0920(4);
    l->head = n ? (*(void**)n = l, n) : 0;
    l->a = 0; l->b = 0; l->c = 0;

    self->flagB8 = flag;
    // INFERRED: the remainder (moon.jpg/sun.jpg/sun-rays.jpg loads, the sunMatl/sunRaysMatl/
    // moonMatl materials, the billboard sets and the skyNode/sunNode scene nodes) is unrecovered.
    return self;
}
