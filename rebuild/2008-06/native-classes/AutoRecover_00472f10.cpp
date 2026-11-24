// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <windows.h>
#include <GL/gl.h>

extern "C" int fn_00471060(int a1);
extern "C" int fn_004729d0(void);

// INFERRED: layout from member accesses in 0x472f10
struct TexParams {
    int filter;      // 1..6
    int wrap;        // 0 clamp, 1 repeat, 2 border
    int shadowMode;  // +8
    float aniso;     // +0xc
    char useMipHint; // +0x10
    int borderA;     // +0x14
    int borderB;     // +0x18
};

// INFERRED: capability flags at 0x96ee7f..0x96ee87
extern bool g_96ee7f, g_96ee80, g_96ee81, g_96ee87;

// INFERRED: esi holds the GL target at entry (register arg); modeled as 'target'
extern "C" void fn_00472f10(TexParams* p)
{
    GLenum target = 0; // INFERRED: caller-provided esi
    GLenum wrap = 0;
    bool genMip = g_96ee81;

    switch (p->wrap) {
    case 0:
        wrap = 0x2900 + (g_96ee7f ? 0x582f : 0);
        break;
    case 1:
        wrap = 0x2901;
        break;
    case 2: {
        wrap = 0x2900 + (g_96ee80 ? 0x582d : 0);
        float border[4] = { 0, 0, 0, 0 };
        glTexParameterfv(target, 0x1004, border);
        break;
    }
    }
    glTexParameteri(target, 0x2802, wrap);
    glTexParameteri(target, 0x2803, wrap);
    if (genMip)
        glTexParameteri(target, 0x8072, wrap);

    bool lod;
    {
        std::string s("GL_EXT_texture_lod");
        lod = fn_00471060((int)&s) != 0;
    }
    if (lod) {
        glTexParameteri(target, 0x813b, p->borderA);
        glTexParameteri(target, 0x813a, p->borderB);
    }

    switch (p->filter) {
    case 1:
        glTexParameteri(target, 0x2800, 0x2601);
        glTexParameteri(target, 0x2801, 0x2703);
        if (fn_004729d0())
            glTexParameteri(target, 0x8191, 1);
        break;
    case 2:
        glTexParameteri(target, 0x2800, 0x2601);
        glTexParameteri(target, 0x2801, 0x2701);
        if (fn_004729d0() && p->useMipHint)
            glTexParameteri(target, 0x8191, 1);
        break;
    case 3:
        glTexParameteri(target, 0x2800, 0x2600);
        glTexParameteri(target, 0x2801, 0x2700);
        if (fn_004729d0() && p->useMipHint)
            glTexParameteri(target, 0x8191, 1);
        break;
    case 4:
        glTexParameteri(target, 0x2800, 0x2601);
        glTexParameteri(target, 0x2801, 0x2601);
        break;
    case 5:
        glTexParameteri(target, 0x2800, 0x2600);
        glTexParameteri(target, 0x2801, 0x2600);
        break;
    }

    static bool haveAniso;
    static bool init;
    if (!init) {
        init = true;
        std::string s("GL_EXT_texture_filter_anisotropic");
        haveAniso = fn_00471060((int)&s) != 0;
    }
    if (haveAniso)
        glTexParameterf(target, 0x84fe, p->aniso);

    if (g_96ee87) {
        if (p->shadowMode == 0) {
            glTexParameteri(target, 0x884c, 0);
            return;
        }
        glTexParameteri(target, 0x884c, 0x884e);
        glTexParameteri(target, 0x884d, 0x203 + ((p->shadowMode - 1) ? 3 : 0));
    }
}
