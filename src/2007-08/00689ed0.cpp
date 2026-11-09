// from server: 100% by auto
// roc 2007-08 00689ed0  unit: CXTPTabClientWnd  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689ed0
//
// 00689ed0  8b442404             mov eax, dword ptr [esp + 4]
// 00689ed4  50                   push eax
// 00689ed5  51                   push ecx
// 00689ed6  ff1528ee7700         call dword ptr [0x77ee28]
// 00689edc  f7d8                 neg eax
// 00689ede  1bc0                 sbb eax, eax
// 00689ee0  83c001               add eax, 1
// 00689ee3  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\bardock.cpp (function ??9CRect@@QBEHABUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/bardock.cpp
