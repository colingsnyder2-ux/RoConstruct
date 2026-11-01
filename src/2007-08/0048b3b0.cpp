// from server: 100% by Yeetserama
// roc 2007-08 0048b3b0  unit: RBX::VGameSettings::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048b3b0
//
// 0048b3b0  6aff                 push -1
// 0048b3b2  68d9717400           push 0x7471d9
// 0048b3b7  64a100000000         mov eax, dword ptr fs:[0]
// 0048b3bd  50                   push eax
// 0048b3be  83ec0c               sub esp, 0xc
// 0048b3c1  56                   push esi
// 0048b3c2  57                   push edi
// 0048b3c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048b3c8  33c4                 xor eax, esp
// 0048b3ca  50                   push eax
// 0048b3cb  8d442418             lea eax, [esp + 0x18]
// 0048b3cf  64a300000000         mov dword ptr fs:[0], eax
// 0048b3d5  8d442410             lea eax, [esp + 0x10]
// 0048b3d9  50                   push eax
// 0048b3da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048b3e2  e839ffffff           call 0x48b320
// 0048b3e7  8b08                 mov ecx, dword ptr [eax]
// 0048b3e9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048b3ed  890f                 mov dword ptr [edi], ecx
// 0048b3ef  8b4004               mov eax, dword ptr [eax + 4]
// 0048b3f2  83c404               add esp, 4
// 0048b3f5  85c0                 test eax, eax
// 0048b3f7  894704               mov dword ptr [edi + 4], eax
// 0048b3fa  740c                 je 0x48b408
// 0048b3fc  83c004               add eax, 4
// 0048b3ff  ba01000000           mov edx, 1
// 0048b404  f00fc110             lock xadd dword ptr [eax], edx
// 0048b408  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048b40c  85f6                 test esi, esi
// 0048b40e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048b416  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0048b41e  742a                 je 0x48b44a
// 0048b420  8d4604               lea eax, [esi + 4]
// 0048b423  83c9ff               or ecx, 0xffffffff
// 0048b426  f00fc108             lock xadd dword ptr [eax], ecx
// 0048b42a  751e                 jne 0x48b44a
// 0048b42c  8b16                 mov edx, dword ptr [esi]
// 0048b42e  8b4204               mov eax, dword ptr [edx + 4]
// 0048b431  8bce                 mov ecx, esi
// 0048b433  ffd0                 call eax
// 0048b435  8d4e08               lea ecx, [esi + 8]
// 0048b438  83caff               or edx, 0xffffffff
// 0048b43b  f00fc111             lock xadd dword ptr [ecx], edx
// 0048b43f  7509                 jne 0x48b44a
// 0048b441  8b06                 mov eax, dword ptr [esi]
// 0048b443  8b5008               mov edx, dword ptr [eax + 8]
// 0048b446  8bce                 mov ecx, esi
// 0048b448  ffd2                 call edx
// 0048b44a  8bc7                 mov eax, edi
// 0048b44c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048b450  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b457  59                   pop ecx
// 0048b458  5f                   pop edi
// 0048b459  5e                   pop esi
// 0048b45a  83c418               add esp, 0x18
// 0048b45d  c20400               ret 4
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
