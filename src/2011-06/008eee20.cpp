// from server: 100% by auto
// roc 2011-06 008eee20  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008eee20
//
// 008eee20  8b5104               mov edx, dword ptr [ecx + 4]
// 008eee23  85d2                 test edx, edx
// 008eee25  7505                 jne 0x8eee2c
// 008eee27  e8deb4f1ff           call 0x80a30a
// 008eee2c  8b02                 mov eax, dword ptr [edx]
// 008eee2e  56                   push esi
// 008eee2f  8b7208               mov esi, dword ptr [edx + 8]
// 008eee32  894104               mov dword ptr [ecx + 4], eax
// 008eee35  85c0                 test eax, eax
// 008eee37  7411                 je 0x8eee4a
// 008eee39  52                   push edx
// 008eee3a  c7400400000000       mov dword ptr [eax + 4], 0
// 008eee41  e82a53b5ff           call 0x444170
// 008eee46  8bc6                 mov eax, esi
// 008eee48  5e                   pop esi
// 008eee49  c3                   ret 
// 008eee4a  52                   push edx
// 008eee4b  c7410800000000       mov dword ptr [ecx + 8], 0
// 008eee52  e81953b5ff           call 0x444170
// 008eee57  8bc6                 mov eax, esi
// 008eee59  5e                   pop esi
// 008eee5a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
