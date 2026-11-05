// from server: 100% by Yeetserama
// roc 2007-08 00408330  unit: RBX::VLocalScript::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00408330
//
// 00408330  6aff                 push -1
// 00408332  68d9717400           push 0x7471d9
// 00408337  64a100000000         mov eax, dword ptr fs:[0]
// 0040833d  50                   push eax
// 0040833e  83ec0c               sub esp, 0xc
// 00408341  56                   push esi
// 00408342  57                   push edi
// 00408343  a188518b00           mov eax, dword ptr [0x8b5188]
// 00408348  33c4                 xor eax, esp
// 0040834a  50                   push eax
// 0040834b  8d442418             lea eax, [esp + 0x18]
// 0040834f  64a300000000         mov dword ptr fs:[0], eax
// 00408355  8d442410             lea eax, [esp + 0x10]
// 00408359  50                   push eax
// 0040835a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00408362  e839ffffff           call 0x4082a0
// 00408367  8b08                 mov ecx, dword ptr [eax]
// 00408369  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0040836d  890f                 mov dword ptr [edi], ecx
// 0040836f  8b4004               mov eax, dword ptr [eax + 4]
// 00408372  83c404               add esp, 4
// 00408375  85c0                 test eax, eax
// 00408377  894704               mov dword ptr [edi + 4], eax
// 0040837a  740c                 je 0x408388
// 0040837c  83c004               add eax, 4
// 0040837f  ba01000000           mov edx, 1
// 00408384  f00fc110             lock xadd dword ptr [eax], edx
// 00408388  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040838c  85f6                 test esi, esi
// 0040838e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00408396  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0040839e  742a                 je 0x4083ca
// 004083a0  8d4604               lea eax, [esi + 4]
// 004083a3  83c9ff               or ecx, 0xffffffff
// 004083a6  f00fc108             lock xadd dword ptr [eax], ecx
// 004083aa  751e                 jne 0x4083ca
// 004083ac  8b16                 mov edx, dword ptr [esi]
// 004083ae  8b4204               mov eax, dword ptr [edx + 4]
// 004083b1  8bce                 mov ecx, esi
// 004083b3  ffd0                 call eax
// 004083b5  8d4e08               lea ecx, [esi + 8]
// 004083b8  83caff               or edx, 0xffffffff
// 004083bb  f00fc111             lock xadd dword ptr [ecx], edx
// 004083bf  7509                 jne 0x4083ca
// 004083c1  8b06                 mov eax, dword ptr [esi]
// 004083c3  8b5008               mov edx, dword ptr [eax + 8]
// 004083c6  8bce                 mov ecx, esi
// 004083c8  ffd2                 call edx
// 004083ca  8bc7                 mov eax, edi
// 004083cc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004083d0  64890d00000000       mov dword ptr fs:[0], ecx
// 004083d7  59                   pop ecx
// 004083d8  5f                   pop edi
// 004083d9  5e                   pop esi
// 004083da  83c418               add esp, 0x18
// 004083dd  c20400               ret 4
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
