// from server: 100% by auto
// roc 2009-06 00759bf0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759bf0
//
// 00759bf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00759bf4  8b542408             mov edx, dword ptr [esp + 8]
// 00759bf8  50                   push eax
// 00759bf9  8b442408             mov eax, dword ptr [esp + 8]
// 00759bfd  52                   push edx
// 00759bfe  50                   push eax
// 00759bff  83c160               add ecx, 0x60
// 00759c02  e899e5ffff           call 0x7581a0
// 00759c07  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
