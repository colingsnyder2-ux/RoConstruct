// from server: 100% by Yeetserama
// roc 2007-08 0040e3c0  unit: RBX::Network::VPlayer::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040e3c0
//
// 0040e3c0  6aff                 push -1
// 0040e3c2  68d9717400           push 0x7471d9
// 0040e3c7  64a100000000         mov eax, dword ptr fs:[0]
// 0040e3cd  50                   push eax
// 0040e3ce  83ec0c               sub esp, 0xc
// 0040e3d1  56                   push esi
// 0040e3d2  57                   push edi
// 0040e3d3  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040e3d8  33c4                 xor eax, esp
// 0040e3da  50                   push eax
// 0040e3db  8d442418             lea eax, [esp + 0x18]
// 0040e3df  64a300000000         mov dword ptr fs:[0], eax
// 0040e3e5  8d442410             lea eax, [esp + 0x10]
// 0040e3e9  50                   push eax
// 0040e3ea  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040e3f2  e839ffffff           call 0x40e330
// 0040e3f7  8b08                 mov ecx, dword ptr [eax]
// 0040e3f9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0040e3fd  890f                 mov dword ptr [edi], ecx
// 0040e3ff  8b4004               mov eax, dword ptr [eax + 4]
// 0040e402  83c404               add esp, 4
// 0040e405  85c0                 test eax, eax
// 0040e407  894704               mov dword ptr [edi + 4], eax
// 0040e40a  740c                 je 0x40e418
// 0040e40c  83c004               add eax, 4
// 0040e40f  ba01000000           mov edx, 1
// 0040e414  f00fc110             lock xadd dword ptr [eax], edx
// 0040e418  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040e41c  85f6                 test esi, esi
// 0040e41e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0040e426  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0040e42e  742a                 je 0x40e45a
// 0040e430  8d4604               lea eax, [esi + 4]
// 0040e433  83c9ff               or ecx, 0xffffffff
// 0040e436  f00fc108             lock xadd dword ptr [eax], ecx
// 0040e43a  751e                 jne 0x40e45a
// 0040e43c  8b16                 mov edx, dword ptr [esi]
// 0040e43e  8b4204               mov eax, dword ptr [edx + 4]
// 0040e441  8bce                 mov ecx, esi
// 0040e443  ffd0                 call eax
// 0040e445  8d4e08               lea ecx, [esi + 8]
// 0040e448  83caff               or edx, 0xffffffff
// 0040e44b  f00fc111             lock xadd dword ptr [ecx], edx
// 0040e44f  7509                 jne 0x40e45a
// 0040e451  8b06                 mov eax, dword ptr [esi]
// 0040e453  8b5008               mov edx, dword ptr [eax + 8]
// 0040e456  8bce                 mov ecx, esi
// 0040e458  ffd2                 call edx
// 0040e45a  8bc7                 mov eax, edi
// 0040e45c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0040e460  64890d00000000       mov dword ptr fs:[0], ecx
// 0040e467  59                   pop ecx
// 0040e468  5f                   pop edi
// 0040e469  5e                   pop esi
// 0040e46a  83c418               add esp, 0x18
// 0040e46d  c20400               ret 4
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
