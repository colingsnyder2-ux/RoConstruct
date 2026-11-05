// from server: 100% by auto
// roc 2008-06 006ba820  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba820
//
// 006ba820  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ba824  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ba828  50                   push eax
// 006ba829  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ba82d  52                   push edx
// 006ba82e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ba832  50                   push eax
// 006ba833  8b4104               mov eax, dword ptr [ecx + 4]
// 006ba836  52                   push edx
// 006ba837  50                   push eax
// 006ba838  ff1580208000         call dword ptr [0x802080]
// 006ba83e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
