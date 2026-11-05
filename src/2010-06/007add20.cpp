// from server: 100% by auto
// roc 2010-06 007add20  unit: CXTPPaintManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007add20
//
// 007add20  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007add24  8b4908               mov ecx, dword ptr [ecx + 8]
// 007add27  83ec08               sub esp, 8
// 007add2a  8d0424               lea eax, [esp]
// 007add2d  50                   push eax
// 007add2e  8b442414             mov eax, dword ptr [esp + 0x14]
// 007add32  52                   push edx
// 007add33  50                   push eax
// 007add34  51                   push ecx
// 007add35  ff1594a19e00         call dword ptr [0x9ea194]
// 007add3b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007add3f  8b1424               mov edx, dword ptr [esp]
// 007add42  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007add46  8910                 mov dword ptr [eax], edx
// 007add48  894804               mov dword ptr [eax + 4], ecx
// 007add4b  83c408               add esp, 8
// 007add4e  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxstatusbar.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstatusbar.cpp
