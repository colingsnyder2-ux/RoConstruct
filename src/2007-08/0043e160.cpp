// from server: 100% by Yeetserama
// roc 2007-08 0043e160  unit: RBX::VSoundChannel::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e160
//
// 0043e160  6aff                 push -1
// 0043e162  68d9717400           push 0x7471d9
// 0043e167  64a100000000         mov eax, dword ptr fs:[0]
// 0043e16d  50                   push eax
// 0043e16e  83ec0c               sub esp, 0xc
// 0043e171  56                   push esi
// 0043e172  57                   push edi
// 0043e173  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e178  33c4                 xor eax, esp
// 0043e17a  50                   push eax
// 0043e17b  8d442418             lea eax, [esp + 0x18]
// 0043e17f  64a300000000         mov dword ptr fs:[0], eax
// 0043e185  8d442410             lea eax, [esp + 0x10]
// 0043e189  50                   push eax
// 0043e18a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043e192  e839ffffff           call 0x43e0d0
// 0043e197  8b08                 mov ecx, dword ptr [eax]
// 0043e199  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0043e19d  890f                 mov dword ptr [edi], ecx
// 0043e19f  8b4004               mov eax, dword ptr [eax + 4]
// 0043e1a2  83c404               add esp, 4
// 0043e1a5  85c0                 test eax, eax
// 0043e1a7  894704               mov dword ptr [edi + 4], eax
// 0043e1aa  740c                 je 0x43e1b8
// 0043e1ac  83c004               add eax, 4
// 0043e1af  ba01000000           mov edx, 1
// 0043e1b4  f00fc110             lock xadd dword ptr [eax], edx
// 0043e1b8  8b742414             mov esi, dword ptr [esp + 0x14]
// 0043e1bc  85f6                 test esi, esi
// 0043e1be  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043e1c6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0043e1ce  742a                 je 0x43e1fa
// 0043e1d0  8d4604               lea eax, [esi + 4]
// 0043e1d3  83c9ff               or ecx, 0xffffffff
// 0043e1d6  f00fc108             lock xadd dword ptr [eax], ecx
// 0043e1da  751e                 jne 0x43e1fa
// 0043e1dc  8b16                 mov edx, dword ptr [esi]
// 0043e1de  8b4204               mov eax, dword ptr [edx + 4]
// 0043e1e1  8bce                 mov ecx, esi
// 0043e1e3  ffd0                 call eax
// 0043e1e5  8d4e08               lea ecx, [esi + 8]
// 0043e1e8  83caff               or edx, 0xffffffff
// 0043e1eb  f00fc111             lock xadd dword ptr [ecx], edx
// 0043e1ef  7509                 jne 0x43e1fa
// 0043e1f1  8b06                 mov eax, dword ptr [esi]
// 0043e1f3  8b5008               mov edx, dword ptr [eax + 8]
// 0043e1f6  8bce                 mov ecx, esi
// 0043e1f8  ffd2                 call edx
// 0043e1fa  8bc7                 mov eax, edi
// 0043e1fc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043e200  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e207  59                   pop ecx
// 0043e208  5f                   pop edi
// 0043e209  5e                   pop esi
// 0043e20a  83c418               add esp, 0x18
// 0043e20d  c20400               ret 4
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
