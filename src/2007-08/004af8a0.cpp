// from server: 100% by Yeetserama
// roc 2007-08 004af8a0  unit: RBX::VMotor::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004af8a0
//
// 004af8a0  6aff                 push -1
// 004af8a2  68d9717400           push 0x7471d9
// 004af8a7  64a100000000         mov eax, dword ptr fs:[0]
// 004af8ad  50                   push eax
// 004af8ae  83ec0c               sub esp, 0xc
// 004af8b1  56                   push esi
// 004af8b2  57                   push edi
// 004af8b3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004af8b8  33c4                 xor eax, esp
// 004af8ba  50                   push eax
// 004af8bb  8d442418             lea eax, [esp + 0x18]
// 004af8bf  64a300000000         mov dword ptr fs:[0], eax
// 004af8c5  8d442410             lea eax, [esp + 0x10]
// 004af8c9  50                   push eax
// 004af8ca  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004af8d2  e839ffffff           call 0x4af810
// 004af8d7  8b08                 mov ecx, dword ptr [eax]
// 004af8d9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004af8dd  890f                 mov dword ptr [edi], ecx
// 004af8df  8b4004               mov eax, dword ptr [eax + 4]
// 004af8e2  83c404               add esp, 4
// 004af8e5  85c0                 test eax, eax
// 004af8e7  894704               mov dword ptr [edi + 4], eax
// 004af8ea  740c                 je 0x4af8f8
// 004af8ec  83c004               add eax, 4
// 004af8ef  ba01000000           mov edx, 1
// 004af8f4  f00fc110             lock xadd dword ptr [eax], edx
// 004af8f8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004af8fc  85f6                 test esi, esi
// 004af8fe  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004af906  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004af90e  742a                 je 0x4af93a
// 004af910  8d4604               lea eax, [esi + 4]
// 004af913  83c9ff               or ecx, 0xffffffff
// 004af916  f00fc108             lock xadd dword ptr [eax], ecx
// 004af91a  751e                 jne 0x4af93a
// 004af91c  8b16                 mov edx, dword ptr [esi]
// 004af91e  8b4204               mov eax, dword ptr [edx + 4]
// 004af921  8bce                 mov ecx, esi
// 004af923  ffd0                 call eax
// 004af925  8d4e08               lea ecx, [esi + 8]
// 004af928  83caff               or edx, 0xffffffff
// 004af92b  f00fc111             lock xadd dword ptr [ecx], edx
// 004af92f  7509                 jne 0x4af93a
// 004af931  8b06                 mov eax, dword ptr [esi]
// 004af933  8b5008               mov edx, dword ptr [eax + 8]
// 004af936  8bce                 mov ecx, esi
// 004af938  ffd2                 call edx
// 004af93a  8bc7                 mov eax, edi
// 004af93c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004af940  64890d00000000       mov dword ptr fs:[0], ecx
// 004af947  59                   pop ecx
// 004af948  5f                   pop edi
// 004af949  5e                   pop esi
// 004af94a  83c418               add esp, 0x18
// 004af94d  c20400               ret 4
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
