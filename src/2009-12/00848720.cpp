// from server: 100% by auto
// roc 2009-12 00848720  unit: CXTPControlToolbars  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00848720
//
// 00848720  56                   push esi
// 00848721  8bf1                 mov esi, ecx
// 00848723  e8387a0400           call 0x890160
// 00848728  c706b4ab9f00         mov dword ptr [esi], 0x9fabb4
// 0084872e  c7462054ab9f00       mov dword ptr [esi + 0x20], 0x9fab54
// 00848735  8bc6                 mov eax, esi
// 00848737  5e                   pop esi
// 00848738  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlExt.cpp (function ??0CXTPControlWindowList@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlExt.cpp
