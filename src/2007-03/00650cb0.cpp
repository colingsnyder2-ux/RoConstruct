// from server: 100% by auto
// roc 2007-03 00650cb0  unit: seg_00650000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00650cb0
//
// 00650cb0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00650cb4  8b542408             mov edx, dword ptr [esp + 8]
// 00650cb8  50                   push eax
// 00650cb9  8b442408             mov eax, dword ptr [esp + 8]
// 00650cbd  52                   push edx
// 00650cbe  50                   push eax
// 00650cbf  83c154               add ecx, 0x54
// 00650cc2  e879210000           call 0x652e40
// 00650cc7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
