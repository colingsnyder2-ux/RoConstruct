// from server: 100% by auto
// roc 2011-06 0085f3e0  unit: CXTPPrintingDialog  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f3e0
//
// 0085f3e0  56                   push esi
// 0085f3e1  8bf1                 mov esi, ecx
// 0085f3e3  6840f28500           push 0x85f240
// 0085f3e8  b97c8ad100           mov ecx, 0xd18a7c
// 0085f3ed  e87ad51600           call 0x9cc96c
// 0085f3f2  85c0                 test eax, eax
// 0085f3f4  7505                 jne 0x85f3fb
// 0085f3f6  e80faffaff           call 0x80a30a
// 0085f3fb  8bce                 mov ecx, esi
// 0085f3fd  c7400401000000       mov dword ptr [eax + 4], 1
// 0085f404  5e                   pop esi
// 0085f405  e92eaefaff           jmp 0x80a238
// library mfc-9.0/atlmfc\src\mfc\viewprnt.cpp (function ?OnCancel@CPrintingDialog@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/viewprnt.cpp
