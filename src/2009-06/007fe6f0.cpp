// from server: 100% by auto
// roc 2009-06 007fe6f0  unit: CXTColorHex  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007fe6f0
//
// 007fe6f0  8b542404             mov edx, dword ptr [esp + 4]
// 007fe6f4  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 007fe6f7  7d13                 jge 0x7fe70c
// 007fe6f9  85d2                 test edx, edx
// 007fe6fb  7c0f                 jl 0x7fe70c
// 007fe6fd  8b4104               mov eax, dword ptr [ecx + 4]
// 007fe700  740c                 je 0x7fe70e
// 007fe702  83ea01               sub edx, 1
// 007fe705  8b00                 mov eax, dword ptr [eax]
// 007fe707  75f9                 jne 0x7fe702
// 007fe709  c20400               ret 4
// 007fe70c  33c0                 xor eax, eax
// 007fe70e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?FindIndex@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
