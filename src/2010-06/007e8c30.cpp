// from server: 100% by auto
// roc 2010-06 007e8c30  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8c30
//
// 007e8c30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e8c34  8b542408             mov edx, dword ptr [esp + 8]
// 007e8c38  50                   push eax
// 007e8c39  8b442408             mov eax, dword ptr [esp + 8]
// 007e8c3d  52                   push edx
// 007e8c3e  50                   push eax
// 007e8c3f  83c160               add ecx, 0x60
// 007e8c42  e899e5ffff           call 0x7e71e0
// 007e8c47  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
