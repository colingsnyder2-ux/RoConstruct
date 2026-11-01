// from server: 100% by auto
// roc 2007-03 005b8e50  unit: seg_005b0000  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8e50
//
// 005b8e50  56                   push esi
// 005b8e51  8b742408             mov esi, dword ptr [esp + 8]
// 005b8e55  57                   push edi
// 005b8e56  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b8e5a  8bc7                 mov eax, edi
// 005b8e5c  8bce                 mov ecx, esi
// 005b8e5e  e84dfaffff           call 0x5b88b0
// 005b8e63  83780804             cmp dword ptr [eax + 8], 4
// 005b8e67  743e                 je 0x5b8ea7
// 005b8e69  50                   push eax
// 005b8e6a  56                   push esi
// 005b8e6b  e8600c0400           call 0x5f9ad0
// 005b8e70  83c408               add esp, 8
// 005b8e73  85c0                 test eax, eax
// 005b8e75  7513                 jne 0x5b8e8a
// 005b8e77  8b442414             mov eax, dword ptr [esp + 0x14]
// 005b8e7b  85c0                 test eax, eax
// 005b8e7d  7406                 je 0x5b8e85
// 005b8e7f  c70000000000         mov dword ptr [eax], 0
// 005b8e85  5f                   pop edi
// 005b8e86  33c0                 xor eax, eax
// 005b8e88  5e                   pop esi
// 005b8e89  c3                   ret 
// 005b8e8a  8b4610               mov eax, dword ptr [esi + 0x10]
// 005b8e8d  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005b8e90  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005b8e93  7209                 jb 0x5b8e9e
// 005b8e95  56                   push esi
// 005b8e96  e815090400           call 0x5f97b0
// 005b8e9b  83c404               add esp, 4
// 005b8e9e  8bc7                 mov eax, edi
// 005b8ea0  8bce                 mov ecx, esi
// 005b8ea2  e809faffff           call 0x5b88b0
// 005b8ea7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005b8eab  85c9                 test ecx, ecx
// 005b8ead  7407                 je 0x5b8eb6
// 005b8eaf  8b10                 mov edx, dword ptr [eax]
// 005b8eb1  8b520c               mov edx, dword ptr [edx + 0xc]
// 005b8eb4  8911                 mov dword ptr [ecx], edx
// 005b8eb6  8b00                 mov eax, dword ptr [eax]
// 005b8eb8  5f                   pop edi
// 005b8eb9  83c010               add eax, 0x10
// 005b8ebc  5e                   pop esi
// 005b8ebd  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
