// from server: 100% by auto
// roc 2007-03 00650d50  unit: seg_00650000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00650d50
//
// 00650d50  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00650d54  8b542408             mov edx, dword ptr [esp + 8]
// 00650d58  50                   push eax
// 00650d59  8b442408             mov eax, dword ptr [esp + 8]
// 00650d5d  52                   push edx
// 00650d5e  50                   push eax
// 00650d5f  83c154               add ecx, 0x54
// 00650d62  e8091e0000           call 0x652b70
// 00650d67  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
