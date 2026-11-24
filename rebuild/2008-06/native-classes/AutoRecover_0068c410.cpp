// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were available, so the types below are minimal local stand-ins.
namespace Ogre {
    class Matrix4 {
    public:
        float m[4][4];
        __declspec(dllimport) static const Matrix4 IDENTITY;
    };
}

// INFERRED: the class and argument types are unknown; members are reached by raw offset.
struct Renderer;
struct StateArg;

typedef void (__stdcall *SetMatrixFn)(const Ogre::Matrix4* m);
typedef void (__stdcall *MulMatrixFn)(const Ogre::Matrix4* a, Ogre::Matrix4* out, int flag);
typedef void (__stdcall *ApplyMatrixFn)(Ogre::Matrix4* m);

extern "C" void __fastcall fn_0068c410(Renderer* self, int unusedEdx, StateArg* arg)
{
    char* s = reinterpret_cast<char*>(self);
    char* a = reinterpret_cast<char*>(arg);
    Ogre::Matrix4 tmp;

    if (a[0x26]) {
        // INFERRED: device object at this+0x34 exposes a vtable; slot 0x68 sets a matrix
        void* dev = *reinterpret_cast<void**>(s + 0x34);
        void** vt = *reinterpret_cast<void***>(dev);
        // INFERRED: thiscall with one stack arg; callee pops it
        reinterpret_cast<SetMatrixFn>(vt[0x68 / 4])(&Ogre::Matrix4::IDENTITY);
        s[0x41d8] = 1;
    }
    if (a[0x25]) {
        void* dev = *reinterpret_cast<void**>(s + 0x34);
        void** vt = *reinterpret_cast<void***>(dev);
        reinterpret_cast<MulMatrixFn>(vt[0x110 / 4])(&Ogre::Matrix4::IDENTITY, &tmp, 0);
        dev = *reinterpret_cast<void**>(s + 0x34);
        vt = *reinterpret_cast<void***>(dev);
        reinterpret_cast<ApplyMatrixFn>(vt[0x6c / 4])(&tmp);
        s[0x41d9] = 1;
    }
}
