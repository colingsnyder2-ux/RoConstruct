// from server: 100% by auto
// roc 2011-06 008201b0  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008201b0
//
// 008201b0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008201b4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008201b8  50                   push eax
// 008201b9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008201bd  52                   push edx
// 008201be  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008201c2  50                   push eax
// 008201c3  8b4104               mov eax, dword ptr [ecx + 4]
// 008201c6  52                   push edx
// 008201c7  50                   push eax
// 008201c8  ff157001a400         call dword ptr [0xa40170]
// 008201ce  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
