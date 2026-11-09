// from server: 100% by auto
// roc 2008-06 006ba6d0  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba6d0
//
// 006ba6d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ba6d4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ba6d8  50                   push eax
// 006ba6d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ba6dd  52                   push edx
// 006ba6de  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ba6e2  50                   push eax
// 006ba6e3  8b4104               mov eax, dword ptr [ecx + 4]
// 006ba6e6  52                   push edx
// 006ba6e7  50                   push eax
// 006ba6e8  ff1584208000         call dword ptr [0x802084]
// 006ba6ee  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
