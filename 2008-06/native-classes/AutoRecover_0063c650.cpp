// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
class Seat;
class PartInstance;
extern char sSeat[];

template<class Class, class Base, const char* ClassName>
class FactoryProduct;
}

typedef RBX::FactoryProduct<RBX::Seat, RBX::PartInstance, RBX::sSeat> SeatFactoryProduct;

// INFERRED: Storage view exposes the hidden most-derived argument of RBX::PartInstance::PartInstance().
struct SeatFactoryProductStorage {
    unsigned char data[0x404];
    void __thiscall constructPartInstanceBase(int mostDerived);
};

#pragma comment(linker, "/alternatename:?constructPartInstanceBase@SeatFactoryProductStorage@@QAEXH@Z=??0PartInstance@RBX@@QAE@XZ")

extern "C" {
extern char g_00849e6c[];
extern char g_00846144[];
extern char g_00849c8c[];
extern char g_00849c7c[];
extern char g_00849c74[];
extern char g_00849c6c[];
extern char g_00849c5c[];
extern char g_00849c4c[];
extern char g_00849c3c[];
extern char g_00849c2c[];
extern char g_00849c1c[];
extern char g_00849c0c[];
extern char g_00849c00[];
extern char g_00849bf0[];
extern char g_00849be4[];
extern char g_00849bcc[];
extern char g_00849bc0[];
extern char g_00849bb8[];
extern char g_00849b9c[];
}

// MSVC 2008 byte match unverified for this translation unit.
extern "C" SeatFactoryProduct* __fastcall fn_0063c650(SeatFactoryProduct* self, int unusedEdx, int initialize)
{
    volatile int state = 0;
    unsigned char* data = reinterpret_cast<SeatFactoryProductStorage*>(self)->data;

    if (initialize) {
        *(int*)(data + 0x134) = reinterpret_cast<int>(g_00849e6c);
        *(int*)(data + 0x400) = reinterpret_cast<int>(g_00846144);
    }

    reinterpret_cast<SeatFactoryProductStorage*>(self)->constructPartInstanceBase(0);

    int* table = *(int**)(data + 0x134);
    *(int*)(data + 0x000) = reinterpret_cast<int>(g_00849c8c);
    *(int*)(data + 0x010) = reinterpret_cast<int>(g_00849c7c);
    *(int*)(data + 0x014) = reinterpret_cast<int>(g_00849c74);
    *(int*)(data + 0x020) = reinterpret_cast<int>(g_00849c6c);
    *(int*)(data + 0x024) = reinterpret_cast<int>(g_00849c5c);
    *(int*)(data + 0x044) = reinterpret_cast<int>(g_00849c4c);
    *(int*)(data + 0x064) = reinterpret_cast<int>(g_00849c3c);
    *(int*)(data + 0x084) = reinterpret_cast<int>(g_00849c2c);
    *(int*)(data + 0x0a4) = reinterpret_cast<int>(g_00849c1c);
    *(int*)(data + 0x0c4) = reinterpret_cast<int>(g_00849c0c);
    *(int*)(data + 0x130) = reinterpret_cast<int>(g_00849c00);
    *(int*)(data + 0x1a0) = reinterpret_cast<int>(g_00849bf0);
    *(int*)(data + 0x1c0) = reinterpret_cast<int>(g_00849be4);
    *(int*)(data + 0x1cc) = reinterpret_cast<int>(g_00849bcc);

    *(int*)(data + table[1] + 0x134) = reinterpret_cast<int>(g_00849bc0);
    *(int*)(data + (*(int**)(data + 0x134))[2] + 0x134) = reinterpret_cast<int>(g_00849bb8);
    *(int*)(data + (*(int**)(data + 0x134))[3] + 0x134) = reinterpret_cast<int>(g_00849b9c);

    int offset = (*(int**)(data + 0x134))[1];
    *(int*)(data + offset + 0x130) = offset - 0x2b8;
    offset = (*(int**)(data + 0x134))[2];
    *(int*)(data + offset + 0x130) = offset - 0x2c0;
    offset = (*(int**)(data + 0x134))[3];
    *(int*)(data + offset + 0x130) = offset - 0x2c8;

    return self;
}
