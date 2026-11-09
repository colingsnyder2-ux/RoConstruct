// from server: 100% by auto
// roc 2007-08 005c8680  unit: lua_exception  size: 144 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c8680
//
// 005c8680  56                   push esi
// 005c8681  8bf0                 mov esi, eax
// 005c8683  8b4620               mov eax, dword ptr [esi + 0x20]
// 005c8686  57                   push edi
// 005c8687  8b7e10               mov edi, dword ptr [esi + 0x10]
// 005c868a  50                   push eax
// 005c868b  56                   push esi
// 005c868c  e82faa0400           call 0x6130c0
// 005c8691  56                   push esi
// 005c8692  e8a9730400           call 0x60fa40
// 005c8697  8b4610               mov eax, dword ptr [esi + 0x10]
// 005c869a  8b4808               mov ecx, dword ptr [eax + 8]
// 005c869d  8b10                 mov edx, dword ptr [eax]
// 005c869f  03c9                 add ecx, ecx
// 005c86a1  6a00                 push 0
// 005c86a3  03c9                 add ecx, ecx
// 005c86a5  51                   push ecx
// 005c86a6  52                   push edx
// 005c86a7  56                   push esi
// 005c86a8  e843b30400           call 0x6139f0
// 005c86ad  8b473c               mov eax, dword ptr [edi + 0x3c]
// 005c86b0  8b4f34               mov ecx, dword ptr [edi + 0x34]
// 005c86b3  6a00                 push 0
// 005c86b5  50                   push eax
// 005c86b6  51                   push ecx
// 005c86b7  56                   push esi
// 005c86b8  e833b30400           call 0x6139f0
// 005c86bd  894734               mov dword ptr [edi + 0x34], eax
// 005c86c0  c7473c00000000       mov dword ptr [edi + 0x3c], 0
// 005c86c7  8b4630               mov eax, dword ptr [esi + 0x30]
// 005c86ca  8d1440               lea edx, [eax + eax*2]
// 005c86cd  8b4628               mov eax, dword ptr [esi + 0x28]
// 005c86d0  03d2                 add edx, edx
// 005c86d2  03d2                 add edx, edx
// 005c86d4  6a00                 push 0
// 005c86d6  03d2                 add edx, edx
// 005c86d8  52                   push edx
// 005c86d9  50                   push eax
// 005c86da  56                   push esi
// 005c86db  e810b30400           call 0x6139f0
// 005c86e0  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 005c86e3  8b5620               mov edx, dword ptr [esi + 0x20]
// 005c86e6  6a00                 push 0
// 005c86e8  c1e104               shl ecx, 4
// 005c86eb  51                   push ecx
// 005c86ec  52                   push edx
// 005c86ed  56                   push esi
// 005c86ee  e8fdb20400           call 0x6139f0
// 005c86f3  8b4710               mov eax, dword ptr [edi + 0x10]
// 005c86f6  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 005c86f9  83c44c               add esp, 0x4c
// 005c86fc  6a00                 push 0
// 005c86fe  6884010000           push 0x184
// 005c8703  83c6f4               add esi, -0xc
// 005c8706  56                   push esi
// 005c8707  50                   push eax
// 005c8708  ffd1                 call ecx
// 005c870a  83c410               add esp, 0x10
// 005c870d  5f                   pop edi
// 005c870e  5e                   pop esi
// 005c870f  c3                   ret 
// library lua-5.1.2-rbx/lstate.c (function _close_state)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2-rbx lstate.c
