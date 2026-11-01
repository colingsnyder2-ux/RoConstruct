// from server: 100% by auto
// roc 2007-03 0065a3b0  unit: seg_00650000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065a3b0
//
// 0065a3b0  8b542404             mov edx, dword ptr [esp + 4]
// 0065a3b4  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0065a3b7  7d13                 jge 0x65a3cc
// 0065a3b9  85d2                 test edx, edx
// 0065a3bb  7c0f                 jl 0x65a3cc
// 0065a3bd  8b4104               mov eax, dword ptr [ecx + 4]
// 0065a3c0  740c                 je 0x65a3ce
// 0065a3c2  83ea01               sub edx, 1
// 0065a3c5  8b00                 mov eax, dword ptr [eax]
// 0065a3c7  75f9                 jne 0x65a3c2
// 0065a3c9  c20400               ret 4
// 0065a3cc  33c0                 xor eax, eax
// 0065a3ce  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?FindIndex@CObList@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
