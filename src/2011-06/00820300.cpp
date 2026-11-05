// from server: 100% by auto
// roc 2011-06 00820300  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820300
//
// 00820300  8b442410             mov eax, dword ptr [esp + 0x10]
// 00820304  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00820308  50                   push eax
// 00820309  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0082030d  52                   push edx
// 0082030e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00820312  50                   push eax
// 00820313  8b4104               mov eax, dword ptr [ecx + 4]
// 00820316  52                   push edx
// 00820317  50                   push eax
// 00820318  ff15e400a400         call dword ptr [0xa400e4]
// 0082031e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
