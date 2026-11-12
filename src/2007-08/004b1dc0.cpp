// from server: 100% by EspClaude
// from server: 51% by colin
// roc 2007-08 004b1dc0  unit: RBX::Network::VReplicator::?$BoundFuncDesc  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b1dc0
//
// 004b1dc0  6aff                 push -1
// 004b1dc2  6878237400           push 0x742378
// 004b1dc7  64a100000000         mov eax, dword ptr fs:[0]
// 004b1dcd  50                   push eax
// 004b1dce  51                   push ecx
// 004b1dcf  56                   push esi
// 004b1dd0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b1dd5  33c4                 xor eax, esp
// 004b1dd7  50                   push eax
// 004b1dd8  8d44240c             lea eax, [esp + 0xc]
// 004b1ddc  64a300000000         mov dword ptr fs:[0], eax
// 004b1de2  8bf1                 mov esi, ecx
// 004b1de4  89742408             mov dword ptr [esp + 8], esi
// 004b1de8  e8d38cfaff           call 0x45aac0
// 004b1ded  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004b1df1  8d8e10010000         lea ecx, [esi + 0x110]
// 004b1df7  c70644dc7900         mov dword ptr [esi], 0x79dc44
// 004b1dfd  c746043cdc7900       mov dword ptr [esi + 4], 0x79dc3c
// 004b1e04  c7461034dc7900       mov dword ptr [esi + 0x10], 0x79dc34
// 004b1e0b  c7461424dc7900       mov dword ptr [esi + 0x14], 0x79dc24
// 004b1e12  c7462c14dc7900       mov dword ptr [esi + 0x2c], 0x79dc14
// 004b1e19  c7464404dc7900       mov dword ptr [esi + 0x44], 0x79dc04
// 004b1e20  c7465cf4db7900       mov dword ptr [esi + 0x5c], 0x79dbf4
// 004b1e27  c74674e4db7900       mov dword ptr [esi + 0x74], 0x79dbe4
// 004b1e2e  c7868c000000d4db7900 mov dword ptr [esi + 0x8c], 0x79dbd4
// 004b1e38  b840995b00           mov eax, 0x5b9940
// 004b1e3d  52                   push edx
// 004b1e3e  50                   push eax
// 004b1e3f  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004b1e47  c70100000000         mov dword ptr [ecx], 0
// 004b1e4d  c7410400000000       mov dword ptr [ecx + 4], 0
// 004b1e54  c7410800000000       mov dword ptr [ecx + 8], 0
// 004b1e5b  e830acffff           call 0x4aca90
// 004b1e60  8bc6                 mov eax, esi
// 004b1e62  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b1e66  64890d00000000       mov dword ptr fs:[0], ecx
// 004b1e6d  59                   pop ecx
// 004b1e6e  5e                   pop esi
// 004b1e6f  83c410               add esp, 0x10
// 004b1e72  c20400               ret 4

// Sub-object vptr offsets 0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c and the
// member at 0x110 are read off the stores in the target.
struct S0 { virtual ~S0(); };
struct S1 { virtual ~S1(); int pad_[2]; };   // 0x04..0x10
struct S2 { virtual ~S2(); };                // 0x10
struct S3 { virtual ~S3(); int pad_[5]; };   // 0x14..0x2c
struct S4 { virtual ~S4(); int pad_[5]; };   // 0x2c..0x44
struct S5 { virtual ~S5(); int pad_[5]; };   // 0x44..0x5c
struct S6 { virtual ~S6(); int pad_[5]; };   // 0x5c..0x74
struct S7 { virtual ~S7(); int pad_[5]; };   // 0x74..0x8c
struct S8 { virtual ~S8(); int pad_[0x20]; };// 0x8c..0x110

struct FuncDesc : S0, S1, S2, S3, S4, S5, S6, S7, S8 {
    FuncDesc();
    virtual ~FuncDesc();
};

struct Binder { void (*fn)(void*); void* arg; };

struct FunctionBase {
    void* vtable; void* obj; void* extra;
    FunctionBase() : vtable(0), obj(0), extra(0) {}
};
struct Function : FunctionBase {
    Function(Binder b) { assign_to(b); }
    ~Function();
    void assign_to(Binder b);
};

extern void boundHandler(void*);

static Binder makeBinder(void* arg) { Binder b; b.fn = &boundHandler; b.arg = arg; return b; }

struct BoundFuncDesc : FuncDesc {
    Function function;   // +0x110
    BoundFuncDesc(void* arg);
};

BoundFuncDesc::BoundFuncDesc(void* arg)
    : function(makeBinder(arg))
{
}
