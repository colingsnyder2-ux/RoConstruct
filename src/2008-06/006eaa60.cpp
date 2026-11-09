// from server: 100% by auto
// roc 2008-06 006eaa60  unit: CXTPCustomizeSheet  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006eaa60
//
// 006eaa60  8b442418             mov eax, dword ptr [esp + 0x18]
// 006eaa64  8b542410             mov edx, dword ptr [esp + 0x10]
// 006eaa68  8b4904               mov ecx, dword ptr [ecx + 4]
// 006eaa6b  83c803               or eax, 3
// 006eaa6e  50                   push eax
// 006eaa6f  8b442410             mov eax, dword ptr [esp + 0x10]
// 006eaa73  52                   push edx
// 006eaa74  8b542410             mov edx, dword ptr [esp + 0x10]
// 006eaa78  50                   push eax
// 006eaa79  8b442410             mov eax, dword ptr [esp + 0x10]
// 006eaa7d  52                   push edx
// 006eaa7e  8b542424             mov edx, dword ptr [esp + 0x24]
// 006eaa82  50                   push eax
// 006eaa83  8b442430             mov eax, dword ptr [esp + 0x30]
// 006eaa87  6a00                 push 0
// 006eaa89  52                   push edx
// 006eaa8a  6a00                 push 0
// 006eaa8c  50                   push eax
// 006eaa8d  51                   push ecx
// 006eaa8e  ff15782b8000         call dword ptr [0x802b78]
// 006eaa94  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
