// from server: 100% by Yeetserama
// roc 2007-08 00461a60  unit: CScriptEditor  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00461a60
//
// 00461a60  837c240801           cmp dword ptr [esp + 8], 1
// 00461a65  56                   push esi
// 00461a66  752f                 jne 0x461a97
// 00461a68  8b4154               mov eax, dword ptr [ecx + 0x54]
// 00461a6b  8b7054               mov esi, dword ptr [eax + 0x54]
// 00461a6e  83c054               add eax, 0x54
// 00461a71  83ec08               sub esp, 8
// 00461a74  8bd4                 mov edx, esp
// 00461a76  8932                 mov dword ptr [edx], esi
// 00461a78  8b4004               mov eax, dword ptr [eax + 4]
// 00461a7b  85c0                 test eax, eax
// 00461a7d  89642414             mov dword ptr [esp + 0x14], esp
// 00461a81  894204               mov dword ptr [edx + 4], eax
// 00461a84  740c                 je 0x461a92
// 00461a86  83c004               add eax, 4
// 00461a89  ba01000000           mov edx, 1
// 00461a8e  f00fc110             lock xadd dword ptr [eax], edx
// 00461a92  e839fcffff           call 0x4616d0
// 00461a97  5e                   pop esi
// 00461a98  c20c00               ret 0xc
// copied from an identical function in another client (function ?notify@CScriptEditor@ns_ROCX00001e@@QAEXHHH@Z)

namespace ns_ROCX00001e {
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
