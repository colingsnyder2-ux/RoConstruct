// from server: 100% by auto
// roc 2009-12 008c2a70  unit: CXTPImageEditorDlg  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c2a70
//
// 008c2a70  8b5104               mov edx, dword ptr [ecx + 4]
// 008c2a73  85d2                 test edx, edx
// 008c2a75  7505                 jne 0x8c2a7c
// 008c2a77  e89010f3ff           call 0x7f3b0c
// 008c2a7c  8b02                 mov eax, dword ptr [edx]
// 008c2a7e  56                   push esi
// 008c2a7f  8b7208               mov esi, dword ptr [edx + 8]
// 008c2a82  894104               mov dword ptr [ecx + 4], eax
// 008c2a85  85c0                 test eax, eax
// 008c2a87  7411                 je 0x8c2a9a
// 008c2a89  52                   push edx
// 008c2a8a  c7400400000000       mov dword ptr [eax + 4], 0
// 008c2a91  e8ea54feff           call 0x8a7f80
// 008c2a96  8bc6                 mov eax, esi
// 008c2a98  5e                   pop esi
// 008c2a99  c3                   ret 
// 008c2a9a  52                   push edx
// 008c2a9b  c7410800000000       mov dword ptr [ecx + 8], 0
// 008c2aa2  e8d954feff           call 0x8a7f80
// 008c2aa7  8bc6                 mov eax, esi
// 008c2aa9  5e                   pop esi
// 008c2aaa  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
