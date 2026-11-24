// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: minimal local types, no authentic headers; best-effort draft, not compiled or diffed.
#include <stdio.h>
#include <string>
#include <exception>

extern "C" int fn_006a0920(int a1);

#include <G3D/BinaryInput.h>   // real G3D 6.09 class: readUInt16 is inline there (no separate function in the exe)

struct FontTexture {
    unsigned int widths[128];   // 0x000
    int cellsX;                 // 0x200
    int cellsY;                 // 0x204
    unsigned int val;           // 0x208
    char texturePtr[8];         // 0x20c Ogre::TexturePtr
    void* pixelBuffer;          // 0x210
};

extern "C" unsigned int __fastcall fn_00509b40(G3D::BinaryInput* self, int unusedEdx);
extern "C" FontTexture* __fastcall fn_00684b10(FontTexture* self, int unusedEdx, void* arg1, G3D::BinaryInput* in)
{
    // INFERRED: body not recoverable without Ogre headers; reads and layout only
    fn_00509b40(in, 0);
    for (int i = 0; i < 128; ++i)
        self->widths[i] = in->readUInt16();
    self->val = in->readUInt16();
    int n = in->readUInt16() / 16;
    self->cellsX = n;
    self->cellsY = n;
    return self;
}
