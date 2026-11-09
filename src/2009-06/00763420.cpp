// from server: 100% by auto
// roc 2009-06 00763420  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00763420
//
// 00763420  8b442418             mov eax, dword ptr [esp + 0x18]
// 00763424  8b542410             mov edx, dword ptr [esp + 0x10]
// 00763428  8b4904               mov ecx, dword ptr [ecx + 4]
// 0076342b  83c803               or eax, 3
// 0076342e  50                   push eax
// 0076342f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00763433  52                   push edx
// 00763434  8b542410             mov edx, dword ptr [esp + 0x10]
// 00763438  50                   push eax
// 00763439  8b442410             mov eax, dword ptr [esp + 0x10]
// 0076343d  52                   push edx
// 0076343e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00763442  50                   push eax
// 00763443  8b442430             mov eax, dword ptr [esp + 0x30]
// 00763447  6a00                 push 0
// 00763449  52                   push edx
// 0076344a  6a00                 push 0
// 0076344c  50                   push eax
// 0076344d  51                   push ecx
// 0076344e  ff150cef8900         call dword ptr [0x89ef0c]
// 00763454  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
