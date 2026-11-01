// from server: 100% by auto
// roc 2009-12 00815450  unit: MyXTPCommandBars  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00815450
//
// 00815450  e80bf6ffff           call 0x814a60
// 00815455  85c0                 test eax, eax
// 00815457  7407                 je 0x815460
// 00815459  8bc8                 mov ecx, eax
// 0081545b  e9f0d60700           jmp 0x892b50
// 00815460  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewhtml.cpp (function ?OnStatusTextChange@CHtmlView@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewhtml.cpp
