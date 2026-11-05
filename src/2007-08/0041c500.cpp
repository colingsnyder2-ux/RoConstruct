// from server: 100% by Yeetserama
// roc 2007-08 0041c500  unit: RBX::VDecal::?$FactoryProduct::Creator  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041c500
//
// 0041c500  6aff                 push -1
// 0041c502  68d9717400           push 0x7471d9
// 0041c507  64a100000000         mov eax, dword ptr fs:[0]
// 0041c50d  50                   push eax
// 0041c50e  83ec0c               sub esp, 0xc
// 0041c511  56                   push esi
// 0041c512  57                   push edi
// 0041c513  a188518b00           mov eax, dword ptr [0x8b5188]
// 0041c518  33c4                 xor eax, esp
// 0041c51a  50                   push eax
// 0041c51b  8d442418             lea eax, [esp + 0x18]
// 0041c51f  64a300000000         mov dword ptr fs:[0], eax
// 0041c525  8d442410             lea eax, [esp + 0x10]
// 0041c529  50                   push eax
// 0041c52a  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041c532  e889feffff           call 0x41c3c0
// 0041c537  8b08                 mov ecx, dword ptr [eax]
// 0041c539  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0041c53d  890f                 mov dword ptr [edi], ecx
// 0041c53f  8b4004               mov eax, dword ptr [eax + 4]
// 0041c542  83c404               add esp, 4
// 0041c545  85c0                 test eax, eax
// 0041c547  894704               mov dword ptr [edi + 4], eax
// 0041c54a  740c                 je 0x41c558
// 0041c54c  83c004               add eax, 4
// 0041c54f  ba01000000           mov edx, 1
// 0041c554  f00fc110             lock xadd dword ptr [eax], edx
// 0041c558  8b742414             mov esi, dword ptr [esp + 0x14]
// 0041c55c  85f6                 test esi, esi
// 0041c55e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0041c566  c744240c01000000     mov dword ptr [esp + 0xc], 1
// 0041c56e  742a                 je 0x41c59a
// 0041c570  8d4604               lea eax, [esi + 4]
// 0041c573  83c9ff               or ecx, 0xffffffff
// 0041c576  f00fc108             lock xadd dword ptr [eax], ecx
// 0041c57a  751e                 jne 0x41c59a
// 0041c57c  8b16                 mov edx, dword ptr [esi]
// 0041c57e  8b4204               mov eax, dword ptr [edx + 4]
// 0041c581  8bce                 mov ecx, esi
// 0041c583  ffd0                 call eax
// 0041c585  8d4e08               lea ecx, [esi + 8]
// 0041c588  83caff               or edx, 0xffffffff
// 0041c58b  f00fc111             lock xadd dword ptr [ecx], edx
// 0041c58f  7509                 jne 0x41c59a
// 0041c591  8b06                 mov eax, dword ptr [esi]
// 0041c593  8b5008               mov edx, dword ptr [eax + 8]
// 0041c596  8bce                 mov ecx, esi
// 0041c598  ffd2                 call edx
// 0041c59a  8bc7                 mov eax, edi
// 0041c59c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0041c5a0  64890d00000000       mov dword ptr fs:[0], ecx
// 0041c5a7  59                   pop ecx
// 0041c5a8  5f                   pop edi
// 0041c5a9  5e                   pop esi
// 0041c5aa  83c418               add esp, 0x18
// 0041c5ad  c20400               ret 4
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
