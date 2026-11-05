// from server: 100% by auto
// roc 2012-06 009d77f0  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d77f0
//
// 009d77f0  56                   push esi
// 009d77f1  8bf1                 mov esi, ecx
// 009d77f3  6850769d00           push 0x9d7650
// 009d77f8  b9ec9be500           mov ecx, 0xe59bec
// 009d77fd  e818210c00           call 0xa9991a
// 009d7802  85c0                 test eax, eax
// 009d7804  7505                 jne 0x9d780b
// 009d7806  e8b5abfaff           call 0x9823c0
// 009d780b  8bce                 mov ecx, esi
// 009d780d  c7400401000000       mov dword ptr [eax + 4], 1
// 009d7814  5e                   pop esi
// 009d7815  e9daaafaff           jmp 0x9822f4
// library mfc-9.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewprnt.cpp
