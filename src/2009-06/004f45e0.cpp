// from server: 100% by auto
// roc 2009-06 004f45e0  unit: Exposer  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004f45e0
//
// 004f45e0  8b01                 mov eax, dword ptr [ecx]
// 004f45e2  8b4038               mov eax, dword ptr [eax + 0x38]
// 004f45e5  ffe0                 jmp eax
// library mfc-9.0/atlmfc\src\mfc\sockcore.cpp (function ?ReceiveFrom@CAsyncSocket@@QAEHPAXHPAUsockaddr@@PAHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/sockcore.cpp
