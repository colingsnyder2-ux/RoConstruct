// from server: 100% by Yeetserama
// roc 2007-08 00432d80  unit: RBX::VAccoutrement::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00432d80
//
// 00432d80  6aff                 push -1
// 00432d82  68d9717400           push 0x7471d9
// 00432d87  64a100000000         mov eax, dword ptr fs:[0]
// 00432d8d  50                   push eax
// 00432d8e  83ec0c               sub esp, 0xc
// 00432d91  56                   push esi
// 00432d92  57                   push edi
// 00432d93  a188518b00           mov eax, dword ptr [0x8b5188]
// 00432d98  33c4                 xor eax, esp
// 00432d9a  50                   push eax
// 00432d9b  8d442418             lea eax, [esp + 0x18]
// 00432d9f  64a300000000         mov dword ptr fs:[0], eax
// 00432da5  8d442410             lea eax, [esp + 0x10]
// 00432da9  50                   push eax
// 00432daa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00432db2  e839ffffff           call 0x432cf0
// 00432db7  8b08                 mov ecx, dword ptr [eax]
// 00432db9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00432dbd  890f                 mov dword ptr [edi], ecx
// 00432dbf  8b4004               mov eax, dword ptr [eax + 4]
// 00432dc2  83c404               add esp, 4
// 00432dc5  85c0                 test eax, eax
// 00432dc7  894704               mov dword ptr [edi + 4], eax
// 00432dca  740c                 je 0x432dd8
// 00432dcc  83c004               add eax, 4
// 00432dcf  ba01000000           mov edx, 1
// 00432dd4  f00fc110             lock xadd dword ptr [eax], edx
// 00432dd8  8b742414             mov esi, dword ptr [esp + 0x14]
// 00432ddc  85f6                 test esi, esi
// 00432dde  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00432de6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 00432dee  742a                 je 0x432e1a
// 00432df0  8d4604               lea eax, [esi + 4]
// 00432df3  83c9ff               or ecx, 0xffffffff
// 00432df6  f00fc108             lock xadd dword ptr [eax], ecx
// 00432dfa  751e                 jne 0x432e1a
// 00432dfc  8b16                 mov edx, dword ptr [esi]
// 00432dfe  8b4204               mov eax, dword ptr [edx + 4]
// 00432e01  8bce                 mov ecx, esi
// 00432e03  ffd0                 call eax
// 00432e05  8d4e08               lea ecx, [esi + 8]
// 00432e08  83caff               or edx, 0xffffffff
// 00432e0b  f00fc111             lock xadd dword ptr [ecx], edx
// 00432e0f  7509                 jne 0x432e1a
// 00432e11  8b06                 mov eax, dword ptr [esi]
// 00432e13  8b5008               mov edx, dword ptr [eax + 8]
// 00432e16  8bce                 mov ecx, esi
// 00432e18  ffd2                 call edx
// 00432e1a  8bc7                 mov eax, edi
// 00432e1c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00432e20  64890d00000000       mov dword ptr fs:[0], ecx
// 00432e27  59                   pop ecx
// 00432e28  5f                   pop edi
// 00432e29  5e                   pop esi
// 00432e2a  83c418               add esp, 0x18
// 00432e2d  c20400               ret 4
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
