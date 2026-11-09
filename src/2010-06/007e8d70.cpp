// from server: 100% by auto
// roc 2010-06 007e8d70  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8d70
//
// 007e8d70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e8d74  8b542408             mov edx, dword ptr [esp + 8]
// 007e8d78  50                   push eax
// 007e8d79  8b442408             mov eax, dword ptr [esp + 8]
// 007e8d7d  52                   push edx
// 007e8d7e  50                   push eax
// 007e8d7f  83c154               add ecx, 0x54
// 007e8d82  e859e4ffff           call 0x7e71e0
// 007e8d87  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
