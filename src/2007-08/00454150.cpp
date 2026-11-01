// from server: 100% by Yeetserama
// roc 2007-08 00454150  unit: RBX::VInstance::?$MarshaledListener  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00454150
//
// 00454150  6aff                 push -1
// 00454152  6898d97300           push 0x73d998
// 00454157  64a100000000         mov eax, dword ptr fs:[0]
// 0045415d  50                   push eax
// 0045415e  83ec08               sub esp, 8
// 00454161  56                   push esi
// 00454162  a188518b00           mov eax, dword ptr [0x8b5188]
// 00454167  33c4                 xor eax, esp
// 00454169  50                   push eax
// 0045416a  8d442410             lea eax, [esp + 0x10]
// 0045416e  64a300000000         mov dword ptr fs:[0], eax
// 00454174  8bf1                 mov esi, ecx
// 00454176  8b442420             mov eax, dword ptr [esp + 0x20]
// 0045417a  50                   push eax
// 0045417b  8d4c240c             lea ecx, [esp + 0xc]
// 0045417f  51                   push ecx
// 00454180  e8eb940400           call 0x49d670
// 00454185  83c408               add esp, 8
// 00454188  8b10                 mov edx, dword ptr [eax]
// 0045418a  83c004               add eax, 4
// 0045418d  50                   push eax
// 0045418e  8d4e08               lea ecx, [esi + 8]
// 00454191  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00454199  895604               mov dword ptr [esi + 4], edx
// 0045419c  e8bfe8faff           call 0x402a60
// 004541a1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004541a5  85f6                 test esi, esi
// 004541a7  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 004541af  742a                 je 0x4541db
// 004541b1  8d4604               lea eax, [esi + 4]
// 004541b4  83c9ff               or ecx, 0xffffffff
// 004541b7  f00fc108             lock xadd dword ptr [eax], ecx
// 004541bb  751e                 jne 0x4541db
// 004541bd  8b16                 mov edx, dword ptr [esi]
// 004541bf  8b4204               mov eax, dword ptr [edx + 4]
// 004541c2  8bce                 mov ecx, esi
// 004541c4  ffd0                 call eax
// 004541c6  8d4e08               lea ecx, [esi + 8]
// 004541c9  83caff               or edx, 0xffffffff
// 004541cc  f00fc111             lock xadd dword ptr [ecx], edx
// 004541d0  7509                 jne 0x4541db
// 004541d2  8b06                 mov eax, dword ptr [esi]
// 004541d4  8b5008               mov edx, dword ptr [eax + 8]
// 004541d7  8bce                 mov ecx, esi
// 004541d9  ffd2                 call edx
// 004541db  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004541df  64890d00000000       mov dword ptr fs:[0], ecx
// 004541e6  59                   pop ecx
// 004541e7  5e                   pop esi
// 004541e8  83c414               add esp, 0x14
// 004541eb  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX000008@@QAEXPAX@Z)

namespace ns_ROCX000008 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Holder
{
    Control* control;

    Holder& operator=(const Holder&);
    ~Holder();
};

__forceinline Holder::~Holder()
{
    if (control)
        control->release();
}

struct Pair
{
    void* object;
    Holder owner;

    Pair(const Pair&);
};

Pair __cdecl makePair(void*);

struct S
{
    unsigned long reserved;
    void* object;
    Holder owner;

    void assign(const Pair&);
    void f(void*);
};

__forceinline void S::assign(const Pair& value)
{
    object = value.object;
    owner = value.owner;
}

void S::f(void* argument)
{
    assign(makePair(argument));
}
}
