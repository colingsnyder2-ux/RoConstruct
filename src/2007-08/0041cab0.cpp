// from server: 100% by Yeetserama
// roc 2007-08 0041cab0  unit: RBX::VSpecialShape::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041cab0
//
// 0041cab0  6aff                 push -1
// 0041cab2  68d9717400           push 0x7471d9
// 0041cab7  64a100000000         mov eax, dword ptr fs:[0]
// 0041cabd  50                   push eax
// 0041cabe  83ec0c               sub esp, 0xc
// 0041cac1  56                   push esi
// 0041cac2  57                   push edi
// 0041cac3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041cac8  33c4                 xor eax, esp
// 0041caca  50                   push eax
// 0041cacb  8d442418             lea eax, [esp + 0x18]
// 0041cacf  64a300000000         mov dword ptr fs:[0], eax
// 0041cad5  8d442410             lea eax, [esp + 0x10]
// 0041cad9  50                   push eax
// 0041cada  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041cae2  e839ffffff           call 0x41ca20
// 0041cae7  8b08                 mov ecx, dword ptr [eax]
// 0041cae9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0041caed  890f                 mov dword ptr [edi], ecx
// 0041caef  8b4004               mov eax, dword ptr [eax + 4]
// 0041caf2  83c404               add esp, 4
// 0041caf5  85c0                 test eax, eax
// 0041caf7  894704               mov dword ptr [edi + 4], eax
// 0041cafa  740c                 je 0x41cb08
// 0041cafc  83c004               add eax, 4
// 0041caff  ba01000000           mov edx, 1
// 0041cb04  f00fc110             lock xadd dword ptr [eax], edx
// 0041cb08  8b742414             mov esi, dword ptr [esp + 0x14]
// 0041cb0c  85f6                 test esi, esi
// 0041cb0e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0041cb16  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0041cb1e  742a                 je 0x41cb4a
// 0041cb20  8d4604               lea eax, [esi + 4]
// 0041cb23  83c9ff               or ecx, 0xffffffff
// 0041cb26  f00fc108             lock xadd dword ptr [eax], ecx
// 0041cb2a  751e                 jne 0x41cb4a
// 0041cb2c  8b16                 mov edx, dword ptr [esi]
// 0041cb2e  8b4204               mov eax, dword ptr [edx + 4]
// 0041cb31  8bce                 mov ecx, esi
// 0041cb33  ffd0                 call eax
// 0041cb35  8d4e08               lea ecx, [esi + 8]
// 0041cb38  83caff               or edx, 0xffffffff
// 0041cb3b  f00fc111             lock xadd dword ptr [ecx], edx
// 0041cb3f  7509                 jne 0x41cb4a
// 0041cb41  8b06                 mov eax, dword ptr [esi]
// 0041cb43  8b5008               mov edx, dword ptr [eax + 8]
// 0041cb46  8bce                 mov ecx, esi
// 0041cb48  ffd2                 call edx
// 0041cb4a  8bc7                 mov eax, edi
// 0041cb4c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041cb50  64890d00000000       mov dword ptr fs:[0], ecx
// 0041cb57  59                   pop ecx
// 0041cb58  5f                   pop edi
// 0041cb59  5e                   pop esi
// 0041cb5a  83c418               add esp, 0x18
// 0041cb5d  c20400               ret 4
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
