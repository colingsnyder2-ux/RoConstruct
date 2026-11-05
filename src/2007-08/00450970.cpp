// from server: 100% by Yeetserama
// roc 2007-08 00450970  unit: RBX::VVisit::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00450970
//
// 00450970  6aff                 push -1
// 00450972  68d9717400           push 0x7471d9
// 00450977  64a100000000         mov eax, dword ptr fs:[0]
// 0045097d  50                   push eax
// 0045097e  83ec0c               sub esp, 0xc
// 00450981  56                   push esi
// 00450982  57                   push edi
// 00450983  a188518b00           mov eax, dword ptr [0x8b5188]
// 00450988  33c4                 xor eax, esp
// 0045098a  50                   push eax
// 0045098b  8d442418             lea eax, [esp + 0x18]
// 0045098f  64a300000000         mov dword ptr fs:[0], eax
// 00450995  8d442410             lea eax, [esp + 0x10]
// 00450999  50                   push eax
// 0045099a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004509a2  e839ffffff           call 0x4508e0
// 004509a7  8b08                 mov ecx, dword ptr [eax]
// 004509a9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004509ad  890f                 mov dword ptr [edi], ecx
// 004509af  8b4004               mov eax, dword ptr [eax + 4]
// 004509b2  83c404               add esp, 4
// 004509b5  85c0                 test eax, eax
// 004509b7  894704               mov dword ptr [edi + 4], eax
// 004509ba  740c                 je 0x4509c8
// 004509bc  83c004               add eax, 4
// 004509bf  ba01000000           mov edx, 1
// 004509c4  f00fc110             lock xadd dword ptr [eax], edx
// 004509c8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004509cc  85f6                 test esi, esi
// 004509ce  c744242000000000     mov dword ptr [esp + 0x20], 0
// 004509d6  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 004509de  742a                 je 0x450a0a
// 004509e0  8d4604               lea eax, [esi + 4]
// 004509e3  83c9ff               or ecx, 0xffffffff
// 004509e6  f00fc108             lock xadd dword ptr [eax], ecx
// 004509ea  751e                 jne 0x450a0a
// 004509ec  8b16                 mov edx, dword ptr [esi]
// 004509ee  8b4204               mov eax, dword ptr [edx + 4]
// 004509f1  8bce                 mov ecx, esi
// 004509f3  ffd0                 call eax
// 004509f5  8d4e08               lea ecx, [esi + 8]
// 004509f8  83caff               or edx, 0xffffffff
// 004509fb  f00fc111             lock xadd dword ptr [ecx], edx
// 004509ff  7509                 jne 0x450a0a
// 00450a01  8b06                 mov eax, dword ptr [esi]
// 00450a03  8b5008               mov edx, dword ptr [eax + 8]
// 00450a06  8bce                 mov ecx, esi
// 00450a08  ffd2                 call edx
// 00450a0a  8bc7                 mov eax, edi
// 00450a0c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00450a10  64890d00000000       mov dword ptr fs:[0], ecx
// 00450a17  59                   pop ecx
// 00450a18  5f                   pop edi
// 00450a19  5e                   pop esi
// 00450a1a  83c418               add esp, 0x18
// 00450a1d  c20400               ret 4
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
