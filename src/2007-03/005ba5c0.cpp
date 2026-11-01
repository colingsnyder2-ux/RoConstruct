// from server: 100% by auto
// roc 2007-03 005ba5c0  unit: seg_005b0000  size: 88 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba5c0
//
// 005ba5c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005ba5c4  53                   push ebx
// 005ba5c5  56                   push esi
// 005ba5c6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 005ba5ca  57                   push edi
// 005ba5cb  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005ba5cf  50                   push eax
// 005ba5d0  57                   push edi
// 005ba5d1  56                   push esi
// 005ba5d2  e879e8ffff           call 0x5b8e50
// 005ba5d7  8bd8                 mov ebx, eax
// 005ba5d9  83c40c               add esp, 0xc
// 005ba5dc  85db                 test ebx, ebx
// 005ba5de  7534                 jne 0x5ba614
// 005ba5e0  55                   push ebp
// 005ba5e1  6a04                 push 4
// 005ba5e3  56                   push esi
// 005ba5e4  e877e6ffff           call 0x5b8c60
// 005ba5e9  57                   push edi
// 005ba5ea  56                   push esi
// 005ba5eb  8be8                 mov ebp, eax
// 005ba5ed  e84ee6ffff           call 0x5b8c40
// 005ba5f2  50                   push eax
// 005ba5f3  56                   push esi
// 005ba5f4  e867e6ffff           call 0x5b8c60
// 005ba5f9  50                   push eax
// 005ba5fa  55                   push ebp
// 005ba5fb  68dc917b00           push 0x7b91dc
// 005ba600  56                   push esi
// 005ba601  e85aebffff           call 0x5b9160
// 005ba606  50                   push eax
// 005ba607  57                   push edi
// 005ba608  56                   push esi
// 005ba609  e8e2fdffff           call 0x5ba3f0
// 005ba60e  83c434               add esp, 0x34
// 005ba611  8bc3                 mov eax, ebx
// 005ba613  5d                   pop ebp
// 005ba614  5f                   pop edi
// 005ba615  5e                   pop esi
// 005ba616  5b                   pop ebx
// 005ba617  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checklstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
