// from server: 100% by auto
// roc 2007-03 006afca0  unit: seg_006a0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006afca0
//
// 006afca0  6a38                 push 0x38
// 006afca2  e8f924f8ff           call 0x6321a0
// 006afca7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006afcab  50                   push eax
// 006afcac  8d44240c             lea eax, [esp + 0xc]
// 006afcb0  50                   push eax
// 006afcb1  e864f0f6ff           call 0x61ed1a
// 006afcb6  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPOfficeTheme.cpp (function ?FillPopupLabelEntry@CXTPOfficeTheme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOfficeTheme.cpp
