// from server: 100% by auto
// roc 2007-08 006828a0  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006828a0
//
// 006828a0  56                   push esi
// 006828a1  8bf1                 mov esi, ecx
// 006828a3  6800276800           push 0x682700
// 006828a8  b9688f8c00           mov ecx, 0x8c8f68
// 006828ad  e84c600b00           call 0x7388fe
// 006828b2  85c0                 test eax, eax
// 006828b4  7505                 jne 0x6828bb
// 006828b6  e965d6faff           jmp 0x62ff20
// 006828bb  8bce                 mov ecx, esi
// 006828bd  c7400401000000       mov dword ptr [eax + 4], 1
// 006828c4  5e                   pop esi
// 006828c5  e972d5faff           jmp 0x62fe3c
// library mfc-8.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewprnt.cpp
