// from server: 100% by auto
// roc 2009-06 006b9180  unit: RBX::UniversalTool  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b9180
//
// 006b9180  56                   push esi
// 006b9181  8b742408             mov esi, dword ptr [esp + 8]
// 006b9185  57                   push edi
// 006b9186  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006b918a  8bc7                 mov eax, edi
// 006b918c  8bce                 mov ecx, esi
// 006b918e  e83dfaffff           call 0x6b8bd0
// 006b9193  83780804             cmp dword ptr [eax + 8], 4
// 006b9197  743e                 je 0x6b91d7
// 006b9199  50                   push eax
// 006b919a  56                   push esi
// 006b919b  e8400d0300           call 0x6e9ee0
// 006b91a0  83c408               add esp, 8
// 006b91a3  85c0                 test eax, eax
// 006b91a5  7513                 jne 0x6b91ba
// 006b91a7  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b91ab  85c0                 test eax, eax
// 006b91ad  7406                 je 0x6b91b5
// 006b91af  c70000000000         mov dword ptr [eax], 0
// 006b91b5  5f                   pop edi
// 006b91b6  33c0                 xor eax, eax
// 006b91b8  5e                   pop esi
// 006b91b9  c3                   ret 
// 006b91ba  8b4610               mov eax, dword ptr [esi + 0x10]
// 006b91bd  8b4844               mov ecx, dword ptr [eax + 0x44]
// 006b91c0  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 006b91c3  7209                 jb 0x6b91ce
// 006b91c5  56                   push esi
// 006b91c6  e8f5090300           call 0x6e9bc0
// 006b91cb  83c404               add esp, 4
// 006b91ce  8bc7                 mov eax, edi
// 006b91d0  8bce                 mov ecx, esi
// 006b91d2  e8f9f9ffff           call 0x6b8bd0
// 006b91d7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006b91db  85c9                 test ecx, ecx
// 006b91dd  7407                 je 0x6b91e6
// 006b91df  8b10                 mov edx, dword ptr [eax]
// 006b91e1  8b520c               mov edx, dword ptr [edx + 0xc]
// 006b91e4  8911                 mov dword ptr [ecx], edx
// 006b91e6  8b00                 mov eax, dword ptr [eax]
// 006b91e8  5f                   pop edi
// 006b91e9  83c010               add eax, 0x10
// 006b91ec  5e                   pop esi
// 006b91ed  c3                   ret 
// library lua-5.1/lapi.c (function _lua_tolstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
