// from server: 100% by auto
// roc 2009-06 00772bd0  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772bd0
//
// 00772bd0  56                   push esi
// 00772bd1  8bf1                 mov esi, ecx
// 00772bd3  68302a7700           push 0x772a30
// 00772bd8  b91022a500           mov ecx, 0xa52210
// 00772bdd  e840980d00           call 0x84c422
// 00772be2  85c0                 test eax, eax
// 00772be4  7505                 jne 0x772beb
// 00772be6  e8f960faff           call 0x718ce4
// 00772beb  8bce                 mov ecx, esi
// 00772bed  c7400401000000       mov dword ptr [eax + 4], 1
// 00772bf4  5e                   pop esi
// 00772bf5  e91860faff           jmp 0x718c12
// library mfc-9.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewprnt.cpp
