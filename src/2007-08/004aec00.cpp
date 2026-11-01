// from server: 100% by Yeetserama
// roc 2007-08 004aec00  unit: RBX::VWeld::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aec00
//
// 004aec00  6aff                 push -1
// 004aec02  68d9717400           push 0x7471d9
// 004aec07  64a100000000         mov eax, dword ptr fs:[0]
// 004aec0d  50                   push eax
// 004aec0e  83ec0c               sub esp, 0xc
// 004aec11  56                   push esi
// 004aec12  57                   push edi
// 004aec13  a188518b00           mov eax, dword ptr [0x8b5188]
// 004aec18  33c4                 xor eax, esp
// 004aec1a  50                   push eax
// 004aec1b  8d442418             lea eax, [esp + 0x18]
// 004aec1f  64a300000000         mov dword ptr fs:[0], eax
// 004aec25  8d442410             lea eax, [esp + 0x10]
// 004aec29  50                   push eax
// 004aec2a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004aec32  e839ffffff           call 0x4aeb70
// 004aec37  8b08                 mov ecx, dword ptr [eax]
// 004aec39  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004aec3d  890f                 mov dword ptr [edi], ecx
// 004aec3f  8b4004               mov eax, dword ptr [eax + 4]
// 004aec42  83c404               add esp, 4
// 004aec45  85c0                 test eax, eax
// 004aec47  894704               mov dword ptr [edi + 4], eax
// 004aec4a  740c                 je 0x4aec58
// 004aec4c  83c004               add eax, 4
// 004aec4f  ba01000000           mov edx, 1
// 004aec54  f00fc110             lock xadd dword ptr [eax], edx
// 004aec58  8b742414             mov esi, dword ptr [esp + 0x14]
// 004aec5c  85f6                 test esi, esi
// 004aec5e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004aec66  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004aec6e  742a                 je 0x4aec9a
// 004aec70  8d4604               lea eax, [esi + 4]
// 004aec73  83c9ff               or ecx, 0xffffffff
// 004aec76  f00fc108             lock xadd dword ptr [eax], ecx
// 004aec7a  751e                 jne 0x4aec9a
// 004aec7c  8b16                 mov edx, dword ptr [esi]
// 004aec7e  8b4204               mov eax, dword ptr [edx + 4]
// 004aec81  8bce                 mov ecx, esi
// 004aec83  ffd0                 call eax
// 004aec85  8d4e08               lea ecx, [esi + 8]
// 004aec88  83caff               or edx, 0xffffffff
// 004aec8b  f00fc111             lock xadd dword ptr [ecx], edx
// 004aec8f  7509                 jne 0x4aec9a
// 004aec91  8b06                 mov eax, dword ptr [esi]
// 004aec93  8b5008               mov edx, dword ptr [eax + 8]
// 004aec96  8bce                 mov ecx, esi
// 004aec98  ffd2                 call edx
// 004aec9a  8bc7                 mov eax, edi
// 004aec9c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004aeca0  64890d00000000       mov dword ptr fs:[0], ecx
// 004aeca7  59                   pop ecx
// 004aeca8  5f                   pop edi
// 004aeca9  5e                   pop esi
// 004aecaa  83c418               add esp, 0x18
// 004aecad  c20400               ret 4
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
