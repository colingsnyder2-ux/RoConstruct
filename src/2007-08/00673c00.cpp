// from server: 100% by auto
// roc 2007-08 00673c00  unit: CXTPCustomizeSheet  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00673c00
//
// 00673c00  8b442418             mov eax, dword ptr [esp + 0x18]
// 00673c04  8b542410             mov edx, dword ptr [esp + 0x10]
// 00673c08  8b4904               mov ecx, dword ptr [ecx + 4]
// 00673c0b  83c803               or eax, 3
// 00673c0e  50                   push eax
// 00673c0f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00673c13  52                   push edx
// 00673c14  8b542410             mov edx, dword ptr [esp + 0x10]
// 00673c18  50                   push eax
// 00673c19  8b442410             mov eax, dword ptr [esp + 0x10]
// 00673c1d  52                   push edx
// 00673c1e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00673c22  50                   push eax
// 00673c23  8b442430             mov eax, dword ptr [esp + 0x30]
// 00673c27  6a00                 push 0
// 00673c29  52                   push edx
// 00673c2a  6a00                 push 0
// 00673c2c  50                   push eax
// 00673c2d  51                   push ecx
// 00673c2e  ff1578ee7700         call dword ptr [0x77ee78]
// 00673c34  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
