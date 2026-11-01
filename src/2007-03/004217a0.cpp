// from server: 100% by auto
// roc 2007-03 004217a0  unit: seg_00420000  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004217a0
//
// 004217a0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004217a4  8b542408             mov edx, dword ptr [esp + 8]
// 004217a8  50                   push eax
// 004217a9  8b442408             mov eax, dword ptr [esp + 8]
// 004217ad  52                   push edx
// 004217ae  50                   push eax
// 004217af  83c154               add ecx, 0x54
// 004217b2  e859122300           call 0x652a10
// 004217b7  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Shell\XTPShellTreeCtrlView.cpp (function ?OnLButtonDown@CXTPShellTreeBaseCTreeCtrl@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Shell/XTPShellTreeCtrlView.cpp
