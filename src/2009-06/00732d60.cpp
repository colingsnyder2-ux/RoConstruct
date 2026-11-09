// from server: 100% by auto
// roc 2009-06 00732d60  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732d60
//
// 00732d60  8b442410             mov eax, dword ptr [esp + 0x10]
// 00732d64  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00732d68  50                   push eax
// 00732d69  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00732d6d  52                   push edx
// 00732d6e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00732d72  50                   push eax
// 00732d73  8b4104               mov eax, dword ptr [ecx + 4]
// 00732d76  52                   push edx
// 00732d77  50                   push eax
// 00732d78  ff15a4e08900         call dword ptr [0x89e0a4]
// 00732d7e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
