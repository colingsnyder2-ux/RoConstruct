// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
class PartInstance;
class SpawnLocation;
extern char sSpawnLocation[];

template<class Class, class Base, const char* ClassName>
class FactoryProduct;
}

typedef RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance,
    RBX::sSpawnLocation> SpawnLocationFactoryProduct;

// INFERRED: The ABI view exposes the hidden most-derived argument as an int.
struct SpawnLocationFactoryProductStorage {
    unsigned int data[257];
    void __thiscall constructPartInstanceBase(int mostDerived);
};

#pragma comment(linker, "/alternatename:?constructPartInstanceBase@SpawnLocationFactoryProductStorage@@QAEXH@Z=??0PartInstance@RBX@@QAE@XZ")

extern "C" {
extern char g_00849e6c[];
extern char g_00846144[];
extern char g_0083bb3c[];
extern char g_0083bb2c[];
extern char g_0083bb24[];
extern char g_0083bb1c[];
extern char g_0083bb0c[];
extern char g_0083bafc[];
extern char g_0083baec[];
extern char g_0083badc[];
extern char g_0083bacc[];
extern char g_0083babc[];
extern char g_0083bab0[];
extern char g_0083baa0[];
extern char g_0083ba94[];
extern char g_0083ba7c[];
extern char g_0083ba70[];
extern char g_0083ba68[];
extern char g_0083ba4c[];
}

// MSVC 2008 byte match unverified for this translation unit.
extern "C" SpawnLocationFactoryProduct* __fastcall fn_005d1fa0(
    SpawnLocationFactoryProduct* self, int unusedEdx, int complete)
{
    SpawnLocationFactoryProductStorage* storage =
        reinterpret_cast<SpawnLocationFactoryProductStorage*>(self);
    volatile int state = 0;
    if (complete) {
        storage->data[0x134 / 4] = reinterpret_cast<unsigned int>(g_00849e6c);
        storage->data[0x400 / 4] = reinterpret_cast<unsigned int>(g_00846144);
    }

    storage->constructPartInstanceBase(0);

    int* table = (int*)storage->data[0x134 / 4];
    storage->data[0] = reinterpret_cast<unsigned int>(g_0083bb3c);
    storage->data[0x10 / 4] = reinterpret_cast<unsigned int>(g_0083bb2c);
    storage->data[0x14 / 4] = reinterpret_cast<unsigned int>(g_0083bb24);
    storage->data[0x20 / 4] = reinterpret_cast<unsigned int>(g_0083bb1c);
    storage->data[0x24 / 4] = reinterpret_cast<unsigned int>(g_0083bb0c);
    storage->data[0x44 / 4] = reinterpret_cast<unsigned int>(g_0083bafc);
    storage->data[0x64 / 4] = reinterpret_cast<unsigned int>(g_0083baec);
    storage->data[0x84 / 4] = reinterpret_cast<unsigned int>(g_0083badc);
    storage->data[0xa4 / 4] = reinterpret_cast<unsigned int>(g_0083bacc);
    storage->data[0xc4 / 4] = reinterpret_cast<unsigned int>(g_0083babc);
    storage->data[0x130 / 4] = reinterpret_cast<unsigned int>(g_0083bab0);
    storage->data[0x1a0 / 4] = reinterpret_cast<unsigned int>(g_0083baa0);
    storage->data[0x1c0 / 4] = reinterpret_cast<unsigned int>(g_0083ba94);
    storage->data[0x1cc / 4] = reinterpret_cast<unsigned int>(g_0083ba7c);

    *(unsigned int*)((char*)storage + 0x134 + table[1]) =
        reinterpret_cast<unsigned int>(g_0083ba70);
    *(unsigned int*)((char*)storage + 0x134 +
        ((int*)storage->data[0x134 / 4])[2]) =
        reinterpret_cast<unsigned int>(g_0083ba68);
    *(unsigned int*)((char*)storage + 0x134 +
        ((int*)storage->data[0x134 / 4])[3]) =
        reinterpret_cast<unsigned int>(g_0083ba4c);

    int offset = ((int*)storage->data[0x134 / 4])[1];
    *(int*)((char*)storage + 0x130 + offset) = offset - 0x2b8;
    offset = ((int*)storage->data[0x134 / 4])[2];
    *(int*)((char*)storage + 0x130 + offset) = offset - 0x2c0;
    offset = ((int*)storage->data[0x134 / 4])[3];
    *(int*)((char*)storage + 0x130 + offset) = offset - 0x2c8;

    return self;
}
