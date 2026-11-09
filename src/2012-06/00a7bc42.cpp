// roc 2012-06 00a7bc42  unit: CXTIconHandle  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bc42
//
// 00a7bc42  8bff                 mov edi, edi
// 00a7bc44  56                   push esi
// 00a7bc45  8bf1                 mov esi, ecx
// 00a7bc47  8d4e04               lea ecx, [esi + 4]
// 00a7bc4a  e8b18598ff           call 0x404200
// 00a7bc4f  33c0                 xor eax, eax
// 00a7bc51  894620               mov dword ptr [esi + 0x20], eax
// 00a7bc54  894624               mov dword ptr [esi + 0x24], eax
// 00a7bc57  894628               mov dword ptr [esi + 0x28], eax
// 00a7bc5a  8bc6                 mov eax, esi
// 00a7bc5c  5e                   pop esi
// 00a7bc5d  c3                   ret 
// copied from an identical function in another client (function ??0_ATL_WIN_MODULE70@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlwinmodule.obj