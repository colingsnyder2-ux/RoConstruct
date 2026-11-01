// from server: 100% by auto
// roc 2009-12 00834980  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834980
//
// 00834980  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00834984  8b542408             mov edx, dword ptr [esp + 8]
// 00834988  50                   push eax
// 00834989  8b442408             mov eax, dword ptr [esp + 8]
// 0083498d  52                   push edx
// 0083498e  50                   push eax
// 0083498f  83c160               add ecx, 0x60
// 00834992  e859e9ffff           call 0x8332f0
// 00834997  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
