// from server: 100% by Yeetserama
// roc 2007-08 00407e30  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00407e30
//
// 00407e30  6aff                 push -1
// 00407e32  68d9717400           push 0x7471d9
// 00407e37  64a100000000         mov eax, dword ptr fs:[0]
// 00407e3d  50                   push eax
// 00407e3e  83ec0c               sub esp, 0xc
// 00407e41  56                   push esi
// 00407e42  57                   push edi
// 00407e43  a188518b00           mov eax, dword ptr [0x8b5188]
// 00407e48  33c4                 xor eax, esp
// 00407e4a  50                   push eax
// 00407e4b  8d442418             lea eax, [esp + 0x18]
// 00407e4f  64a300000000         mov dword ptr fs:[0], eax
// 00407e55  8d442410             lea eax, [esp + 0x10]
// 00407e59  50                   push eax
// 00407e5a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00407e62  e839ffffff           call 0x407da0
// 00407e67  8b08                 mov ecx, dword ptr [eax]
// 00407e69  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00407e6d  890f                 mov dword ptr [edi], ecx
// 00407e6f  8b4004               mov eax, dword ptr [eax + 4]
// 00407e72  83c404               add esp, 4
// 00407e75  85c0                 test eax, eax
// 00407e77  894704               mov dword ptr [edi + 4], eax
// 00407e7a  740c                 je 0x407e88
// 00407e7c  83c004               add eax, 4
// 00407e7f  ba01000000           mov edx, 1
// 00407e84  f00fc110             lock xadd dword ptr [eax], edx
// 00407e88  8b742414             mov esi, dword ptr [esp + 0x14]
// 00407e8c  85f6                 test esi, esi
// 00407e8e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00407e96  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00407e9e  742a                 je 0x407eca
// 00407ea0  8d4604               lea eax, [esi + 4]
// 00407ea3  83c9ff               or ecx, 0xffffffff
// 00407ea6  f00fc108             lock xadd dword ptr [eax], ecx
// 00407eaa  751e                 jne 0x407eca
// 00407eac  8b16                 mov edx, dword ptr [esi]
// 00407eae  8b4204               mov eax, dword ptr [edx + 4]
// 00407eb1  8bce                 mov ecx, esi
// 00407eb3  ffd0                 call eax
// 00407eb5  8d4e08               lea ecx, [esi + 8]
// 00407eb8  83caff               or edx, 0xffffffff
// 00407ebb  f00fc111             lock xadd dword ptr [ecx], edx
// 00407ebf  7509                 jne 0x407eca
// 00407ec1  8b06                 mov eax, dword ptr [esi]
// 00407ec3  8b5008               mov edx, dword ptr [eax + 8]
// 00407ec6  8bce                 mov ecx, esi
// 00407ec8  ffd2                 call edx
// 00407eca  8bc7                 mov eax, edi
// 00407ecc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00407ed0  64890d00000000       mov dword ptr fs:[0], ecx
// 00407ed7  59                   pop ecx
// 00407ed8  5f                   pop edi
// 00407ed9  5e                   pop esi
// 00407eda  83c418               add esp, 0x18
// 00407edd  c20400               ret 4
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
