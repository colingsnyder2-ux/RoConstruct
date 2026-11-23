// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: no native headers were shown for this function, so every type below is a
// minimal local stand-in. The layouts and vtable slots are taken from the disassembly.

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace G3D {
class ReferenceCountedObject {
public:
    virtual ~ReferenceCountedObject() {}
    volatile long m_refCount;                 // +4
    void ReferenceCountedObject_zeroWeakPointers();
};
}

namespace Ogre {

class Resource;
class Texture {
public:
    // INFERRED: slot 24 (+0x60) and slot 25 (+0x64) are width/height style getters.
    virtual int slot_pad() { return 0; }
};

template <class T>
class SharedPtr {
public:
    virtual ~SharedPtr() {}
    T* pRep;                 // +4
    unsigned int* pUseCount; // +8
};

class TexturePtr : public SharedPtr<Texture> {
public:
    __declspec(dllimport) TexturePtr(const SharedPtr<Resource>& r);
    __declspec(dllimport) virtual ~TexturePtr();
};

class TextureManager {
public:
    __declspec(dllimport) static TextureManager& getSingleton();
};

}

struct SelfObj {
    int pad0;
    int field4;
};

struct RectOut {
    float x0, y0, x1, y1;
};

typedef G3D::ReferenceCountedObject RCO;

// Release a G3D-style intrusive reference (the inlined ReferenceCountedPointer dtor).
static inline void releaseRef(RCO* p)
{
    if (p) {
        if (InterlockedDecrement(&p->m_refCount) == 0) {
            p->ReferenceCountedObject_zeroWeakPointers();
            if (p) {
                delete p;
            }
        }
    }
}

typedef RCO* (__fastcall *GetRefFn)(void* self, int edx, RCO** ret, int arg);
typedef void (__fastcall *GetTexFn)(void* self, int edx, Ogre::SharedPtr<Ogre::Resource>* ret, const void* name);
typedef int  (__fastcall *GetIntFn)(void* self, int edx);

extern "C" RectOut* __fastcall fn_00670210(SelfObj* self, int unusedEdx, RectOut* out, RCO* source)
{
    RCO* tmpRef = 0;
    {
        void** vt = *(void***)source;
        ((GetRefFn)vt[6])(source, 0, &tmpRef, self->field4);
    }
    releaseRef(tmpRef);

    Ogre::TextureManager& mgr = Ogre::TextureManager::getSingleton();
    Ogre::SharedPtr<Ogre::Resource>* resTmp;
    char resBuf[12];
    resTmp = (Ogre::SharedPtr<Ogre::Resource>*)resBuf;
    {
        void** vt = *(void***)&mgr;
        ((GetTexFn)vt[0x4c / 4])(&mgr, 0, resTmp, (const char*)source + 0xc);
    }

    Ogre::TexturePtr tex(*resTmp);
    // temporary SharedPtr<Resource> released here (inlined in the original)

    void** tvt = *(void***)tex.pRep;
    int a = ((GetIntFn)tvt[0x64 / 4])(tex.pRep, 0);
    void** tvt2 = *(void***)tex.pRep;
    int b = ((GetIntFn)tvt2[0x60 / 4])(tex.pRep, 0);

    out->x0 = 0.0f;
    out->y0 = 0.0f;
    out->x1 = (float)(unsigned int)a;
    out->y1 = (float)(unsigned int)b;

    // tex destroyed here
    releaseRef(source);
    return out;
}
