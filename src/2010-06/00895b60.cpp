// from server: 100% by auto
// roc 2010-06 00895b60  unit: CXTColorSelectorCtrl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00895b60
//
// 00895b60  8b542404             mov edx, dword ptr [esp + 4]
// 00895b64  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00895b67  7d13                 jge 0x895b7c
// 00895b69  85d2                 test edx, edx
// 00895b6b  7c0f                 jl 0x895b7c
// 00895b6d  8b4104               mov eax, dword ptr [ecx + 4]
// 00895b70  740c                 je 0x895b7e
// 00895b72  83ea01               sub edx, 1
// 00895b75  8b00                 mov eax, dword ptr [eax]
// 00895b77  75f9                 jne 0x895b72
// 00895b79  c20400               ret 4
// 00895b7c  33c0                 xor eax, eax
// 00895b7e  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?FindIndex@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QBEPAU__POSITION@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
