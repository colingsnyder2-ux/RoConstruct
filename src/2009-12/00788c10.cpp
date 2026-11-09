// roc 2009-12 00788c10  unit: RBX::UniversalTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788c10
//
// 00788c10  8b442408             mov eax, dword ptr [esp + 8]
// 00788c14  56                   push esi
// 00788c15  57                   push edi
// 00788c16  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00788c1a  8bcf                 mov ecx, edi
// 00788c1c  e8cff9ffff           call 0x7885f0
// 00788c21  8bf0                 mov esi, eax
// 00788c23  8b4608               mov eax, dword ptr [esi + 8]
// 00788c26  83c0fd               add eax, -3
// 00788c29  83f804               cmp eax, 4
// 00788c2c  7733                 ja 0x788c61
// 00788c2e  ff2485688c7800       jmp dword ptr [eax*4 + 0x788c68]
// 00788c35  8b06                 mov eax, dword ptr [esi]
// 00788c37  8b400c               mov eax, dword ptr [eax + 0xc]
// 00788c3a  5f                   pop edi
// 00788c3b  5e                   pop esi
// 00788c3c  c3                   ret 
// 00788c3d  8b0e                 mov ecx, dword ptr [esi]
// 00788c3f  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00788c42  5f                   pop edi
// 00788c43  5e                   pop esi
// 00788c44  c3                   ret 
// 00788c45  8b16                 mov edx, dword ptr [esi]
// 00788c47  52                   push edx
// 00788c48  e8f3780400           call 0x7d0540
// 00788c4d  83c404               add esp, 4
// 00788c50  5f                   pop edi
// 00788c51  5e                   pop esi
// 00788c52  c3                   ret 
// 00788c53  56                   push esi
// 00788c54  57                   push edi
// 00788c55  e8d6520400           call 0x7cdf30
// 00788c5a  83c408               add esp, 8
// 00788c5d  85c0                 test eax, eax
// 00788c5f  75d4                 jne 0x788c35
// 00788c61  5f                   pop edi
// 00788c62  33c0                 xor eax, eax
// 00788c64  5e                   pop esi
// 00788c65  c3                   ret 
// 00788c66  8bff                 mov edi, edi
// 00788c68  53                   push ebx
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
