// from server: 100% by auto
// roc 2009-12 005524f0  unit: Exposer  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005524f0
//
// 005524f0  8b01                 mov eax, dword ptr [ecx]
// 005524f2  8b4038               mov eax, dword ptr [eax + 0x38]
// 005524f5  ffe0                 jmp eax
// library mfc-8.0/atlmfc\src\mfc\sockcore.cpp (function ?ReceiveFrom@CAsyncSocket@@QAEHPAXHPAUsockaddr@@PAHH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/sockcore.cpp
