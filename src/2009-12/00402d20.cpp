// from server: 100% by auto
// roc 2009-12 00402d20  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402d20
//
// 00402d20  56                   push esi
// 00402d21  8bf1                 mov esi, ecx
// 00402d23  8b4620               mov eax, dword ptr [esi + 0x20]
// 00402d26  50                   push eax
// 00402d27  ff15bccb9800         call dword ptr [0x98cbbc]
// 00402d2d  50                   push eax
// 00402d2e  e8f70d3f00           call 0x7f3b2a
// 00402d33  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00402d36  8b5020               mov edx, dword ptr [eax + 0x20]
// 00402d39  6a00                 push 0
// 00402d3b  51                   push ecx
// 00402d3c  6822020000           push 0x222
// 00402d41  52                   push edx
// 00402d42  ff15c4cb9800         call dword ptr [0x98cbc4]
// 00402d48  5e                   pop esi
// 00402d49  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\winmdi.cpp (function ?MDIActivate@CMDIChildWnd@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/winmdi.cpp
