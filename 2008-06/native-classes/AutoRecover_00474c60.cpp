// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// Reconstruction of G3D 6.09 Texture::fromFile(const std::string filename[6], ...)
#include <string>
#include <math.h>
#include <windows.h>

struct TextureFormat;

// INFERRED: weak-pointer list node used by ReferenceCountedObject
struct WeakTarget {
    virtual void slot0();
    virtual void objectCollected();
};
struct WeakNode {
    WeakTarget* target;
    WeakNode*   next;
};

// INFERRED: G3D::ReferenceCountedObject layout (vtable, refcount, weak list)
struct TexRefCounted {
    virtual ~TexRefCounted() {}
    long      refCount;
    WeakNode* weakList;
};

// INFERRED: minimal ReferenceCountedPointer<Texture>
struct TextureRef {
    TexRefCounted* p;
    TextureRef() : p(0) {}
    TextureRef(const TextureRef& r) : p(0) {
        if (r.p) {
            p = r.p;
            InterlockedIncrement(&p->refCount);
        }
    }
    ~TextureRef() {
        if (p) {
            if (InterlockedDecrement(&p->refCount) == 0) {
                WeakNode* n = p->weakList;
                while (n) {
                    n->target->objectCollected();
                    WeakNode* d = n;
                    n = n->next;
                    operator delete(d);
                }
                delete p;
            }
            p = 0;
        }
    }
};

extern "C" int __fastcall fn_0071f200(void* self, int unusedEdx);                 // DDSTexture::~DDSTexture
extern "C" int __fastcall fn_00484ea0(void* self, int unusedEdx, const std::string* name); // DDSTexture ctor
extern "C" int __fastcall fn_00474520(void* self, int unusedEdx, int n, bool shrink);      // Array<Array<const void*>>::resize
extern "C" int __fastcall fn_00473cd0(void* self, int unusedEdx, int n, bool shrink);      // Array<const void*>::resize
extern "C" int __fastcall fn_00474320(void* self, int unusedEdx);                 // Array<Array<const void*>>::~Array
extern "C" int __fastcall fn_00510490(void* self, int unusedEdx, int a1, int a2); // GImage::load
extern "C" int __fastcall fn_0045aca0(void* self, int unusedEdx);                 // GImage::GImage
extern "C" int __fastcall fn_0050e230(void* self, int unusedEdx);                 // GImage::~GImage
// INFERRED: caller pops 3 args (add esp,0xc) -> cdecl splitFilenameAtWildCard
extern "C" void fn_00473350(const std::string& filename, std::string& base, std::string& ext);
extern "C" void fn_004731c0(unsigned char* image, int n, double brighten, int ch); // brightenImage
extern "C" std::string fn_00512210(const std::string& s);                          // G3D::toUpper

// INFERRED: DDSTexture layout
struct DDSTexture {
    const unsigned char* bytes;
    const TextureFormat* bytesFormat;
    int width;
    int height;
    int numMipMaps;
    int pad;
    DDSTexture(const std::string& f) { fn_00484ea0(this, 0, &f); }
    ~DDSTexture() { fn_0071f200(this, 0); }
};

struct VoidPtrArray {
    const void** data;
    int num;
    int numAlloc;
};

struct MipArray {
    VoidPtrArray* data;
    int num;
    int numAlloc;
    MipArray() : data(0), num(0), numAlloc(0) {}
    ~MipArray() { fn_00474320(this, 0); }
};

// INFERRED: GImage layout (0x14 bytes)
struct GImage {
    int            pad0;
    unsigned char* byte;
    int            width;
    int            height;
    int            channels;
    GImage() { fn_0045aca0(this, 0); }
    ~GImage() { fn_0050e230(this, 0); }
};

extern "C" TextureRef fn_00473fc0(const std::string& name, MipArray* mips,
                                  const TextureFormat* bytesFormat, int w, int h, int d,
                                  const TextureFormat* desired, int wrap, int interpolate,
                                  int dimension, int depthRead, float f0, float f1);
extern "C" TextureRef fn_00474690(const std::string& name, const void** bytes,
                                  const TextureFormat* bytesFormat, int w, int h, int d,
                                  const TextureFormat* desired, int wrap, int interpolate,
                                  int dimension, int depthRead, float f0, float f1);

