// from server: 100% by auto
// roc 2008-06 006fa230  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fa230
//
// 006fa230  56                   push esi
// 006fa231  8bf1                 mov esi, ecx
// 006fa233  6890a06f00           push 0x6fa090
// 006fa238  b918e99700           mov ecx, 0x97e918
// 006fa23d  e82c230c00           call 0x7bc56e
// 006fa242  85c0                 test eax, eax
// 006fa244  7505                 jne 0x6fa24b
// 006fa246  e8f966faff           call 0x6a0944
// 006fa24b  8bce                 mov ecx, esi
// 006fa24d  c7400401000000       mov dword ptr [eax + 4], 1
// 006fa254  5e                   pop esi
// 006fa255  e90666faff           jmp 0x6a0860
// library mfc-9.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewprnt.cpp
