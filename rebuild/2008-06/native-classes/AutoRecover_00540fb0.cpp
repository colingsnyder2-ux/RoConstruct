// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <ios>
#include <new>

// INFERRED: minimal declaration of RakNet::BitStream; only GetWriteOffset is needed here.
namespace RakNet {
class BitStream {
public:
    int GetWriteOffset() const;
};
}

extern "C" int __fastcall fn_00542770(void* self, int unusedEdx, int a1);

// INFERRED: the class derives from std::ios_base (ios_base ctor is called first),
// then its vtable is set, the dword at +4 is cleared, and an init helper is called
// with the BitStream write offset.
struct Fn00540fb0Stream : public std::ios_base {
    Fn00540fb0Stream(RakNet::BitStream* bs)
        : std::ios_base()
    {
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 0;
        fn_00542770(this, 0, bs->GetWriteOffset());
    }
    virtual ~Fn00540fb0Stream() {}
};

extern "C" void* __fastcall fn_00540fb0(void* self, int unusedEdx, RakNet::BitStream* bs)
{
    return new (self) Fn00540fb0Stream(bs);
}
