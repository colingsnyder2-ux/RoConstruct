// from server: 100% by auto
// roc 2010-06 00808f40  unit: CXTPTabClientWnd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00808f40
//
// 00808f40  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00808f44  6a00                 push 0
// 00808f46  6a00                 push 0
// 00808f48  68b9280000           push 0x28b9
// 00808f4d  e89e71ebff           call 0x6c00f0
// 00808f52  50                   push eax
// 00808f53  ff1554ba9e00         call dword ptr [0x9eba54]
// 00808f59  85c0                 test eax, eax
// 00808f5b  7503                 jne 0x808f60
// 00808f5d  83c8ff               or eax, 0xffffffff
// 00808f60  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?GetItemColor@CXTPTabClientWnd@@MBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
