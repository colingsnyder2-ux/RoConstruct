// from server: 100% by auto
// roc 2009-06 00728bf0  unit: CXTPPaintManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00728bf0
//
// 00728bf0  6a0c                 push 0xc
// 00728bf2  e8899bffff           call 0x722780
// 00728bf7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00728bfb  50                   push eax
// 00728bfc  8d44240c             lea eax, [esp + 0xc]
// 00728c00  50                   push eax
// 00728c01  e8ca0bffff           call 0x7197d0
// 00728c06  c22400               ret 0x24
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?FillWorkspace@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
