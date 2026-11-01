// from server: 100% by Yeetserama
// roc 2007-08 00426ed0  unit: RBX::Reflection::Metadata::VEvents::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426ed0
//
// 00426ed0  6aff                 push -1
// 00426ed2  68d9717400           push 0x7471d9
// 00426ed7  64a100000000         mov eax, dword ptr fs:[0]
// 00426edd  50                   push eax
// 00426ede  83ec0c               sub esp, 0xc
// 00426ee1  56                   push esi
// 00426ee2  57                   push edi
// 00426ee3  a188518b00           mov eax, dword ptr [0x8b5188]
// 00426ee8  33c4                 xor eax, esp
// 00426eea  50                   push eax
// 00426eeb  8d442418             lea eax, [esp + 0x18]
// 00426eef  64a300000000         mov dword ptr fs:[0], eax
// 00426ef5  8d442410             lea eax, [esp + 0x10]
// 00426ef9  50                   push eax
// 00426efa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00426f02  e8c9fcffff           call 0x426bd0
// 00426f07  8b08                 mov ecx, dword ptr [eax]
// 00426f09  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00426f0d  890f                 mov dword ptr [edi], ecx
// 00426f0f  8b4004               mov eax, dword ptr [eax + 4]
// 00426f12  83c404               add esp, 4
// 00426f15  85c0                 test eax, eax
// 00426f17  894704               mov dword ptr [edi + 4], eax
// 00426f1a  740c                 je 0x426f28
// 00426f1c  83c004               add eax, 4
// 00426f1f  ba01000000           mov edx, 1
// 00426f24  f00fc110             lock xadd dword ptr [eax], edx
// 00426f28  8b742414             mov esi, dword ptr [esp + 0x14]
// 00426f2c  85f6                 test esi, esi
// 00426f2e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00426f36  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00426f3e  742a                 je 0x426f6a
// 00426f40  8d4604               lea eax, [esi + 4]
// 00426f43  83c9ff               or ecx, 0xffffffff
// 00426f46  f00fc108             lock xadd dword ptr [eax], ecx
// 00426f4a  751e                 jne 0x426f6a
// 00426f4c  8b16                 mov edx, dword ptr [esi]
// 00426f4e  8b4204               mov eax, dword ptr [edx + 4]
// 00426f51  8bce                 mov ecx, esi
// 00426f53  ffd0                 call eax
// 00426f55  8d4e08               lea ecx, [esi + 8]
// 00426f58  83caff               or edx, 0xffffffff
// 00426f5b  f00fc111             lock xadd dword ptr [ecx], edx
// 00426f5f  7509                 jne 0x426f6a
// 00426f61  8b06                 mov eax, dword ptr [esi]
// 00426f63  8b5008               mov edx, dword ptr [eax + 8]
// 00426f66  8bce                 mov ecx, esi
// 00426f68  ffd2                 call edx
// 00426f6a  8bc7                 mov eax, edi
// 00426f6c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00426f70  64890d00000000       mov dword ptr fs:[0], ecx
// 00426f77  59                   pop ecx
// 00426f78  5f                   pop edi
// 00426f79  5e                   pop esi
// 00426f7a  83c418               add esp, 0x18
// 00426f7d  c20400               ret 4
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
