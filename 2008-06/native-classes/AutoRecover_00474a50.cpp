// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were available, so the G3D types below are local stand-ins
// laid out to match the observed offsets.
#include <string>

extern "C" {
__declspec(dllimport) void __stdcall glPushAttrib(unsigned mask);
__declspec(dllimport) void __stdcall glPushClientAttrib(unsigned mask);
__declspec(dllimport) void __stdcall glPopAttrib();
__declspec(dllimport) void __stdcall glPopClientAttrib();
__declspec(dllimport) void __stdcall glBindTexture(unsigned target, unsigned tex);
__declspec(dllimport) void __stdcall glGetTexImage(unsigned target, int level, unsigned format, unsigned type, void* pixels);
__declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
}

// INFERRED: globals at 0x96ee7e / 0x96f804 / 0x96fab8 / 0x81c434
extern bool g_hasMultitexture;
extern void (__stdcall* g_glActiveTextureARB)(unsigned);
extern const void* g_A8Format;
extern const float g_defaultFloat;

namespace G3D {

class System {
public:
    static void* malloc(unsigned size);
    static void  free(void* p);
};

// INFERRED: weak pointer node: object with virtual slot 1 called on release
class WeakObj {
public:
    virtual void dummy0();
    virtual void notify();
};

struct WeakNode {
    WeakObj*  obj;
    WeakNode* next;
};

class ReferenceCountedObject {
public:
    virtual ~ReferenceCountedObject() {}
    volatile long refCount;   // 0x04
    WeakNode* weakList;       // 0x08
};

template <class T>
class ReferenceCountedPointer {
public:
    T* m_p;
    ReferenceCountedPointer() : m_p(0) {}
    ReferenceCountedPointer(const ReferenceCountedPointer& r) : m_p(r.m_p) {
        if (m_p) InterlockedIncrement(&m_p->refCount);
    }
    ~ReferenceCountedPointer() {
        if (m_p) {
            if (InterlockedDecrement(&m_p->refCount) == 0) {
                WeakNode* n = m_p->weakList;
                while (n) {
                    n->obj->notify();
                    WeakNode* nx = n->next;
                    ::operator delete(n);
                    n = nx;
                }
                if (m_p) delete m_p;
            }
        }
    }
};

class Texture : public ReferenceCountedObject {
public:
    typedef ReferenceCountedPointer<Texture> Ref;

    unsigned textureID;       // 0x0c
    int      pad10[2];
    int      interpolateMode; // 0x18
    int      wrapMode;        // 0x1c
    char     pad20[28];
    std::string name;         // 0x3c
    int      dimension;       // 0x58
    bool     opaque;          // 0x5c
    int      pad60;
    int      width;           // 0x64
    int      height;          // 0x68

    static Ref fromMemory(const std::string& name, const void* const* bytes,
                          const void* bytesFormat, int width, int height, int depth,
                          const void* desiredFormat, int wrap, int interpolate,
                          int dimension, int preProcess, float a, float b);
};

} // namespace G3D

using namespace G3D;

extern "C" Texture::Ref* __fastcall fn_00474a50(Texture* self, int unusedEdx, Texture::Ref* ret)
{
    if (self->opaque) {
        ret->m_p = 0;
        return ret;
    }

    const void** data = (const void**)System::malloc(4);
    const void* fmt = g_A8Format;

    glPushAttrib(0xfffff);
    glPushClientAttrib(0xffffffff);
    if (g_hasMultitexture) {
        g_glActiveTextureARB(0x84c0);
    }

    unsigned target;
    switch (self->dimension) {
    case 4:  target = 0x84f5; break;
    case 5:
    case 7:  target = 0x8513; break;
    default: target = 0xde1;  break;
    }
    glBindTexture(target, self->textureID);

    data[0] = System::malloc(self->width * self->height);
    glGetTexImage(target, 0, 0x1906, 0x1401, (void*)data[0]);

    glPopClientAttrib();
    glPopAttrib();

    Texture::Ref r = Texture::fromMemory(self->name + " Alpha", data, fmt,
                                         self->width, self->height, 1,
                                         g_A8Format, self->wrapMode,
                                         self->interpolateMode, self->dimension,
                                         0, g_defaultFloat, 1.0f);

    System::free((void*)data[0]);
    System::free(data);

    new (ret) Texture::Ref(r);
    return ret;
}
