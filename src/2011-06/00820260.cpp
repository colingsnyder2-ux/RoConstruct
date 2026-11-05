// from server: 100% by auto
// roc 2011-06 00820260  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00820260
//
// 00820260  8b442410             mov eax, dword ptr [esp + 0x10]
// 00820264  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00820268  50                   push eax
// 00820269  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0082026d  52                   push edx
// 0082026e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00820272  50                   push eax
// 00820273  8b4104               mov eax, dword ptr [ecx + 4]
// 00820276  52                   push edx
// 00820277  50                   push eax
// 00820278  ff15dc1aa400         call dword ptr [0xa41adc]
// 0082027e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
