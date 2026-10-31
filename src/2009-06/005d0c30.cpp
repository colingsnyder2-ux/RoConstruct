// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00558830  unit: RBX::VInstance::?$AbstractFactoryProduct  size: 209 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00558830
//
// 00558830  6aff                 push -1
// 00558832  6853e27c00           push 0x7ce253
// 00558837  64a100000000         mov eax, dword ptr fs:[0]
// 0055883d  50                   push eax
// 0055883e  64892500000000       mov dword ptr fs:[0], esp
// 00558845  83ec08               sub esp, 8
// 00558848  56                   push esi
// 00558849  8bf1                 mov esi, ecx
// 0055884b  6a18                 push 0x18
// 0055884d  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00558855  e8c6801400           call 0x6a0920
// 0055885a  83c404               add esp, 4
// 0055885d  89442404             mov dword ptr [esp + 4], eax
// 00558861  c644241401           mov byte ptr [esp + 0x14], 1
// 00558866  85c0                 test eax, eax
// 00558868  7438                 je 0x5588a2
// 0055886a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055886e  83ec08               sub esp, 8
// 00558871  8bd4                 mov edx, esp
// 00558873  890a                 mov dword ptr [edx], ecx
// 00558875  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00558879  894a04               mov dword ptr [edx + 4], ecx
// 0055887c  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00558880  89642410             mov dword ptr [esp + 0x10], esp
// 00558884  85c9                 test ecx, ecx
// 00558886  740c                 je 0x558894
// 00558888  83c104               add ecx, 4
// 0055888b  ba01000000           mov edx, 1
// 00558890  f00fc111             lock xadd dword ptr [ecx], edx
// 00558894  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00558898  51                   push ecx
// 00558899  8bc8                 mov ecx, eax
// 0055889b  e890f7ffff           call 0x558030
// 005588a0  eb02                 jmp 0x5588a4
// 005588a2  33c0                 xor eax, eax
// 005588a4  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 005588a7  85c9                 test ecx, ecx
// 005588a9  7505                 jne 0x5588b0
// 005588ab  894620               mov dword ptr [esi + 0x20], eax
// 005588ae  eb02                 jmp 0x5588b2
// 005588b0  8901                 mov dword ptr [ecx], eax
// 005588b2  894624               mov dword ptr [esi + 0x24], eax
// 005588b5  8b742424             mov esi, dword ptr [esp + 0x24]
// 005588b9  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 005588c1  85f6                 test esi, esi
// 005588c3  742a                 je 0x5588ef
// 005588c5  8d5604               lea edx, [esi + 4]
// 005588c8  83c8ff               or eax, 0xffffffff
// 005588cb  f00fc102             lock xadd dword ptr [edx], eax
// 005588cf  751e                 jne 0x5588ef
// 005588d1  8b16                 mov edx, dword ptr [esi]
// 005588d3  8b4204               mov eax, dword ptr [edx + 4]
// 005588d6  8bce                 mov ecx, esi
// 005588d8  ffd0                 call eax
// 005588da  8d4e08               lea ecx, [esi + 8]
// 005588dd  83caff               or edx, 0xffffffff
// 005588e0  f00fc111             lock xadd dword ptr [ecx], edx
// 005588e4  7509                 jne 0x5588ef
// 005588e6  8b06                 mov eax, dword ptr [esi]
// 005588e8  8b5008               mov edx, dword ptr [eax + 8]
// 005588eb  8bce                 mov ecx, esi
// 005588ed  ffd2                 call edx
// 005588ef  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005588f3  64890d00000000       mov dword ptr fs:[0], ecx
// 005588fa  5e                   pop esi
// 005588fb  83c414               add esp, 0x14
// 005588fe  c20c00               ret 0xc

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* pointer;
    Control* control;

    Shared(const Shared& other);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control) {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Node {
    Node* next;
    char storage[20];

    Node(int value, Shared object);
};

struct S {
    char padding[32];
    Node* first;
    Node* last;

    void f(int value, Shared object);
};

void S::f(int value, Shared object)
{
    Node* node = new Node(value, object);
    if (!last)
        first = node;
    else
        last->next = node;
    last = node;
}
