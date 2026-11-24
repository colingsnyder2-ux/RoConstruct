// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the owning class is unknown, so the object is accessed through raw
// byte offsets, and the virtual calls go through the vtable by offset.
namespace Ogre {
class Viewport {
public:
    __declspec(dllimport) bool getShadowsEnabled() const;
};
}

typedef bool (__fastcall *VBoolFn)(void* self, int unusedEdx);

struct ArgObj2 {
    virtual void v00() {}
};

static inline bool callVirt(void* obj, unsigned byteOffset)
{
    void** vtbl = *(void***)obj;
    VBoolFn fn = (VBoolFn)vtbl[byteOffset / 4];
    return fn(obj, 0);
}

// INFERRED: arg1 is a struct with a 16-bit count at +4; arg2 is an object with a virtual at vtable+0x30.
extern "C" bool __fastcall fn_0068bfe0(void* self, int unusedEdx, void* arg1, void* arg2)
{
    char* p = (char*)self;

    if (*(unsigned char*)(p + 0x8b82) == 0) {
        Ogre::Viewport* vp = *(Ogre::Viewport**)(p + 0xbc);
        if (vp->getShadowsEnabled()) {
            if (callVirt(self, 0x2ec)) {
                if (*(int*)(p + 0x8a54) == 2) {
                    if (callVirt(arg2, 0x30)) {
                        if (*(unsigned char*)(p + 0x8af8) == 0)
                            return false;
                    }
                }
                bool cond = false;
                if (callVirt(self, 0x2f0) && *(int*)(p + 0x8a54) == 2)
                    cond = true;
                else if (*(int*)(p + 0x8a54) == 1)
                    cond = true;
                else if (*(unsigned char*)(p + 0x8b81) != 0)
                    cond = true;
                if (cond) {
                    if (*(unsigned short*)((char*)arg1 + 4) != 0)
                        return false;
                }
            }
        }
    }
    return true;
}
