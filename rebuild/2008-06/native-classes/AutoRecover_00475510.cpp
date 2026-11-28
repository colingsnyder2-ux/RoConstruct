// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <windows.h>

// INFERRED: the real G3D/Roblox headers are not available, so the types used
// here are minimal local stand-ins.

// INFERRED: table of six cube-face filename suffixes
extern "C" const char* g_009337ac[6];
// INFERRED: pointer to a G3D::TextureFormat (e.g. TextureFormat::RGBA8)
extern "C" const void* g_0096faa8;

extern "C" void fn_00473350(const std::string& in, std::string* prefix, std::string* ext); // INFERRED: cdecl, as the call site shows (add esp,0xc)
extern "C" int  __fastcall fn_00510490(void* self, int unusedEdx, int a1, int a2);         // image load (name, flags)
extern "C" void __fastcall fn_0045aca0(void* self, int unusedEdx);                         // image ctor
extern "C" void __fastcall fn_0050e230(void* self, int unusedEdx);                         // image dtor

// INFERRED: Texture::fromMemory(...) returns the ref through a hidden first arg
extern "C" void* fn_00474690(void* ret, const std::string& name, const unsigned char** bytes,
                             const void* bytesFormat, int width, int height, int depth,
                             int a4, int a5, int a6, int a7, int a8, float f9, float one);

// INFERRED: 20-byte image object (vtbl/pad, data, width, height, channels)
struct Img {
    int pad;
    unsigned char* data;
    int width;
    int height;
    int channels;
    Img()  { fn_0045aca0(this, 0); }
    ~Img() { fn_0050e230(this, 0); }
};

// INFERRED: intrusive ref counted object: vtable +0, refcount +4, weak list +8
struct WeakNode {
    struct Dtor { virtual void d0() = 0; virtual void d1() = 0; } *target;
    WeakNode* next;
};
struct RCObject {
    virtual ~RCObject() {}
    volatile LONG refCount;
    WeakNode* weakList;
};

static void rcRelease(RCObject* p)
{
    if (p && InterlockedDecrement(&p->refCount) == 0) {
        WeakNode* n = p->weakList;
        while (n) {
            n->target->d1();
            WeakNode* nx = n->next;
            ::operator delete(n);
            n = nx;
        }
        delete p;
    }
}

extern "C" RCObject** fn_00475510(RCObject** out,
                                  const std::string& fileName,
                                  const std::string& alphaName,
                                  int a4, int a5, int a6, int dimension, int a8, float a9)
{
    const unsigned char* bytes[6] = {0, 0, 0, 0, 0, 0};

    int count;
    if (dimension == 5)
        count = 6;
    else
        count = (dimension == 7) ? 6 : 1;

    std::string prefix(fileName);
    std::string ext;
    std::string alphaPrefix(alphaName);
    std::string alphaExt;

    if (count == 6)
        fn_00473350(fileName, &prefix, &ext);

    Img colorImg[6];
    Img alphaImg[6];

    *out = 0;

    for (int i = 0; i < count; ++i) {
        std::string fileA(fileName);
        std::string fileB(alphaName);

        if (count == 6) {
            fileA = (prefix + g_009337ac[i]) + ext;
            fileB = (alphaPrefix + g_009337ac[i]) + alphaExt;
        }

        fn_00510490(&colorImg[i], 0, (int)&fileA, 8);
        fn_00510490(&alphaImg[i], 0, (int)&fileB, 8);

        unsigned char* result;
        if (colorImg[i].channels == 4) {
            result = colorImg[i].data;
            for (int k = 0; k < colorImg[i].width * colorImg[i].height; ++k)
                result[k * 4 + 3] = alphaImg[i].data[alphaImg[i].channels * k];
        } else {
            result = (unsigned char*)::operator new[](colorImg[i].width * colorImg[i].height * 4);
            for (int k = 0; k < colorImg[i].width * colorImg[i].height; ++k) {
                result[k * 4]     = colorImg[i].data[k * 3];
                result[k * 4 + 1] = colorImg[i].data[k * 3 + 1];
                result[k * 4 + 2] = colorImg[i].data[k * 3 + 2];
                result[k * 4 + 3] = alphaImg[i].data[alphaImg[i].channels * k];
            }
        }
        bytes[i] = result;
    }

    RCObject* tmp = 0;
    fn_00474690(&tmp, fileName, bytes, g_0096faa8,
                colorImg[0].width, colorImg[0].height, 1,
                a4, a5, a6, dimension, a8, a9, 1.0f);

    RCObject* np = tmp;
    if (np != *out) {
        if (*out) {
            rcRelease(*out);
            *out = 0;
        }
        if (np) {
            *out = np;
            InterlockedIncrement(&np->refCount);
        }
    }
    rcRelease(tmp);

    if (colorImg[0].channels == 3) {
        for (int i = 0; i < count; ++i)
            ::operator delete[]((void*)bytes[i]);
    }

    return out;
}
