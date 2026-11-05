// from server: 100% by auto
// roc 2009-06 0072d850  unit: CXTPCommandBar  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0072d850
//
// 0072d850  8b442414             mov eax, dword ptr [esp + 0x14]
// 0072d854  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072d858  8b4904               mov ecx, dword ptr [ecx + 4]
// 0072d85b  50                   push eax
// 0072d85c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0072d860  52                   push edx
// 0072d861  8b542410             mov edx, dword ptr [esp + 0x10]
// 0072d865  50                   push eax
// 0072d866  8b442410             mov eax, dword ptr [esp + 0x10]
// 0072d86a  52                   push edx
// 0072d86b  50                   push eax
// 0072d86c  51                   push ecx
// 0072d86d  ff15c8e08900         call dword ptr [0x89e0c8]
// 0072d873  c21400               ret 0x14
// library mfc-9.0/atlmfc\src\mfc\afxoutlookbartabctrl.cpp (function ?PatBlt@CDC@@QAEHHHHHK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxoutlookbartabctrl.cpp
