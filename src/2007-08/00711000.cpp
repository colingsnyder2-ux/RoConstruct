// from server: 100% by auto
// roc 2007-08 00711000  unit: CXTColorSelectorCtrl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00711000
//
// 00711000  8b542404             mov edx, dword ptr [esp + 4]
// 00711004  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00711007  7d13                 jge 0x71101c
// 00711009  85d2                 test edx, edx
// 0071100b  7c0f                 jl 0x71101c
// 0071100d  8b4104               mov eax, dword ptr [ecx + 4]
// 00711010  740c                 je 0x71101e
// 00711012  83ea01               sub edx, 1
// 00711015  8b00                 mov eax, dword ptr [eax]
// 00711017  75f9                 jne 0x711012
// 00711019  c20400               ret 4
// 0071101c  33c0                 xor eax, eax
// 0071101e  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?FindIndex@CObList@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
