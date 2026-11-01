// from server: 100% by auto
// roc 2009-12 008c7a00  unit: CXTPPropertyGridInplaceEdit  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c7a00
//
// 008c7a00  56                   push esi
// 008c7a01  8bf1                 mov esi, ecx
// 008c7a03  e808ffffff           call 0x8c7910
// 008c7a08  8bc6                 mov eax, esi
// 008c7a0a  5e                   pop esi
// 008c7a0b  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??0CDaoIndexFieldInfo@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
