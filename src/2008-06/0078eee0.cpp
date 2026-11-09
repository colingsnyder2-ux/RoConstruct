// from server: 100% by auto
// roc 2008-06 0078eee0  unit: CXTPPropertyGridItemColor::?8??OnInplaceButtonDown::CPropertyGridItemColorColorPopup  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0078eee0
//
// 0078eee0  8b5104               mov edx, dword ptr [ecx + 4]
// 0078eee3  85d2                 test edx, edx
// 0078eee5  7505                 jne 0x78eeec
// 0078eee7  e8581af1ff           call 0x6a0944
// 0078eeec  8b02                 mov eax, dword ptr [edx]
// 0078eeee  56                   push esi
// 0078eeef  8b7208               mov esi, dword ptr [edx + 8]
// 0078eef2  894104               mov dword ptr [ecx + 4], eax
// 0078eef5  85c0                 test eax, eax
// 0078eef7  7411                 je 0x78ef0a
// 0078eef9  52                   push edx
// 0078eefa  c7400400000000       mov dword ptr [eax + 4], 0
// 0078ef01  e8da98caff           call 0x4387e0
// 0078ef06  8bc6                 mov eax, esi
// 0078ef08  5e                   pop esi
// 0078ef09  c3                   ret 
// 0078ef0a  52                   push edx
// 0078ef0b  c7410800000000       mov dword ptr [ecx + 8], 0
// 0078ef12  e8c998caff           call 0x4387e0
// 0078ef17  8bc6                 mov eax, esi
// 0078ef19  5e                   pop esi
// 0078ef1a  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\afxpropertygridctrl.cpp (function ?RemoveHead@?$CList@PAVCMFCPropertyGridProperty@@PAV1@@@QAEPAVCMFCPropertyGridProperty@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxpropertygridctrl.cpp
