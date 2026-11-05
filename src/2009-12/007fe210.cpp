// from server: 100% by auto
// roc 2009-12 007fe210  unit: CXTPPaintManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe210
//
// 007fe210  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007fe214  8b4908               mov ecx, dword ptr [ecx + 8]
// 007fe217  83ec08               sub esp, 8
// 007fe21a  8d0424               lea eax, [esp]
// 007fe21d  50                   push eax
// 007fe21e  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fe222  52                   push edx
// 007fe223  50                   push eax
// 007fe224  51                   push ecx
// 007fe225  ff156cb19800         call dword ptr [0x98b16c]
// 007fe22b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007fe22f  8b1424               mov edx, dword ptr [esp]
// 007fe232  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007fe236  8910                 mov dword ptr [eax], edx
// 007fe238  894804               mov dword ptr [eax + 4], ecx
// 007fe23b  83c408               add esp, 8
// 007fe23e  c20c00               ret 0xc
// library mfc-8.0/atlmfc\src\mfc\dcmeta.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dcmeta.cpp
