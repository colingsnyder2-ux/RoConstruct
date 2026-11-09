// from server: 100% by Yeetserama
// roc 2007-08 0040a680  unit: RBX::VDebugSettings::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a680
//
// 0040a680  6aff                 push -1
// 0040a682  68d9717400           push 0x7471d9
// 0040a687  64a100000000         mov eax, dword ptr fs:[0]
// 0040a68d  50                   push eax
// 0040a68e  83ec0c               sub esp, 0xc
// 0040a691  56                   push esi
// 0040a692  57                   push edi
// 0040a693  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040a698  33c4                 xor eax, esp
// 0040a69a  50                   push eax
// 0040a69b  8d442418             lea eax, [esp + 0x18]
// 0040a69f  64a300000000         mov dword ptr fs:[0], eax
// 0040a6a5  8d442410             lea eax, [esp + 0x10]
// 0040a6a9  50                   push eax
// 0040a6aa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040a6b2  e819efffff           call 0x4095d0
// 0040a6b7  8b08                 mov ecx, dword ptr [eax]
// 0040a6b9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0040a6bd  890f                 mov dword ptr [edi], ecx
// 0040a6bf  8b4004               mov eax, dword ptr [eax + 4]
// 0040a6c2  83c404               add esp, 4
// 0040a6c5  85c0                 test eax, eax
// 0040a6c7  894704               mov dword ptr [edi + 4], eax
// 0040a6ca  740c                 je 0x40a6d8
// 0040a6cc  83c004               add eax, 4
// 0040a6cf  ba01000000           mov edx, 1
// 0040a6d4  f00fc110             lock xadd dword ptr [eax], edx
// 0040a6d8  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040a6dc  85f6                 test esi, esi
// 0040a6de  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0040a6e6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0040a6ee  742a                 je 0x40a71a
// 0040a6f0  8d4604               lea eax, [esi + 4]
// 0040a6f3  83c9ff               or ecx, 0xffffffff
// 0040a6f6  f00fc108             lock xadd dword ptr [eax], ecx
// 0040a6fa  751e                 jne 0x40a71a
// 0040a6fc  8b16                 mov edx, dword ptr [esi]
// 0040a6fe  8b4204               mov eax, dword ptr [edx + 4]
// 0040a701  8bce                 mov ecx, esi
// 0040a703  ffd0                 call eax
// 0040a705  8d4e08               lea ecx, [esi + 8]
// 0040a708  83caff               or edx, 0xffffffff
// 0040a70b  f00fc111             lock xadd dword ptr [ecx], edx
// 0040a70f  7509                 jne 0x40a71a
// 0040a711  8b06                 mov eax, dword ptr [esi]
// 0040a713  8b5008               mov edx, dword ptr [eax + 8]
// 0040a716  8bce                 mov ecx, esi
// 0040a718  ffd2                 call edx
// 0040a71a  8bc7                 mov eax, edi
// 0040a71c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0040a720  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a727  59                   pop ecx
// 0040a728  5f                   pop edi
// 0040a729  5e                   pop esi
// 0040a72a  83c418               add esp, 0x18
// 0040a72d  c20400               ret 4
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
