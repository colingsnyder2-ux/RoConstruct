// from server: 100% by Yeetserama
// roc 2007-08 0048bb30  unit: RBX::VShirtGraphic::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048bb30
//
// 0048bb30  6aff                 push -1
// 0048bb32  68d9717400           push 0x7471d9
// 0048bb37  64a100000000         mov eax, dword ptr fs:[0]
// 0048bb3d  50                   push eax
// 0048bb3e  83ec0c               sub esp, 0xc
// 0048bb41  56                   push esi
// 0048bb42  57                   push edi
// 0048bb43  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048bb48  33c4                 xor eax, esp
// 0048bb4a  50                   push eax
// 0048bb4b  8d442418             lea eax, [esp + 0x18]
// 0048bb4f  64a300000000         mov dword ptr fs:[0], eax
// 0048bb55  8d442410             lea eax, [esp + 0x10]
// 0048bb59  50                   push eax
// 0048bb5a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048bb62  e839ffffff           call 0x48baa0
// 0048bb67  8b08                 mov ecx, dword ptr [eax]
// 0048bb69  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048bb6d  890f                 mov dword ptr [edi], ecx
// 0048bb6f  8b4004               mov eax, dword ptr [eax + 4]
// 0048bb72  83c404               add esp, 4
// 0048bb75  85c0                 test eax, eax
// 0048bb77  894704               mov dword ptr [edi + 4], eax
// 0048bb7a  740c                 je 0x48bb88
// 0048bb7c  83c004               add eax, 4
// 0048bb7f  ba01000000           mov edx, 1
// 0048bb84  f00fc110             lock xadd dword ptr [eax], edx
// 0048bb88  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048bb8c  85f6                 test esi, esi
// 0048bb8e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048bb96  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0048bb9e  742a                 je 0x48bbca
// 0048bba0  8d4604               lea eax, [esi + 4]
// 0048bba3  83c9ff               or ecx, 0xffffffff
// 0048bba6  f00fc108             lock xadd dword ptr [eax], ecx
// 0048bbaa  751e                 jne 0x48bbca
// 0048bbac  8b16                 mov edx, dword ptr [esi]
// 0048bbae  8b4204               mov eax, dword ptr [edx + 4]
// 0048bbb1  8bce                 mov ecx, esi
// 0048bbb3  ffd0                 call eax
// 0048bbb5  8d4e08               lea ecx, [esi + 8]
// 0048bbb8  83caff               or edx, 0xffffffff
// 0048bbbb  f00fc111             lock xadd dword ptr [ecx], edx
// 0048bbbf  7509                 jne 0x48bbca
// 0048bbc1  8b06                 mov eax, dword ptr [esi]
// 0048bbc3  8b5008               mov edx, dword ptr [eax + 8]
// 0048bbc6  8bce                 mov ecx, esi
// 0048bbc8  ffd2                 call edx
// 0048bbca  8bc7                 mov eax, edi
// 0048bbcc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048bbd0  64890d00000000       mov dword ptr fs:[0], ecx
// 0048bbd7  59                   pop ecx
// 0048bbd8  5f                   pop edi
// 0048bbd9  5e                   pop esi
// 0048bbda  83c418               add esp, 0x18
// 0048bbdd  c20400               ret 4
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
