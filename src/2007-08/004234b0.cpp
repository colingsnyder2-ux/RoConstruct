// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2007-08 004234b0  unit: CSelectionTreeCtrl  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004234b0
//
// 004234b0  6aff                 push -1
// 004234b2  688ac07300           push 0x73c08a
// 004234b7  64a100000000         mov eax, dword ptr fs:[0]
// 004234bd  50                   push eax
// 004234be  51                   push ecx
// 004234bf  53                   push ebx
// 004234c0  55                   push ebp
// 004234c1  56                   push esi
// 004234c2  57                   push edi
// 004234c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004234c8  33c4                 xor eax, esp
// 004234ca  50                   push eax
// 004234cb  8d442418             lea eax, [esp + 0x18]
// 004234cf  64a300000000         mov dword ptr fs:[0], eax
// 004234d5  8bf1                 mov esi, ecx
// 004234d7  89742414             mov dword ptr [esp + 0x14], esi
// 004234db  e840e9ffff           call 0x421e20
// 004234e0  8dbeb8000000         lea edi, [esi + 0xb8]
// 004234e6  33db                 xor ebx, ebx
// 004234e8  8bcf                 mov ecx, edi
// 004234ea  895c2420             mov dword ptr [esp + 0x20], ebx
// 004234ee  e8cd3efeff           call 0x4073c0
// 004234f3  c786bc00000038837800 mov dword ptr [esi + 0xbc], 0x788338
// 004234fd  8daec0000000         lea ebp, [esi + 0xc0]
// 00423503  c7062c867800         mov dword ptr [esi], 0x78862c
// 00423509  c74654ac857800       mov dword ptr [esi + 0x54], 0x7885ac
// 00423510  c707a4857800         mov dword ptr [edi], 0x7885a4
// 00423516  c786bc00000098857800 mov dword ptr [esi + 0xbc], 0x788598
// 00423520  c7450018837800       mov dword ptr [ebp], 0x788318
// 00423527  895d04               mov dword ptr [ebp + 4], ebx
// 0042352a  8dbecc000000         lea edi, [esi + 0xcc]
// 00423530  8bcf                 mov ecx, edi
// 00423532  c644242003           mov byte ptr [esp + 0x20], 3
// 00423537  889ec8000000         mov byte ptr [esi + 0xc8], bl
// 0042353d  889ec9000000         mov byte ptr [esi + 0xc9], bl
// 00423543  889eca000000         mov byte ptr [esi + 0xca], bl
// 00423549  e862001600           call 0x5835b0
// 0042354e  894704               mov dword ptr [edi + 4], eax
// 00423551  c6401501             mov byte ptr [eax + 0x15], 1
// 00423555  8b4704               mov eax, dword ptr [edi + 4]
// 00423558  894004               mov dword ptr [eax + 4], eax
// 0042355b  8b4704               mov eax, dword ptr [edi + 4]
// 0042355e  8900                 mov dword ptr [eax], eax
// 00423560  8b4704               mov eax, dword ptr [edi + 4]
// 00423563  894008               mov dword ptr [eax + 8], eax
// 00423566  895f08               mov dword ptr [edi + 8], ebx
// 00423569  8dbed8000000         lea edi, [esi + 0xd8]
// 0042356f  8bcf                 mov ecx, edi
// 00423571  c644242004           mov byte ptr [esp + 0x20], 4
// 00423576  e8355e1800           call 0x5a93b0
// 0042357b  894704               mov dword ptr [edi + 4], eax
// 0042357e  c6401101             mov byte ptr [eax + 0x11], 1
// 00423582  8b4704               mov eax, dword ptr [edi + 4]
// 00423585  894004               mov dword ptr [eax + 4], eax
// 00423588  8b4704               mov eax, dword ptr [edi + 4]
// 0042358b  8900                 mov dword ptr [eax], eax
// 0042358d  8b4704               mov eax, dword ptr [edi + 4]
// 00423590  894008               mov dword ptr [eax + 8], eax
// 00423593  895f08               mov dword ptr [edi + 8], ebx
// 00423596  899ee4000000         mov dword ptr [esi + 0xe4], ebx
// 0042359c  899ee8000000         mov dword ptr [esi + 0xe8], ebx
// 004235a2  899eec000000         mov dword ptr [esi + 0xec], ebx
// 004235a8  6a67                 push 0x67
// 004235aa  6a04                 push 4
// 004235ac  6a67                 push 0x67
// 004235ae  c644242c07           mov byte ptr [esp + 0x2c], 7
// 004235b3  e8c0ce2000           call 0x630478
// 004235b8  50                   push eax
// 004235b9  ff15f8ed7700         call dword ptr [0x77edf8]
// 004235bf  50                   push eax
// 004235c0  8bcd                 mov ecx, ebp
// 004235c2  e8abce2000           call 0x630472
// 004235c7  8bc6                 mov eax, esi
// 004235c9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004235cd  64890d00000000       mov dword ptr fs:[0], ecx
// 004235d4  59                   pop ecx
// 004235d5  5f                   pop edi
// 004235d6  5e                   pop esi
// 004235d7  5d                   pop ebp
// 004235d8  5b                   pop ebx
// 004235d9  83c410               add esp, 0x10
// 004235dc  c3                   ret 

