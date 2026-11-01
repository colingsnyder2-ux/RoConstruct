// from server: 100% by auto
// roc 2009-12 0083e200  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083e200
//
// 0083e200  8b442418             mov eax, dword ptr [esp + 0x18]
// 0083e204  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083e208  8b4904               mov ecx, dword ptr [ecx + 4]
// 0083e20b  83c803               or eax, 3
// 0083e20e  50                   push eax
// 0083e20f  8b442410             mov eax, dword ptr [esp + 0x10]
// 0083e213  52                   push edx
// 0083e214  8b542410             mov edx, dword ptr [esp + 0x10]
// 0083e218  50                   push eax
// 0083e219  8b442410             mov eax, dword ptr [esp + 0x10]
// 0083e21d  52                   push edx
// 0083e21e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0083e222  50                   push eax
// 0083e223  8b442430             mov eax, dword ptr [esp + 0x30]
// 0083e227  6a00                 push 0
// 0083e229  52                   push edx
// 0083e22a  6a00                 push 0
// 0083e22c  50                   push eax
// 0083e22d  51                   push ecx
// 0083e22e  ff15f8ca9800         call dword ptr [0x98caf8]
// 0083e234  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
