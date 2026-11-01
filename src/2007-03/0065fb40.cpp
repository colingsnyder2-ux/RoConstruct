// from server: 100% by auto
// roc 2007-03 0065fb40  unit: seg_00650000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065fb40
//
// 0065fb40  8b442418             mov eax, dword ptr [esp + 0x18]
// 0065fb44  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065fb48  8b4904               mov ecx, dword ptr [ecx + 4]
// 0065fb4b  83c803               or eax, 3
// 0065fb4e  50                   push eax
// 0065fb4f  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065fb53  52                   push edx
// 0065fb54  8b542410             mov edx, dword ptr [esp + 0x10]
// 0065fb58  50                   push eax
// 0065fb59  8b442410             mov eax, dword ptr [esp + 0x10]
// 0065fb5d  52                   push edx
// 0065fb5e  8b542424             mov edx, dword ptr [esp + 0x24]
// 0065fb62  50                   push eax
// 0065fb63  8b442430             mov eax, dword ptr [esp + 0x30]
// 0065fb67  6a00                 push 0
// 0065fb69  52                   push edx
// 0065fb6a  6a00                 push 0
// 0065fb6c  50                   push eax
// 0065fb6d  51                   push ecx
// 0065fb6e  ff15f4ee7700         call dword ptr [0x77eef4]
// 0065fb74  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
