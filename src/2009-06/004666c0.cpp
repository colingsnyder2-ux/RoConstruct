// from server: 100% by EspClaude
// roc 2009-06 004666c0  unit: CScriptEditor  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004666c0
//
// 004666c0  837c240801           cmp dword ptr [esp + 8], 1
// 004666c5  56                   push esi
// 004666c6  752f                 jne 0x4666f7
// 004666c8  8b4154               mov eax, dword ptr [ecx + 0x54]
// 004666cb  8b7054               mov esi, dword ptr [eax + 0x54]
// 004666ce  83c054               add eax, 0x54
// 004666d1  83ec08               sub esp, 8
// 004666d4  8bd4                 mov edx, esp
// 004666d6  8932                 mov dword ptr [edx], esi
// 004666d8  8b4004               mov eax, dword ptr [eax + 4]
// 004666db  89642414             mov dword ptr [esp + 0x14], esp
// 004666df  894204               mov dword ptr [edx + 4], eax
// 004666e2  85c0                 test eax, eax
// 004666e4  740c                 je 0x4666f2
// 004666e6  83c004               add eax, 4
// 004666e9  ba01000000           mov edx, 1
// 004666ee  f00fc110             lock xadd dword ptr [eax], edx
// 004666f2  e8f9fcffff           call 0x4663f0
// 004666f7  5e                   pop esi
// 004666f8  c20c00               ret 0xc
// copied from an identical function in another client (function ?notify@CScriptEditor@ns_ROCX00001c@@QAEXHHH@Z)

namespace ns_ROCX00001c {
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
