// from server: 100% by Yeetserama
// roc 2007-08 00426e20  unit: RBX::Reflection::Metadata::VFunctions::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426e20
//
// 00426e20  6aff                 push -1
// 00426e22  68d9717400           push 0x7471d9
// 00426e27  64a100000000         mov eax, dword ptr fs:[0]
// 00426e2d  50                   push eax
// 00426e2e  83ec0c               sub esp, 0xc
// 00426e31  56                   push esi
// 00426e32  57                   push edi
// 00426e33  a188518b00           mov eax, dword ptr [0x8b5188]
// 00426e38  33c4                 xor eax, esp
// 00426e3a  50                   push eax
// 00426e3b  8d442418             lea eax, [esp + 0x18]
// 00426e3f  64a300000000         mov dword ptr fs:[0], eax
// 00426e45  8d442410             lea eax, [esp + 0x10]
// 00426e49  50                   push eax
// 00426e4a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00426e52  e8e9fcffff           call 0x426b40
// 00426e57  8b08                 mov ecx, dword ptr [eax]
// 00426e59  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00426e5d  890f                 mov dword ptr [edi], ecx
// 00426e5f  8b4004               mov eax, dword ptr [eax + 4]
// 00426e62  83c404               add esp, 4
// 00426e65  85c0                 test eax, eax
// 00426e67  894704               mov dword ptr [edi + 4], eax
// 00426e6a  740c                 je 0x426e78
// 00426e6c  83c004               add eax, 4
// 00426e6f  ba01000000           mov edx, 1
// 00426e74  f00fc110             lock xadd dword ptr [eax], edx
// 00426e78  8b742414             mov esi, dword ptr [esp + 0x14]
// 00426e7c  85f6                 test esi, esi
// 00426e7e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00426e86  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00426e8e  742a                 je 0x426eba
// 00426e90  8d4604               lea eax, [esi + 4]
// 00426e93  83c9ff               or ecx, 0xffffffff
// 00426e96  f00fc108             lock xadd dword ptr [eax], ecx
// 00426e9a  751e                 jne 0x426eba
// 00426e9c  8b16                 mov edx, dword ptr [esi]
// 00426e9e  8b4204               mov eax, dword ptr [edx + 4]
// 00426ea1  8bce                 mov ecx, esi
// 00426ea3  ffd0                 call eax
// 00426ea5  8d4e08               lea ecx, [esi + 8]
// 00426ea8  83caff               or edx, 0xffffffff
// 00426eab  f00fc111             lock xadd dword ptr [ecx], edx
// 00426eaf  7509                 jne 0x426eba
// 00426eb1  8b06                 mov eax, dword ptr [esi]
// 00426eb3  8b5008               mov edx, dword ptr [eax + 8]
// 00426eb6  8bce                 mov ecx, esi
// 00426eb8  ffd2                 call edx
// 00426eba  8bc7                 mov eax, edi
// 00426ebc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00426ec0  64890d00000000       mov dword ptr fs:[0], ecx
// 00426ec7  59                   pop ecx
// 00426ec8  5f                   pop edi
// 00426ec9  5e                   pop esi
// 00426eca  83c418               add esp, 0x18
// 00426ecd  c20400               ret 4
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
