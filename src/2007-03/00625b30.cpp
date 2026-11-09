// from server: 100% by auto
// roc 2007-03 00625b30  unit: seg_00620000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00625b30
//
// 00625b30  8b442418             mov eax, dword ptr [esp + 0x18]
// 00625b34  8b542410             mov edx, dword ptr [esp + 0x10]
// 00625b38  8b4904               mov ecx, dword ptr [ecx + 4]
// 00625b3b  83c804               or eax, 4
// 00625b3e  50                   push eax
// 00625b3f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00625b43  52                   push edx
// 00625b44  8b542410             mov edx, dword ptr [esp + 0x10]
// 00625b48  50                   push eax
// 00625b49  8b442410             mov eax, dword ptr [esp + 0x10]
// 00625b4d  52                   push edx
// 00625b4e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00625b52  50                   push eax
// 00625b53  8b442430             mov eax, dword ptr [esp + 0x30]
// 00625b57  6a00                 push 0
// 00625b59  52                   push edx
// 00625b5a  6a00                 push 0
// 00625b5c  50                   push eax
// 00625b5d  51                   push ecx
// 00625b5e  ff15f4ee7700         call dword ptr [0x77eef4]
// 00625b64  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdialogex.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHBITMAP__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdialogex.cpp
