// from server: 100% by auto
// roc 2009-12 00809d70  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809d70
//
// 00809d70  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809d74  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00809d78  50                   push eax
// 00809d79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00809d7d  52                   push edx
// 00809d7e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00809d82  50                   push eax
// 00809d83  8b4104               mov eax, dword ptr [ecx + 4]
// 00809d86  52                   push edx
// 00809d87  50                   push eax
// 00809d88  ff1540ca9800         call dword ptr [0x98ca40]
// 00809d8e  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
