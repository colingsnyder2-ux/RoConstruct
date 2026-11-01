// from server: 100% by auto
// roc 2007-03 00420880  unit: seg_00420000  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00420880
//
// 00420880  8b4108               mov eax, dword ptr [ecx + 8]
// 00420883  0301                 add eax, dword ptr [ecx]
// 00420885  56                   push esi
// 00420886  8b742408             mov esi, dword ptr [esp + 8]
// 0042088a  99                   cdq 
// 0042088b  2bc2                 sub eax, edx
// 0042088d  d1f8                 sar eax, 1
// 0042088f  8906                 mov dword ptr [esi], eax
// 00420891  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00420894  034104               add eax, dword ptr [ecx + 4]
// 00420897  99                   cdq 
// 00420898  2bc2                 sub eax, edx
// 0042089a  d1f8                 sar eax, 1
// 0042089c  894604               mov dword ptr [esi + 4], eax
// 0042089f  8bc6                 mov eax, esi
// 004208a1  5e                   pop esi
// 004208a2  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewrich.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewrich.cpp
