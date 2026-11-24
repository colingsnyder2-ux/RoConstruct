// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace Ogre {
class __declspec(dllimport) Viewport {
public:
    bool getShadowsEnabled() const;
};
}

// INFERRED: the argument is a struct pointer with a 16-bit count at offset 4.
struct fn_0068bf80_Arg {
    int unk0;
    unsigned short count;
};

// INFERRED: the class is unknown, so its fields are accessed by raw byte offset.
struct fn_0068bf80_Self;

typedef bool (__thiscall *fn_0068bf80_VFn)(void*);

extern "C" bool __fastcall fn_0068bf80(fn_0068bf80_Self* self, int unusedEdx, const fn_0068bf80_Arg* arg)
{
    char* base = reinterpret_cast<char*>(self);

    if (*(base + 0x8b82) == 0) {
        Ogre::Viewport* vp = *reinterpret_cast<Ogre::Viewport**>(base + 0xbc);
        if (vp->getShadowsEnabled()) {
            void** vtbl = *reinterpret_cast<void***>(base);
            fn_0068bf80_VFn fn = reinterpret_cast<fn_0068bf80_VFn>(vtbl[0x2f0 / 4]);
            int mode;
            bool hit = false;
            if (fn(self)) {
                mode = *reinterpret_cast<int*>(base + 0x8a54);
                if (mode == 2)
                    hit = true;
            }
            if (!hit) {
                mode = *reinterpret_cast<int*>(base + 0x8a54);
                if (mode == 1 || *(base + 0x8b81) != 0)
                    hit = true;
            }
            if (hit) {
                if (arg->count > 0)
                    return false;
            }
        }
    }
    return true;
}
