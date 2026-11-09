// from server: 100% by auto
// roc 2009-12 0084d900  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084d900
//
// 0084d900  56                   push esi
// 0084d901  8bf1                 mov esi, ecx
// 0084d903  6860d78400           push 0x84d760
// 0084d908  b968b6b900           mov ecx, 0xb9b668
// 0084d90d  e87c900d00           call 0x92698e
// 0084d912  85c0                 test eax, eax
// 0084d914  7505                 jne 0x84d91b
// 0084d916  e8f161faff           call 0x7f3b0c
// 0084d91b  8bce                 mov ecx, esi
// 0084d91d  c7400401000000       mov dword ptr [eax + 4], 1
// 0084d924  5e                   pop esi
// 0084d925  e91061faff           jmp 0x7f3a3a
// library mfc-9.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewprnt.cpp