// from server: 100% by nuck16
// roc 2008-06 00425c90  unit: CRobloxTreeCtrl  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00425c90
//
// 00425c90  6aff                 push -1
// 00425c92  687cec7b00           push 0x7bec7c
// 00425c97  64a100000000         mov eax, dword ptr fs:[0]
// 00425c9d  50                   push eax
// 00425c9e  64892500000000       mov dword ptr fs:[0], esp
// 00425ca5  83ec08               sub esp, 8
// 00425ca8  53                   push ebx
// 00425ca9  56                   push esi
// 00425caa  8bf1                 mov esi, ecx
// 00425cac  57                   push edi
// 00425cad  89742410             mov dword ptr [esp + 0x10], esi
// 00425cb1  e84afeffff           call 0x425b00
// 00425cb6  8dbed0000000         lea edi, [esi + 0xd0]
// 00425cbc  33db                 xor ebx, ebx
// 00425cbe  8bcf                 mov ecx, edi
// 00425cc0  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00425cc4  e88700feff           call 0x405d50
// 00425cc9  c70740008100         mov dword ptr [edi], 0x810040
// 00425ccf  8dbed8000000         lea edi, [esi + 0xd8]
// 00425cd5  c706d4fe8000         mov dword ptr [esi], 0x80fed4
// 00425cdb  c746544cfe8000       mov dword ptr [esi + 0x54], 0x80fe4c
// 00425ce2  c786d400000040fe8000 mov dword ptr [esi + 0xd4], 0x80fe40
// 00425cec  c707dcfb8000         mov dword ptr [edi], 0x80fbdc
// 00425cf2  895f04               mov dword ptr [edi + 4], ebx
// 00425cf5  8d44240f             lea eax, [esp + 0xf]
// 00425cf9  50                   push eax
// 00425cfa  8d542413             lea edx, [esp + 0x13]
// 00425cfe  8d8ee4000000         lea ecx, [esi + 0xe4]
// 00425d04  52                   push edx
// 00425d05  c644242402           mov byte ptr [esp + 0x24], 2
// 00425d0a  889ee0000000         mov byte ptr [esi + 0xe0], bl
// 00425d10  889ee1000000         mov byte ptr [esi + 0xe1], bl
// 00425d16  889ee2000000         mov byte ptr [esi + 0xe2], bl
// 00425d1c  e8ef030200           call 0x446110
// 00425d21  8d44240f             lea eax, [esp + 0xf]
// 00425d25  50                   push eax
// 00425d26  8d542413             lea edx, [esp + 0x13]
// 00425d2a  8d8e04010000         lea ecx, [esi + 0x104]
// 00425d30  52                   push edx
// 00425d31  c644242403           mov byte ptr [esp + 0x24], 3
// 00425d36  e865552200           call 0x64b2a0
// 00425d3b  899e24010000         mov dword ptr [esi + 0x124], ebx
// 00425d41  899e28010000         mov dword ptr [esi + 0x128], ebx
// 00425d47  899e2c010000         mov dword ptr [esi + 0x12c], ebx
// 00425d4d  6a67                 push 0x67
// 00425d4f  6a04                 push 4
// 00425d51  6a67                 push 0x67
// 00425d53  c644242806           mov byte ptr [esp + 0x28], 6
// 00425d58  e8cfb12700           call 0x6a0f2c
// 00425d5d  50                   push eax
// 00425d5e  ff15882d8000         call dword ptr [0x802d88]
// 00425d64  50                   push eax
// 00425d65  8bcf                 mov ecx, edi
// 00425d67  e8bab12700           call 0x6a0f26
// 00425d6c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00425d70  5f                   pop edi
// 00425d71  8bc6                 mov eax, esi
// 00425d73  5e                   pop esi
// 00425d74  5b                   pop ebx
// 00425d75  64890d00000000       mov dword ptr fs:[0], ecx
// 00425d7c  83c414               add esp, 0x14
// 00425d7f  c3                   ret 

