// from server: 100% by colin
// from server: 88% by king_originala
// roc 2008-06 005e8f70  unit: RBX::PhysicsService  size: 203 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e8f70
//
// 005e8f70  64a100000000         mov eax, dword ptr fs:[0]
// 005e8f76  6aff                 push -1
// 005e8f78  68e8147d00           push 0x7d14e8
// 005e8f7d  50                   push eax
// 005e8f7e  64892500000000       mov dword ptr fs:[0], esp
// 005e8f85  83ec18               sub esp, 0x18
// 005e8f88  56                   push esi
// 005e8f89  57                   push edi
// 005e8f8a  8bf9                 mov edi, ecx
// 005e8f8c  85ff                 test edi, edi
// 005e8f8e  7405                 je 0x5e8f95
// 005e8f90  8d7714               lea esi, [edi + 0x14]
// 005e8f93  eb02                 jmp 0x5e8f97
// 005e8f95  33f6                 xor esi, esi
// 005e8f97  8b442430             mov eax, dword ptr [esp + 0x30]
// 005e8f9b  50                   push eax
// 005e8f9c  8d4c2410             lea ecx, [esp + 0x10]
// 005e8fa0  51                   push ecx
// 005e8fa1  e89afa0200           call 0x618a40
// 005e8fa6  8b10                 mov edx, dword ptr [eax]
// 005e8fa8  8bcc                 mov ecx, esp
// 005e8faa  8911                 mov dword ptr [ecx], edx
// 005e8fac  8b4004               mov eax, dword ptr [eax + 4]
// 005e8faf  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005e8fb7  89642410             mov dword ptr [esp + 0x10], esp
// 005e8fbb  894104               mov dword ptr [ecx + 4], eax
// 005e8fbe  85c0                 test eax, eax
// 005e8fc0  740c                 je 0x5e8fce
// 005e8fc2  83c004               add eax, 4
// 005e8fc5  b901000000           mov ecx, 1
// 005e8fca  f00fc108             lock xadd dword ptr [eax], ecx
// 005e8fce  56                   push esi
// 005e8fcf  b9ecab9700           mov ecx, 0x97abec
// 005e8fd4  e82742ebff           call 0x49d200
// 005e8fd9  8b742410             mov esi, dword ptr [esp + 0x10]
// 005e8fdd  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 005e8fe5  85f6                 test esi, esi
// 005e8fe7  742a                 je 0x5e9013
// 005e8fe9  8d5604               lea edx, [esi + 4]
// 005e8fec  83c8ff               or eax, 0xffffffff
// 005e8fef  f00fc102             lock xadd dword ptr [edx], eax
// 005e8ff3  751e                 jne 0x5e9013
// 005e8ff5  8b16                 mov edx, dword ptr [esi]
// 005e8ff7  8b4204               mov eax, dword ptr [edx + 4]
// 005e8ffa  8bce                 mov ecx, esi
// 005e8ffc  ffd0                 call eax
// 005e8ffe  8d4e08               lea ecx, [esi + 8]
// 005e9001  83caff               or edx, 0xffffffff
// 005e9004  f00fc111             lock xadd dword ptr [ecx], edx
// 005e9008  7509                 jne 0x5e9013
// 005e900a  8b06                 mov eax, dword ptr [esi]
// 005e900c  8b5008               mov edx, dword ptr [eax + 8]
// 005e900f  8bce                 mov ecx, esi
// 005e9011  ffd2                 call edx
// 005e9013  8d442430             lea eax, [esp + 0x30]
// 005e9017  50                   push eax
// 005e9018  8d4c2418             lea ecx, [esp + 0x18]
// 005e901c  51                   push ecx
// 005e901d  8d8f38010000         lea ecx, [edi + 0x138]
// 005e9023  e818fcffff           call 0x5e8c40
// 005e9028  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005e902c  5f                   pop edi
// 005e902d  64890d00000000       mov dword ptr fs:[0], ecx
// 005e9034  5e                   pop esi
// 005e9035  83c424               add esp, 0x24
// 005e9038  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long uses;
    volatile long weak;
    void release();
};

inline void Control::release() {
    if (_InterlockedDecrement(&uses) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Temporary;

struct Shared {
    void* object;
    Control* control;
    Shared(const Temporary&);
    ~Shared();
};

struct Temporary {
    void* object;
    Control* control;
    ~Temporary();
};

inline Shared::Shared(const Temporary& other)
    : object(other.object), control(other.control) {
    if (control)
        _InterlockedIncrement(&control->uses);
}

inline Shared::~Shared() {
    if (control)
        control->release();
}

inline Temporary::~Temporary() {
    if (control)
        control->release();
}

extern Temporary __cdecl makeShared(void*);

struct Base {
    char data[0x124];
};

struct Iterator {
    void* data[3];
};

struct Container {
    Iterator erase(void* const&);
};

struct Descriptor {
    void invoke(Base*, Shared);
};

extern Descriptor descriptor;

struct S {
    char prefix[0x14];
    Base base;
    Container container;
    void f(void*);
};

void S::f(void* value) {
    Base* target = this ? &base : 0;
    descriptor.invoke(target, makeShared(value));
    container.erase(value);
}
