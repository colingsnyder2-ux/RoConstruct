// from server: 100% by auto
// roc 2008-06 006ba780  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006ba780
//
// 006ba780  8b442410             mov eax, dword ptr [esp + 0x10]
// 006ba784  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ba788  50                   push eax
// 006ba789  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006ba78d  52                   push edx
// 006ba78e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006ba792  50                   push eax
// 006ba793  8b4104               mov eax, dword ptr [ecx + 4]
// 006ba796  52                   push edx
// 006ba797  50                   push eax
// 006ba798  ff15182d8000         call dword ptr [0x802d18]
// 006ba79e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
