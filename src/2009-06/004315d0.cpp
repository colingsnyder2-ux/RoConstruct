// from server: 100% by EspClaude
// roc 2009-06 004315d0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004315d0
//
// 004315d0  56                   push esi
// 004315d1  8bf1                 mov esi, ecx
// 004315d3  e8307a2e00           call 0x719008
// 004315d8  83f8ff               cmp eax, -1
// 004315db  7506                 jne 0x4315e3
// 004315dd  0bc0                 or eax, eax
// 004315df  5e                   pop esi
// 004315e0  c20400               ret 4
// 004315e3  6a06                 push 6
// 004315e5  8bce                 mov ecx, esi
// 004315e7  e844343400           call 0x774a30
// 004315ec  e8cf7d3000           call 0x7393c0
// 004315f1  83c004               add eax, 4
// 004315f4  50                   push eax
// 004315f5  ff15d0e18900         call dword ptr [0x89e1d0]
// 004315fb  e8c07d3000           call 0x7393c0
// 00431600  50                   push eax
// 00431601  8bce                 mov ecx, esi
// 00431603  e8e8183400           call 0x772ef0
// 00431608  33c0                 xor eax, eax
// 0043160a  5e                   pop esi
// 0043160b  c20400               ret 4
// copied from an identical function in another client (function ?Create@S@ns_ROCX000004@@QAEHPAX@Z)

namespace ns_ROCX000004 {
extern "C" long (__stdcall *InterlockedIncrement)(volatile long *);
extern long * __cdecl GetSharedObject();

struct S {
    int QueryState();
    void SetMode(int);
    void SetSharedObject(long *);
    int Create(void *);
};

int S::Create(void *)
{
    if (QueryState() == -1)
        return -1;

    SetMode(6);
    InterlockedIncrement(GetSharedObject() + 1);
    SetSharedObject(GetSharedObject());
    return 0;
}
}
