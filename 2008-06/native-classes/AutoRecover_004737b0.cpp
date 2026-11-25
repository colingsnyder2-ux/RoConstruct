// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <new>

// INFERRED: Layout follows the supplied disassembly.
// INFERRED: Byte-exact code generation is not verified; the supplied
// analog contains disassembly but no corresponding source statements.
struct TextureSettings {
    int interpolate;
    int wrap;
    int depthRead;
    float maxAnisotropy;
    bool autoMipMap;
    char padding[3];
    int minMipMap;
    int maxMipMap;
};

namespace G3D {
struct Texture {
    void* vtable;
    int referenceCount;
    int field08;
    unsigned int id;
    int depthRead;
    float maxAnisotropy;
    int interpolate;
    int wrap;
    TextureSettings settings;
    std::string name;
    int dimension;
    bool flag;
    char padding[3];
    const void* format;
    int width;
    int height;
    int depth;
    bool field70;

    unsigned int sizeInMemory() const;
};
}

extern "C" {
extern char g_0081e1e0[];
extern char g_0081e36c[];
extern float g_0081c434;
extern unsigned char g_0096ee7e;
extern unsigned int g_0096ef44;
extern void (__stdcall *g_0096f804)(unsigned int);

__declspec(dllimport) void __stdcall glPushAttrib(unsigned int);
__declspec(dllimport) void __stdcall glPushClientAttrib(unsigned int);
__declspec(dllimport) void __stdcall glBindTexture(unsigned int, unsigned int);
__declspec(dllimport) void __stdcall glGetTexLevelParameteriv(
    unsigned int, int, unsigned int, int*);
__declspec(dllimport) void __stdcall glPopClientAttrib();
__declspec(dllimport) void __stdcall glPopAttrib();

int fn_00472f10(TextureSettings*);
}

extern "C" G3D::Texture* __fastcall fn_004737b0(
    G3D::Texture* self, int unusedEdx, const std::string& name,
    unsigned int id, int dimension, const void* format, int interpolate,
    int wrap, bool flag, int depthRead, float maxAnisotropy)
{
    self->vtable = g_0081e1e0;
    self->referenceCount = 0;
    self->field08 = 0;
    self->maxAnisotropy = maxAnisotropy;
    self->id = id;
    self->vtable = g_0081e36c;
    self->depthRead = depthRead;
    self->settings.maxAnisotropy = g_0081c434;
    self->settings.interpolate = 3;
    self->settings.wrap = 1;
    self->settings.depthRead = 0;
    self->settings.autoMipMap = true;
    self->settings.minMipMap = 1000;
    self->settings.maxMipMap = -1000;
    new (&self->name) std::string;

    self->settings.maxAnisotropy = maxAnisotropy;
    self->dimension = dimension;
    self->flag = flag;
    self->format = format;
    self->settings.interpolate = interpolate;
    self->settings.wrap = wrap;
    self->settings.depthRead = depthRead;
    self->settings.autoMipMap = true;

    glPushAttrib(0xfffff);
    glPushClientAttrib(-1);
    if (g_0096ee7e)
        g_0096f804(0x84c0);

    unsigned int target;
    switch (dimension) {
    case 4:
        target = 0x84f5;
        break;
    case 5:
    case 7:
        target = 0x8513;
        break;
    case 2:
    case 3:
    case 6:
    default:
        target = 0x0de1;
        break;
    }

    glBindTexture(target, id);
    self->name = name;

    unsigned int queryTarget = target;
    if (dimension == 5 || dimension == 7)
        queryTarget = 0x8515;

    glGetTexLevelParameteriv(queryTarget, 0, 0x1000, &self->width);
    glGetTexLevelParameteriv(queryTarget, 0, 0x1001, &self->height);

    self->depth = 1;
    self->field70 = false;
    self->interpolate = interpolate;
    self->wrap = wrap;
    fn_00472f10(&self->settings);
    glPopClientAttrib();
    glPopAttrib();
    g_0096ef44 += self->sizeInMemory();
    return self;
}
