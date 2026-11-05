// from server: 100% by Yeetserama
// roc 2007-08 004080b0  unit: RBX::VScript::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004080b0
//
// 004080b0  6aff                 push -1
// 004080b2  68d9717400           push 0x7471d9
// 004080b7  64a100000000         mov eax, dword ptr fs:[0]
// 004080bd  50                   push eax
// 004080be  83ec0c               sub esp, 0xc
// 004080c1  56                   push esi
// 004080c2  57                   push edi
// 004080c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004080c8  33c4                 xor eax, esp
// 004080ca  50                   push eax
// 004080cb  8d442418             lea eax, [esp + 0x18]
// 004080cf  64a300000000         mov dword ptr fs:[0], eax
// 004080d5  8d442410             lea eax, [esp + 0x10]
// 004080d9  50                   push eax
// 004080da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004080e2  e839ffffff           call 0x408020
// 004080e7  8b08                 mov ecx, dword ptr [eax]
// 004080e9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004080ed  890f                 mov dword ptr [edi], ecx
// 004080ef  8b4004               mov eax, dword ptr [eax + 4]
// 004080f2  83c404               add esp, 4
// 004080f5  85c0                 test eax, eax
// 004080f7  894704               mov dword ptr [edi + 4], eax
// 004080fa  740c                 je 0x408108
// 004080fc  83c004               add eax, 4
// 004080ff  ba01000000           mov edx, 1
// 00408104  f00fc110             lock xadd dword ptr [eax], edx
// 00408108  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040810c  85f6                 test esi, esi
// 0040810e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00408116  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0040811e  742a                 je 0x40814a
// 00408120  8d4604               lea eax, [esi + 4]
// 00408123  83c9ff               or ecx, 0xffffffff
// 00408126  f00fc108             lock xadd dword ptr [eax], ecx
// 0040812a  751e                 jne 0x40814a
// 0040812c  8b16                 mov edx, dword ptr [esi]
// 0040812e  8b4204               mov eax, dword ptr [edx + 4]
// 00408131  8bce                 mov ecx, esi
// 00408133  ffd0                 call eax
// 00408135  8d4e08               lea ecx, [esi + 8]
// 00408138  83caff               or edx, 0xffffffff
// 0040813b  f00fc111             lock xadd dword ptr [ecx], edx
// 0040813f  7509                 jne 0x40814a
// 00408141  8b06                 mov eax, dword ptr [esi]
// 00408143  8b5008               mov edx, dword ptr [eax + 8]
// 00408146  8bce                 mov ecx, esi
// 00408148  ffd2                 call edx
// 0040814a  8bc7                 mov eax, edi
// 0040814c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00408150  64890d00000000       mov dword ptr fs:[0], ecx
// 00408157  59                   pop ecx
// 00408158  5f                   pop edi
// 00408159  5e                   pop esi
// 0040815a  83c418               add esp, 0x18
// 0040815d  c20400               ret 4
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
