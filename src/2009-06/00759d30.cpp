// from server: 100% by auto
// roc 2009-06 00759d30  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759d30
//
// 00759d30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00759d34  8b542408             mov edx, dword ptr [esp + 8]
// 00759d38  50                   push eax
// 00759d39  8b442408             mov eax, dword ptr [esp + 8]
// 00759d3d  52                   push edx
// 00759d3e  50                   push eax
// 00759d3f  83c154               add ecx, 0x54
// 00759d42  e859e4ffff           call 0x7581a0
// 00759d47  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
