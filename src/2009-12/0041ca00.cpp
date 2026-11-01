// from server: 100% by auto
// roc 2009-12 0041ca00  unit: CSettingsExplorer  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0041ca00
//
// 0041ca00  8b4108               mov eax, dword ptr [ecx + 8]
// 0041ca03  0301                 add eax, dword ptr [ecx]
// 0041ca05  56                   push esi
// 0041ca06  8b742408             mov esi, dword ptr [esp + 8]
// 0041ca0a  99                   cdq 
// 0041ca0b  2bc2                 sub eax, edx
// 0041ca0d  d1f8                 sar eax, 1
// 0041ca0f  8906                 mov dword ptr [esi], eax
// 0041ca11  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0041ca14  034104               add eax, dword ptr [ecx + 4]
// 0041ca17  99                   cdq 
// 0041ca18  2bc2                 sub eax, edx
// 0041ca1a  d1f8                 sar eax, 1
// 0041ca1c  894604               mov dword ptr [esi + 4], eax
// 0041ca1f  8bc6                 mov eax, esi
// 0041ca21  5e                   pop esi
// 0041ca22  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\viewrich.cpp (function ?CenterPoint@CRect@@QBE?AVCPoint@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/viewrich.cpp
