// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0057e660  unit: RBX::ClearBackpack  size: 201 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057e660
//
// 0057e660  6aff                 push -1
// 0057e662  6809d97b00           push 0x7bd909
// 0057e667  64a100000000         mov eax, dword ptr fs:[0]
// 0057e66d  50                   push eax
// 0057e66e  64892500000000       mov dword ptr fs:[0], esp
// 0057e675  83ec08               sub esp, 8
// 0057e678  53                   push ebx
// 0057e679  33db                 xor ebx, ebx
// 0057e67b  895c2404             mov dword ptr [esp + 4], ebx
// 0057e67f  8b8954010000         mov ecx, dword ptr [ecx + 0x154]
// 0057e685  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0057e688  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0057e68b  56                   push esi
// 0057e68c  c1f803               sar eax, 3
// 0057e68f  57                   push edi
// 0057e690  85c0                 test eax, eax
// 0057e692  760b                 jbe 0x57e69f
// 0057e694  e827a1fdff           call 0x5587c0
// 0057e699  8b742410             mov esi, dword ptr [esp + 0x10]
// 0057e69d  eb11                 jmp 0x57e6b0
// 0057e69f  33f6                 xor esi, esi
// 0057e6a1  895c240c             mov dword ptr [esp + 0xc], ebx
// 0057e6a5  89742410             mov dword ptr [esp + 0x10], esi
// 0057e6a9  8d44240c             lea eax, [esp + 0xc]
// 0057e6ad  8d5e01               lea ebx, [esi + 1]
// 0057e6b0  8b08                 mov ecx, dword ptr [eax]
// 0057e6b2  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0057e6b6  890f                 mov dword ptr [edi], ecx
// 0057e6b8  8b4004               mov eax, dword ptr [eax + 4]
// 0057e6bb  894704               mov dword ptr [edi + 4], eax
// 0057e6be  85c0                 test eax, eax
// 0057e6c0  740c                 je 0x57e6ce
// 0057e6c2  83c004               add eax, 4
// 0057e6c5  ba01000000           mov edx, 1
// 0057e6ca  f00fc110             lock xadd dword ptr [eax], edx
// 0057e6ce  83cb02               or ebx, 2
// 0057e6d1  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0057e6d9  f6c301               test bl, 1
// 0057e6dc  7435                 je 0x57e713
// 0057e6de  83e3fe               and ebx, 0xfffffffe
// 0057e6e1  895c240c             mov dword ptr [esp + 0xc], ebx
// 0057e6e5  85f6                 test esi, esi
// 0057e6e7  742a                 je 0x57e713
// 0057e6e9  8d4604               lea eax, [esi + 4]
// 0057e6ec  83c9ff               or ecx, 0xffffffff
// 0057e6ef  f00fc108             lock xadd dword ptr [eax], ecx
// 0057e6f3  751e                 jne 0x57e713
// 0057e6f5  8b16                 mov edx, dword ptr [esi]
// 0057e6f7  8b4204               mov eax, dword ptr [edx + 4]
// 0057e6fa  8bce                 mov ecx, esi
// 0057e6fc  ffd0                 call eax
// 0057e6fe  8d4e08               lea ecx, [esi + 8]
// 0057e701  83caff               or edx, 0xffffffff
// 0057e704  f00fc111             lock xadd dword ptr [ecx], edx
// 0057e708  7509                 jne 0x57e713
// 0057e70a  8b06                 mov eax, dword ptr [esi]
// 0057e70c  8b5008               mov edx, dword ptr [eax + 8]
// 0057e70f  8bce                 mov ecx, esi
// 0057e711  ffd2                 call edx
// 0057e713  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0057e717  8bc7                 mov eax, edi
// 0057e719  5f                   pop edi
// 0057e71a  5e                   pop esi
// 0057e71b  5b                   pop ebx
// 0057e71c  64890d00000000       mov dword ptr fs:[0], ecx
// 0057e723  83c414               add esp, 0x14
// 0057e726  c20400               ret 4

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

inline long exchangeAdd(volatile long* p, long value)
{
    return _InterlockedExchangeAdd(p, value);
}

inline long decrement(volatile long* p)
{
    return _InterlockedDecrement(p);
}

struct Control
{
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void weakRelease();
};

inline void Control::weakRelease()
{
    if (decrement(&weak) == 0)
        destroy();
}

struct Shared
{
    void* px;
    Control* pn;

    Shared();
    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared() : px(0), pn(0)
{
}

inline Shared::Shared(const Shared& other) : px(other.px), pn(other.pn)
{
    if (pn)
        exchangeAdd(&pn->strong, 1);
}

inline Shared::~Shared()
{
    if (pn && decrement(&pn->strong) == 0)
    {
        pn->dispose();
        pn->weakRelease();
    }
}

struct List
{
    char padding[12];
    Shared* first;
    Shared* last;

    unsigned int size() const;
    Shared& front();
};

inline unsigned int List::size() const
{
    return static_cast<unsigned int>(last - first);
}

struct S
{
    char padding[340];
    List* children;

    Shared f();
};

Shared S::f()
{
    return children->size() > 0 ? children->front() : Shared();
}
