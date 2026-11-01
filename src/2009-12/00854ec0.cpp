// from server: 100% by auto
// roc 2009-12 00854ec0  unit: CXTPTabClientWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00854ec0
//
// 00854ec0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00854ec4  6a00                 push 0
// 00854ec6  6a00                 push 0
// 00854ec8  68b9280000           push 0x28b9
// 00854ecd  e8aeb5eeff           call 0x740480
// 00854ed2  50                   push eax
// 00854ed3  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00854ed9  85c0                 test eax, eax
// 00854edb  7503                 jne 0x854ee0
// 00854edd  83c8ff               or eax, 0xffffffff
// 00854ee0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemColor@CXTPTabClientWnd@@MBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
