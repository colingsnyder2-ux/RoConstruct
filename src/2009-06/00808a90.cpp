// from server: 100% by auto
// roc 2009-06 00808a90  unit: CXTShadowWnd  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00808a90
//
// 00808a90  8b5104               mov edx, dword ptr [ecx + 4]
// 00808a93  85d2                 test edx, edx
// 00808a95  7505                 jne 0x808a9c
// 00808a97  e84802f1ff           call 0x718ce4
// 00808a9c  8b02                 mov eax, dword ptr [edx]
// 00808a9e  56                   push esi
// 00808a9f  8b7208               mov esi, dword ptr [edx + 8]
// 00808aa2  894104               mov dword ptr [ecx + 4], eax
// 00808aa5  85c0                 test eax, eax
// 00808aa7  7411                 je 0x808aba
// 00808aa9  52                   push edx
// 00808aaa  c7400400000000       mov dword ptr [eax + 4], 0
// 00808ab1  e8ba8bfdff           call 0x7e1670
// 00808ab6  8bc6                 mov eax, esi
// 00808ab8  5e                   pop esi
// 00808ab9  c3                   ret 
// 00808aba  52                   push edx
// 00808abb  c7410800000000       mov dword ptr [ecx + 8], 0
// 00808ac2  e8a98bfdff           call 0x7e1670
// 00808ac7  8bc6                 mov eax, esi
// 00808ac9  5e                   pop esi
// 00808aca  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
