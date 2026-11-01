// from server: 100% by auto
// roc 2009-12 00809e10  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00809e10
//
// 00809e10  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809e14  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00809e18  50                   push eax
// 00809e19  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00809e1d  52                   push edx
// 00809e1e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00809e22  50                   push eax
// 00809e23  8b4104               mov eax, dword ptr [ecx + 4]
// 00809e26  52                   push edx
// 00809e27  50                   push eax
// 00809e28  ff15e8b09800         call dword ptr [0x98b0e8]
// 00809e2e  c21000               ret 0x10
// library mfc-8.0/atlmfc\src\mfc\cmdtarg.cpp (function ?ModifyMenuA@CMenu@@QAEHIIIPBD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/cmdtarg.cpp
