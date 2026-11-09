// from server: 100% by auto
// roc 2009-12 00838920  unit: CXTPDockingPaneManager  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00838920
//
// 00838920  8b542404             mov edx, dword ptr [esp + 4]
// 00838924  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00838927  7d13                 jge 0x83893c
// 00838929  85d2                 test edx, edx
// 0083892b  7c0f                 jl 0x83893c
// 0083892d  8b4104               mov eax, dword ptr [ecx + 4]
// 00838930  740c                 je 0x83893e
// 00838932  83ea01               sub edx, 1
// 00838935  8b00                 mov eax, dword ptr [eax]
// 00838937  75f9                 jne 0x838932
// 00838939  c20400               ret 4
// 0083893c  33c0                 xor eax, eax
// 0083893e  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\list_o.cpp (function ?FindIndex@CObList@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/list_o.cpp
