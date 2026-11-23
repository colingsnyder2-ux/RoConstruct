// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>
#include <new>

// INFERRED: no headers were provided, so the Ogre base class is declared locally.
// Its constructor is the rgmain import called through [0x8048e4].
namespace Ogre {
class SceneManager {
public:
    __declspec(dllimport) SceneManager(const std::string& name);
    __declspec(dllimport) virtual ~SceneManager();
    char pad[0x8bbc - 4]; // INFERRED: opaque base body up to 0x8bbc
};
}

extern "C" int fn_006a0920(int a1);

// INFERRED: small helper object allocated with 0x20 bytes (vtable 0x84e994)
struct SmObjA {
    virtual void vf0() {}
    void* owner;     // +4
    int   f8;        // +8
    char  fC;        // +0xc
    int   f10;       // +0x10
    int   f14;       // +0x14
};

// INFERRED: embedded sub-object at 0x8bd8 (vtable 0x84ec3c)
struct SmSubB {
    virtual void vf0() {}
    int f4;
    int f8;
};

// INFERRED: embedded sub-object at 0x8bf0 (vtable 0x84e9a4)
struct SmSubC {
    virtual void vf0() {}
    char pad[8];
    char fC;
};

struct SceneManagerDerived : public Ogre::SceneManager {
    std::string name;      // 0x8bbc
    SmSubB      subB;      // 0x8bd8
    int         pad8be4;
    SmObjA*     objA;      // 0x8be8
    SmSubC*     objCPtr;   // 0x8bec
    SmSubC      subC;      // 0x8bf0

    SceneManagerDerived(const std::string& n)
        : Ogre::SceneManager(n)
    {
        subB.f4 = 0;
        subB.f8 = 0;
        subC.fC = 0;
        SmObjA* p = (SmObjA*)fn_006a0920(0x20);
        if (p) {
            new (p) SmObjA();
            p->owner = this;
            p->f8 = 0;
            p->fC = 0;
            p->f10 = 0;
            p->f14 = 0;
        }
        objCPtr = &subC;
        objA = p;
    }
};

extern "C" SceneManagerDerived* __fastcall fn_0068e7c0(SceneManagerDerived* self, int unusedEdx, const std::string& n)
{
    return new (self) SceneManagerDerived(n);
}
