// from server: 100% by auto
// roc 2009-12 00809cc0  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809cc0
//
// 00809cc0  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809cc4  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00809cc8  50                   push eax
// 00809cc9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00809ccd  52                   push edx
// 00809cce  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00809cd2  50                   push eax
// 00809cd3  8b4104               mov eax, dword ptr [ecx + 4]
// 00809cd6  52                   push edx
// 00809cd7  50                   push eax
// 00809cd8  ff15ecb09800         call dword ptr [0x98b0ec]
// 00809cde  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
