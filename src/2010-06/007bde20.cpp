// from server: 100% by auto
// roc 2010-06 007bde20  unit: CXTPImageManagerResource::CBitmapDC  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bde20
//
// 007bde20  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bde24  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bde28  50                   push eax
// 007bde29  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bde2d  52                   push edx
// 007bde2e  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007bde32  50                   push eax
// 007bde33  8b4104               mov eax, dword ptr [ecx + 4]
// 007bde36  52                   push edx
// 007bde37  50                   push eax
// 007bde38  ff1534a19e00         call dword ptr [0x9ea134]
// 007bde3e  c21000               ret 0x10
// library mfc-9.0/atlmfc\src\mfc\afxdrawmanager.cpp (function ?Ellipse@CDC@@QAEHHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxdrawmanager.cpp
