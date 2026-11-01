// from server: 100% by Yeetserama
// roc 2007-08 00407bb0  unit: RBX::VSelection::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00407bb0
//
// 00407bb0  6aff                 push -1
// 00407bb2  68d9717400           push 0x7471d9
// 00407bb7  64a100000000         mov eax, dword ptr fs:[0]
// 00407bbd  50                   push eax
// 00407bbe  83ec0c               sub esp, 0xc
// 00407bc1  56                   push esi
// 00407bc2  57                   push edi
// 00407bc3  a188518b00           mov eax, dword ptr [0x8b5188]
// 00407bc8  33c4                 xor eax, esp
// 00407bca  50                   push eax
// 00407bcb  8d442418             lea eax, [esp + 0x18]
// 00407bcf  64a300000000         mov dword ptr fs:[0], eax
// 00407bd5  8d442410             lea eax, [esp + 0x10]
// 00407bd9  50                   push eax
// 00407bda  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00407be2  e839ffffff           call 0x407b20
// 00407be7  8b08                 mov ecx, dword ptr [eax]
// 00407be9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00407bed  890f                 mov dword ptr [edi], ecx
// 00407bef  8b4004               mov eax, dword ptr [eax + 4]
// 00407bf2  83c404               add esp, 4
// 00407bf5  85c0                 test eax, eax
// 00407bf7  894704               mov dword ptr [edi + 4], eax
// 00407bfa  740c                 je 0x407c08
// 00407bfc  83c004               add eax, 4
// 00407bff  ba01000000           mov edx, 1
// 00407c04  f00fc110             lock xadd dword ptr [eax], edx
// 00407c08  8b742414             mov esi, dword ptr [esp + 0x14]
// 00407c0c  85f6                 test esi, esi
// 00407c0e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00407c16  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00407c1e  742a                 je 0x407c4a
// 00407c20  8d4604               lea eax, [esi + 4]
// 00407c23  83c9ff               or ecx, 0xffffffff
// 00407c26  f00fc108             lock xadd dword ptr [eax], ecx
// 00407c2a  751e                 jne 0x407c4a
// 00407c2c  8b16                 mov edx, dword ptr [esi]
// 00407c2e  8b4204               mov eax, dword ptr [edx + 4]
// 00407c31  8bce                 mov ecx, esi
// 00407c33  ffd0                 call eax
// 00407c35  8d4e08               lea ecx, [esi + 8]
// 00407c38  83caff               or edx, 0xffffffff
// 00407c3b  f00fc111             lock xadd dword ptr [ecx], edx
// 00407c3f  7509                 jne 0x407c4a
// 00407c41  8b06                 mov eax, dword ptr [esi]
// 00407c43  8b5008               mov edx, dword ptr [eax + 8]
// 00407c46  8bce                 mov ecx, esi
// 00407c48  ffd2                 call edx
// 00407c4a  8bc7                 mov eax, edi
// 00407c4c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00407c50  64890d00000000       mov dword ptr fs:[0], ecx
// 00407c57  59                   pop ecx
// 00407c58  5f                   pop edi
// 00407c59  5e                   pop esi
// 00407c5a  83c418               add esp, 0x18
// 00407c5d  c20400               ret 4
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
