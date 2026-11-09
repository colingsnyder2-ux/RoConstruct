// from server: 100% by auto
// roc 2010-06 007e8b60  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8b60
//
// 007e8b60  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e8b64  8b542408             mov edx, dword ptr [esp + 8]
// 007e8b68  50                   push eax
// 007e8b69  8b442408             mov eax, dword ptr [esp + 8]
// 007e8b6d  52                   push edx
// 007e8b6e  50                   push eax
// 007e8b6f  83c160               add ecx, 0x60
// 007e8b72  e829eaffff           call 0x7e75a0
// 007e8b77  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
