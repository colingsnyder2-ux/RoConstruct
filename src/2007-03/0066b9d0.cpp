// from server: 100% by auto
// roc 2007-03 0066b9d0  unit: seg_00660000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066b9d0
//
// 0066b9d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066b9d4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0066b9d8  50                   push eax
// 0066b9d9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066b9dd  52                   push edx
// 0066b9de  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0066b9e2  50                   push eax
// 0066b9e3  8b4104               mov eax, dword ptr [ecx + 4]
// 0066b9e6  52                   push edx
// 0066b9e7  50                   push eax
// 0066b9e8  ff1550d17700         call dword ptr [0x77d150]
// 0066b9ee  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
