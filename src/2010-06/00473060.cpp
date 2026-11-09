// from server: 100% by Yeetserama
// roc 2010-06 00473060  unit: CScriptEditor  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00473060
//
// 00473060  837c240801           cmp dword ptr [esp + 8], 1
// 00473065  56                   push esi
// 00473066  752f                 jne 0x473097
// 00473068  8b4154               mov eax, dword ptr [ecx + 0x54]
// 0047306b  8b7054               mov esi, dword ptr [eax + 0x54]
// 0047306e  83c054               add eax, 0x54
// 00473071  83ec08               sub esp, 8
// 00473074  8bd4                 mov edx, esp
// 00473076  8932                 mov dword ptr [edx], esi
// 00473078  8b4004               mov eax, dword ptr [eax + 4]
// 0047307b  89642414             mov dword ptr [esp + 0x14], esp
// 0047307f  894204               mov dword ptr [edx + 4], eax
// 00473082  85c0                 test eax, eax
// 00473084  740c                 je 0x473092
// 00473086  83c004               add eax, 4
// 00473089  ba01000000           mov edx, 1
// 0047308e  f00fc110             lock xadd dword ptr [eax], edx
// 00473092  e8f9fcffff           call 0x472d90
// 00473097  5e                   pop esi
// 00473098  c20c00               ret 0xc
// copied from an identical function in another client (function ?notify@CScriptEditor@ns_ROCX000013@@QAEXHHH@Z)

namespace ns_ROCX000013 {
// from server: 100% by colin
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control
{
    long unused;
    volatile long references;
};

struct Shared
{
    void* pointer;
    Control* control;

    Shared(const Shared&);
    ~Shared();
};

inline Shared::Shared(const Shared& other)
    : pointer(other.pointer), control(other.control)
{
    if (control)
        _InterlockedIncrement(&control->references);
}

struct Document
{
    char padding[0x54];
    Shared value;
};

struct CScriptEditor
{
    char padding[0x54];
    Document* document;

    void consume(Shared);
    void notify(int, int, int);
};

void CScriptEditor::notify(int, int event, int)
{
    if (event == 1)
        consume(document->value);
}
}
