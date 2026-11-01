// from server: 100% by Yeetserama
// roc 2007-08 004af600  unit: RBX::VRotateV::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004af600
//
// 004af600  6aff                 push -1
// 004af602  68d9717400           push 0x7471d9
// 004af607  64a100000000         mov eax, dword ptr fs:[0]
// 004af60d  50                   push eax
// 004af60e  83ec0c               sub esp, 0xc
// 004af611  56                   push esi
// 004af612  57                   push edi
// 004af613  a188518b00           mov eax, dword ptr [0x8b5188]
// 004af618  33c4                 xor eax, esp
// 004af61a  50                   push eax
// 004af61b  8d442418             lea eax, [esp + 0x18]
// 004af61f  64a300000000         mov dword ptr fs:[0], eax
// 004af625  8d442410             lea eax, [esp + 0x10]
// 004af629  50                   push eax
// 004af62a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004af632  e839ffffff           call 0x4af570
// 004af637  8b08                 mov ecx, dword ptr [eax]
// 004af639  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004af63d  890f                 mov dword ptr [edi], ecx
// 004af63f  8b4004               mov eax, dword ptr [eax + 4]
// 004af642  83c404               add esp, 4
// 004af645  85c0                 test eax, eax
// 004af647  894704               mov dword ptr [edi + 4], eax
// 004af64a  740c                 je 0x4af658
// 004af64c  83c004               add eax, 4
// 004af64f  ba01000000           mov edx, 1
// 004af654  f00fc110             lock xadd dword ptr [eax], edx
// 004af658  8b742414             mov esi, dword ptr [esp + 0x14]
// 004af65c  85f6                 test esi, esi
// 004af65e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004af666  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004af66e  742a                 je 0x4af69a
// 004af670  8d4604               lea eax, [esi + 4]
// 004af673  83c9ff               or ecx, 0xffffffff
// 004af676  f00fc108             lock xadd dword ptr [eax], ecx
// 004af67a  751e                 jne 0x4af69a
// 004af67c  8b16                 mov edx, dword ptr [esi]
// 004af67e  8b4204               mov eax, dword ptr [edx + 4]
// 004af681  8bce                 mov ecx, esi
// 004af683  ffd0                 call eax
// 004af685  8d4e08               lea ecx, [esi + 8]
// 004af688  83caff               or edx, 0xffffffff
// 004af68b  f00fc111             lock xadd dword ptr [ecx], edx
// 004af68f  7509                 jne 0x4af69a
// 004af691  8b06                 mov eax, dword ptr [esi]
// 004af693  8b5008               mov edx, dword ptr [eax + 8]
// 004af696  8bce                 mov ecx, esi
// 004af698  ffd2                 call edx
// 004af69a  8bc7                 mov eax, edi
// 004af69c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004af6a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004af6a7  59                   pop ecx
// 004af6a8  5f                   pop edi
// 004af6a9  5e                   pop esi
// 004af6aa  83c418               add esp, 0x18
// 004af6ad  c20400               ret 4
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
