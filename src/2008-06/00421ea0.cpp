// from server: 100% by auto
// roc 2008-06 00421ea0  unit: CSettingsExplorer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00421ea0
//
// 00421ea0  8b4108               mov eax, dword ptr [ecx + 8]
// 00421ea3  0301                 add eax, dword ptr [ecx]
// 00421ea5  56                   push esi
// 00421ea6  8b742408             mov esi, dword ptr [esp + 8]
// 00421eaa  99                   cdq 
// 00421eab  2bc2                 sub eax, edx
// 00421ead  d1f8                 sar eax, 1
// 00421eaf  8906                 mov dword ptr [esi], eax
// 00421eb1  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00421eb4  034104               add eax, dword ptr [ecx + 4]
// 00421eb7  99                   cdq 
// 00421eb8  2bc2                 sub eax, edx
// 00421eba  d1f8                 sar eax, 1
// 00421ebc  894604               mov dword ptr [esi + 4], eax
// 00421ebf  8bc6                 mov eax, esi
// 00421ec1  5e                   pop esi
// 00421ec2  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
