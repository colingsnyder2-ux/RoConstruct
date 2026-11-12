// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 58% by colin
// roc 2007-08 0055f690  unit: RBX::ClearBackpack  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f690
//
// 0055f690  6aff                 push -1
// 0055f692  68bdac7500           push 0x75acbd
// 0055f697  64a100000000         mov eax, dword ptr fs:[0]
// 0055f69d  50                   push eax
// 0055f69e  64892500000000       mov dword ptr fs:[0], esp
// 0055f6a5  83ec20               sub esp, 0x20
// 0055f6a8  56                   push esi
// 0055f6a9  8bf1                 mov esi, ecx
// 0055f6ab  89742404             mov dword ptr [esp + 4], esi
// 0055f6af  e86c57eeff           call 0x444e20
// 0055f6b4  c786e800000084917a00 mov dword ptr [esi + 0xe8], 0x7a9184
// 0055f6be  33c0                 xor eax, eax
// 0055f6c0  c706a4927a00         mov dword ptr [esi], 0x7a92a4
// 0055f6c6  c7460498927a00       mov dword ptr [esi + 4], 0x7a9298
// 0055f6cd  c7461090927a00       mov dword ptr [esi + 0x10], 0x7a9290
// 0055f6d4  c7461480927a00       mov dword ptr [esi + 0x14], 0x7a9280
// 0055f6db  c7462c70927a00       mov dword ptr [esi + 0x2c], 0x7a9270
// 0055f6e2  c7464460927a00       mov dword ptr [esi + 0x44], 0x7a9260
// 0055f6e9  c7465c50927a00       mov dword ptr [esi + 0x5c], 0x7a9250
// 0055f6f0  c7467440927a00       mov dword ptr [esi + 0x74], 0x7a9240
// 0055f6f7  c7868c00000030927a00 mov dword ptr [esi + 0x8c], 0x7a9230
// 0055f701  c786e800000028927a00 mov dword ptr [esi + 0xe8], 0x7a9228
// 0055f70b  8986ec000000         mov dword ptr [esi + 0xec], eax
// 0055f711  8944242c             mov dword ptr [esp + 0x2c], eax
// 0055f715  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0055f71b  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 0055f721  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0055f727  898600010000         mov dword ptr [esi + 0x100], eax
// 0055f72d  6810927a00           push 0x7a9210
// 0055f732  8d4c240c             lea ecx, [esp + 0xc]
// 0055f736  c644243002           mov byte ptr [esp + 0x30], 2
// 0055f73b  ff1598e67700         call dword ptr [0x77e698]
// 0055f741  8d442408             lea eax, [esp + 8]
// 0055f745  50                   push eax
// 0055f746  8bce                 mov ecx, esi
// 0055f748  c644243003           mov byte ptr [esp + 0x30], 3
// 0055f74d  e89e24feff           call 0x541bf0
// 0055f752  8d4c2408             lea ecx, [esp + 8]
// 0055f756  c644242c02           mov byte ptr [esp + 0x2c], 2
// 0055f75b  ff15ace67700         call dword ptr [0x77e6ac]
// 0055f761  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0055f765  8bc6                 mov eax, esi
// 0055f767  5e                   pop esi
// 0055f768  64890d00000000       mov dword ptr fs:[0], ecx
// 0055f76f  83c42c               add esp, 0x2c
// 0055f772  c3                   ret 

#include <string>
#include <vector>

struct Item;

// Polymorphic subobjects of the base, at the vptr offsets the target rewrites.
struct I00 { virtual ~I00(); };
struct I04 { virtual void f04(); int pad[2]; };
struct I10 { virtual void f10(); };
struct I14 { virtual void f14(); int pad[5]; };
struct I2c { virtual void f2c(); int pad[5]; };
struct I44 { virtual void f44(); int pad[5]; };
struct I5c { virtual void f5c(); int pad[5]; };
struct I74 { virtual void f74(); int pad[5]; };
struct I8c { virtual void f8c(); int pad[22]; };

struct Command : I00, I04, I10, I14, I2c, I44, I5c, I74, I8c {
    Command();
    void setName(const std::string& name);
};

struct Listener {
    virtual void onEvent() = 0;
};

struct ScopedPtr {
    void* p;
    ScopedPtr() : p(0) {}
    ~ScopedPtr();
};

struct FilteredSelection : Command, Listener {
    void onEvent();
    int id;
    ScopedPtr owner;
    std::vector<Item*> items;
    FilteredSelection();
};

FilteredSelection::FilteredSelection() : id(0)
{
    setName("FilteredSelection");
}
