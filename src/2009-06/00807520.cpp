// from server: 100% by auto
// roc 2009-06 00807520  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00807520
//
// 00807520  8b5104               mov edx, dword ptr [ecx + 4]
// 00807523  85d2                 test edx, edx
// 00807525  7505                 jne 0x80752c
// 00807527  e8b817f1ff           call 0x718ce4
// 0080752c  8b02                 mov eax, dword ptr [edx]
// 0080752e  56                   push esi
// 0080752f  8b7208               mov esi, dword ptr [edx + 8]
// 00807532  894104               mov dword ptr [ecx + 4], eax
// 00807535  85c0                 test eax, eax
// 00807537  7411                 je 0x80754a
// 00807539  52                   push edx
// 0080753a  c7400400000000       mov dword ptr [eax + 4], 0
// 00807541  e83aacc2ff           call 0x432180
// 00807546  8bc6                 mov eax, esi
// 00807548  5e                   pop esi
// 00807549  c3                   ret 
// 0080754a  52                   push edx
// 0080754b  c7410800000000       mov dword ptr [ecx + 8], 0
// 00807552  e829acc2ff           call 0x432180
// 00807557  8bc6                 mov eax, esi
// 00807559  5e                   pop esi
// 0080755a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
