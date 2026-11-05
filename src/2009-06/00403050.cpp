// from server: 100% by auto
// roc 2009-06 00403050  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00403050
//
// 00403050  56                   push esi
// 00403051  8bf1                 mov esi, ecx
// 00403053  8b4620               mov eax, dword ptr [esi + 0x20]
// 00403056  50                   push eax
// 00403057  ff1598ee8900         call dword ptr [0x89ee98]
// 0040305d  50                   push eax
// 0040305e  e89f5c3100           call 0x718d02
// 00403063  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00403066  8b5020               mov edx, dword ptr [eax + 0x20]
// 00403069  6a00                 push 0
// 0040306b  51                   push ecx
// 0040306c  6822020000           push 0x222
// 00403071  52                   push edx
// 00403072  ff1590ee8900         call dword ptr [0x89ee90]
// 00403078  5e                   pop esi
// 00403079  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winmdi.cpp (function ?MDIActivate@CMDIChildWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winmdi.cpp
