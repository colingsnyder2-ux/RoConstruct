// from server: 100% by auto
// roc 2010-06 007b3670  unit: CXTPPaintManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3670
//
// 007b3670  6a0c                 push 0xc
// 007b3672  e8999affff           call 0x7ad110
// 007b3677  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007b367b  50                   push eax
// 007b367c  8d44240c             lea eax, [esp + 0xc]
// 007b3680  50                   push eax
// 007b3681  e8b850ffff           call 0x7a873e
// 007b3686  c22400               ret 0x24
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?FillWorkspace@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
