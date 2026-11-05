// from server: 100% by auto
// roc 2007-08 00680170  unit: CXTPBufferDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00680170
//
// 00680170  8b442410             mov eax, dword ptr [esp + 0x10]
// 00680174  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00680178  50                   push eax
// 00680179  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0068017d  52                   push edx
// 0068017e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00680182  50                   push eax
// 00680183  8b4104               mov eax, dword ptr [ecx + 4]
// 00680186  52                   push edx
// 00680187  50                   push eax
// 00680188  ff1574d07700         call dword ptr [0x77d074]
// 0068018e  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
