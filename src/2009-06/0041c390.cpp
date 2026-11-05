// from server: 100% by auto
// roc 2009-06 0041c390  unit: CSettingsExplorer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041c390
//
// 0041c390  8b4108               mov eax, dword ptr [ecx + 8]
// 0041c393  0301                 add eax, dword ptr [ecx]
// 0041c395  56                   push esi
// 0041c396  8b742408             mov esi, dword ptr [esp + 8]
// 0041c39a  99                   cdq 
// 0041c39b  2bc2                 sub eax, edx
// 0041c39d  d1f8                 sar eax, 1
// 0041c39f  8906                 mov dword ptr [esi], eax
// 0041c3a1  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0041c3a4  034104               add eax, dword ptr [ecx + 4]
// 0041c3a7  99                   cdq 
// 0041c3a8  2bc2                 sub eax, edx
// 0041c3aa  d1f8                 sar eax, 1
// 0041c3ac  894604               mov dword ptr [esi + 4], eax
// 0041c3af  8bc6                 mov eax, esi
// 0041c3b1  5e                   pop esi
// 0041c3b2  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
