// from server: 100% by Yeetserama
// roc 2007-08 004378f0  unit: RBX::VStandardOut::?$MarshaledListener  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004378f0
//
// 004378f0  6aff                 push -1
// 004378f2  6898d97300           push 0x73d998
// 004378f7  64a100000000         mov eax, dword ptr fs:[0]
// 004378fd  50                   push eax
// 004378fe  83ec08               sub esp, 8
// 00437901  56                   push esi
// 00437902  a188518b00           mov eax, dword ptr [0x8b5188]
// 00437907  33c4                 xor eax, esp
// 00437909  50                   push eax
// 0043790a  8d442410             lea eax, [esp + 0x10]
// 0043790e  64a300000000         mov dword ptr fs:[0], eax
// 00437914  8bf1                 mov esi, ecx
// 00437916  8b442420             mov eax, dword ptr [esp + 0x20]
// 0043791a  50                   push eax
// 0043791b  8d4c240c             lea ecx, [esp + 0xc]
// 0043791f  51                   push ecx
// 00437920  e8abfdffff           call 0x4376d0
// 00437925  83c408               add esp, 8
// 00437928  8b10                 mov edx, dword ptr [eax]
// 0043792a  83c004               add eax, 4
// 0043792d  50                   push eax
// 0043792e  8d4e08               lea ecx, [esi + 8]
// 00437931  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00437939  895604               mov dword ptr [esi + 4], edx
// 0043793c  e81fb1fcff           call 0x402a60
// 00437941  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00437945  85f6                 test esi, esi
// 00437947  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0043794f  742a                 je 0x43797b
// 00437951  8d4604               lea eax, [esi + 4]
// 00437954  83c9ff               or ecx, 0xffffffff
// 00437957  f00fc108             lock xadd dword ptr [eax], ecx
// 0043795b  751e                 jne 0x43797b
// 0043795d  8b16                 mov edx, dword ptr [esi]
// 0043795f  8b4204               mov eax, dword ptr [edx + 4]
// 00437962  8bce                 mov ecx, esi
// 00437964  ffd0                 call eax
// 00437966  8d4e08               lea ecx, [esi + 8]
// 00437969  83caff               or edx, 0xffffffff
// 0043796c  f00fc111             lock xadd dword ptr [ecx], edx
// 00437970  7509                 jne 0x43797b
// 00437972  8b06                 mov eax, dword ptr [esi]
// 00437974  8b5008               mov edx, dword ptr [eax + 8]
// 00437977  8bce                 mov ecx, esi
// 00437979  ffd2                 call edx
// 0043797b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043797f  64890d00000000       mov dword ptr fs:[0], ecx
// 00437986  59                   pop ecx
// 00437987  5e                   pop esi
// 00437988  83c414               add esp, 0x14
// 0043798b  c20400               ret 4
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
