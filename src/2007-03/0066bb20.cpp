// from server: 100% by auto
// roc 2007-03 0066bb20  unit: seg_00660000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066bb20
//
// 0066bb20  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066bb24  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0066bb28  50                   push eax
// 0066bb29  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066bb2d  52                   push edx
// 0066bb2e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0066bb32  50                   push eax
// 0066bb33  8b4104               mov eax, dword ptr [ecx + 4]
// 0066bb36  52                   push edx
// 0066bb37  50                   push eax
// 0066bb38  ff1554d17700         call dword ptr [0x77d154]
// 0066bb3e  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