// from server: 96% by EspClaude
// roc 2008-06 00425c90  unit: CRobloxTreeCtrl  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00425c90
//
// 00425c90  6aff                 push -1
// 00425c92  687cec7b00           push 0x7bec7c
// 00425c97  64a100000000         mov eax, dword ptr fs:[0]
// 00425c9d  50                   push eax
// 00425c9e  64892500000000       mov dword ptr fs:[0], esp
// 00425ca5  83ec08               sub esp, 8
// 00425ca8  53                   push ebx
// 00425ca9  56                   push esi
// 00425caa  8bf1                 mov esi, ecx
// 00425cac  57                   push edi
// 00425cad  89742410             mov dword ptr [esp + 0x10], esi
// 00425cb1  e84afeffff           call 0x425b00
// 00425cb6  8dbed0000000         lea edi, [esi + 0xd0]
// 00425cbc  33db                 xor ebx, ebx
// 00425cbe  8bcf                 mov ecx, edi
// 00425cc0  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00425cc4  e88700feff           call 0x405d50
// 00425cc9  c70740008100         mov dword ptr [edi], 0x810040
// 00425ccf  8dbed8000000         lea edi, [esi + 0xd8]
// 00425cd5  c706d4fe8000         mov dword ptr [esi], 0x80fed4
// 00425cdb  c746544cfe8000       mov dword ptr [esi + 0x54], 0x80fe4c
// 00425ce2  c786d400000040fe8000 mov dword ptr [esi + 0xd4], 0x80fe40
// 00425cec  c707dcfb8000         mov dword ptr [edi], 0x80fbdc
// 00425cf2  895f04               mov dword ptr [edi + 4], ebx
// 00425cf5  8d44240f             lea eax, [esp + 0xf]
// 00425cf9  50                   push eax
// 00425cfa  8d542413             lea edx, [esp + 0x13]
// 00425cfe  8d8ee4000000         lea ecx, [esi + 0xe4]
// 00425d04  52                   push edx
// 00425d05  c644242402           mov byte ptr [esp + 0x24], 2
// 00425d0a  889ee0000000         mov byte ptr [esi + 0xe0], bl
// 00425d10  889ee1000000         mov byte ptr [esi + 0xe1], bl
// 00425d16  889ee2000000         mov byte ptr [esi + 0xe2], bl
// 00425d1c  e8ef030200           call 0x446110
// 00425d21  8d44240f             lea eax, [esp + 0xf]
// 00425d25  50                   push eax
// 00425d26  8d542413             lea edx, [esp + 0x13]
// 00425d2a  8d8e04010000         lea ecx, [esi + 0x104]
// 00425d30  52                   push edx
// 00425d31  c644242403           mov byte ptr [esp + 0x24], 3
// 00425d36  e865552200           call 0x64b2a0
// 00425d3b  899e24010000         mov dword ptr [esi + 0x124], ebx
// 00425d41  899e28010000         mov dword ptr [esi + 0x128], ebx
// 00425d47  899e2c010000         mov dword ptr [esi + 0x12c], ebx
// 00425d4d  6a67                 push 0x67
// 00425d4f  6a04                 push 4
// 00425d51  6a67                 push 0x67
// 00425d53  c644242806           mov byte ptr [esp + 0x28], 6
// 00425d58  e8cfb12700           call 0x6a0f2c
// 00425d5d  50                   push eax
// 00425d5e  ff15882d8000         call dword ptr [0x802d88]
// 00425d64  50                   push eax
// 00425d65  8bcf                 mov ecx, edi
// 00425d67  e8bab12700           call 0x6a0f26
// 00425d6c  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00425d70  5f                   pop edi
// 00425d71  8bc6                 mov eax, esi
// 00425d73  5e                   pop esi
// 00425d74  5b                   pop ebx
// 00425d75  64890d00000000       mov dword ptr fs:[0], ecx
// 00425d7c  83c414               add esp, 0x14
// 00425d7f  c3                   ret 

