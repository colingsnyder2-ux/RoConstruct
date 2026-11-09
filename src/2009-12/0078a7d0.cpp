// from server: 100% by auto
// roc 2009-12 0078a7d0  unit: RBX::UniversalTool  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a7d0
//
// 0078a7d0  56                   push esi
// 0078a7d1  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a7d5  57                   push edi
// 0078a7d6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0078a7da  56                   push esi
// 0078a7db  57                   push edi
// 0078a7dc  e8afe1ffff           call 0x788990
// 0078a7e1  83c408               add esp, 8
// 0078a7e4  85c0                 test eax, eax
// 0078a7e6  7f2d                 jg 0x78a815
// 0078a7e8  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0078a7ec  8b442414             mov eax, dword ptr [esp + 0x14]
// 0078a7f0  85ff                 test edi, edi
// 0078a7f2  7430                 je 0x78a824
// 0078a7f4  85c0                 test eax, eax
// 0078a7f6  7416                 je 0x78a80e
// 0078a7f8  8bc8                 mov ecx, eax
// 0078a7fa  8d7101               lea esi, [ecx + 1]
// 0078a7fd  8d4900               lea ecx, [ecx]
// 0078a800  8a11                 mov dl, byte ptr [ecx]
// 0078a802  41                   inc ecx
// 0078a803  84d2                 test dl, dl
// 0078a805  75f9                 jne 0x78a800
// 0078a807  2bce                 sub ecx, esi
// 0078a809  890f                 mov dword ptr [edi], ecx
// 0078a80b  5f                   pop edi
// 0078a80c  5e                   pop esi
// 0078a80d  c3                   ret 
// 0078a80e  33c9                 xor ecx, ecx
// 0078a810  890f                 mov dword ptr [edi], ecx
// 0078a812  5f                   pop edi
// 0078a813  5e                   pop esi
// 0078a814  c3                   ret 
// 0078a815  8b442418             mov eax, dword ptr [esp + 0x18]
// 0078a819  50                   push eax
// 0078a81a  56                   push esi
// 0078a81b  57                   push edi
// 0078a81c  e84fffffff           call 0x78a770
// 0078a821  83c40c               add esp, 0xc
// 0078a824  5f                   pop edi
// 0078a825  5e                   pop esi
// 0078a826  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_optlstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
