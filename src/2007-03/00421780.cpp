// from server: 100% by auto
// roc 2007-03 00421780  unit: seg_00420000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00421780
//
// 00421780  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00421784  8b542408             mov edx, dword ptr [esp + 8]
// 00421788  50                   push eax
// 00421789  8b442408             mov eax, dword ptr [esp + 8]
// 0042178d  52                   push edx
// 0042178e  50                   push eax
// 0042178f  83c154               add ecx, 0x54
// 00421792  e899172300           call 0x652f30
// 00421797  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
