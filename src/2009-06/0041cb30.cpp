// from server: 100% by auto
// roc 2009-06 0041cb30  unit: CXTTreeCtrl  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041cb30
//
// 0041cb30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041cb34  8b542408             mov edx, dword ptr [esp + 8]
// 0041cb38  50                   push eax
// 0041cb39  8b442408             mov eax, dword ptr [esp + 8]
// 0041cb3d  52                   push edx
// 0041cb3e  50                   push eax
// 0041cb3f  83c154               add ecx, 0x54
// 0041cb42  e8f9b43300           call 0x758040
// 0041cb47  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
