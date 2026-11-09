// from server: 100% by Yeetserama
// roc 2007-08 0041b070  unit: VDHTMLWindowService::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041b070
//
// 0041b070  6aff                 push -1
// 0041b072  68d9717400           push 0x7471d9
// 0041b077  64a100000000         mov eax, dword ptr fs:[0]
// 0041b07d  50                   push eax
// 0041b07e  83ec0c               sub esp, 0xc
// 0041b081  56                   push esi
// 0041b082  57                   push edi
// 0041b083  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041b088  33c4                 xor eax, esp
// 0041b08a  50                   push eax
// 0041b08b  8d442418             lea eax, [esp + 0x18]
// 0041b08f  64a300000000         mov dword ptr fs:[0], eax
// 0041b095  8d442410             lea eax, [esp + 0x10]
// 0041b099  50                   push eax
// 0041b09a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041b0a2  e869fcffff           call 0x41ad10
// 0041b0a7  8b08                 mov ecx, dword ptr [eax]
// 0041b0a9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0041b0ad  890f                 mov dword ptr [edi], ecx
// 0041b0af  8b4004               mov eax, dword ptr [eax + 4]
// 0041b0b2  83c404               add esp, 4
// 0041b0b5  85c0                 test eax, eax
// 0041b0b7  894704               mov dword ptr [edi + 4], eax
// 0041b0ba  740c                 je 0x41b0c8
// 0041b0bc  83c004               add eax, 4
// 0041b0bf  ba01000000           mov edx, 1
// 0041b0c4  f00fc110             lock xadd dword ptr [eax], edx
// 0041b0c8  8b742414             mov esi, dword ptr [esp + 0x14]
// 0041b0cc  85f6                 test esi, esi
// 0041b0ce  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0041b0d6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0041b0de  742a                 je 0x41b10a
// 0041b0e0  8d4604               lea eax, [esi + 4]
// 0041b0e3  83c9ff               or ecx, 0xffffffff
// 0041b0e6  f00fc108             lock xadd dword ptr [eax], ecx
// 0041b0ea  751e                 jne 0x41b10a
// 0041b0ec  8b16                 mov edx, dword ptr [esi]
// 0041b0ee  8b4204               mov eax, dword ptr [edx + 4]
// 0041b0f1  8bce                 mov ecx, esi
// 0041b0f3  ffd0                 call eax
// 0041b0f5  8d4e08               lea ecx, [esi + 8]
// 0041b0f8  83caff               or edx, 0xffffffff
// 0041b0fb  f00fc111             lock xadd dword ptr [ecx], edx
// 0041b0ff  7509                 jne 0x41b10a
// 0041b101  8b06                 mov eax, dword ptr [esi]
// 0041b103  8b5008               mov edx, dword ptr [eax + 8]
// 0041b106  8bce                 mov ecx, esi
// 0041b108  ffd2                 call edx
// 0041b10a  8bc7                 mov eax, edi
// 0041b10c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041b110  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b117  59                   pop ecx
// 0041b118  5f                   pop edi
// 0041b119  5e                   pop esi
// 0041b11a  83c418               add esp, 0x18
// 0041b11d  c20400               ret 4
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
