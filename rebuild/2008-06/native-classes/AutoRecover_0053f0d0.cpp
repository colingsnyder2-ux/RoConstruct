// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: no class header was available, so the layout below is reconstructed from the disassembly.
// The unknown callees are declared with the fn_<addr> convention.
extern "C" int __fastcall fn_004d6f60(void* self, int unusedEdx, int arg); // chain_client<...> ctor
extern "C" int __fastcall fn_00540800(void* self, int unusedEdx);          // std::set<int> ctor
extern "C" int __fastcall fn_00540a80(void* self, int unusedEdx);

// INFERRED: the destructors are only declared. They are needed so the compiler emits the
// SEH unwind states 0, 1 and 2 seen in the disassembly.
struct ChainClientBase {
    ChainClientBase(int arg) { fn_004d6f60(this, 0, arg); }
    virtual ~ChainClientBase();
    int field4; // INFERRED: second dword of the base
};

struct IntSetMember {  // INFERRED: 0x20 bytes at +8
    char data[0x20];
    IntSetMember() { fn_00540800(this, 0); }
    ~IntSetMember();
};

struct SubMember {     // INFERRED: 0x20 bytes each at +0x28 and +0x48
    char data[0x20];
    SubMember() { fn_00540a80(this, 0); }
    ~SubMember();
};

struct DerivedClient : public ChainClientBase {
    IntSetMember set;
    SubMember a;
    SubMember b;
    DerivedClient(int arg) : ChainClientBase(arg) {}
    virtual ~DerivedClient();
};

extern "C" DerivedClient* __fastcall fn_0053f0d0(DerivedClient* self, int unusedEdx, int arg)
{
    return new (self) DerivedClient(arg);
}
