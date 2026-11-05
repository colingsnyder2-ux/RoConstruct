// roc 2012-06 00a7bcea  unit: CXTIconHandle  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a7bcea
//
// 00a7bcea  8bff                 mov edi, edi
// 00a7bcec  56                   push esi
// 00a7bced  ff3584a4e500         push dword ptr [0xe5a484]
// 00a7bcf3  8bf1                 mov esi, ecx
// 00a7bcf5  56                   push esi
// 00a7bcf6  e863ffffff           call 0xa7bc5e
// 00a7bcfb  8d4e20               lea ecx, [esi + 0x20]
// 00a7bcfe  5e                   pop esi
// 00a7bcff  e944fcffff           jmp 0xa7b948
// copied from an identical function in another client (function ??1CAtlWinModule@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-archive: msvc-atlmfc-rtm atls.lib/f:/dd/vctools/vc7libs/ship/atlmfc/src/atl/atls/staticrelease/obj1r/i386/atlwinmodule.obj