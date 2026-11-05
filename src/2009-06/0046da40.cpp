// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc 2009-06 0046da40  unit: PartDataSource  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046da40
//
// 0046da40  6aff                 push -1
// 0046da42  68f8358500           push 0x8535f8
// 0046da47  64a100000000         mov eax, dword ptr fs:[0]
// 0046da4d  50                   push eax
// 0046da4e  64892500000000       mov dword ptr fs:[0], esp
// 0046da55  83ec08               sub esp, 8
// 0046da58  56                   push esi
// 0046da59  8bf1                 mov esi, ecx
// 0046da5b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0046da5e  6a01                 push 1
// 0046da60  83ec08               sub esp, 8
// 0046da63  8bcc                 mov ecx, esp
// 0046da65  89642410             mov dword ptr [esp + 0x10], esp
// 0046da69  8901                 mov dword ptr [ecx], eax
// 0046da6b  8b4620               mov eax, dword ptr [esi + 0x20]
// 0046da6e  894104               mov dword ptr [ecx + 4], eax
// 0046da71  85c0                 test eax, eax
// 0046da73  740c                 je 0x46da81
// 0046da75  83c004               add eax, 4
// 0046da78  b901000000           mov ecx, 1
// 0046da7d  f00fc108             lock xadd dword ptr [eax], ecx
// 0046da81  8d4c2410             lea ecx, [esp + 0x10]
// 0046da85  e886601900           call 0x603b10
// 0046da8a  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0046da8d  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0046da91  50                   push eax
// 0046da92  52                   push edx
// 0046da93  8d4c2410             lea ecx, [esp + 0x10]
// 0046da97  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0046da9f  e83c671b00           call 0x6241e0
// 0046daa4  8b761c               mov esi, dword ptr [esi + 0x1c]
// 0046daa7  85f6                 test esi, esi
// 0046daa9  7408                 je 0x46dab3
// 0046daab  8b8e0c020000         mov ecx, dword ptr [esi + 0x20c]
// 0046dab1  eb02                 jmp 0x46dab5
// 0046dab3  33c9                 xor ecx, ecx
// 0046dab5  e8e6e31b00           call 0x62bea0
// 0046daba  8d4c2404             lea ecx, [esp + 4]
// 0046dabe  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0046dac6  e8d51a1900           call 0x5ff5a0
// 0046dacb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0046dacf  64890d00000000       mov dword ptr fs:[0], ecx
// 0046dad6  5e                   pop esi
// 0046dad7  83c414               add esp, 0x14
// 0046dada  c20400               ret 4

// from server: 100% by king_originala
// roc 2008-06 0046aa70  unit: VCWorkspace::?$CComObject  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046aa70
//
// 0046aa70  6aff                 push -1
// 0046aa72  6828397c00           push 0x7c3928
// 0046aa77  64a100000000         mov eax, dword ptr fs:[0]
// 0046aa7d  50                   push eax
// 0046aa7e  64892500000000       mov dword ptr fs:[0], esp
// 0046aa85  83ec10               sub esp, 0x10
// 0046aa88  56                   push esi
// 0046aa89  8bf1                 mov esi, ecx
// 0046aa8b  8b4624               mov eax, dword ptr [esi + 0x24]
// 0046aa8e  83ec08               sub esp, 8
// 0046aa91  8bcc                 mov ecx, esp
// 0046aa93  8964240c             mov dword ptr [esp + 0xc], esp
// 0046aa97  8901                 mov dword ptr [ecx], eax
// 0046aa99  8b4628               mov eax, dword ptr [esi + 0x28]
// 0046aa9c  894104               mov dword ptr [ecx + 4], eax
// 0046aa9f  85c0                 test eax, eax
// 0046aaa1  740c                 je 0x46aaaf
// 0046aaa3  83c004               add eax, 4
// 0046aaa6  b901000000           mov ecx, 1
// 0046aaab  f00fc108             lock xadd dword ptr [eax], ecx
// 0046aaaf  8d4c2410             lea ecx, [esp + 0x10]
// 0046aab3  e88870faff           call 0x411b40
// 0046aab8  8b4624               mov eax, dword ptr [esi + 0x24]
// 0046aabb  8b542424             mov edx, dword ptr [esp + 0x24]
// 0046aabf  50                   push eax
// 0046aac0  52                   push edx
// 0046aac1  8d4c240c             lea ecx, [esp + 0xc]
// 0046aac5  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0046aacd  e85e8c1200           call 0x593730
// 0046aad2  8b7624               mov esi, dword ptr [esi + 0x24]
// 0046aad5  85f6                 test esi, esi
// 0046aad7  7408                 je 0x46aae1
// 0046aad9  8b8e04020000         mov ecx, dword ptr [esi + 0x204]
// 0046aadf  eb02                 jmp 0x46aae3
// 0046aae1  33c9                 xor ecx, ecx
// 0046aae3  e8f8621300           call 0x5a0de0
// 0046aae8  8d4c2408             lea ecx, [esp + 8]
// 0046aaec  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0046aaf4  e8c7c81000           call 0x5773c0
// 0046aaf9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0046aafd  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ab04  5e                   pop esi
// 0046ab05  83c41c               add esp, 0x1c
// 0046ab08  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    long unused;
    volatile long references;
    void addReference();
};

__forceinline void Control::addReference()
{
    volatile long* count = &references;
    _InterlockedExchangeAdd(count, 1);
}

struct Service {
    void f();
};

struct Object {
    char padding[0x20c];
    Service* service;
};

struct Shared {
    Object* object;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : object(other.object), control(other.control)
{
    if (control)
        control->addReference();
}

struct Guard {
    unsigned long storage;
    Guard(Shared value, bool);
    ~Guard();
};

struct Action {
    unsigned long storage;
    void apply(unsigned long argument, Object* object);
};

struct S {
    char padding[0x1c];
    Shared value;
    void f(unsigned long argument);
};

void S::f(unsigned long argument)
{
    Guard guard(value, true);
    Object* target = value.object;
    Action action;
    action.apply(argument, target);
    Object* object = value.object;
    Service* service = object ? object->service : 0;
    service->f();
}
