// from server: 100% by auto
// roc 2007-08 006802c0  unit: CXTPBufferDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006802c0
//
// 006802c0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006802c4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006802c8  50                   push eax
// 006802c9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006802cd  52                   push edx
// 006802ce  8b54240c             mov edx, dword ptr [esp + 0xc]
// 006802d2  50                   push eax
// 006802d3  8b4104               mov eax, dword ptr [ecx + 4]
// 006802d6  52                   push edx
// 006802d7  50                   push eax
// 006802d8  ff1578d07700         call dword ptr [0x77d078]
// 006802de  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
