// from server: 100% by auto
// roc 2007-03 00638400  unit: seg_00630000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00638400
//
// 00638400  6a0c                 push 0xc
// 00638402  e8999dffff           call 0x6321a0
// 00638407  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0063840b  50                   push eax
// 0063840c  8d44240c             lea eax, [esp + 0xc]
// 00638410  50                   push eax
// 00638411  e80469feff           call 0x61ed1a
// 00638416  c22400               ret 0x24
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?FillWorkspace@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
