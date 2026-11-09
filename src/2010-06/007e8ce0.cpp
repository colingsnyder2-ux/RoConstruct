// from server: 100% by auto
// roc 2010-06 007e8ce0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8ce0
//
// 007e8ce0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007e8ce4  8b542408             mov edx, dword ptr [esp + 8]
// 007e8ce8  50                   push eax
// 007e8ce9  8b442408             mov eax, dword ptr [esp + 8]
// 007e8ced  52                   push edx
// 007e8cee  50                   push eax
// 007e8cef  83c154               add ecx, 0x54
// 007e8cf2  e8b9e7ffff           call 0x7e74b0
// 007e8cf7  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
