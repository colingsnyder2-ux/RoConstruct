// from server: 100% by auto
// roc 2010-06 0041c8e0  unit: CSettingsExplorer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041c8e0
//
// 0041c8e0  8b4108               mov eax, dword ptr [ecx + 8]
// 0041c8e3  0301                 add eax, dword ptr [ecx]
// 0041c8e5  56                   push esi
// 0041c8e6  8b742408             mov esi, dword ptr [esp + 8]
// 0041c8ea  99                   cdq 
// 0041c8eb  2bc2                 sub eax, edx
// 0041c8ed  d1f8                 sar eax, 1
// 0041c8ef  8906                 mov dword ptr [esi], eax
// 0041c8f1  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0041c8f4  034104               add eax, dword ptr [ecx + 4]
// 0041c8f7  99                   cdq 
// 0041c8f8  2bc2                 sub eax, edx
// 0041c8fa  d1f8                 sar eax, 1
// 0041c8fc  894604               mov dword ptr [esi + 4], eax
// 0041c8ff  8bc6                 mov eax, esi
// 0041c901  5e                   pop esi
// 0041c902  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
