// from server: 100% by Yeetserama
// roc 2007-08 0045a140  unit: RBX::VCamera::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045a140
//
// 0045a140  6aff                 push -1
// 0045a142  68d9717400           push 0x7471d9
// 0045a147  64a100000000         mov eax, dword ptr fs:[0]
// 0045a14d  50                   push eax
// 0045a14e  83ec0c               sub esp, 0xc
// 0045a151  56                   push esi
// 0045a152  57                   push edi
// 0045a153  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045a158  33c4                 xor eax, esp
// 0045a15a  50                   push eax
// 0045a15b  8d442418             lea eax, [esp + 0x18]
// 0045a15f  64a300000000         mov dword ptr fs:[0], eax
// 0045a165  8d442410             lea eax, [esp + 0x10]
// 0045a169  50                   push eax
// 0045a16a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0045a172  e839ffffff           call 0x45a0b0
// 0045a177  8b08                 mov ecx, dword ptr [eax]
// 0045a179  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0045a17d  890f                 mov dword ptr [edi], ecx
// 0045a17f  8b4004               mov eax, dword ptr [eax + 4]
// 0045a182  83c404               add esp, 4
// 0045a185  85c0                 test eax, eax
// 0045a187  894704               mov dword ptr [edi + 4], eax
// 0045a18a  740c                 je 0x45a198
// 0045a18c  83c004               add eax, 4
// 0045a18f  ba01000000           mov edx, 1
// 0045a194  f00fc110             lock xadd dword ptr [eax], edx
// 0045a198  8b742414             mov esi, dword ptr [esp + 0x14]
// 0045a19c  85f6                 test esi, esi
// 0045a19e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0045a1a6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0045a1ae  742a                 je 0x45a1da
// 0045a1b0  8d4604               lea eax, [esi + 4]
// 0045a1b3  83c9ff               or ecx, 0xffffffff
// 0045a1b6  f00fc108             lock xadd dword ptr [eax], ecx
// 0045a1ba  751e                 jne 0x45a1da
// 0045a1bc  8b16                 mov edx, dword ptr [esi]
// 0045a1be  8b4204               mov eax, dword ptr [edx + 4]
// 0045a1c1  8bce                 mov ecx, esi
// 0045a1c3  ffd0                 call eax
// 0045a1c5  8d4e08               lea ecx, [esi + 8]
// 0045a1c8  83caff               or edx, 0xffffffff
// 0045a1cb  f00fc111             lock xadd dword ptr [ecx], edx
// 0045a1cf  7509                 jne 0x45a1da
// 0045a1d1  8b06                 mov eax, dword ptr [esi]
// 0045a1d3  8b5008               mov edx, dword ptr [eax + 8]
// 0045a1d6  8bce                 mov ecx, esi
// 0045a1d8  ffd2                 call edx
// 0045a1da  8bc7                 mov eax, edi
// 0045a1dc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0045a1e0  64890d00000000       mov dword ptr fs:[0], ecx
// 0045a1e7  59                   pop ecx
// 0045a1e8  5f                   pop edi
// 0045a1e9  5e                   pop esi
// 0045a1ea  83c418               add esp, 0x18
// 0045a1ed  c20400               ret 4
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
