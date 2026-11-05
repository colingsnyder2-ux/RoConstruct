// from server: 100% by auto
// roc 2011-06 0082afd0  unit: MyXTPCommandBars  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0082afd0
//
// 0082afd0  e82bf6ffff           call 0x82a600
// 0082afd5  85c0                 test eax, eax
// 0082afd7  7407                 je 0x82afe0
// 0082afd9  8bc8                 mov ecx, eax
// 0082afdb  e9008f0700           jmp 0x8a3ee0
// 0082afe0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewhtml.cpp (function ?OnStatusTextChange@CHtmlView@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewhtml.cpp
