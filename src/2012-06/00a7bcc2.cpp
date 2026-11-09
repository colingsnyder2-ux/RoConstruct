// roc 2012-06 00a7bcc2  unit: CXTIconHandle  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bcc2
//
// 00a7bcc2  8bff                 mov edi, edi
// 00a7bcc4  56                   push esi
// 00a7bcc5  8bf1                 mov esi, ecx
// 00a7bcc7  e876ffffff           call 0xa7bc42
// 00a7bccc  56                   push esi
// 00a7bccd  c7062c000000         mov dword ptr [esi], 0x2c
// 00a7bcd3  e816ffffff           call 0xa7bbee
// 00a7bcd8  85c0                 test eax, eax
// 00a7bcda  7d0a                 jge 0xa7bce6
// 00a7bcdc  c60564a2e10001       mov byte ptr [0xe1a264], 1
// 00a7bce3  832600               and dword ptr [esi], 0
// 00a7bce6  8bc6                 mov eax, esi
// 00a7bce8  5e                   pop esi
// 00a7bce9  c3                   ret 
// copied from an identical function in another client (function ??0CAtlWinModule@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlwinmodule.obj