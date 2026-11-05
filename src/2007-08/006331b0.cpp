// from server: 100% by auto
// roc 2007-08 006331b0  unit: MyXTPCommandBars  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006331b0
//
// 006331b0  e82bf4ffff           call 0x6325e0
// 006331b5  85c0                 test eax, eax
// 006331b7  7407                 je 0x6331c0
// 006331b9  8bc8                 mov ecx, eax
// 006331bb  e9a0100700           jmp 0x6a4260
// 006331c0  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewhtml.cpp (function ?OnStatusTextChange@CHtmlView@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewhtml.cpp
