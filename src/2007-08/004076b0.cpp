// from server: 100% by Yeetserama
// roc 2007-08 004076b0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004076b0
//
// 004076b0  6aff                 push -1
// 004076b2  68d9717400           push 0x7471d9
// 004076b7  64a100000000         mov eax, dword ptr fs:[0]
// 004076bd  50                   push eax
// 004076be  83ec0c               sub esp, 0xc
// 004076c1  56                   push esi
// 004076c2  57                   push edi
// 004076c3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004076c8  33c4                 xor eax, esp
// 004076ca  50                   push eax
// 004076cb  8d442418             lea eax, [esp + 0x18]
// 004076cf  64a300000000         mov dword ptr fs:[0], eax
// 004076d5  8d442410             lea eax, [esp + 0x10]
// 004076d9  50                   push eax
// 004076da  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004076e2  e839ffffff           call 0x407620
// 004076e7  8b08                 mov ecx, dword ptr [eax]
// 004076e9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004076ed  890f                 mov dword ptr [edi], ecx
// 004076ef  8b4004               mov eax, dword ptr [eax + 4]
// 004076f2  83c404               add esp, 4
// 004076f5  85c0                 test eax, eax
// 004076f7  894704               mov dword ptr [edi + 4], eax
// 004076fa  740c                 je 0x407708
// 004076fc  83c004               add eax, 4
// 004076ff  ba01000000           mov edx, 1
// 00407704  f00fc110             lock xadd dword ptr [eax], edx
// 00407708  8b742414             mov esi, dword ptr [esp + 0x14]
// 0040770c  85f6                 test esi, esi
// 0040770e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00407716  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0040771e  742a                 je 0x40774a
// 00407720  8d4604               lea eax, [esi + 4]
// 00407723  83c9ff               or ecx, 0xffffffff
// 00407726  f00fc108             lock xadd dword ptr [eax], ecx
// 0040772a  751e                 jne 0x40774a
// 0040772c  8b16                 mov edx, dword ptr [esi]
// 0040772e  8b4204               mov eax, dword ptr [edx + 4]
// 00407731  8bce                 mov ecx, esi
// 00407733  ffd0                 call eax
// 00407735  8d4e08               lea ecx, [esi + 8]
// 00407738  83caff               or edx, 0xffffffff
// 0040773b  f00fc111             lock xadd dword ptr [ecx], edx
// 0040773f  7509                 jne 0x40774a
// 00407741  8b06                 mov eax, dword ptr [esi]
// 00407743  8b5008               mov edx, dword ptr [eax + 8]
// 00407746  8bce                 mov ecx, esi
// 00407748  ffd2                 call edx
// 0040774a  8bc7                 mov eax, edi
// 0040774c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00407750  64890d00000000       mov dword ptr fs:[0], ecx
// 00407757  59                   pop ecx
// 00407758  5f                   pop edi
// 00407759  5e                   pop esi
// 0040775a  83c418               add esp, 0x18
// 0040775d  c20400               ret 4
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
