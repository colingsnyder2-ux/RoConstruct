// from server: 100% by auto
// roc 2007-03 0066ba80  unit: seg_00660000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0066ba80
//
// 0066ba80  8b442410             mov eax, dword ptr [esp + 0x10]
// 0066ba84  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0066ba88  50                   push eax
// 0066ba89  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0066ba8d  52                   push edx
// 0066ba8e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0066ba92  50                   push eax
// 0066ba93  8b4104               mov eax, dword ptr [ecx + 4]
// 0066ba96  52                   push edx
// 0066ba97  50                   push eax
// 0066ba98  ff15aced7700         call dword ptr [0x77edac]
// 0066ba9e  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
