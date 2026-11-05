// from server: 100% by auto
// roc 2009-06 0072a7a0  unit: MyXTPCommandBars  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072a7a0
//
// 0072a7a0  e80bf6ffff           call 0x729db0
// 0072a7a5  85c0                 test eax, eax
// 0072a7a7  7407                 je 0x72a7b0
// 0072a7a9  8bc8                 mov ecx, eax
// 0072a7ab  e9c0990800           jmp 0x7b4170
// 0072a7b0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\viewhtml.cpp (function ?OnStatusTextChange@CHtmlView@@UAEXPBD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewhtml.cpp
