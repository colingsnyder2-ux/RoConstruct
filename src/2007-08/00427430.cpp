// from server: 100% by Yeetserama
// roc 2007-08 00427430  unit: RBX::Reflection::Metadata::VClass::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00427430
//
// 00427430  6aff                 push -1
// 00427432  68d9717400           push 0x7471d9
// 00427437  64a100000000         mov eax, dword ptr fs:[0]
// 0042743d  50                   push eax
// 0042743e  83ec0c               sub esp, 0xc
// 00427441  56                   push esi
// 00427442  57                   push edi
// 00427443  a188518b00           mov eax, dword ptr [0x8b5188]
// 00427448  33c4                 xor eax, esp
// 0042744a  50                   push eax
// 0042744b  8d442418             lea eax, [esp + 0x18]
// 0042744f  64a300000000         mov dword ptr fs:[0], eax
// 00427455  8d442410             lea eax, [esp + 0x10]
// 00427459  50                   push eax
// 0042745a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00427462  e8e9feffff           call 0x427350
// 00427467  8b08                 mov ecx, dword ptr [eax]
// 00427469  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0042746d  890f                 mov dword ptr [edi], ecx
// 0042746f  8b4004               mov eax, dword ptr [eax + 4]
// 00427472  83c404               add esp, 4
// 00427475  85c0                 test eax, eax
// 00427477  894704               mov dword ptr [edi + 4], eax
// 0042747a  740c                 je 0x427488
// 0042747c  83c004               add eax, 4
// 0042747f  ba01000000           mov edx, 1
// 00427484  f00fc110             lock xadd dword ptr [eax], edx
// 00427488  8b742414             mov esi, dword ptr [esp + 0x14]
// 0042748c  85f6                 test esi, esi
// 0042748e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00427496  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0042749e  742a                 je 0x4274ca
// 004274a0  8d4604               lea eax, [esi + 4]
// 004274a3  83c9ff               or ecx, 0xffffffff
// 004274a6  f00fc108             lock xadd dword ptr [eax], ecx
// 004274aa  751e                 jne 0x4274ca
// 004274ac  8b16                 mov edx, dword ptr [esi]
// 004274ae  8b4204               mov eax, dword ptr [edx + 4]
// 004274b1  8bce                 mov ecx, esi
// 004274b3  ffd0                 call eax
// 004274b5  8d4e08               lea ecx, [esi + 8]
// 004274b8  83caff               or edx, 0xffffffff
// 004274bb  f00fc111             lock xadd dword ptr [ecx], edx
// 004274bf  7509                 jne 0x4274ca
// 004274c1  8b06                 mov eax, dword ptr [esi]
// 004274c3  8b5008               mov edx, dword ptr [eax + 8]
// 004274c6  8bce                 mov ecx, esi
// 004274c8  ffd2                 call edx
// 004274ca  8bc7                 mov eax, edi
// 004274cc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004274d0  64890d00000000       mov dword ptr fs:[0], ecx
// 004274d7  59                   pop ecx
// 004274d8  5f                   pop edi
// 004274d9  5e                   pop esi
// 004274da  83c418               add esp, 0x18
// 004274dd  c20400               ret 4
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
