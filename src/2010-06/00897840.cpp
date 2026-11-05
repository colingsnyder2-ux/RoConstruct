// from server: 100% by auto
// roc 2010-06 00897840  unit: CXTShadowWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00897840
//
// 00897840  8b5104               mov edx, dword ptr [ecx + 4]
// 00897843  85d2                 test edx, edx
// 00897845  7505                 jne 0x89784c
// 00897847  e80004f1ff           call 0x7a7c4c
// 0089784c  8b02                 mov eax, dword ptr [edx]
// 0089784e  56                   push esi
// 0089784f  8b7208               mov esi, dword ptr [edx + 8]
// 00897852  894104               mov dword ptr [ecx + 4], eax
// 00897855  85c0                 test eax, eax
// 00897857  7411                 je 0x89786a
// 00897859  52                   push edx
// 0089785a  c7400400000000       mov dword ptr [eax + 4], 0
// 00897861  e89a48fcff           call 0x85c100
// 00897866  8bc6                 mov eax, esi
// 00897868  5e                   pop esi
// 00897869  c3                   ret 
// 0089786a  52                   push edx
// 0089786b  c7410800000000       mov dword ptr [ecx + 8], 0
// 00897872  e88948fcff           call 0x85c100
// 00897877  8bc6                 mov eax, esi
// 00897879  5e                   pop esi
// 0089787a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
