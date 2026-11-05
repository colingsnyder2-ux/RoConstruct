// from server: 100% by auto
// roc 2007-08 0041ece0  unit: CSettingsExplorer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041ece0
//
// 0041ece0  8b4108               mov eax, dword ptr [ecx + 8]
// 0041ece3  0301                 add eax, dword ptr [ecx]
// 0041ece5  56                   push esi
// 0041ece6  8b742408             mov esi, dword ptr [esp + 8]
// 0041ecea  99                   cdq 
// 0041eceb  2bc2                 sub eax, edx
// 0041eced  d1f8                 sar eax, 1
// 0041ecef  8906                 mov dword ptr [esi], eax
// 0041ecf1  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0041ecf4  034104               add eax, dword ptr [ecx + 4]
// 0041ecf7  99                   cdq 
// 0041ecf8  2bc2                 sub eax, edx
// 0041ecfa  d1f8                 sar eax, 1
// 0041ecfc  894604               mov dword ptr [esi + 4], eax
// 0041ecff  8bc6                 mov eax, esi
// 0041ed01  5e                   pop esi
// 0041ed02  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewrich.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewrich.cpp
