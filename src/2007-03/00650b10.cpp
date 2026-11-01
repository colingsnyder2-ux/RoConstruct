// from server: 100% by auto
// roc 2007-03 00650b10  unit: seg_00650000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00650b10
//
// 00650b10  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00650b14  8b542408             mov edx, dword ptr [esp + 8]
// 00650b18  50                   push eax
// 00650b19  8b442408             mov eax, dword ptr [esp + 8]
// 00650b1d  52                   push edx
// 00650b1e  50                   push eax
// 00650b1f  83c160               add ecx, 0x60
// 00650b22  e819230000           call 0x652e40
// 00650b27  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
