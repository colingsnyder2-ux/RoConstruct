// from server: 100% by auto
// roc 2009-12 00788ba0  unit: RBX::UniversalTool  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788ba0
//
// 00788ba0  56                   push esi
// 00788ba1  8b742408             mov esi, dword ptr [esp + 8]
// 00788ba5  57                   push edi
// 00788ba6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00788baa  8bc7                 mov eax, edi
// 00788bac  8bce                 mov ecx, esi
// 00788bae  e83dfaffff           call 0x7885f0
// 00788bb3  83780804             cmp dword ptr [eax + 8], 4
// 00788bb7  743e                 je 0x788bf7
// 00788bb9  50                   push eax
// 00788bba  56                   push esi
// 00788bbb  e870530400           call 0x7cdf30
// 00788bc0  83c408               add esp, 8
// 00788bc3  85c0                 test eax, eax
// 00788bc5  7513                 jne 0x788bda
// 00788bc7  8b442414             mov eax, dword ptr [esp + 0x14]
// 00788bcb  85c0                 test eax, eax
// 00788bcd  7406                 je 0x788bd5
// 00788bcf  c70000000000         mov dword ptr [eax], 0
// 00788bd5  5f                   pop edi
// 00788bd6  33c0                 xor eax, eax
// 00788bd8  5e                   pop esi
// 00788bd9  c3                   ret 
// 00788bda  8b4610               mov eax, dword ptr [esi + 0x10]
// 00788bdd  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00788be0  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00788be3  7209                 jb 0x788bee
// 00788be5  56                   push esi
// 00788be6  e825500400           call 0x7cdc10
// 00788beb  83c404               add esp, 4
// 00788bee  8bc7                 mov eax, edi
// 00788bf0  8bce                 mov ecx, esi
// 00788bf2  e8f9f9ffff           call 0x7885f0
// 00788bf7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00788bfb  85c9                 test ecx, ecx
// 00788bfd  7407                 je 0x788c06
// 00788bff  8b10                 mov edx, dword ptr [eax]
// 00788c01  8b520c               mov edx, dword ptr [edx + 0xc]
// 00788c04  8911                 mov dword ptr [ecx], edx
// 00788c06  8b00                 mov eax, dword ptr [eax]
// 00788c08  5f                   pop edi
// 00788c09  83c010               add eax, 0x10
// 00788c0c  5e                   pop esi
// 00788c0d  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
