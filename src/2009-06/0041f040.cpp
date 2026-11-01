// from server: 100% by EspClaude
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
extern "C" void* (__stdcall *LoadMenuA)(void*, const char*);

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
    char padding[0x7c];
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern long g_counter;
struct CountedBase { CountedBase() { InterlockedIncrement(&g_counter); } };
struct Weak : CountedBase { void* a; void* b; Weak() : a(0), b(0) {} ~Weak(); };
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

struct __declspec(novtable) Interface {
    virtual void interfaceFunction();
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
struct CRobloxTreeCtrl : Base, RegBase {
    Weak weak;
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
