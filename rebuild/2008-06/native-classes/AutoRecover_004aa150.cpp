// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <typeinfo>

// INFERRED: no native headers were provided, so every type here is a local
// stand-in that follows the disassembly offsets. The members have non-trivial
// destructors so that the compiler emits the same EH state numbers
// (0, 1, 2, 4, 6, 8, 0xa, 0xc) as the original constructor.

namespace RBX {
namespace Reflection {
class EnumDescriptor {
protected:
    EnumDescriptor(const char* name, const type_info& ti);   // 0x56c590
    virtual ~EnumDescriptor();
    char base[0x2c];
};
}
}

extern "C" int fn_006a0920(int a1);
extern "C" void __fastcall fn_00446110(void* self, int unusedEdx, char* a, char* b);
extern "C" void __fastcall fn_0064d530(void* self, int unusedEdx, int value, const char* name);

extern "C" const type_info g_0093a8e0;   // INFERRED: type_info of the enum type

struct MapMember {                       // 0x20 bytes
    char data[0x20];
    __forceinline MapMember()
    {
        char a, b;
        fn_00446110(this, 0, &a, &b);
    }
    ~MapMember() { *(volatile int*)this = 0; }
};

struct ListBase {
    ~ListBase() { *(volatile int*)this = 0; }
};

struct ListMember : ListBase {           // 0x18 bytes
    ListMember** node;                   // +0x00
    int pad[2];
    int a;                               // +0x0c
    int b;                               // +0x10
    int c;                               // +0x14
    __forceinline ListMember()
    {
        ListMember** p = (ListMember**)fn_006a0920(4);
        if (p) {
            *p = this;
        } else {
            p = 0;
        }
        node = p;
        a = 0;
        b = 0;
        c = 0;
    }
    ~ListMember() { *(volatile int*)this = 0; }
};

#pragma warning(disable: 4291)
struct PhysicsSendMethodDesc : RBX::Reflection::EnumDescriptor {
    MapMember map1;     // +0x30
    MapMember map2;     // +0x50
    ListMember l0;      // +0x70
    ListMember l1;      // +0x88
    ListMember l2;      // +0xa0
    ListMember l3;      // +0xb8
    ListMember l4;      // +0xd0

    // INFERRED: non-throw placement new so no null check is emitted
    static __forceinline void* operator new(unsigned int, void* p) { return p; }

    __forceinline PhysicsSendMethodDesc()
        : EnumDescriptor("PhysicsSendMethod", g_0093a8e0)
    {
        fn_0064d530(this, 0, 0, "ErrorComputation");
        fn_0064d530(this, 0, 1, "RoundRobin");
    }
    ~PhysicsSendMethodDesc() {}
};

extern "C" PhysicsSendMethodDesc* __fastcall fn_004aa150(PhysicsSendMethodDesc* self, int unusedEdx)
{
    return new (self) PhysicsSendMethodDesc();
}
