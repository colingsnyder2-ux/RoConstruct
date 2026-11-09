// from server: 100% by auto
// roc 2007-08 00680220  unit: CXTPBufferDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00680220
//
// 00680220  8b442410             mov eax, dword ptr [esp + 0x10]
// 00680224  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00680228  50                   push eax
// 00680229  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068022d  52                   push edx
// 0068022e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00680232  50                   push eax
// 00680233  8b4104               mov eax, dword ptr [ecx + 4]
// 00680236  52                   push edx
// 00680237  50                   push eax
// 00680238  ff1580ed7700         call dword ptr [0x77ed80]
// 0068023e  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
