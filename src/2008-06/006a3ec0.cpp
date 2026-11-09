// from server: 100% by auto
// roc 2008-06 006a3ec0  unit: MyXTPCommandBars  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006a3ec0
//
// 006a3ec0  e8ebf5ffff           call 0x6a34b0
// 006a3ec5  85c0                 test eax, eax
// 006a3ec7  7407                 je 0x6a3ed0
// 006a3ec9  8bc8                 mov ecx, eax
// 006a3ecb  e9409b0700           jmp 0x71da10
// 006a3ed0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewhtml.cpp (function ?OnStatusTextChange@CHtmlView@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewhtml.cpp
