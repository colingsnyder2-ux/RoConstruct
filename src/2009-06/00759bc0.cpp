// from server: 100% by auto
// roc 2009-06 00759bc0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759bc0
//
// 00759bc0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00759bc4  8b542408             mov edx, dword ptr [esp + 8]
// 00759bc8  50                   push eax
// 00759bc9  8b442408             mov eax, dword ptr [esp + 8]
// 00759bcd  52                   push edx
// 00759bce  50                   push eax
// 00759bcf  83c160               add ecx, 0x60
// 00759bd2  e869e4ffff           call 0x758040
// 00759bd7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
