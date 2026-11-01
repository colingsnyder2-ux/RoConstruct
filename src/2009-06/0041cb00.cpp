// from server: 100% by auto
// roc 2009-06 0041cb00  unit: CXTTreeCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cb00
//
// 0041cb00  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041cb04  8b542408             mov edx, dword ptr [esp + 8]
// 0041cb08  50                   push eax
// 0041cb09  8b442408             mov eax, dword ptr [esp + 8]
// 0041cb0d  52                   push edx
// 0041cb0e  50                   push eax
// 0041cb0f  83c154               add ecx, 0x54
// 0041cb12  e849ba3300           call 0x758560
// 0041cb17  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
