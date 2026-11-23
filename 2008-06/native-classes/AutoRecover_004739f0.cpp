// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <cstdlib>

// INFERRED: no native headers were provided, so the GL imports and the minimal
// G3D::Texture layout are declared locally from the disassembly offsets.
extern "C" {
__declspec(dllimport) void __stdcall glPushAttrib(unsigned mask);
__declspec(dllimport) void __stdcall glPushClientAttrib(unsigned mask);
__declspec(dllimport) void __stdcall glPopAttrib(void);
__declspec(dllimport) void __stdcall glPopClientAttrib(void);
__declspec(dllimport) void __stdcall glReadBuffer(unsigned mode);
__declspec(dllimport) void __stdcall glEnable(unsigned cap);
__declspec(dllimport) void __stdcall glDisable(unsigned cap);
__declspec(dllimport) void __stdcall glBindTexture(unsigned target, unsigned tex);
__declspec(dllimport) unsigned __stdcall glGetError(void);
__declspec(dllimport) void __stdcall glGetDoublev(unsigned pname, double* v);
__declspec(dllimport) void __stdcall glCopyTexImage2D(unsigned target, int level, unsigned fmt,
                                                      int x, int y, int w, int h, int border);

extern int fn_00483a00(int a1);
extern int fn_00472f10(int a1);

// INFERRED: globals (by original address)
extern bool g_00096ee7e;                         // 0x96ee7e: multitexture supported
extern void(__stdcall* g_0096f804)(unsigned);    // 0x96f804: glActiveTextureARB
extern unsigned g_0096ef44;                      // 0x96ef44: texture memory counter
extern bool g_0096efac;                          // 0x96efac: ignore-always flag
extern bool(__cdecl* g_0094278c)(const char*, const std::string&, const char*, int, bool*, bool); // assert handler
}

namespace G3D {
namespace _internal {
void _releaseInputGrab_();
void _restoreInputGrab_();
}
unsigned getCurrentBuffer(bool useBackBuffer);
void glDisableAllTextures();

class Texture {
public:
    unsigned sizeInMemory() const;
    char pad0[0x0c];
    unsigned textureID;      // 0x0c
    char pad1[0x10];
    char sub20[0x38];        // 0x20
    int dimension;           // 0x58
    char pad2[4];
    struct Fmt { char p[0x14]; unsigned openGLFormat; }* format; // 0x60
    int w;                   // 0x64
    int h;                   // 0x68
    int d;                   // 0x6c
    bool dirty;              // 0x70
};
}

// INFERRED: iRound (original used fistp)
static inline int iRoundD(double x) { return (int)(x + 0.5); }

extern "C" void __fastcall fn_004739f0(G3D::Texture* self, int unusedEdx, const float* rect, bool useBackBuffer)
{
    glPushAttrib(0xfffff);
    glPushClientAttrib((unsigned)-1);
    if (g_00096ee7e) g_0096f804(0x84c0);

    glReadBuffer(G3D::getCurrentBuffer(useBackBuffer));

    g_0096ef44 -= self->sizeInMemory();

    self->w = (int)(rect[2] - rect[0]);
    self->h = (int)(rect[3] - rect[1]);
    self->d = 1;

    if (g_00096ee7e) g_0096f804(0x84c0);
    G3D::glDisableAllTextures();

    unsigned target;
    switch (self->dimension) {
    case 4:
        target = 0x84f5;
        break;
    case 5:
    case 7:
        target = 0x8513;
        break;
    default:
        target = 0xde1;
        break;
    }

    glEnable(target);
    glBindTexture(target, self->textureID);
    unsigned e = glGetError();

    if (!g_0096efac && e != 0) {
        G3D::_internal::_releaseInputGrab_();
        if (g_0094278c) {
            std::string msg = std::string("Error encountered during glBindTexture: ")
                              + (const char*)fn_00483a00((int)e);
            bool r = g_0094278c("e == GL_NONE", msg, ".\\glg3dcpp\\Texture.cpp", 0x51c,
                                &g_0096efac, true);
            if (r) {
                exit(-1);
            }
        }
        G3D::_internal::_restoreInputGrab_();
    }

    double vp[4];
    glGetDoublev(0xba2, vp);
    double vh = vp[3];

    int h = iRoundD(rect[3] - rect[1]);
    int w = iRoundD(rect[2] - rect[0]);
    int y = iRoundD(vh - (double)rect[3]);
    int x = iRoundD(rect[0]);

    glCopyTexImage2D(target, 0, self->format->openGLFormat, x, y, w, h, 0);

    fn_00472f10((int)(self->sub20));

    glDisable(target);
    self->dirty = true;
    glPopClientAttrib();
    glPopAttrib();

    g_0096ef44 += self->sizeInMemory();
}
