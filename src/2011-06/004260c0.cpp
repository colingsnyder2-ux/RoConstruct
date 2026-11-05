// from server: 100% by auto
// roc 2011-06 004260c0  unit: CInstanceExplorer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004260c0
//
// 004260c0  8b4108               mov eax, dword ptr [ecx + 8]
// 004260c3  0301                 add eax, dword ptr [ecx]
// 004260c5  56                   push esi
// 004260c6  8b742408             mov esi, dword ptr [esp + 8]
// 004260ca  99                   cdq 
// 004260cb  2bc2                 sub eax, edx
// 004260cd  d1f8                 sar eax, 1
// 004260cf  8906                 mov dword ptr [esi], eax
// 004260d1  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004260d4  034104               add eax, dword ptr [ecx + 4]
// 004260d7  99                   cdq 
// 004260d8  2bc2                 sub eax, edx
// 004260da  d1f8                 sar eax, 1
// 004260dc  894604               mov dword ptr [esi + 4], eax
// 004260df  8bc6                 mov eax, esi
// 004260e1  5e                   pop esi
// 004260e2  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbaseribbonelement.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbaseribbonelement.cpp
