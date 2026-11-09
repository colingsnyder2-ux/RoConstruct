// from server: 100% by auto
// roc 2009-06 00732cc0  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732cc0
//
// 00732cc0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00732cc4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00732cc8  50                   push eax
// 00732cc9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00732ccd  52                   push edx
// 00732cce  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00732cd2  50                   push eax
// 00732cd3  8b4104               mov eax, dword ptr [ecx + 4]
// 00732cd6  52                   push edx
// 00732cd7  50                   push eax
// 00732cd8  ff15aced8900         call dword ptr [0x89edac]
// 00732cde  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
