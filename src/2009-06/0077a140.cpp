// from server: 100% by auto
// roc 2009-06 0077a140  unit: CXTPTabClientWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a140
//
// 0077a140  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0077a144  6a00                 push 0
// 0077a146  6a00                 push 0
// 0077a148  68b9280000           push 0x28b9
// 0077a14d  e87e74f3ff           call 0x6b15d0
// 0077a152  50                   push eax
// 0077a153  ff1590ee8900         call dword ptr [0x89ee90]
// 0077a159  85c0                 test eax, eax
// 0077a15b  7503                 jne 0x77a160
// 0077a15d  83c8ff               or eax, 0xffffffff
// 0077a160  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemColor@CXTPTabClientWnd@@MBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
