// from server: 100% by Yeetserama
// roc 2007-08 004286a0  unit: COleException  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004286a0
//
// 004286a0  6aff                 push -1
// 004286a2  6898d97300           push 0x73d998
// 004286a7  64a100000000         mov eax, dword ptr fs:[0]
// 004286ad  50                   push eax
// 004286ae  83ec08               sub esp, 8
// 004286b1  56                   push esi
// 004286b2  a188518b00           mov eax, dword ptr [0x8b5188]
// 004286b7  33c4                 xor eax, esp
// 004286b9  50                   push eax
// 004286ba  8d442410             lea eax, [esp + 0x10]
// 004286be  64a300000000         mov dword ptr fs:[0], eax
// 004286c4  8d442408             lea eax, [esp + 8]
// 004286c8  50                   push eax
// 004286c9  e8e23c1400           call 0x56c3b0
// 004286ce  83c404               add esp, 4
// 004286d1  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004286d5  8b11                 mov edx, dword ptr [ecx]
// 004286d7  8b30                 mov esi, dword ptr [eax]
// 004286d9  8b4204               mov eax, dword ptr [edx + 4]
// 004286dc  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004286e4  ffd0                 call eax
// 004286e6  50                   push eax
// 004286e7  6a03                 push 3
// 004286e9  56                   push esi
// 004286ea  e8b1391400           call 0x56c0a0
// 004286ef  8b442418             mov eax, dword ptr [esp + 0x18]
// 004286f3  83c40c               add esp, 0xc
// 004286f6  85c0                 test eax, eax
// 004286f8  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00428700  742c                 je 0x42872e
// 00428702  8bf0                 mov esi, eax
// 00428704  83c004               add eax, 4
// 00428707  83c9ff               or ecx, 0xffffffff
// 0042870a  f00fc108             lock xadd dword ptr [eax], ecx
// 0042870e  751e                 jne 0x42872e
// 00428710  8b16                 mov edx, dword ptr [esi]
// 00428712  8b4204               mov eax, dword ptr [edx + 4]
// 00428715  8bce                 mov ecx, esi
// 00428717  ffd0                 call eax
// 00428719  8d4e08               lea ecx, [esi + 8]
// 0042871c  83caff               or edx, 0xffffffff
// 0042871f  f00fc111             lock xadd dword ptr [ecx], edx
// 00428723  7509                 jne 0x42872e
// 00428725  8b06                 mov eax, dword ptr [esi]
// 00428727  8b5008               mov edx, dword ptr [eax + 8]
// 0042872a  8bce                 mov ecx, esi
// 0042872c  ffd2                 call edx
// 0042872e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00428732  64890d00000000       mov dword ptr fs:[0], ecx
// 00428739  59                   pop ecx
// 0042873a  5e                   pop esi
// 0042873b  83c414               add esp, 0x14
// 0042873e  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000001_00428850@ns_ROCX000001@@YAXPAUMessage@1@@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual void unused();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0)
    {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Logger
{
    void __cdecl writeLog(int, const char*);
};

struct Shared
{
    Logger* object;
    Control* control;

    Logger* operator->() const;
    ~Shared();
};

__forceinline Logger* Shared::operator->() const
{
    return object;
}

__forceinline Shared::~Shared()
{
    if (control)
        control->release();
}

struct Message
{
    virtual void unused();
    virtual const char* text();
};

extern Shared __cdecl getLogger();

void __cdecl fn_ROCX000001_00428850(Message* message)
{
    getLogger()->writeLog(3, message->text());
}
}
