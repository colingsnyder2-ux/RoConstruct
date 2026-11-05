// from server: 100% by auto
// roc 2009-12 008eaa50  unit: PAVCXTPRibbonTabContextHeader::?$CArray  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eaa50
//
// 008eaa50  56                   push esi
// 008eaa51  8bf1                 mov esi, ecx
// 008eaa53  e8e8feffff           call 0x8ea940
// 008eaa58  8bc6                 mov eax, esi
// 008eaa5a  5e                   pop esi
// 008eaa5b  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??0CDaoIndexFieldInfo@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
