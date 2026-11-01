// from server: 100% by auto
// roc 2009-06 00759ca0  unit: CXTTreeBase::PAXPAXUCLRFONT::?$CMap  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00759ca0
//
// 00759ca0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00759ca4  8b542408             mov edx, dword ptr [esp + 8]
// 00759ca8  50                   push eax
// 00759ca9  8b442408             mov eax, dword ptr [esp + 8]
// 00759cad  52                   push edx
// 00759cae  50                   push eax
// 00759caf  83c154               add ecx, 0x54
// 00759cb2  e8b9e7ffff           call 0x758470
// 00759cb7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
