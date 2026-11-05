// from server: 100% by auto
// roc 2009-12 0078a0b0  unit: RBX::UniversalTool  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a0b0
//
// 0078a0b0  53                   push ebx
// 0078a0b1  56                   push esi
// 0078a0b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0078a0b6  57                   push edi
// 0078a0b7  8b7e08               mov edi, dword ptr [esi + 8]
// 0078a0ba  8d442410             lea eax, [esp + 0x10]
// 0078a0be  50                   push eax
// 0078a0bf  6aff                 push -1
// 0078a0c1  57                   push edi
// 0078a0c2  e8d9eaffff           call 0x788ba0
// 0078a0c7  8b0e                 mov ecx, dword ptr [esi]
// 0078a0c9  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0078a0cd  8bde                 mov ebx, esi
// 0078a0cf  2bd9                 sub ebx, ecx
// 0078a0d1  81c30c020000         add ebx, 0x20c
// 0078a0d7  83c40c               add esp, 0xc
// 0078a0da  3bd3                 cmp edx, ebx
// 0078a0dc  771d                 ja 0x78a0fb
// 0078a0de  52                   push edx
// 0078a0df  50                   push eax
// 0078a0e0  51                   push ecx
// 0078a0e1  e800ac0600           call 0x7f4ce6
// 0078a0e6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0078a0ea  010e                 add dword ptr [esi], ecx
// 0078a0ec  6afe                 push -2
// 0078a0ee  57                   push edi
// 0078a0ef  e8bce6ffff           call 0x7887b0
// 0078a0f4  83c414               add esp, 0x14
// 0078a0f7  5f                   pop edi
// 0078a0f8  5e                   pop esi
// 0078a0f9  5b                   pop ebx
// 0078a0fa  c3                   ret 
// 0078a0fb  2bce                 sub ecx, esi
// 0078a0fd  83e90c               sub ecx, 0xc
// 0078a100  741e                 je 0x78a120
// 0078a102  8b5608               mov edx, dword ptr [esi + 8]
// 0078a105  51                   push ecx
// 0078a106  8d5e0c               lea ebx, [esi + 0xc]
// 0078a109  53                   push ebx
// 0078a10a  52                   push edx
// 0078a10b  e890ecffff           call 0x788da0
// 0078a110  ff4604               inc dword ptr [esi + 4]
// 0078a113  6afe                 push -2
// 0078a115  57                   push edi
// 0078a116  891e                 mov dword ptr [esi], ebx
// 0078a118  e833e7ffff           call 0x788850
// 0078a11d  83c414               add esp, 0x14
// 0078a120  ff4604               inc dword ptr [esi + 4]
// 0078a123  56                   push esi
// 0078a124  e837feffff           call 0x789f60
// 0078a129  83c404               add esp, 4
// 0078a12c  5f                   pop edi
// 0078a12d  5e                   pop esi
// 0078a12e  5b                   pop ebx
// 0078a12f  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_addvalue)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
