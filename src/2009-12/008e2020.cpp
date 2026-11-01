// from server: 100% by auto
// roc 2009-12 008e2020  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008e2020
//
// 008e2020  8b5104               mov edx, dword ptr [ecx + 4]
// 008e2023  85d2                 test edx, edx
// 008e2025  7505                 jne 0x8e202c
// 008e2027  e8e01af1ff           call 0x7f3b0c
// 008e202c  8b02                 mov eax, dword ptr [edx]
// 008e202e  56                   push esi
// 008e202f  8b7208               mov esi, dword ptr [edx + 8]
// 008e2032  894104               mov dword ptr [ecx + 4], eax
// 008e2035  85c0                 test eax, eax
// 008e2037  7411                 je 0x8e204a
// 008e2039  52                   push edx
// 008e203a  c7400400000000       mov dword ptr [eax + 4], 0
// 008e2041  e86a15b5ff           call 0x4335b0
// 008e2046  8bc6                 mov eax, esi
// 008e2048  5e                   pop esi
// 008e2049  c3                   ret 
// 008e204a  52                   push edx
// 008e204b  c7410800000000       mov dword ptr [ecx + 8], 0
// 008e2052  e85915b5ff           call 0x4335b0
// 008e2057  8bc6                 mov eax, esi
// 008e2059  5e                   pop esi
// 008e205a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
