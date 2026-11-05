// from server: 100% by Yeetserama
// roc 2007-08 00459ec0  unit: RBX::VControllerService::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00459ec0
//
// 00459ec0  6aff                 push -1
// 00459ec2  68d9717400           push 0x7471d9
// 00459ec7  64a100000000         mov eax, dword ptr fs:[0]
// 00459ecd  50                   push eax
// 00459ece  83ec0c               sub esp, 0xc
// 00459ed1  56                   push esi
// 00459ed2  57                   push edi
// 00459ed3  a188518b00           mov eax, dword ptr [0x8b5188]
// 00459ed8  33c4                 xor eax, esp
// 00459eda  50                   push eax
// 00459edb  8d442418             lea eax, [esp + 0x18]
// 00459edf  64a300000000         mov dword ptr fs:[0], eax
// 00459ee5  8d442410             lea eax, [esp + 0x10]
// 00459ee9  50                   push eax
// 00459eea  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00459ef2  e879f6ffff           call 0x459570
// 00459ef7  8b08                 mov ecx, dword ptr [eax]
// 00459ef9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00459efd  890f                 mov dword ptr [edi], ecx
// 00459eff  8b4004               mov eax, dword ptr [eax + 4]
// 00459f02  83c404               add esp, 4
// 00459f05  85c0                 test eax, eax
// 00459f07  894704               mov dword ptr [edi + 4], eax
// 00459f0a  740c                 je 0x459f18
// 00459f0c  83c004               add eax, 4
// 00459f0f  ba01000000           mov edx, 1
// 00459f14  f00fc110             lock xadd dword ptr [eax], edx
// 00459f18  8b742414             mov esi, dword ptr [esp + 0x14]
// 00459f1c  85f6                 test esi, esi
// 00459f1e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00459f26  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00459f2e  742a                 je 0x459f5a
// 00459f30  8d4604               lea eax, [esi + 4]
// 00459f33  83c9ff               or ecx, 0xffffffff
// 00459f36  f00fc108             lock xadd dword ptr [eax], ecx
// 00459f3a  751e                 jne 0x459f5a
// 00459f3c  8b16                 mov edx, dword ptr [esi]
// 00459f3e  8b4204               mov eax, dword ptr [edx + 4]
// 00459f41  8bce                 mov ecx, esi
// 00459f43  ffd0                 call eax
// 00459f45  8d4e08               lea ecx, [esi + 8]
// 00459f48  83caff               or edx, 0xffffffff
// 00459f4b  f00fc111             lock xadd dword ptr [ecx], edx
// 00459f4f  7509                 jne 0x459f5a
// 00459f51  8b06                 mov eax, dword ptr [esi]
// 00459f53  8b5008               mov edx, dword ptr [eax + 8]
// 00459f56  8bce                 mov ecx, esi
// 00459f58  ffd2                 call edx
// 00459f5a  8bc7                 mov eax, edi
// 00459f5c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00459f60  64890d00000000       mov dword ptr fs:[0], ecx
// 00459f67  59                   pop ecx
// 00459f68  5f                   pop edi
// 00459f69  5e                   pop esi
// 00459f6a  83c418               add esp, 0x18
// 00459f6d  c20400               ret 4
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
