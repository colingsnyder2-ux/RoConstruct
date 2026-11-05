// from server: 100% by auto
// roc 2010-06 007e8c00  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8c00
//
// 007e8c00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e8c04  8b542408             mov edx, dword ptr [esp + 8]
// 007e8c08  50                   push eax
// 007e8c09  8b442408             mov eax, dword ptr [esp + 8]
// 007e8c0d  52                   push edx
// 007e8c0e  50                   push eax
// 007e8c0f  83c160               add ecx, 0x60
// 007e8c12  e869e4ffff           call 0x7e7080
// 007e8c17  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
