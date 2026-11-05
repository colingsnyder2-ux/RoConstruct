// roc 2009-12 00788cd0  unit: RBX::UniversalTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788cd0
//
// 00788cd0  56                   push esi
// 00788cd1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00788cd5  57                   push edi
// 00788cd6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00788cda  8bc6                 mov eax, esi
// 00788cdc  8bcf                 mov ecx, edi
// 00788cde  e80df9ffff           call 0x7885f0
// 00788ce3  8b4808               mov ecx, dword ptr [eax + 8]
// 00788ce6  83c1fe               add ecx, -2
// 00788ce9  83f906               cmp ecx, 6
// 00788cec  772a                 ja 0x788d18
// 00788cee  ff248d208d7800       jmp dword ptr [ecx*4 + 0x788d20]
// 00788cf5  8b00                 mov eax, dword ptr [eax]
// 00788cf7  5f                   pop edi
// 00788cf8  5e                   pop esi
// 00788cf9  c3                   ret 
// 00788cfa  8bc6                 mov eax, esi
// 00788cfc  8bcf                 mov ecx, edi
// 00788cfe  e8edf8ffff           call 0x7885f0
// 00788d03  8b4808               mov ecx, dword ptr [eax + 8]
// 00788d06  83e902               sub ecx, 2
// 00788d09  74ea                 je 0x788cf5
// 00788d0b  83e905               sub ecx, 5
// 00788d0e  7508                 jne 0x788d18
// 00788d10  8b00                 mov eax, dword ptr [eax]
// 00788d12  5f                   pop edi
// 00788d13  83c018               add eax, 0x18
// 00788d16  5e                   pop esi
// 00788d17  c3                   ret 
// 00788d18  5f                   pop edi
// 00788d19  33c0                 xor eax, eax
// 00788d1b  5e                   pop esi
// 00788d1c  c3                   ret 
// 00788d1d  8d4900               lea ecx, [ecx]
// 00788d20  fa                   cli 
// library lua-5.1/lapi.c (function _lua_topointer)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
