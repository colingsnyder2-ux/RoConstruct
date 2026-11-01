// from server: 100% by Yeetserama
// roc 2007-08 0048ae00  unit: RBX::VStarterPackService::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0048ae00
//
// 0048ae00  6aff                 push -1
// 0048ae02  68d9717400           push 0x7471d9
// 0048ae07  64a100000000         mov eax, dword ptr fs:[0]
// 0048ae0d  50                   push eax
// 0048ae0e  83ec0c               sub esp, 0xc
// 0048ae11  56                   push esi
// 0048ae12  57                   push edi
// 0048ae13  a188518b00           mov eax, dword ptr [0x8b5188]
// 0048ae18  33c4                 xor eax, esp
// 0048ae1a  50                   push eax
// 0048ae1b  8d442418             lea eax, [esp + 0x18]
// 0048ae1f  64a300000000         mov dword ptr fs:[0], eax
// 0048ae25  8d442410             lea eax, [esp + 0x10]
// 0048ae29  50                   push eax
// 0048ae2a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0048ae32  e839ffffff           call 0x48ad70
// 0048ae37  8b08                 mov ecx, dword ptr [eax]
// 0048ae39  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0048ae3d  890f                 mov dword ptr [edi], ecx
// 0048ae3f  8b4004               mov eax, dword ptr [eax + 4]
// 0048ae42  83c404               add esp, 4
// 0048ae45  85c0                 test eax, eax
// 0048ae47  894704               mov dword ptr [edi + 4], eax
// 0048ae4a  740c                 je 0x48ae58
// 0048ae4c  83c004               add eax, 4
// 0048ae4f  ba01000000           mov edx, 1
// 0048ae54  f00fc110             lock xadd dword ptr [eax], edx
// 0048ae58  8b742414             mov esi, dword ptr [esp + 0x14]
// 0048ae5c  85f6                 test esi, esi
// 0048ae5e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0048ae66  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0048ae6e  742a                 je 0x48ae9a
// 0048ae70  8d4604               lea eax, [esi + 4]
// 0048ae73  83c9ff               or ecx, 0xffffffff
// 0048ae76  f00fc108             lock xadd dword ptr [eax], ecx
// 0048ae7a  751e                 jne 0x48ae9a
// 0048ae7c  8b16                 mov edx, dword ptr [esi]
// 0048ae7e  8b4204               mov eax, dword ptr [edx + 4]
// 0048ae81  8bce                 mov ecx, esi
// 0048ae83  ffd0                 call eax
// 0048ae85  8d4e08               lea ecx, [esi + 8]
// 0048ae88  83caff               or edx, 0xffffffff
// 0048ae8b  f00fc111             lock xadd dword ptr [ecx], edx
// 0048ae8f  7509                 jne 0x48ae9a
// 0048ae91  8b06                 mov eax, dword ptr [esi]
// 0048ae93  8b5008               mov edx, dword ptr [eax + 8]
// 0048ae96  8bce                 mov ecx, esi
// 0048ae98  ffd2                 call edx
// 0048ae9a  8bc7                 mov eax, edi
// 0048ae9c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0048aea0  64890d00000000       mov dword ptr fs:[0], ecx
// 0048aea7  59                   pop ecx
// 0048aea8  5f                   pop edi
// 0048aea9  5e                   pop esi
// 0048aeaa  83c418               add esp, 0x18
// 0048aead  c20400               ret 4
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
