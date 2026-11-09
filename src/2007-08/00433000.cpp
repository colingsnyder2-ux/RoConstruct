// from server: 100% by Yeetserama
// roc 2007-08 00433000  unit: RBX::VHat::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433000
//
// 00433000  6aff                 push -1
// 00433002  68d9717400           push 0x7471d9
// 00433007  64a100000000         mov eax, dword ptr fs:[0]
// 0043300d  50                   push eax
// 0043300e  83ec0c               sub esp, 0xc
// 00433011  56                   push esi
// 00433012  57                   push edi
// 00433013  a188518b00           mov eax, dword ptr [0x8b5188]
// 00433018  33c4                 xor eax, esp
// 0043301a  50                   push eax
// 0043301b  8d442418             lea eax, [esp + 0x18]
// 0043301f  64a300000000         mov dword ptr fs:[0], eax
// 00433025  8d442410             lea eax, [esp + 0x10]
// 00433029  50                   push eax
// 0043302a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00433032  e839ffffff           call 0x432f70
// 00433037  8b08                 mov ecx, dword ptr [eax]
// 00433039  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043303d  890f                 mov dword ptr [edi], ecx
// 0043303f  8b4004               mov eax, dword ptr [eax + 4]
// 00433042  83c404               add esp, 4
// 00433045  85c0                 test eax, eax
// 00433047  894704               mov dword ptr [edi + 4], eax
// 0043304a  740c                 je 0x433058
// 0043304c  83c004               add eax, 4
// 0043304f  ba01000000           mov edx, 1
// 00433054  f00fc110             lock xadd dword ptr [eax], edx
// 00433058  8b742414             mov esi, dword ptr [esp + 0x14]
// 0043305c  85f6                 test esi, esi
// 0043305e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00433066  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0043306e  742a                 je 0x43309a
// 00433070  8d4604               lea eax, [esi + 4]
// 00433073  83c9ff               or ecx, 0xffffffff
// 00433076  f00fc108             lock xadd dword ptr [eax], ecx
// 0043307a  751e                 jne 0x43309a
// 0043307c  8b16                 mov edx, dword ptr [esi]
// 0043307e  8b4204               mov eax, dword ptr [edx + 4]
// 00433081  8bce                 mov ecx, esi
// 00433083  ffd0                 call eax
// 00433085  8d4e08               lea ecx, [esi + 8]
// 00433088  83caff               or edx, 0xffffffff
// 0043308b  f00fc111             lock xadd dword ptr [ecx], edx
// 0043308f  7509                 jne 0x43309a
// 00433091  8b06                 mov eax, dword ptr [esi]
// 00433093  8b5008               mov edx, dword ptr [eax + 8]
// 00433096  8bce                 mov ecx, esi
// 00433098  ffd2                 call edx
// 0043309a  8bc7                 mov eax, edi
// 0043309c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004330a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004330a7  59                   pop ecx
// 004330a8  5f                   pop edi
// 004330a9  5e                   pop esi
// 004330aa  83c418               add esp, 0x18
// 004330ad  c20400               ret 4
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
