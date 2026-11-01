// from server: 100% by Yeetserama
// roc 2007-08 0048c030  unit: RBX::VBodyColors::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048c030
//
// 0048c030  6aff                 push -1
// 0048c032  68d9717400           push 0x7471d9
// 0048c037  64a100000000         mov eax, dword ptr fs:[0]
// 0048c03d  50                   push eax
// 0048c03e  83ec0c               sub esp, 0xc
// 0048c041  56                   push esi
// 0048c042  57                   push edi
// 0048c043  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048c048  33c4                 xor eax, esp
// 0048c04a  50                   push eax
// 0048c04b  8d442418             lea eax, [esp + 0x18]
// 0048c04f  64a300000000         mov dword ptr fs:[0], eax
// 0048c055  8d442410             lea eax, [esp + 0x10]
// 0048c059  50                   push eax
// 0048c05a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048c062  e839ffffff           call 0x48bfa0
// 0048c067  8b08                 mov ecx, dword ptr [eax]
// 0048c069  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048c06d  890f                 mov dword ptr [edi], ecx
// 0048c06f  8b4004               mov eax, dword ptr [eax + 4]
// 0048c072  83c404               add esp, 4
// 0048c075  85c0                 test eax, eax
// 0048c077  894704               mov dword ptr [edi + 4], eax
// 0048c07a  740c                 je 0x48c088
// 0048c07c  83c004               add eax, 4
// 0048c07f  ba01000000           mov edx, 1
// 0048c084  f00fc110             lock xadd dword ptr [eax], edx
// 0048c088  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048c08c  85f6                 test esi, esi
// 0048c08e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048c096  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0048c09e  742a                 je 0x48c0ca
// 0048c0a0  8d4604               lea eax, [esi + 4]
// 0048c0a3  83c9ff               or ecx, 0xffffffff
// 0048c0a6  f00fc108             lock xadd dword ptr [eax], ecx
// 0048c0aa  751e                 jne 0x48c0ca
// 0048c0ac  8b16                 mov edx, dword ptr [esi]
// 0048c0ae  8b4204               mov eax, dword ptr [edx + 4]
// 0048c0b1  8bce                 mov ecx, esi
// 0048c0b3  ffd0                 call eax
// 0048c0b5  8d4e08               lea ecx, [esi + 8]
// 0048c0b8  83caff               or edx, 0xffffffff
// 0048c0bb  f00fc111             lock xadd dword ptr [ecx], edx
// 0048c0bf  7509                 jne 0x48c0ca
// 0048c0c1  8b06                 mov eax, dword ptr [esi]
// 0048c0c3  8b5008               mov edx, dword ptr [eax + 8]
// 0048c0c6  8bce                 mov ecx, esi
// 0048c0c8  ffd2                 call edx
// 0048c0ca  8bc7                 mov eax, edi
// 0048c0cc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048c0d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0048c0d7  59                   pop ecx
// 0048c0d8  5f                   pop edi
// 0048c0d9  5e                   pop esi
// 0048c0da  83c418               add esp, 0x18
// 0048c0dd  c20400               ret 4
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
