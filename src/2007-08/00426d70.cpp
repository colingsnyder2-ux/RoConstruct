// from server: 100% by Yeetserama
// roc 2007-08 00426d70  unit: RBX::Reflection::Metadata::VProperties::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00426d70
//
// 00426d70  6aff                 push -1
// 00426d72  68d9717400           push 0x7471d9
// 00426d77  64a100000000         mov eax, dword ptr fs:[0]
// 00426d7d  50                   push eax
// 00426d7e  83ec0c               sub esp, 0xc
// 00426d81  56                   push esi
// 00426d82  57                   push edi
// 00426d83  a188518b00           mov eax, dword ptr [0x8b5188]
// 00426d88  33c4                 xor eax, esp
// 00426d8a  50                   push eax
// 00426d8b  8d442418             lea eax, [esp + 0x18]
// 00426d8f  64a300000000         mov dword ptr fs:[0], eax
// 00426d95  8d442410             lea eax, [esp + 0x10]
// 00426d99  50                   push eax
// 00426d9a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00426da2  e809fdffff           call 0x426ab0
// 00426da7  8b08                 mov ecx, dword ptr [eax]
// 00426da9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00426dad  890f                 mov dword ptr [edi], ecx
// 00426daf  8b4004               mov eax, dword ptr [eax + 4]
// 00426db2  83c404               add esp, 4
// 00426db5  85c0                 test eax, eax
// 00426db7  894704               mov dword ptr [edi + 4], eax
// 00426dba  740c                 je 0x426dc8
// 00426dbc  83c004               add eax, 4
// 00426dbf  ba01000000           mov edx, 1
// 00426dc4  f00fc110             lock xadd dword ptr [eax], edx
// 00426dc8  8b742414             mov esi, dword ptr [esp + 0x14]
// 00426dcc  85f6                 test esi, esi
// 00426dce  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00426dd6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00426dde  742a                 je 0x426e0a
// 00426de0  8d4604               lea eax, [esi + 4]
// 00426de3  83c9ff               or ecx, 0xffffffff
// 00426de6  f00fc108             lock xadd dword ptr [eax], ecx
// 00426dea  751e                 jne 0x426e0a
// 00426dec  8b16                 mov edx, dword ptr [esi]
// 00426dee  8b4204               mov eax, dword ptr [edx + 4]
// 00426df1  8bce                 mov ecx, esi
// 00426df3  ffd0                 call eax
// 00426df5  8d4e08               lea ecx, [esi + 8]
// 00426df8  83caff               or edx, 0xffffffff
// 00426dfb  f00fc111             lock xadd dword ptr [ecx], edx
// 00426dff  7509                 jne 0x426e0a
// 00426e01  8b06                 mov eax, dword ptr [esi]
// 00426e03  8b5008               mov edx, dword ptr [eax + 8]
// 00426e06  8bce                 mov ecx, esi
// 00426e08  ffd2                 call edx
// 00426e0a  8bc7                 mov eax, edi
// 00426e0c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00426e10  64890d00000000       mov dword ptr fs:[0], ecx
// 00426e17  59                   pop ecx
// 00426e18  5f                   pop edi
// 00426e19  5e                   pop esi
// 00426e1a  83c418               add esp, 0x18
// 00426e1d  c20400               ret 4
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
