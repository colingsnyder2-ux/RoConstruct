// from server: 100% by auto
// roc 2009-06 00759b20  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759b20
//
// 00759b20  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00759b24  8b542408             mov edx, dword ptr [esp + 8]
// 00759b28  50                   push eax
// 00759b29  8b442408             mov eax, dword ptr [esp + 8]
// 00759b2d  52                   push edx
// 00759b2e  50                   push eax
// 00759b2f  83c160               add ecx, 0x60
// 00759b32  e829eaffff           call 0x758560
// 00759b37  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
