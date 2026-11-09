// from server: 100% by auto
// roc 2008-06 006aec40  unit: CXTPPaintManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006aec40
//
// 006aec40  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006aec44  8b4908               mov ecx, dword ptr [ecx + 8]
// 006aec47  83ec08               sub esp, 8
// 006aec4a  8d0424               lea eax, [esp]
// 006aec4d  50                   push eax
// 006aec4e  8b442414             mov eax, dword ptr [esp + 0x14]
// 006aec52  52                   push edx
// 006aec53  50                   push eax
// 006aec54  51                   push ecx
// 006aec55  ff1540218000         call dword ptr [0x802140]
// 006aec5b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006aec5f  8b1424               mov edx, dword ptr [esp]
// 006aec62  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006aec66  8910                 mov dword ptr [eax], edx
// 006aec68  894804               mov dword ptr [eax + 4], ecx
// 006aec6b  83c408               add esp, 8
// 006aec6e  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxstatusbar.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstatusbar.cpp
