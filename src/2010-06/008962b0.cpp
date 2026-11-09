// from server: 100% by auto
// roc 2010-06 008962b0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008962b0
//
// 008962b0  8b5104               mov edx, dword ptr [ecx + 4]
// 008962b3  85d2                 test edx, edx
// 008962b5  7505                 jne 0x8962bc
// 008962b7  e89019f1ff           call 0x7a7c4c
// 008962bc  8b02                 mov eax, dword ptr [edx]
// 008962be  56                   push esi
// 008962bf  8b7208               mov esi, dword ptr [edx + 8]
// 008962c2  894104               mov dword ptr [ecx + 4], eax
// 008962c5  85c0                 test eax, eax
// 008962c7  7411                 je 0x8962da
// 008962c9  52                   push edx
// 008962ca  c7400400000000       mov dword ptr [eax + 4], 0
// 008962d1  e81ae7b9ff           call 0x4349f0
// 008962d6  8bc6                 mov eax, esi
// 008962d8  5e                   pop esi
// 008962d9  c3                   ret 
// 008962da  52                   push edx
// 008962db  c7410800000000       mov dword ptr [ecx + 8], 0
// 008962e2  e809e7b9ff           call 0x4349f0
// 008962e7  8bc6                 mov eax, esi
// 008962e9  5e                   pop esi
// 008962ea  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
