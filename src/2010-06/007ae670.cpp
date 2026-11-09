// from server: 100% by auto
// roc 2010-06 007ae670  unit: CXTPPaintManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ae670
//
// 007ae670  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ae674  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007ae678  83ec08               sub esp, 8
// 007ae67b  56                   push esi
// 007ae67c  8b742410             mov esi, dword ptr [esp + 0x10]
// 007ae680  50                   push eax
// 007ae681  51                   push ecx
// 007ae682  8d54240c             lea edx, [esp + 0xc]
// 007ae686  52                   push edx
// 007ae687  8bce                 mov ecx, esi
// 007ae689  e8eea1ffff           call 0x7a887c
// 007ae68e  8b442420             mov eax, dword ptr [esp + 0x20]
// 007ae692  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007ae696  50                   push eax
// 007ae697  51                   push ecx
// 007ae698  8bce                 mov ecx, esi
// 007ae69a  e8d7a1ffff           call 0x7a8876
// 007ae69f  5e                   pop esi
// 007ae6a0  83c408               add esp, 8
// 007ae6a3  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Line@CXTPPaintManager@@QAEXPAVCDC@@VCPoint@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
