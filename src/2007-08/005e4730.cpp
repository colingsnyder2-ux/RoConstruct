// from server: 100% by EspClaude
// from server: 53% by colin
// roc 2007-08 005e4730  unit: RBX::BoxSelectCommand  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e4730
//
// 005e4730  6aff                 push -1
// 005e4732  68bdac7500           push 0x75acbd
// 005e4737  64a100000000         mov eax, dword ptr fs:[0]
// 005e473d  50                   push eax
// 005e473e  64892500000000       mov dword ptr fs:[0], esp
// 005e4745  83ec20               sub esp, 0x20
// 005e4748  56                   push esi
// 005e4749  8bf1                 mov esi, ecx
// 005e474b  89742404             mov dword ptr [esp + 4], esi
// 005e474f  e8cc06e6ff           call 0x444e20
// 005e4754  c786e800000084917a00 mov dword ptr [esi + 0xe8], 0x7a9184
// 005e475e  33c0                 xor eax, eax
// 005e4760  c70664d17b00         mov dword ptr [esi], 0x7bd164
// 005e4766  c746045cd17b00       mov dword ptr [esi + 4], 0x7bd15c
// 005e476d  c7461054d17b00       mov dword ptr [esi + 0x10], 0x7bd154
// 005e4774  c7461444d17b00       mov dword ptr [esi + 0x14], 0x7bd144
// 005e477b  c7462c34d17b00       mov dword ptr [esi + 0x2c], 0x7bd134
// 005e4782  c7464424d17b00       mov dword ptr [esi + 0x44], 0x7bd124
// 005e4789  c7465c14d17b00       mov dword ptr [esi + 0x5c], 0x7bd114
// 005e4790  c7467404d17b00       mov dword ptr [esi + 0x74], 0x7bd104
// 005e4797  c7868c000000f4d07b00 mov dword ptr [esi + 0x8c], 0x7bd0f4
// 005e47a1  c786e8000000ecd07b00 mov dword ptr [esi + 0xe8], 0x7bd0ec
// 005e47ab  8986ec000000         mov dword ptr [esi + 0xec], eax
// 005e47b1  8944242c             mov dword ptr [esp + 0x2c], eax
// 005e47b5  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 005e47bb  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 005e47c1  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 005e47c7  898600010000         mov dword ptr [esi + 0x100], eax
// 005e47cd  6810927a00           push 0x7a9210
// 005e47d2  8d4c240c             lea ecx, [esp + 0xc]
// 005e47d6  c644243002           mov byte ptr [esp + 0x30], 2
// 005e47db  ff1598e67700         call dword ptr [0x77e698]
// 005e47e1  8d442408             lea eax, [esp + 8]
// 005e47e5  50                   push eax
// 005e47e6  8bce                 mov ecx, esi
// 005e47e8  c644243003           mov byte ptr [esp + 0x30], 3
// 005e47ed  e8fed3f5ff           call 0x541bf0
// 005e47f2  8d4c2408             lea ecx, [esp + 8]
// 005e47f6  c644242c02           mov byte ptr [esp + 0x2c], 2
// 005e47fb  ff15ace67700         call dword ptr [0x77e6ac]
// 005e4801  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005e4805  8bc6                 mov eax, esi
// 005e4807  5e                   pop esi
// 005e4808  64890d00000000       mov dword ptr fs:[0], ecx
// 005e480f  83c42c               add esp, 0x2c
// 005e4812  c3                   ret 

// roc-flags: /O2 /GS- /EHsc /MD
// No security cookie in the EH frame (/GS-, as the rbxgs DataModel.cpp library recipe).
#include <string>
#include <vector>

// Polymorphic subobjects of the out-of-line base (ctor 0x444e20) sit at the offsets the
// target rewrites vptrs at: 0, 4, 0x10, 0x14, 0x2c, 0x44, 0x5c, 0x74, 0x8c; base size 0xe8.
struct P00 { virtual void f00(); };
struct P04 { virtual void f04(); char pad[0x10 - 0x04 - 4]; };
struct P10 { virtual void f10(); };
struct P14 { virtual void f14(); char pad[0x2c - 0x14 - 4]; };
struct P2c { virtual void f2c(); char pad[0x44 - 0x2c - 4]; };
struct P44 { virtual void f44(); char pad[0x5c - 0x44 - 4]; };
struct P5c { virtual void f5c(); char pad[0x74 - 0x5c - 4]; };
struct P74 { virtual void f74(); char pad[0x8c - 0x74 - 4]; };
struct P8c { virtual void f8c(); char pad[0xe8 - 0x8c - 4]; };

namespace RBX {
class Instance : public P00, public P04, public P10, public P14, public P2c,
                 public P44, public P5c, public P74, public P8c {
public:
    Instance();                                   // 0x444e20
    virtual ~Instance();
    void setName(const std::string& name);        // 0x541bf0
};

// Second base at +0xe8: inline ctor stores only its vptr.
class MouseCommandBase {
public:
    MouseCommandBase() {}
    virtual void onMouse();
};

struct OwnedRef {                                 // single pointer, zeroed inline
    void* p;
    OwnedRef() : p(0) {}
    ~OwnedRef();
};

class BoxSelectCommand : public Instance, public MouseCommandBase {
    void* ec;                                     // +0xec
    OwnedRef ref;                                 // +0xf0
    std::vector<void*> items;                     // +0xf4 (first/last/end at +0xf8..+0x100)
public:
    BoxSelectCommand();
    virtual ~BoxSelectCommand();
};

BoxSelectCommand::BoxSelectCommand()
    : ec(0)
{
    setName("FilteredSelection");
}
}
