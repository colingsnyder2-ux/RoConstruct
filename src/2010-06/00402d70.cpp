// from server: 100% by auto
// roc 2010-06 00402d70  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402d70
//
// 00402d70  56                   push esi
// 00402d71  8bf1                 mov esi, ecx
// 00402d73  8b4620               mov eax, dword ptr [esi + 0x20]
// 00402d76  50                   push eax
// 00402d77  ff154cba9e00         call dword ptr [0x9eba4c]
// 00402d7d  50                   push eax
// 00402d7e  e8e74e3a00           call 0x7a7c6a
// 00402d83  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00402d86  8b5020               mov edx, dword ptr [eax + 0x20]
// 00402d89  6a00                 push 0
// 00402d8b  51                   push ecx
// 00402d8c  6822020000           push 0x222
// 00402d91  52                   push edx
// 00402d92  ff1554ba9e00         call dword ptr [0x9eba54]
// 00402d98  5e                   pop esi
// 00402d99  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\winmdi.cpp (function ?MDIActivate@CMDIChildWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/winmdi.cpp
