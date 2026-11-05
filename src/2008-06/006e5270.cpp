// from server: 100% by auto
// roc 2008-06 006e5270  unit: CXTPDockingPaneManager  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006e5270
//
// 006e5270  8b542404             mov edx, dword ptr [esp + 4]
// 006e5274  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 006e5277  7d13                 jge 0x6e528c
// 006e5279  85d2                 test edx, edx
// 006e527b  7c0f                 jl 0x6e528c
// 006e527d  8b4104               mov eax, dword ptr [ecx + 4]
// 006e5280  740c                 je 0x6e528e
// 006e5282  83ea01               sub edx, 1
// 006e5285  8b00                 mov eax, dword ptr [eax]
// 006e5287  75f9                 jne 0x6e5282
// 006e5289  c20400               ret 4
// 006e528c  33c0                 xor eax, eax
// 006e528e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?FindIndex@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
