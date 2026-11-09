// from server: 100% by auto
// roc 2007-08 0063d870  unit: CXTPPaintManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0063d870
//
// 0063d870  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0063d874  8b4908               mov ecx, dword ptr [ecx + 8]
// 0063d877  83ec08               sub esp, 8
// 0063d87a  8d0424               lea eax, [esp]
// 0063d87d  50                   push eax
// 0063d87e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0063d882  52                   push edx
// 0063d883  50                   push eax
// 0063d884  51                   push ecx
// 0063d885  ff15b8d07700         call dword ptr [0x77d0b8]
// 0063d88b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0063d88f  8b1424               mov edx, dword ptr [esp]
// 0063d892  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0063d896  8910                 mov dword ptr [eax], edx
// 0063d898  894804               mov dword ptr [eax + 4], ecx
// 0063d89b  83c408               add esp, 8
// 0063d89e  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dcmeta.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dcmeta.cpp
