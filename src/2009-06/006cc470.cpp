// from server: 100% by EspClaude
// roc 2009-06 006cc470  unit: RBX::HammerTool  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006cc470
//
// 006cc470  6aff                 push -1
// 006cc472  68e8a68600           push 0x86a6e8
// 006cc477  64a100000000         mov eax, dword ptr fs:[0]
// 006cc47d  50                   push eax
// 006cc47e  64892500000000       mov dword ptr fs:[0], esp
// 006cc485  83ec08               sub esp, 8
// 006cc488  8b442418             mov eax, dword ptr [esp + 0x18]
// 006cc48c  56                   push esi
// 006cc48d  68bcfca400           push 0xa4fcbc
// 006cc492  50                   push eax
// 006cc493  8bf1                 mov esi, ecx
// 006cc495  e8069ffeff           call 0x6b63a0
// 006cc49a  50                   push eax
// 006cc49b  8d4c2408             lea ecx, [esp + 8]
// 006cc49f  51                   push ecx
// 006cc4a0  e80bc5f3ff           call 0x6089b0
// 006cc4a5  83c408               add esp, 8
// 006cc4a8  8b10                 mov edx, dword ptr [eax]
// 006cc4aa  83c004               add eax, 4
// 006cc4ad  50                   push eax
// 006cc4ae  8d4e20               lea ecx, [esi + 0x20]
// 006cc4b1  c744241800000000     mov dword ptr [esp + 0x18], 0
// 006cc4b9  89561c               mov dword ptr [esi + 0x1c], edx
// 006cc4bc  e83f60d3ff           call 0x402500
// 006cc4c1  8b742408             mov esi, dword ptr [esp + 8]
// 006cc4c5  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 006cc4cd  85f6                 test esi, esi
// 006cc4cf  742a                 je 0x6cc4fb
// 006cc4d1  8d4604               lea eax, [esi + 4]
// 006cc4d4  83c9ff               or ecx, 0xffffffff
// 006cc4d7  f00fc108             lock xadd dword ptr [eax], ecx
// 006cc4db  751e                 jne 0x6cc4fb
// 006cc4dd  8b16                 mov edx, dword ptr [esi]
// 006cc4df  8b4204               mov eax, dword ptr [edx + 4]
// 006cc4e2  8bce                 mov ecx, esi
// 006cc4e4  ffd0                 call eax
// 006cc4e6  8d4e08               lea ecx, [esi + 8]
// 006cc4e9  83caff               or edx, 0xffffffff
// 006cc4ec  f00fc111             lock xadd dword ptr [ecx], edx
// 006cc4f0  7509                 jne 0x6cc4fb
// 006cc4f2  8b06                 mov eax, dword ptr [esi]
// 006cc4f4  8b5008               mov edx, dword ptr [eax + 8]
// 006cc4f7  8bce                 mov ecx, esi
// 006cc4f9  ffd2                 call edx
// 006cc4fb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006cc4ff  5e                   pop esi
// 006cc500  64890d00000000       mov dword ptr fs:[0], ecx
// 006cc507  83c414               add esp, 0x14
// 006cc50a  c20400               ret 4
// copied from an identical function in another client (function ?set@HammerTool@ns_ROCX000002@@QAEXPAX@Z)

namespace ns_ROCX000002 {
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

struct Owner {
    Control* control;
    Owner& operator=(const Owner&);
};

struct Pair {
    void* pointer;
    Owner owner;
    Pair& operator=(const Pair&);
    ~Pair();
};

extern char factory;
extern void* __stdcall invoke(void*, void*);
extern Pair __cdecl makePair(void*);

struct HammerTool {
    char padding[0x1c];
    Pair value;
    void set(void*);
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

__forceinline Pair& Pair::operator=(const Pair& other)
{
    pointer = other.pointer;
    owner = other.owner;
    return *this;
}

__forceinline Pair::~Pair()
{
    if (owner.control)
        owner.control->release();
}

void HammerTool::set(void* argument)
{
    value = makePair(invoke(argument, &factory));
}
}
