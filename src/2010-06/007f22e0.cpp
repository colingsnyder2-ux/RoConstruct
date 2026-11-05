// from server: 100% by auto
// roc 2010-06 007f22e0  unit: CXTPCustomizeSheet  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f22e0
//
// 007f22e0  8b442418             mov eax, dword ptr [esp + 0x18]
// 007f22e4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007f22e8  8b4904               mov ecx, dword ptr [ecx + 4]
// 007f22eb  83c803               or eax, 3
// 007f22ee  50                   push eax
// 007f22ef  8b442410             mov eax, dword ptr [esp + 0x10]
// 007f22f3  52                   push edx
// 007f22f4  8b542410             mov edx, dword ptr [esp + 0x10]
// 007f22f8  50                   push eax
// 007f22f9  8b442410             mov eax, dword ptr [esp + 0x10]
// 007f22fd  52                   push edx
// 007f22fe  8b542424             mov edx, dword ptr [esp + 0x24]
// 007f2302  50                   push eax
// 007f2303  8b442430             mov eax, dword ptr [esp + 0x30]
// 007f2307  6a00                 push 0
// 007f2309  52                   push edx
// 007f230a  6a00                 push 0
// 007f230c  50                   push eax
// 007f230d  51                   push ecx
// 007f230e  ff15a8ba9e00         call dword ptr [0x9ebaa8]
// 007f2314  c21c00               ret 0x1c
// library mfc-9.0/atlmfc\src\mfc\afxdesktopalertwnd.cpp (function ?DrawState@CDC@@QAEHVCPoint@@VCSize@@PAUHICON__@@IPAUHBRUSH__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdesktopalertwnd.cpp
