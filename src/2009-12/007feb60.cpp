// from server: 100% by auto
// roc 2009-12 007feb60  unit: CXTPPaintManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007feb60
//
// 007feb60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007feb64  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007feb68  83ec08               sub esp, 8
// 007feb6b  56                   push esi
// 007feb6c  8b742410             mov esi, dword ptr [esp + 0x10]
// 007feb70  50                   push eax
// 007feb71  51                   push ecx
// 007feb72  8d54240c             lea edx, [esp + 0xc]
// 007feb76  52                   push edx
// 007feb77  8bce                 mov ecx, esi
// 007feb79  e8c45bffff           call 0x7f4742
// 007feb7e  8b442420             mov eax, dword ptr [esp + 0x20]
// 007feb82  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007feb86  50                   push eax
// 007feb87  51                   push ecx
// 007feb88  8bce                 mov ecx, esi
// 007feb8a  e8ad5bffff           call 0x7f473c
// 007feb8f  5e                   pop esi
// 007feb90  83c408               add esp, 8
// 007feb93  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Line@CXTPPaintManager@@QAEXPAVCDC@@VCPoint@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
