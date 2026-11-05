// from server: 100% by Yeetserama
// roc 2007-08 004ae700  unit: RBX::VLighting::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ae700
//
// 004ae700  6aff                 push -1
// 004ae702  68d9717400           push 0x7471d9
// 004ae707  64a100000000         mov eax, dword ptr fs:[0]
// 004ae70d  50                   push eax
// 004ae70e  83ec0c               sub esp, 0xc
// 004ae711  56                   push esi
// 004ae712  57                   push edi
// 004ae713  a188518b00           mov eax, dword ptr [0x8b5188]
// 004ae718  33c4                 xor eax, esp
// 004ae71a  50                   push eax
// 004ae71b  8d442418             lea eax, [esp + 0x18]
// 004ae71f  64a300000000         mov dword ptr fs:[0], eax
// 004ae725  8d442410             lea eax, [esp + 0x10]
// 004ae729  50                   push eax
// 004ae72a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004ae732  e899a7ffff           call 0x4a8ed0
// 004ae737  8b08                 mov ecx, dword ptr [eax]
// 004ae739  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004ae73d  890f                 mov dword ptr [edi], ecx
// 004ae73f  8b4004               mov eax, dword ptr [eax + 4]
// 004ae742  83c404               add esp, 4
// 004ae745  85c0                 test eax, eax
// 004ae747  894704               mov dword ptr [edi + 4], eax
// 004ae74a  740c                 je 0x4ae758
// 004ae74c  83c004               add eax, 4
// 004ae74f  ba01000000           mov edx, 1
// 004ae754  f00fc110             lock xadd dword ptr [eax], edx
// 004ae758  8b742414             mov esi, dword ptr [esp + 0x14]
// 004ae75c  85f6                 test esi, esi
// 004ae75e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004ae766  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004ae76e  742a                 je 0x4ae79a
// 004ae770  8d4604               lea eax, [esi + 4]
// 004ae773  83c9ff               or ecx, 0xffffffff
// 004ae776  f00fc108             lock xadd dword ptr [eax], ecx
// 004ae77a  751e                 jne 0x4ae79a
// 004ae77c  8b16                 mov edx, dword ptr [esi]
// 004ae77e  8b4204               mov eax, dword ptr [edx + 4]
// 004ae781  8bce                 mov ecx, esi
// 004ae783  ffd0                 call eax
// 004ae785  8d4e08               lea ecx, [esi + 8]
// 004ae788  83caff               or edx, 0xffffffff
// 004ae78b  f00fc111             lock xadd dword ptr [ecx], edx
// 004ae78f  7509                 jne 0x4ae79a
// 004ae791  8b06                 mov eax, dword ptr [esi]
// 004ae793  8b5008               mov edx, dword ptr [eax + 8]
// 004ae796  8bce                 mov ecx, esi
// 004ae798  ffd2                 call edx
// 004ae79a  8bc7                 mov eax, edi
// 004ae79c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004ae7a0  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae7a7  59                   pop ecx
// 004ae7a8  5f                   pop edi
// 004ae7a9  5e                   pop esi
// 004ae7aa  83c418               add esp, 0x18
// 004ae7ad  c20400               ret 4
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
