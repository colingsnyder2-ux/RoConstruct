// from server: 100% by auto
// roc 2011-06 0084e300  unit: CXTPDockingPaneManager  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0084e300
//
// 0084e300  8b542404             mov edx, dword ptr [esp + 4]
// 0084e304  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 0084e307  7d13                 jge 0x84e31c
// 0084e309  85d2                 test edx, edx
// 0084e30b  7c0f                 jl 0x84e31c
// 0084e30d  8b4104               mov eax, dword ptr [ecx + 4]
// 0084e310  740c                 je 0x84e31e
// 0084e312  83ea01               sub edx, 1
// 0084e315  8b00                 mov eax, dword ptr [eax]
// 0084e317  75f9                 jne 0x84e312
// 0084e319  c20400               ret 4
// 0084e31c  33c0                 xor eax, eax
// 0084e31e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?FindIndex@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
