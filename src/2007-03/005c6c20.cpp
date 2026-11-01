// from server: 100% by auto
// roc 2007-03 005c6c20  unit: seg_005c0000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c6c20
//
// 005c6c20  51                   push ecx
// 005c6c21  56                   push esi
// 005c6c22  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005c6c26  57                   push edi
// 005c6c27  8d442408             lea eax, [esp + 8]
// 005c6c2b  50                   push eax
// 005c6c2c  6a01                 push 1
// 005c6c2e  56                   push esi
// 005c6c2f  e88c39ffff           call 0x5ba5c0
// 005c6c34  6a00                 push 0
// 005c6c36  8bf8                 mov edi, eax
// 005c6c38  57                   push edi
// 005c6c39  6a02                 push 2
// 005c6c3b  56                   push esi
// 005c6c3c  e8df39ffff           call 0x5ba620
// 005c6c41  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005c6c45  50                   push eax
// 005c6c46  51                   push ecx
// 005c6c47  57                   push edi
// 005c6c48  56                   push esi
// 005c6c49  e87237ffff           call 0x5ba3c0
// 005c6c4e  83c42c               add esp, 0x2c
// 005c6c51  85c0                 test eax, eax
// 005c6c53  7509                 jne 0x5c6c5e
// 005c6c55  5f                   pop edi
// 005c6c56  b801000000           mov eax, 1
// 005c6c5b  5e                   pop esi
// 005c6c5c  59                   pop ecx
// 005c6c5d  c3                   ret 
// 005c6c5e  56                   push esi
// 005c6c5f  e8bc23ffff           call 0x5b9020
// 005c6c64  6afe                 push -2
// 005c6c66  56                   push esi
// 005c6c67  e8941effff           call 0x5b8b00
// 005c6c6c  83c40c               add esp, 0xc
// 005c6c6f  5f                   pop edi
// 005c6c70  b802000000           mov eax, 2
// 005c6c75  5e                   pop esi
// 005c6c76  59                   pop ecx
// 005c6c77  c3                   ret 
// library lua-5.1.1/lbaselib.c (function _luaB_loadstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lbaselib.c
