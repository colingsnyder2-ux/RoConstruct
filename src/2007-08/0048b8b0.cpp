// from server: 100% by Yeetserama
// roc 2007-08 0048b8b0  unit: RBX::VSpawnerService::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048b8b0
//
// 0048b8b0  6aff                 push -1
// 0048b8b2  68d9717400           push 0x7471d9
// 0048b8b7  64a100000000         mov eax, dword ptr fs:[0]
// 0048b8bd  50                   push eax
// 0048b8be  83ec0c               sub esp, 0xc
// 0048b8c1  56                   push esi
// 0048b8c2  57                   push edi
// 0048b8c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048b8c8  33c4                 xor eax, esp
// 0048b8ca  50                   push eax
// 0048b8cb  8d442418             lea eax, [esp + 0x18]
// 0048b8cf  64a300000000         mov dword ptr fs:[0], eax
// 0048b8d5  8d442410             lea eax, [esp + 0x10]
// 0048b8d9  50                   push eax
// 0048b8da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048b8e2  e839ffffff           call 0x48b820
// 0048b8e7  8b08                 mov ecx, dword ptr [eax]
// 0048b8e9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048b8ed  890f                 mov dword ptr [edi], ecx
// 0048b8ef  8b4004               mov eax, dword ptr [eax + 4]
// 0048b8f2  83c404               add esp, 4
// 0048b8f5  85c0                 test eax, eax
// 0048b8f7  894704               mov dword ptr [edi + 4], eax
// 0048b8fa  740c                 je 0x48b908
// 0048b8fc  83c004               add eax, 4
// 0048b8ff  ba01000000           mov edx, 1
// 0048b904  f00fc110             lock xadd dword ptr [eax], edx
// 0048b908  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048b90c  85f6                 test esi, esi
// 0048b90e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048b916  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0048b91e  742a                 je 0x48b94a
// 0048b920  8d4604               lea eax, [esi + 4]
// 0048b923  83c9ff               or ecx, 0xffffffff
// 0048b926  f00fc108             lock xadd dword ptr [eax], ecx
// 0048b92a  751e                 jne 0x48b94a
// 0048b92c  8b16                 mov edx, dword ptr [esi]
// 0048b92e  8b4204               mov eax, dword ptr [edx + 4]
// 0048b931  8bce                 mov ecx, esi
// 0048b933  ffd0                 call eax
// 0048b935  8d4e08               lea ecx, [esi + 8]
// 0048b938  83caff               or edx, 0xffffffff
// 0048b93b  f00fc111             lock xadd dword ptr [ecx], edx
// 0048b93f  7509                 jne 0x48b94a
// 0048b941  8b06                 mov eax, dword ptr [esi]
// 0048b943  8b5008               mov edx, dword ptr [eax + 8]
// 0048b946  8bce                 mov ecx, esi
// 0048b948  ffd2                 call edx
// 0048b94a  8bc7                 mov eax, edi
// 0048b94c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048b950  64890d00000000       mov dword ptr fs:[0], ecx
// 0048b957  59                   pop ecx
// 0048b958  5f                   pop edi
// 0048b959  5e                   pop esi
// 0048b95a  83c418               add esp, 0x18
// 0048b95d  c20400               ret 4
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
