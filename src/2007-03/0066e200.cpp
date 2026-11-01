// from server: 100% by auto
// roc 2007-03 0066e200  unit: seg_00660000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066e200
//
// 0066e200  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0066e204  6a00                 push 0
// 0066e206  6a00                 push 0
// 0066e208  68b9280000           push 0x28b9
// 0066e20d  e8eef80000           call 0x67db00
// 0066e212  50                   push eax
// 0066e213  ff1550ee7700         call dword ptr [0x77ee50]
// 0066e219  85c0                 test eax, eax
// 0066e21b  7503                 jne 0x66e220
// 0066e21d  83c8ff               or eax, 0xffffffff
// 0066e220  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemColor@CXTPTabClientWnd@@MBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
