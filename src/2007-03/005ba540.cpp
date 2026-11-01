// from server: 100% by auto
// roc 2007-03 005ba540  unit: seg_005b0000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ba540
//
// 005ba540  56                   push esi
// 005ba541  8b742408             mov esi, dword ptr [esp + 8]
// 005ba545  57                   push edi
// 005ba546  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005ba54a  57                   push edi
// 005ba54b  56                   push esi
// 005ba54c  e8efe6ffff           call 0x5b8c40
// 005ba551  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005ba555  83c408               add esp, 8
// 005ba558  3bc1                 cmp eax, ecx
// 005ba55a  7431                 je 0x5ba58d
// 005ba55c  53                   push ebx
// 005ba55d  51                   push ecx
// 005ba55e  56                   push esi
// 005ba55f  e8fce6ffff           call 0x5b8c60
// 005ba564  57                   push edi
// 005ba565  56                   push esi
// 005ba566  8bd8                 mov ebx, eax
// 005ba568  e8d3e6ffff           call 0x5b8c40
// 005ba56d  50                   push eax
// 005ba56e  56                   push esi
// 005ba56f  e8ece6ffff           call 0x5b8c60
// 005ba574  50                   push eax
// 005ba575  53                   push ebx
// 005ba576  68dc917b00           push 0x7b91dc
// 005ba57b  56                   push esi
// 005ba57c  e8dfebffff           call 0x5b9160
// 005ba581  50                   push eax
// 005ba582  57                   push edi
// 005ba583  56                   push esi
// 005ba584  e867feffff           call 0x5ba3f0
// 005ba589  83c434               add esp, 0x34
// 005ba58c  5b                   pop ebx
// 005ba58d  5f                   pop edi
// 005ba58e  5e                   pop esi
// 005ba58f  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_checktype)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
