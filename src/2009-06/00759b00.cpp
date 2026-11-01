// from server: 100% by auto
// roc 2009-06 00759b00  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759b00
//
// 00759b00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00759b04  8b542408             mov edx, dword ptr [esp + 8]
// 00759b08  50                   push eax
// 00759b09  8b442408             mov eax, dword ptr [esp + 8]
// 00759b0d  52                   push edx
// 00759b0e  50                   push eax
// 00759b0f  83c160               add ecx, 0x60
// 00759b12  e859e9ffff           call 0x758470
// 00759b17  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
