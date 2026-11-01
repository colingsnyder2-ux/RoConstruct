// from server: 100% by auto
// roc 2009-12 00834a70  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834a70
//
// 00834a70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00834a74  8b542408             mov edx, dword ptr [esp + 8]
// 00834a78  50                   push eax
// 00834a79  8b442408             mov eax, dword ptr [esp + 8]
// 00834a7d  52                   push edx
// 00834a7e  50                   push eax
// 00834a7f  83c160               add ecx, 0x60
// 00834a82  e899e5ffff           call 0x833020
// 00834a87  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
