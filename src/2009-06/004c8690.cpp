// from server: 100% by EspClaude
// roc 2009-06 004c8690  unit: RBX::VInstance::?$NonFactoryProduct  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004c8690
//
// 004c8690  6aff                 push -1
// 004c8692  6841a18500           push 0x85a141
// 004c8697  64a100000000         mov eax, dword ptr fs:[0]
// 004c869d  50                   push eax
// 004c869e  64892500000000       mov dword ptr fs:[0], esp
// 004c86a5  83ec30               sub esp, 0x30
// 004c86a8  56                   push esi
// 004c86a9  8bf1                 mov esi, ecx
// 004c86ab  833e00               cmp dword ptr [esi], 0
// 004c86ae  c744243c01000000     mov dword ptr [esp + 0x3c], 1
// 004c86b6  7514                 jne 0x4c86cc
// 004c86b8  8d4c240c             lea ecx, [esp + 0xc]
// 004c86bc  e81f0ef4ff           call 0x4094e0
// 004c86c1  50                   push eax
// 004c86c2  c644244002           mov byte ptr [esp + 0x40], 2
// 004c86c7  e8941bf4ff           call 0x40a260
// 004c86cc  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 004c86d0  83ec08               sub esp, 8
// 004c86d3  8bc4                 mov eax, esp
// 004c86d5  8908                 mov dword ptr [eax], ecx
// 004c86d7  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 004c86db  895004               mov dword ptr [eax + 4], edx
// 004c86de  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 004c86e2  8964240c             mov dword ptr [esp + 0xc], esp
// 004c86e6  85c0                 test eax, eax
// 004c86e8  740c                 je 0x4c86f6
// 004c86ea  83c004               add eax, 4
// 004c86ed  b901000000           mov ecx, 1
// 004c86f2  f00fc108             lock xadd dword ptr [eax], ecx
// 004c86f6  83ec1c               sub esp, 0x1c
// 004c86f9  8d542468             lea edx, [esp + 0x68]
// 004c86fd  8bcc                 mov ecx, esp
// 004c86ff  8964242c             mov dword ptr [esp + 0x2c], esp
// 004c8703  52                   push edx
// 004c8704  c644246403           mov byte ptr [esp + 0x64], 3
// 004c8709  ff15b8e48900         call dword ptr [0x89e4b8]
// 004c870f  8b06                 mov eax, dword ptr [esi]
// 004c8711  83c004               add eax, 4
// 004c8714  83c608               add esi, 8
// 004c8717  c644246001           mov byte ptr [esp + 0x60], 1
// 004c871c  8b00                 mov eax, dword ptr [eax]
// 004c871e  56                   push esi
// 004c871f  ffd0                 call eax
// 004c8721  83c428               add esp, 0x28
// 004c8724  8d4c2444             lea ecx, [esp + 0x44]
// 004c8728  c644243c00           mov byte ptr [esp + 0x3c], 0
// 004c872d  ff15c4e48900         call dword ptr [0x89e4c4]
// 004c8733  8b442464             mov eax, dword ptr [esp + 0x64]
// 004c8737  c744243cffffffff     mov dword ptr [esp + 0x3c], 0xffffffff
// 004c873f  85c0                 test eax, eax
// 004c8741  742c                 je 0x4c876f
// 004c8743  8bf0                 mov esi, eax
// 004c8745  83c004               add eax, 4
// 004c8748  83c9ff               or ecx, 0xffffffff
// 004c874b  f00fc108             lock xadd dword ptr [eax], ecx
// 004c874f  751e                 jne 0x4c876f
// 004c8751  8b16                 mov edx, dword ptr [esi]
// 004c8753  8b4204               mov eax, dword ptr [edx + 4]
// 004c8756  8bce                 mov ecx, esi
// 004c8758  ffd0                 call eax
// 004c875a  8d4e08               lea ecx, [esi + 8]
// 004c875d  83caff               or edx, 0xffffffff
// 004c8760  f00fc111             lock xadd dword ptr [ecx], edx
// 004c8764  7509                 jne 0x4c876f
// 004c8766  8b06                 mov eax, dword ptr [esi]
// 004c8768  8b5008               mov edx, dword ptr [eax + 8]
// 004c876b  8bce                 mov ecx, esi
// 004c876d  ffd2                 call edx
// 004c876f  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004c8773  64890d00000000       mov dword ptr fs:[0], ecx
// 004c877a  5e                   pop esi
// 004c877b  83c43c               add esp, 0x3c
// 004c877e  c22400               ret 0x24
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