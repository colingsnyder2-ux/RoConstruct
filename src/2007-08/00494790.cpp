// from server: 100% by Yeetserama
// roc 2007-08 00494790  unit: RBX::Network::VServer::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00494790
//
// 00494790  6aff                 push -1
// 00494792  68d9717400           push 0x7471d9
// 00494797  64a100000000         mov eax, dword ptr fs:[0]
// 0049479d  50                   push eax
// 0049479e  83ec0c               sub esp, 0xc
// 004947a1  56                   push esi
// 004947a2  57                   push edi
// 004947a3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004947a8  33c4                 xor eax, esp
// 004947aa  50                   push eax
// 004947ab  8d442418             lea eax, [esp + 0x18]
// 004947af  64a300000000         mov dword ptr fs:[0], eax
// 004947b5  8d442410             lea eax, [esp + 0x10]
// 004947b9  50                   push eax
// 004947ba  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004947c2  e839ffffff           call 0x494700
// 004947c7  8b08                 mov ecx, dword ptr [eax]
// 004947c9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004947cd  890f                 mov dword ptr [edi], ecx
// 004947cf  8b4004               mov eax, dword ptr [eax + 4]
// 004947d2  83c404               add esp, 4
// 004947d5  85c0                 test eax, eax
// 004947d7  894704               mov dword ptr [edi + 4], eax
// 004947da  740c                 je 0x4947e8
// 004947dc  83c004               add eax, 4
// 004947df  ba01000000           mov edx, 1
// 004947e4  f00fc110             lock xadd dword ptr [eax], edx
// 004947e8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004947ec  85f6                 test esi, esi
// 004947ee  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004947f6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004947fe  742a                 je 0x49482a
// 00494800  8d4604               lea eax, [esi + 4]
// 00494803  83c9ff               or ecx, 0xffffffff
// 00494806  f00fc108             lock xadd dword ptr [eax], ecx
// 0049480a  751e                 jne 0x49482a
// 0049480c  8b16                 mov edx, dword ptr [esi]
// 0049480e  8b4204               mov eax, dword ptr [edx + 4]
// 00494811  8bce                 mov ecx, esi
// 00494813  ffd0                 call eax
// 00494815  8d4e08               lea ecx, [esi + 8]
// 00494818  83caff               or edx, 0xffffffff
// 0049481b  f00fc111             lock xadd dword ptr [ecx], edx
// 0049481f  7509                 jne 0x49482a
// 00494821  8b06                 mov eax, dword ptr [esi]
// 00494823  8b5008               mov edx, dword ptr [eax + 8]
// 00494826  8bce                 mov ecx, esi
// 00494828  ffd2                 call edx
// 0049482a  8bc7                 mov eax, edi
// 0049482c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00494830  64890d00000000       mov dword ptr fs:[0], ecx
// 00494837  59                   pop ecx
// 00494838  5f                   pop edi
// 00494839  5e                   pop esi
// 0049483a  83c418               add esp, 0x18
// 0049483d  c20400               ret 4
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
