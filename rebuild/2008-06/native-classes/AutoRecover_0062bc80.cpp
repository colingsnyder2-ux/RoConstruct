// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
class FlagStand;
class PartInstance;
extern char sFlagStand[];

template<class Class, class Base, const char* ClassName>
class FactoryProduct;
}

typedef RBX::FactoryProduct<RBX::FlagStand, RBX::PartInstance,
    RBX::sFlagStand> FlagStandFactoryProduct;

// INFERRED: Storage view exposes the constructor's hidden most-derived flag.
struct FlagStandFactoryProductStorage
{
    unsigned int data[257];
    void __thiscall constructPartInstanceBase(int mostDerived);
};

#pragma comment(linker, "/alternatename:?constructPartInstanceBase@FlagStandFactoryProductStorage@@QAEXH@Z=??0PartInstance@RBX@@QAE@XZ")

extern "C" {
extern char g_00849e6c[];
extern char g_00846144[];
extern char g_0084601c[];
extern char g_00846010[];
extern char g_00846008[];
extern char g_00846000[];
extern char g_00845ff0[];
extern char g_00845fe0[];
extern char g_00845fd0[];
extern char g_00845fc0[];
extern char g_00845fb0[];
extern char g_00845fa0[];
extern char g_00845f94[];
extern char g_00845f84[];
extern char g_00845f78[];
extern char g_00845f60[];
extern char g_00845f54[];
extern char g_00845f4c[];
extern char g_00845f30[];
}

// MSVC 2008 byte match unverified for this translation unit.
extern "C" FlagStandFactoryProduct* __fastcall fn_0062bc80(
    FlagStandFactoryProduct* self, int unusedEdx, int initialize)
{
    FlagStandFactoryProductStorage* storage =
        reinterpret_cast<FlagStandFactoryProductStorage*>(self);
    volatile int state = 0;

    if (initialize)
    {
        storage->data[0x134 / 4] = reinterpret_cast<unsigned int>(g_00849e6c);
        storage->data[0x400 / 4] = reinterpret_cast<unsigned int>(g_00846144);
    }

    storage->constructPartInstanceBase(0);

    unsigned int* table = (unsigned int*)storage->data[0x134 / 4];

    storage->data[0] = reinterpret_cast<unsigned int>(g_0084601c);
    storage->data[0x10 / 4] = reinterpret_cast<unsigned int>(g_00846010);
    storage->data[0x14 / 4] = reinterpret_cast<unsigned int>(g_00846008);
    storage->data[0x20 / 4] = reinterpret_cast<unsigned int>(g_00846000);
    storage->data[0x24 / 4] = reinterpret_cast<unsigned int>(g_00845ff0);
    storage->data[0x44 / 4] = reinterpret_cast<unsigned int>(g_00845fe0);
    storage->data[0x64 / 4] = reinterpret_cast<unsigned int>(g_00845fd0);
    storage->data[0x84 / 4] = reinterpret_cast<unsigned int>(g_00845fc0);
    storage->data[0xa4 / 4] = reinterpret_cast<unsigned int>(g_00845fb0);
    storage->data[0xc4 / 4] = reinterpret_cast<unsigned int>(g_00845fa0);
    storage->data[0x130 / 4] = reinterpret_cast<unsigned int>(g_00845f94);
    storage->data[0x1a0 / 4] = reinterpret_cast<unsigned int>(g_00845f84);
    storage->data[0x1c0 / 4] = reinterpret_cast<unsigned int>(g_00845f78);
    storage->data[0x1cc / 4] = reinterpret_cast<unsigned int>(g_00845f60);

    *(unsigned int*)((char*)storage + 0x134 + table[1]) =
        reinterpret_cast<unsigned int>(g_00845f54);
    *(unsigned int*)((char*)storage + 0x134 +
        ((unsigned int*)storage->data[0x134 / 4])[2]) =
        reinterpret_cast<unsigned int>(g_00845f4c);
    *(unsigned int*)((char*)storage + 0x134 +
        ((unsigned int*)storage->data[0x134 / 4])[3]) =
        reinterpret_cast<unsigned int>(g_00845f30);

    unsigned int offset = ((unsigned int*)storage->data[0x134 / 4])[1];
    *(unsigned int*)((char*)storage + 0x130 + offset) = offset - 0x2b8;

    offset = ((unsigned int*)storage->data[0x134 / 4])[2];
    *(unsigned int*)((char*)storage + 0x130 + offset) = offset - 0x2c0;

    offset = ((unsigned int*)storage->data[0x134 / 4])[3];
    *(unsigned int*)((char*)storage + 0x130 + offset) = offset - 0x2c8;

    return self;
}
