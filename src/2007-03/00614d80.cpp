// from server: 100% by auto
// roc 2007-03 00614d80  unit: seg_00610000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614d80
//
// 00614d80  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00614d84  56                   push esi
// 00614d85  8b742408             mov esi, dword ptr [esp + 8]
// 00614d89  8b460c               mov eax, dword ptr [esi + 0xc]
// 00614d8c  8b4808               mov ecx, dword ptr [eax + 8]
// 00614d8f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00614d93  83c201               add edx, 1
// 00614d96  c1e217               shl edx, 0x17
// 00614d99  c1e006               shl eax, 6
// 00614d9c  0bd0                 or edx, eax
// 00614d9e  51                   push ecx
// 00614d9f  83ca1e               or edx, 0x1e
// 00614da2  52                   push edx
// 00614da3  e868fdffff           call 0x614b10
// 00614da8  83c408               add esp, 8
// 00614dab  5e                   pop esi
// 00614dac  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_ret)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
