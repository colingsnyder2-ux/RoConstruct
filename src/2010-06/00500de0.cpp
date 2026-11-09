// from server: 100% by auto
// roc 2010-06 00500de0  unit: Exposer  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00500de0
//
// 00500de0  8b01                 mov eax, dword ptr [ecx]
// 00500de2  8b4038               mov eax, dword ptr [eax + 0x38]
// 00500de5  ffe0                 jmp eax
// library mfc-9.0/atlmfc\src\mfc\sockcore.cpp (function ?ReceiveFrom@CAsyncSocket@@QAEHPAXHPAUsockaddr@@PAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/sockcore.cpp
