// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 00544bd0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00544bd0
//
// 00544bd0  6aff                 push -1
// 00544bd2  6851187500           push 0x751851
// 00544bd7  64a100000000         mov eax, dword ptr fs:[0]
// 00544bdd  50                   push eax
// 00544bde  64892500000000       mov dword ptr fs:[0], esp
// 00544be5  83ec20               sub esp, 0x20
// 00544be8  56                   push esi
// 00544be9  8bf1                 mov esi, ecx
// 00544beb  89742404             mov dword ptr [esp + 4], esi
// 00544bef  e82cffffff           call 0x544b20
// 00544bf4  68b8677a00           push 0x7a67b8
// 00544bf9  8d4c240c             lea ecx, [esp + 0xc]
// 00544bfd  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00544c05  c7065c6c7a00         mov dword ptr [esi], 0x7a6c5c
// 00544c0b  c74604546c7a00       mov dword ptr [esi + 4], 0x7a6c54
// 00544c12  c746104c6c7a00       mov dword ptr [esi + 0x10], 0x7a6c4c
// 00544c19  c746143c6c7a00       mov dword ptr [esi + 0x14], 0x7a6c3c
// 00544c20  c7462c2c6c7a00       mov dword ptr [esi + 0x2c], 0x7a6c2c
// 00544c27  c746441c6c7a00       mov dword ptr [esi + 0x44], 0x7a6c1c
// 00544c2e  c7465c0c6c7a00       mov dword ptr [esi + 0x5c], 0x7a6c0c
// 00544c35  c74674fc6b7a00       mov dword ptr [esi + 0x74], 0x7a6bfc
// 00544c3c  c7868c000000ec6b7a00 mov dword ptr [esi + 0x8c], 0x7a6bec
// 00544c46  ff1598e67700         call dword ptr [0x77e698]
// 00544c4c  8d442408             lea eax, [esp + 8]
// 00544c50  50                   push eax
// 00544c51  8bce                 mov ecx, esi
// 00544c53  c644243001           mov byte ptr [esp + 0x30], 1
// 00544c58  e893cfffff           call 0x541bf0
// 00544c5d  8d4c2408             lea ecx, [esp + 8]
// 00544c61  c644242c00           mov byte ptr [esp + 0x2c], 0
// 00544c66  ff15ace67700         call dword ptr [0x77e6ac]
// 00544c6c  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00544c70  893544af8b00         mov dword ptr [0x8baf44], esi
// 00544c76  8bc6                 mov eax, esi
// 00544c78  5e                   pop esi
// 00544c79  64890d00000000       mov dword ptr fs:[0], ecx
// 00544c80  83c42c               add esp, 0x2c
// 00544c83  c3                   ret 
// Derived-class constructor: base ctor 0x544b20, then the derived vfptrs at the base-subobject
// offsets the target stores (0,4,0x10,0x14,0x2c,0x44,0x5c,0x74,0x8c), then
// setName(std::string("DebugSettings")) (0x541bf0, thiscall, const std::string&), then the
// singleton pointer store. Subobject sizes are only the gaps between those proven offsets.

#include <string>

struct S0  { virtual void s0(); };
struct S4  { virtual void s4();  int pad[2]; };   // 0x04..0x10
struct S10 { virtual void s10(); };               // 0x10..0x14
struct S14 { virtual void s14(); int pad[5]; };   // 0x14..0x2c
struct S2c { virtual void s2c(); int pad[5]; };   // 0x2c..0x44
struct S44 { virtual void s44(); int pad[5]; };   // 0x44..0x5c
struct S5c { virtual void s5c(); int pad[5]; };   // 0x5c..0x74
struct S74 { virtual void s74(); int pad[5]; };   // 0x74..0x8c
struct S8c { virtual void s8c(); };               // 0x8c

struct Base : S0, S4, S10, S14, S2c, S44, S5c, S74, S8c {
    Base();                                   // 0x544b20
    ~Base();
    void setName(const std::string &name);    // 0x541bf0
};

struct DebugSettings : Base {
    DebugSettings();
    virtual void s0();
    static DebugSettings *singleton;          // 0x8baf44
};

DebugSettings::DebugSettings()
{
    {
        std::string name("DebugSettings");
        setName(name);
    }
    singleton = this;
}
