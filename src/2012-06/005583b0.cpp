// from server: 100% by Xemicl
// roc 2012-06 005583b0  unit: CrashReporter  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005583b0
//
// 005583b0  55                   push ebp
// 005583b1  8bec                 mov ebp, esp
// 005583b3  51                   push ecx
// 005583b4  8b4508               mov eax, dword ptr [ebp + 8]
// 005583b7  50                   push eax
// 005583b8  e853ffffff           call 0x558310
// 005583bd  83c404               add esp, 4
// 005583c0  8945fc               mov dword ptr [ebp - 4], eax
// 005583c3  6a01                 push 1
// 005583c5  ff155429b200         call dword ptr [0xb22954]
// 005583cb  8be5                 mov esp, ebp
// 005583cd  5d                   pop ebp
// 005583ce  c20400               ret 4
// copied from an identical function in another client (function ?threadProc@@YGKPAX@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MD
#include <stdlib.h>
int __cdecl run(void* p);
unsigned long __stdcall threadProc(void* p)
{
    int r = run(p);
    _exit(1);
}