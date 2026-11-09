// from server: 100% by Yeetserama
// roc 2007-08 004af100  unit: RBX::VRotate::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004af100
//
// 004af100  6aff                 push -1
// 004af102  68d9717400           push 0x7471d9
// 004af107  64a100000000         mov eax, dword ptr fs:[0]
// 004af10d  50                   push eax
// 004af10e  83ec0c               sub esp, 0xc
// 004af111  56                   push esi
// 004af112  57                   push edi
// 004af113  a188518b00           mov eax, dword ptr [0x8b5188]
// 004af118  33c4                 xor eax, esp
// 004af11a  50                   push eax
// 004af11b  8d442418             lea eax, [esp + 0x18]
// 004af11f  64a300000000         mov dword ptr fs:[0], eax
// 004af125  8d442410             lea eax, [esp + 0x10]
// 004af129  50                   push eax
// 004af12a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004af132  e839ffffff           call 0x4af070
// 004af137  8b08                 mov ecx, dword ptr [eax]
// 004af139  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004af13d  890f                 mov dword ptr [edi], ecx
// 004af13f  8b4004               mov eax, dword ptr [eax + 4]
// 004af142  83c404               add esp, 4
// 004af145  85c0                 test eax, eax
// 004af147  894704               mov dword ptr [edi + 4], eax
// 004af14a  740c                 je 0x4af158
// 004af14c  83c004               add eax, 4
// 004af14f  ba01000000           mov edx, 1
// 004af154  f00fc110             lock xadd dword ptr [eax], edx
// 004af158  8b742414             mov esi, dword ptr [esp + 0x14]
// 004af15c  85f6                 test esi, esi
// 004af15e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004af166  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004af16e  742a                 je 0x4af19a
// 004af170  8d4604               lea eax, [esi + 4]
// 004af173  83c9ff               or ecx, 0xffffffff
// 004af176  f00fc108             lock xadd dword ptr [eax], ecx
// 004af17a  751e                 jne 0x4af19a
// 004af17c  8b16                 mov edx, dword ptr [esi]
// 004af17e  8b4204               mov eax, dword ptr [edx + 4]
// 004af181  8bce                 mov ecx, esi
// 004af183  ffd0                 call eax
// 004af185  8d4e08               lea ecx, [esi + 8]
// 004af188  83caff               or edx, 0xffffffff
// 004af18b  f00fc111             lock xadd dword ptr [ecx], edx
// 004af18f  7509                 jne 0x4af19a
// 004af191  8b06                 mov eax, dword ptr [esi]
// 004af193  8b5008               mov edx, dword ptr [eax + 8]
// 004af196  8bce                 mov ecx, esi
// 004af198  ffd2                 call edx
// 004af19a  8bc7                 mov eax, edi
// 004af19c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004af1a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004af1a7  59                   pop ecx
// 004af1a8  5f                   pop edi
// 004af1a9  5e                   pop esi
// 004af1aa  83c418               add esp, 0x18
// 004af1ad  c20400               ret 4
// copied from an identical function in another client (function ?get@InsertTexture@ns_ROCX000016@@QAE?AUResult@2@XZ)

namespace ns_ROCX000016 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose() = 0;
    virtual void destroy() = 0;

    volatile long strong;
    volatile long weak;

    void release();
    void releaseWeak();
};

inline void Control::releaseWeak()
{
    if (_InterlockedDecrement(&weak) == 0)
        destroy();
}

inline void Control::release()
{
    volatile long* count = &strong;
    if (_InterlockedDecrement(count) == 0)
    {
        dispose();
        releaseWeak();
    }
}

struct Temporary
{
    void* pointer;
    Control* control;

    ~Temporary();
};

inline Temporary::~Temporary()
{
    if (control)
        control->release();
}

struct Result
{
    void* pointer;
    Control* control;

    Result(const Temporary&);
    ~Result();
};

inline Result::Result(const Temporary& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
    {
        volatile long* count = &control->strong;
        _InterlockedExchangeAdd(count, 1);
    }
}

inline Result::~Result()
{
    if (control)
        control->release();
}

Temporary __cdecl makeTemporary();

struct InsertTexture
{
    Result get();
};

Result InsertTexture::get()
{
    return Result(makeTemporary());
}
}
