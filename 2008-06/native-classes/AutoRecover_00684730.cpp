// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <stdlib.h>

// INFERRED: draft only. Arg roles come from the disassembly and nothing was compiled.
// Arguments are guessed as: out vec2, owner (+0x14 = TwoDManager*), text string,
// pos vec2, scale, color, alignX, alignY, flags, quad count, extra.
extern "C" int __fastcall fn_00684640(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5);
extern "C" int __fastcall fn_006843f0(void* self, int unusedEdx, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
extern "C" void __fastcall fn_00682d60(void* twoD, int unusedEdx, std::string name, float a, float b, float c, float d, float e, float f, float g, float h, int color);

struct Vec2f { float x, y; };
struct Surface { virtual void v0(); };
struct TextOwner { char pad[0x14]; void* twoD; };

struct TextDrawer {
    char pad0[0x200];
    int width;
    int height;
    int pad208;
    int unk20c;
    struct Dev {
        char pad[0x24];
        std::string material;
    }* dev;
};

extern "C" void __fastcall fn_00684730(TextDrawer* self, int unusedEdx, Vec2f* out, TextOwner* owner,
                                       std::string* text, Vec2f* pos, float a5, float a6, float a7,
                                       float a8, int alignX, int alignY, int a11)
{
    float x = pos->x;
    float y = pos->y;
    int count = 0;
    for (unsigned i = 0; i < text->size(); ++i)
        if ((*text)[i] != ' ')
            ++count;
    if (!count) {
        out->x = 0;
        out->y = 0;
        return;
    }
    void* glyphs = malloc(count << 6);
    // The real code lays out quads via fn_006843f0 / fn_00684640 and emits them with addQuad.
    (void)x; (void)y; (void)owner; (void)alignX; (void)alignY; (void)a11;
    (void)a5; (void)a6; (void)a7; (void)a8; (void)self;
    free(glyphs);
    out->x = 0;
    out->y = 0;
}
