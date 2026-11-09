// from server: 100% by Yeetserama
// roc 2007-08 004aee80  unit: RBX::VGlue::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aee80
//
// 004aee80  6aff                 push -1
// 004aee82  68d9717400           push 0x7471d9
// 004aee87  64a100000000         mov eax, dword ptr fs:[0]
// 004aee8d  50                   push eax
// 004aee8e  83ec0c               sub esp, 0xc
// 004aee91  56                   push esi
// 004aee92  57                   push edi
// 004aee93  a188518b00           mov eax, dword ptr [0x8b5188]
// 004aee98  33c4                 xor eax, esp
// 004aee9a  50                   push eax
// 004aee9b  8d442418             lea eax, [esp + 0x18]
// 004aee9f  64a300000000         mov dword ptr fs:[0], eax
// 004aeea5  8d442410             lea eax, [esp + 0x10]
// 004aeea9  50                   push eax
// 004aeeaa  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004aeeb2  e839ffffff           call 0x4aedf0
// 004aeeb7  8b08                 mov ecx, dword ptr [eax]
// 004aeeb9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004aeebd  890f                 mov dword ptr [edi], ecx
// 004aeebf  8b4004               mov eax, dword ptr [eax + 4]
// 004aeec2  83c404               add esp, 4
// 004aeec5  85c0                 test eax, eax
// 004aeec7  894704               mov dword ptr [edi + 4], eax
// 004aeeca  740c                 je 0x4aeed8
// 004aeecc  83c004               add eax, 4
// 004aeecf  ba01000000           mov edx, 1
// 004aeed4  f00fc110             lock xadd dword ptr [eax], edx
// 004aeed8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004aeedc  85f6                 test esi, esi
// 004aeede  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004aeee6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004aeeee  742a                 je 0x4aef1a
// 004aeef0  8d4604               lea eax, [esi + 4]
// 004aeef3  83c9ff               or ecx, 0xffffffff
// 004aeef6  f00fc108             lock xadd dword ptr [eax], ecx
// 004aeefa  751e                 jne 0x4aef1a
// 004aeefc  8b16                 mov edx, dword ptr [esi]
// 004aeefe  8b4204               mov eax, dword ptr [edx + 4]
// 004aef01  8bce                 mov ecx, esi
// 004aef03  ffd0                 call eax
// 004aef05  8d4e08               lea ecx, [esi + 8]
// 004aef08  83caff               or edx, 0xffffffff
// 004aef0b  f00fc111             lock xadd dword ptr [ecx], edx
// 004aef0f  7509                 jne 0x4aef1a
// 004aef11  8b06                 mov eax, dword ptr [esi]
// 004aef13  8b5008               mov edx, dword ptr [eax + 8]
// 004aef16  8bce                 mov ecx, esi
// 004aef18  ffd2                 call edx
// 004aef1a  8bc7                 mov eax, edi
// 004aef1c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004aef20  64890d00000000       mov dword ptr fs:[0], ecx
// 004aef27  59                   pop ecx
// 004aef28  5f                   pop edi
// 004aef29  5e                   pop esi
// 004aef2a  83c418               add esp, 0x18
// 004aef2d  c20400               ret 4
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
