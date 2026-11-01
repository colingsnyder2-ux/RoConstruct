// from server: 100% by Yeetserama
// roc 2007-08 0041c830  unit: RBX::VPartInstance::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041c830
//
// 0041c830  6aff                 push -1
// 0041c832  68d9717400           push 0x7471d9
// 0041c837  64a100000000         mov eax, dword ptr fs:[0]
// 0041c83d  50                   push eax
// 0041c83e  83ec0c               sub esp, 0xc
// 0041c841  56                   push esi
// 0041c842  57                   push edi
// 0041c843  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041c848  33c4                 xor eax, esp
// 0041c84a  50                   push eax
// 0041c84b  8d442418             lea eax, [esp + 0x18]
// 0041c84f  64a300000000         mov dword ptr fs:[0], eax
// 0041c855  8d442410             lea eax, [esp + 0x10]
// 0041c859  50                   push eax
// 0041c85a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041c862  e839ffffff           call 0x41c7a0
// 0041c867  8b08                 mov ecx, dword ptr [eax]
// 0041c869  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0041c86d  890f                 mov dword ptr [edi], ecx
// 0041c86f  8b4004               mov eax, dword ptr [eax + 4]
// 0041c872  83c404               add esp, 4
// 0041c875  85c0                 test eax, eax
// 0041c877  894704               mov dword ptr [edi + 4], eax
// 0041c87a  740c                 je 0x41c888
// 0041c87c  83c004               add eax, 4
// 0041c87f  ba01000000           mov edx, 1
// 0041c884  f00fc110             lock xadd dword ptr [eax], edx
// 0041c888  8b742414             mov esi, dword ptr [esp + 0x14]
// 0041c88c  85f6                 test esi, esi
// 0041c88e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0041c896  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0041c89e  742a                 je 0x41c8ca
// 0041c8a0  8d4604               lea eax, [esi + 4]
// 0041c8a3  83c9ff               or ecx, 0xffffffff
// 0041c8a6  f00fc108             lock xadd dword ptr [eax], ecx
// 0041c8aa  751e                 jne 0x41c8ca
// 0041c8ac  8b16                 mov edx, dword ptr [esi]
// 0041c8ae  8b4204               mov eax, dword ptr [edx + 4]
// 0041c8b1  8bce                 mov ecx, esi
// 0041c8b3  ffd0                 call eax
// 0041c8b5  8d4e08               lea ecx, [esi + 8]
// 0041c8b8  83caff               or edx, 0xffffffff
// 0041c8bb  f00fc111             lock xadd dword ptr [ecx], edx
// 0041c8bf  7509                 jne 0x41c8ca
// 0041c8c1  8b06                 mov eax, dword ptr [esi]
// 0041c8c3  8b5008               mov edx, dword ptr [eax + 8]
// 0041c8c6  8bce                 mov ecx, esi
// 0041c8c8  ffd2                 call edx
// 0041c8ca  8bc7                 mov eax, edi
// 0041c8cc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041c8d0  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c8d7  59                   pop ecx
// 0041c8d8  5f                   pop edi
// 0041c8d9  5e                   pop esi
// 0041c8da  83c418               add esp, 0x18
// 0041c8dd  c20400               ret 4
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
