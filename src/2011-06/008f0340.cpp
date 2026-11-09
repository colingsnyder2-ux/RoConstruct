// from server: 100% by auto
// roc 2011-06 008f0340  unit: CXTShadowWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008f0340
//
// 008f0340  8b5104               mov edx, dword ptr [ecx + 4]
// 008f0343  85d2                 test edx, edx
// 008f0345  7505                 jne 0x8f034c
// 008f0347  e8be9ff1ff           call 0x80a30a
// 008f034c  8b02                 mov eax, dword ptr [edx]
// 008f034e  56                   push esi
// 008f034f  8b7208               mov esi, dword ptr [edx + 8]
// 008f0352  894104               mov dword ptr [ecx + 4], eax
// 008f0355  85c0                 test eax, eax
// 008f0357  7411                 je 0x8f036a
// 008f0359  52                   push edx
// 008f035a  c7400400000000       mov dword ptr [eax + 4], 0
// 008f0361  e86a5dffff           call 0x8e60d0
// 008f0366  8bc6                 mov eax, esi
// 008f0368  5e                   pop esi
// 008f0369  c3                   ret 
// 008f036a  52                   push edx
// 008f036b  c7410800000000       mov dword ptr [ecx + 8], 0
// 008f0372  e8595dffff           call 0x8e60d0
// 008f0377  8bc6                 mov eax, esi
// 008f0379  5e                   pop esi
// 008f037a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
