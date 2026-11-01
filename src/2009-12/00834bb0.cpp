// from server: 100% by auto
// roc 2009-12 00834bb0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00834bb0
//
// 00834bb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00834bb4  8b542408             mov edx, dword ptr [esp + 8]
// 00834bb8  50                   push eax
// 00834bb9  8b442408             mov eax, dword ptr [esp + 8]
// 00834bbd  52                   push edx
// 00834bbe  50                   push eax
// 00834bbf  83c154               add ecx, 0x54
// 00834bc2  e859e4ffff           call 0x833020
// 00834bc7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
