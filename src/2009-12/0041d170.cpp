// from server: 100% by auto
// roc 2009-12 0041d170  unit: CXTTreeCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041d170
//
// 0041d170  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041d174  8b542408             mov edx, dword ptr [esp + 8]
// 0041d178  50                   push eax
// 0041d179  8b442408             mov eax, dword ptr [esp + 8]
// 0041d17d  52                   push edx
// 0041d17e  50                   push eax
// 0041d17f  83c154               add ecx, 0x54
// 0041d182  e859624100           call 0x8333e0
// 0041d187  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
