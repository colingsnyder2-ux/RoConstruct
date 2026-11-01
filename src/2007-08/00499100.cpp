// from server: 100% by Yeetserama
// roc 2007-08 00499100  unit: RBX::VNetworkSettings::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00499100
//
// 00499100  6aff                 push -1
// 00499102  68d9717400           push 0x7471d9
// 00499107  64a100000000         mov eax, dword ptr fs:[0]
// 0049910d  50                   push eax
// 0049910e  83ec0c               sub esp, 0xc
// 00499111  56                   push esi
// 00499112  57                   push edi
// 00499113  a188518b00           mov eax, dword ptr [0x8b5188]
// 00499118  33c4                 xor eax, esp
// 0049911a  50                   push eax
// 0049911b  8d442418             lea eax, [esp + 0x18]
// 0049911f  64a300000000         mov dword ptr fs:[0], eax
// 00499125  8d442410             lea eax, [esp + 0x10]
// 00499129  50                   push eax
// 0049912a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00499132  e899fdffff           call 0x498ed0
// 00499137  8b08                 mov ecx, dword ptr [eax]
// 00499139  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0049913d  890f                 mov dword ptr [edi], ecx
// 0049913f  8b4004               mov eax, dword ptr [eax + 4]
// 00499142  83c404               add esp, 4
// 00499145  85c0                 test eax, eax
// 00499147  894704               mov dword ptr [edi + 4], eax
// 0049914a  740c                 je 0x499158
// 0049914c  83c004               add eax, 4
// 0049914f  ba01000000           mov edx, 1
// 00499154  f00fc110             lock xadd dword ptr [eax], edx
// 00499158  8b742414             mov esi, dword ptr [esp + 0x14]
// 0049915c  85f6                 test esi, esi
// 0049915e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 00499166  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0049916e  742a                 je 0x49919a
// 00499170  8d4604               lea eax, [esi + 4]
// 00499173  83c9ff               or ecx, 0xffffffff
// 00499176  f00fc108             lock xadd dword ptr [eax], ecx
// 0049917a  751e                 jne 0x49919a
// 0049917c  8b16                 mov edx, dword ptr [esi]
// 0049917e  8b4204               mov eax, dword ptr [edx + 4]
// 00499181  8bce                 mov ecx, esi
// 00499183  ffd0                 call eax
// 00499185  8d4e08               lea ecx, [esi + 8]
// 00499188  83caff               or edx, 0xffffffff
// 0049918b  f00fc111             lock xadd dword ptr [ecx], edx
// 0049918f  7509                 jne 0x49919a
// 00499191  8b06                 mov eax, dword ptr [esi]
// 00499193  8b5008               mov edx, dword ptr [eax + 8]
// 00499196  8bce                 mov ecx, esi
// 00499198  ffd2                 call edx
// 0049919a  8bc7                 mov eax, edi
// 0049919c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004991a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004991a7  59                   pop ecx
// 004991a8  5f                   pop edi
// 004991a9  5e                   pop esi
// 004991aa  83c418               add esp, 0x18
// 004991ad  c20400               ret 4
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
