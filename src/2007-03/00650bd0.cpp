// from server: 100% by auto
// roc 2007-03 00650bd0  unit: seg_00650000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00650bd0
//
// 00650bd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00650bd4  8b542408             mov edx, dword ptr [esp + 8]
// 00650bd8  50                   push eax
// 00650bd9  8b442408             mov eax, dword ptr [esp + 8]
// 00650bdd  52                   push edx
// 00650bde  50                   push eax
// 00650bdf  83c160               add ecx, 0x60
// 00650be2  e8291e0000           call 0x652a10
// 00650be7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeView@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
