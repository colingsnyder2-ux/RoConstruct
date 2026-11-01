// from server: 100% by auto
// roc 2009-12 00803b60  unit: CXTPPaintManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00803b60
//
// 00803b60  6a0c                 push 0xc
// 00803b62  e8d99affff           call 0x7fd640
// 00803b67  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00803b6b  50                   push eax
// 00803b6c  8d44240c             lea eax, [esp + 0xc]
// 00803b70  50                   push eax
// 00803b71  e8880affff           call 0x7f45fe
// 00803b76  c22400               ret 0x24
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?FillWorkspace@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
