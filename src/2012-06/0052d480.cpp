// from server: 100% by Yeetserama
// roc 2012-06 0052d480  unit: RBX::Network::VPlayer::?$EventDesc  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0052d480
//
// 0052d480  6aff                 push -1
// 0052d482  68217cad00           push 0xad7c21
// 0052d487  64a100000000         mov eax, dword ptr fs:[0]
// 0052d48d  50                   push eax
// 0052d48e  64892500000000       mov dword ptr fs:[0], esp
// 0052d495  83ec30               sub esp, 0x30
// 0052d498  56                   push esi
// 0052d499  8bf1                 mov esi, ecx
// 0052d49b  833e00               cmp dword ptr [esi], 0
// 0052d49e  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 0052d4a6  7514                 jne 0x52d4bc
// 0052d4a8  8d4c240c             lea ecx, [esp + 0xc]
// 0052d4ac  e82feeedff           call 0x40c2e0
// 0052d4b1  50                   push eax
// 0052d4b2  c644244002           mov byte ptr [esp + 0x40], 2
// 0052d4b7  e80420eeff           call 0x40f4c0
// 0052d4bc  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0052d4c0  83ec08               sub esp, 8
// 0052d4c3  8bc4                 mov eax, esp
// 0052d4c5  8908                 mov dword ptr [eax], ecx
// 0052d4c7  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 0052d4cb  895004               mov dword ptr [eax + 4], edx
// 0052d4ce  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 0052d4d2  8964240c             mov dword ptr [esp + 0xc], esp
// 0052d4d6  85c0                 test eax, eax
// 0052d4d8  740c                 je 0x52d4e6
// 0052d4da  83c004               add eax, 4
// 0052d4dd  b901000000           mov ecx, 1
// 0052d4e2  f00fc108             lock xadd dword ptr [eax], ecx
// 0052d4e6  83ec1c               sub esp, 0x1c
// 0052d4e9  8d542468             lea edx, [esp + 0x68]
// 0052d4ed  8bcc                 mov ecx, esp
// 0052d4ef  8964242c             mov dword ptr [esp + 0x2c], esp
// 0052d4f3  52                   push edx
// 0052d4f4  c644246403           mov byte ptr [esp + 0x64], 3
// 0052d4f9  ff154426b200         call dword ptr [0xb22644]
// 0052d4ff  8b06                 mov eax, dword ptr [esi]
// 0052d501  83c004               add eax, 4
// 0052d504  83c608               add esi, 8
// 0052d507  c644246001           mov byte ptr [esp + 0x60], 1
// 0052d50c  8b00                 mov eax, dword ptr [eax]
// 0052d50e  56                   push esi
// 0052d50f  ffd0                 call eax
// 0052d511  83c428               add esp, 0x28
// 0052d514  8d4c2444             lea ecx, [esp + 0x44]
// 0052d518  c644243c00           mov byte ptr [esp + 0x3c], 0
// 0052d51d  ff153c26b200         call dword ptr [0xb2263c]
// 0052d523  8b442464             mov eax, dword ptr [esp + 0x64]
// 0052d527  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 0052d52f  85c0                 test eax, eax
// 0052d531  742c                 je 0x52d55f
// 0052d533  8bf0                 mov esi, eax
// 0052d535  83c004               add eax, 4
// 0052d538  83c9ff               or ecx, 0xffffffff
// 0052d53b  f00fc108             lock xadd dword ptr [eax], ecx
// 0052d53f  751e                 jne 0x52d55f
// 0052d541  8b16                 mov edx, dword ptr [esi]
// 0052d543  8b4204               mov eax, dword ptr [edx + 4]
// 0052d546  8bce                 mov ecx, esi
// 0052d548  ffd0                 call eax
// 0052d54a  8d4e08               lea ecx, [esi + 8]
// 0052d54d  83caff               or edx, 0xffffffff
// 0052d550  f00fc111             lock xadd dword ptr [ecx], edx
// 0052d554  7509                 jne 0x52d55f
// 0052d556  8b06                 mov eax, dword ptr [esi]
// 0052d558  8b5008               mov edx, dword ptr [eax + 8]
// 0052d55b  8bce                 mov ecx, esi
// 0052d55d  ffd2                 call edx
// 0052d55f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0052d563  64890d00000000       mov dword ptr fs:[0], ecx
// 0052d56a  5e                   pop esi
// 0052d56b  83c43c               add esp, 0x3c
// 0052d56e  c22400               ret 0x24
// copied from an identical function in another client (function ?f@S@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UShared@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)








struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* pointer;
    Control* control;
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared() {
    if (control) {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Error {
    unsigned char storage[40];
    Error();
    ~Error();
};

__declspec(noreturn) void __cdecl raiseError(const Error&);

typedef void (__cdecl *Invoke)(void*, std::string, Shared);

struct Table {
    void* unused;
    Invoke invoke;
};

struct S {
    Table* table;
    unsigned long reserved;
    unsigned char callable[1];
    void f(std::string, Shared);
};

void S::f(std::string text, Shared value) {
    if (!table)
        raiseError(Error());
    table->invoke(callable, text, value);
}