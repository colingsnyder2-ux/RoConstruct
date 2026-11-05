// roc 2012-06 00a7bbee  unit: CXTIconHandle  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bbee
//
// 00a7bbee  8bff                 mov edi, edi
// 00a7bbf0  55                   push ebp
// 00a7bbf1  8bec                 mov ebp, esp
// 00a7bbf3  8b4508               mov eax, dword ptr [ebp + 8]
// 00a7bbf6  85c0                 test eax, eax
// 00a7bbf8  7507                 jne 0xa7bc01
// 00a7bbfa  b857000780           mov eax, 0x80070057
// 00a7bbff  eb11                 jmp 0xa7bc12
// 00a7bc01  83382c               cmp dword ptr [eax], 0x2c
// 00a7bc04  75f4                 jne 0xa7bbfa
// 00a7bc06  83601c00             and dword ptr [eax + 0x1c], 0
// 00a7bc0a  8d4804               lea ecx, [eax + 4]
// 00a7bc0d  e80e8698ff           call 0x404220
// 00a7bc12  5d                   pop ebp
// 00a7bc13  c20400               ret 4
// copied from an identical function in another client (function ?AtlWinModuleInit@ATL@@YGJPAU_ATL_WIN_MODULE70@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlwinmodule.obj