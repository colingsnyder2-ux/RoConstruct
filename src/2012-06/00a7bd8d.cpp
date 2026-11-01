// from server: 100% by Yeetserama
// roc 2012-06 00a7bd8d  unit: CXTIconHandle  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bd8d
//
// 00a7bd8d  8bff                 mov edi, edi
// 00a7bd8f  55                   push ebp
// 00a7bd90  8bec                 mov ebp, esp
// 00a7bd92  ff7508               push dword ptr [ebp + 8]
// 00a7bd95  6a00                 push 0
// 00a7bd97  ff7104               push dword ptr [ecx + 4]
// 00a7bd9a  ff158823b200         call dword ptr [0xb22388]
// 00a7bda0  5d                   pop ebp
// 00a7bda1  c20400               ret 4
// copied from an identical function in another client (function ?Allocate@CWin32Heap@ATL@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlstr.obj