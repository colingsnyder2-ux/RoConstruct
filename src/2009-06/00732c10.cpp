// from server: 100% by auto
// roc 2009-06 00732c10  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00732c10
//
// 00732c10  8b442410             mov eax, dword ptr [esp + 0x10]
// 00732c14  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00732c18  50                   push eax
// 00732c19  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00732c1d  52                   push edx
// 00732c1e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00732c22  50                   push eax
// 00732c23  8b4104               mov eax, dword ptr [ecx + 4]
// 00732c26  52                   push edx
// 00732c27  50                   push eax
// 00732c28  ff15a8e08900         call dword ptr [0x89e0a8]
// 00732c2e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
