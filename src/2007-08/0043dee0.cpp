// from server: 100% by Yeetserama
// roc 2007-08 0043dee0  unit: RBX::VSoundService::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043dee0
//
// 0043dee0  6aff                 push -1
// 0043dee2  68d9717400           push 0x7471d9
// 0043dee7  64a100000000         mov eax, dword ptr fs:[0]
// 0043deed  50                   push eax
// 0043deee  83ec0c               sub esp, 0xc
// 0043def1  56                   push esi
// 0043def2  57                   push edi
// 0043def3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043def8  33c4                 xor eax, esp
// 0043defa  50                   push eax
// 0043defb  8d442418             lea eax, [esp + 0x18]
// 0043deff  64a300000000         mov dword ptr fs:[0], eax
// 0043df05  8d442410             lea eax, [esp + 0x10]
// 0043df09  50                   push eax
// 0043df0a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043df12  e839ffffff           call 0x43de50
// 0043df17  8b08                 mov ecx, dword ptr [eax]
// 0043df19  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043df1d  890f                 mov dword ptr [edi], ecx
// 0043df1f  8b4004               mov eax, dword ptr [eax + 4]
// 0043df22  83c404               add esp, 4
// 0043df25  85c0                 test eax, eax
// 0043df27  894704               mov dword ptr [edi + 4], eax
// 0043df2a  740c                 je 0x43df38
// 0043df2c  83c004               add eax, 4
// 0043df2f  ba01000000           mov edx, 1
// 0043df34  f00fc110             lock xadd dword ptr [eax], edx
// 0043df38  8b742414             mov esi, dword ptr [esp + 0x14]
// 0043df3c  85f6                 test esi, esi
// 0043df3e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043df46  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0043df4e  742a                 je 0x43df7a
// 0043df50  8d4604               lea eax, [esi + 4]
// 0043df53  83c9ff               or ecx, 0xffffffff
// 0043df56  f00fc108             lock xadd dword ptr [eax], ecx
// 0043df5a  751e                 jne 0x43df7a
// 0043df5c  8b16                 mov edx, dword ptr [esi]
// 0043df5e  8b4204               mov eax, dword ptr [edx + 4]
// 0043df61  8bce                 mov ecx, esi
// 0043df63  ffd0                 call eax
// 0043df65  8d4e08               lea ecx, [esi + 8]
// 0043df68  83caff               or edx, 0xffffffff
// 0043df6b  f00fc111             lock xadd dword ptr [ecx], edx
// 0043df6f  7509                 jne 0x43df7a
// 0043df71  8b06                 mov eax, dword ptr [esi]
// 0043df73  8b5008               mov edx, dword ptr [eax + 8]
// 0043df76  8bce                 mov ecx, esi
// 0043df78  ffd2                 call edx
// 0043df7a  8bc7                 mov eax, edi
// 0043df7c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043df80  64890d00000000       mov dword ptr fs:[0], ecx
// 0043df87  59                   pop ecx
// 0043df88  5f                   pop edi
// 0043df89  5e                   pop esi
// 0043df8a  83c418               add esp, 0x18
// 0043df8d  c20400               ret 4
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
