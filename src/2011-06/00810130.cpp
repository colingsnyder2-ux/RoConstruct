// from server: 100% by auto
// roc 2011-06 00810130  unit: CXTPPaintManager  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00810130
//
// 00810130  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00810134  8b4908               mov ecx, dword ptr [ecx + 8]
// 00810137  83ec08               sub esp, 8
// 0081013a  8d0424               lea eax, [esp]
// 0081013d  50                   push eax
// 0081013e  8b442414             mov eax, dword ptr [esp + 0x14]
// 00810142  52                   push edx
// 00810143  50                   push eax
// 00810144  51                   push ecx
// 00810145  ff153801a400         call dword ptr [0xa40138]
// 0081014b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0081014f  8b1424               mov edx, dword ptr [esp]
// 00810152  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00810156  8910                 mov dword ptr [eax], edx
// 00810158  894804               mov dword ptr [eax + 4], ecx
// 0081015b  83c408               add esp, 8
// 0081015e  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxstatusbar.cpp (function ?GetTextExtent@CDC@@QBE?AVCSize@@PBDH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxstatusbar.cpp
