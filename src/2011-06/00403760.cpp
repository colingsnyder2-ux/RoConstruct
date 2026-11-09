// from server: 100% by auto
// roc 2011-06 00403760  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00403760
//
// 00403760  56                   push esi
// 00403761  8bf1                 mov esi, ecx
// 00403763  8b4620               mov eax, dword ptr [esi + 0x20]
// 00403766  50                   push eax
// 00403767  ff15b819a400         call dword ptr [0xa419b8]
// 0040376d  50                   push eax
// 0040376e  e8b56b4000           call 0x80a328
// 00403773  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00403776  8b5020               mov edx, dword ptr [eax + 0x20]
// 00403779  6a00                 push 0
// 0040377b  51                   push ecx
// 0040377c  6822020000           push 0x222
// 00403781  52                   push edx
// 00403782  ff15c019a400         call dword ptr [0xa419c0]
// 00403788  5e                   pop esi
// 00403789  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winmdi.cpp (function ?MDIActivate@CMDIChildWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winmdi.cpp