#include <map>
#include <set>
// from server: 93% by Espeon
// roc 2008-06 00425c90  unit: CRobloxTreeCtrl  size: 240 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00425c90
//

// from server: 89% by king_originala
typedef unsigned long DWORD;

extern "C" void* __stdcall FindResourceHandle(const char*, const char*);
extern "C" __declspec(dllimport) void* __stdcall LoadMenuA(void*, const char*);

extern DWORD registeredTable[];
extern DWORD menuTable[];

struct Empty {
    Empty() {}
};

struct Primary {
    virtual void primaryFunction();
    char padding[0x50];
};

struct Secondary {
    virtual void secondaryFunction();
    char padding[0x60];   // 2007-08: Secondary vptr at +0x54, next base at +0xb8
};

struct Base : Primary, Secondary {
    Base();
    ~Base();
};

struct RegisteredMember {
    DWORD* tablePointer;
    RegisteredMember* initialize();
    RegisteredMember();
    ~RegisteredMember();
};

inline RegisteredMember::RegisteredMember()
{
    initialize();
    tablePointer = registeredTable;
}

struct Interface {
    virtual void interfaceFunction();
    ~Interface();   // EH states: map at 3, set at 4, final 7 => one more unwind state than 2008
};

struct Menu {
    DWORD* tablePointer;
    void* handle;
    Menu();
    ~Menu();
    int attach(void*);
};

inline Menu::Menu() : tablePointer(menuTable), handle(0)
{
}

struct Pair { void* a; void* b; Pair():a(0),b(0){} ~Pair(); };
struct Allocator {Allocator(){}};
struct EmptyPack : Empty, Allocator {};
struct RawPointer {void* value;RawPointer():value(0){}};
struct ContainerA {
    DWORD data[8];
    ContainerA();
    void initialize(const Empty&, const Allocator&);
    ~ContainerA();
};

inline ContainerA::ContainerA()
{
    EmptyPack value;
    initialize(value,value);
}

struct ContainerB {
    DWORD data[8];
    ContainerB();
    void initialize(const Empty&, const Allocator&);
    ~ContainerB();
};

inline ContainerB::ContainerB()
{
    EmptyPack value;
    initialize(value,value);
}

struct PointerMember {
    void* value;
    PointerMember();
    ~PointerMember();
};

inline PointerMember::PointerMember() : value(0)
{
}

struct RegBase { RegBase(); ~RegBase(); virtual void regFunction(); };
struct CRobloxTreeCtrl : Base, RegBase, Interface {
    Menu menu;
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
    std::map<void*,void*> first;
    std::set<void*> second;
    Pair pointer0;
    PointerMember pointer1;

    virtual void primaryFunction();
    virtual void secondaryFunction();
    CRobloxTreeCtrl();
};

CRobloxTreeCtrl::CRobloxTreeCtrl()
    : flag0(0), flag1(0), flag2(0)
{
    menu.attach(LoadMenuA(
        FindResourceHandle((const char*)0x67, (const char*)4),
        (const char*)0x67));
}