extern const TextureFormat* g_0096fab0;     // INFERRED: TextureFormat::RGB8
extern const TextureFormat* g_0096faa8;     // INFERRED: TextureFormat::RGBA8
extern const char* g_009337ac[6];           // INFERRED: cubeMapString

extern "C" TextureRef fn_00474c60(
    const std::string    filename[6],
    const TextureFormat* desiredFormat,
    int                  wrap,
    int                  interpolate,
    int                  dimension,
    double               brighten,
    int                  depthRead,
    int                  unused,          // INFERRED: unreferenced argument slot
    float                f1,
    float                f0)
{
    std::string realFilename[6];
    const TextureFormat* format = g_0096fab0;
    GImage image[6];
    const void* array[6] = { 0, 0, 0, 0, 0, 0 };

    int numFaces;
    if (dimension == 5) {
        numFaces = 6;
    } else {
        numFaces = (dimension == 7) ? 6 : 1;
    }

    std::string ext;
    {
        int dot   = (int)filename[0].rfind('.');
        int bs    = (int)filename[0].rfind('\\');
        int slash = (int)filename[0].rfind('/');
        if (slash < bs) slash = bs;
        if ((std::string::size_type)dot != std::string::npos &&
            (std::string::size_type)dot > (std::string::size_type)slash) {
            ext = filename[0].substr(dot + 1, filename[0].size() - dot - 1);
        }
    }

    bool isDDS = (fn_00512210(ext) == "DDS");

    if (isDDS) {
        DDSTexture ddsTexture(filename[0]);
        MipArray byteMipMapFaces;

        const unsigned char* ptr = ddsTexture.bytes;
        const TextureFormat* bytesFormat = ddsTexture.bytesFormat;
        int w = ddsTexture.width;
        int h = ddsTexture.height;
        int numMipMaps = ddsTexture.numMipMaps;

        fn_00474520(&byteMipMapFaces, 0, numMipMaps, true);
        for (int i = 0; i < numMipMaps; ++i) {
            fn_00473cd0(&byteMipMapFaces.data[i], 0, numFaces, true);
            for (int f = 0; f < numFaces; ++f) {
                byteMipMapFaces.data[i].data[f] = ptr;
                ptr += ((((const int*)bytesFormat)[0x38 / 4]) / 8) * ((w + 3) / 4) * ((h + 3) / 4);
            }
            w = (int)floor((double)(w / 2));
            if (w < 1) w = 1;
            h = (int)floor((double)(h / 2));
            if (h < 1) h = 1;
        }

        return fn_00473fc0(filename[0], &byteMipMapFaces, bytesFormat,
                           ddsTexture.width, ddsTexture.height, 1,
                           desiredFormat, wrap, interpolate, dimension,
                           depthRead, f1, f0);
    }

    if (numFaces == 6) {
        if (filename[1] == "") {
            std::string filenameBase;
            std::string filenameExt;
            fn_00473350(filename[0], filenameBase, filenameExt);
            for (int f = 0; f < 6; ++f) {
                realFilename[f] = filenameBase + g_009337ac[f] + filenameExt;
            }
        } else {
            realFilename[0] = filename[0];
            for (int f = 1; f < 6; ++f) {
                realFilename[f] = filename[f];
            }
        }
    } else {
        realFilename[0] = filename[0];
    }

    for (int f = 0; f < numFaces; ++f) {
        fn_00510490(&image[f], 0, (int)&realFilename[f], 8);
        if (image[f].channels == 4) {
            format = g_0096faa8;
        }
        if (desiredFormat == 0) {
            desiredFormat = format;
        }
        array[f] = image[f].byte;
    }

    if (brighten != 1.0) {
        for (int f = 0; f < numFaces; ++f) {
            fn_004731c0(image[f].byte,
                        image[f].width * image[f].height * image[f].channels,
                        brighten, image[f].channels);
        }
    }

    TextureRef t = fn_00474690(filename[0], array, format,
                               image[0].width, image[0].height, 1,
                               desiredFormat, wrap, interpolate, dimension,
                               depthRead, f1, f0);
    return t;
}
