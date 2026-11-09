// from server: 100% by auto
// roc 2010-06 0041d050  unit: CXTTreeCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041d050
//
// 0041d050  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d054  8b542408             mov edx, dword ptr [esp + 8]
// 0041d058  50                   push eax
// 0041d059  8b442408             mov eax, dword ptr [esp + 8]
// 0041d05d  52                   push edx
// 0041d05e  50                   push eax
// 0041d05f  83c154               add ecx, 0x54
// 0041d062  e839a53c00           call 0x7e75a0
// 0041d067  c20c00               ret 0xc
// library xtp-13.2.1/Source\Controls\XTShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTShellTreeCtrlView.cpp
