// from server: 100% by auto
// roc 2010-06 007bdf70  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bdf70
//
// 007bdf70  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bdf74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bdf78  50                   push eax
// 007bdf79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bdf7d  52                   push edx
// 007bdf7e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bdf82  50                   push eax
// 007bdf83  8b4104               mov eax, dword ptr [ecx + 4]
// 007bdf86  52                   push edx
// 007bdf87  50                   push eax
// 007bdf88  ff1530a19e00         call dword ptr [0x9ea130]
// 007bdf8e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
