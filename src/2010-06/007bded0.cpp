// from server: 100% by auto
// roc 2010-06 007bded0  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bded0
//
// 007bded0  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bded4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bded8  50                   push eax
// 007bded9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bdedd  52                   push edx
// 007bdede  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bdee2  50                   push eax
// 007bdee3  8b4104               mov eax, dword ptr [ecx + 4]
// 007bdee6  52                   push edx
// 007bdee7  50                   push eax
// 007bdee8  ff15b4b99e00         call dword ptr [0x9eb9b4]
// 007bdeee  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
