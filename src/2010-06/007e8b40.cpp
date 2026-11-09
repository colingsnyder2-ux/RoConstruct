// from server: 100% by auto
// roc 2010-06 007e8b40  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8b40
//
// 007e8b40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e8b44  8b542408             mov edx, dword ptr [esp + 8]
// 007e8b48  50                   push eax
// 007e8b49  8b442408             mov eax, dword ptr [esp + 8]
// 007e8b4d  52                   push edx
// 007e8b4e  50                   push eax
// 007e8b4f  83c160               add ecx, 0x60
// 007e8b52  e859e9ffff           call 0x7e74b0
// 007e8b57  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
