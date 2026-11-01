// from server: 100% by auto
// roc 2007-03 00600250  unit: seg_00600000  size: 194 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00600250
//
// 00600250  81ec84020000         sub esp, 0x284
// 00600256  8b842490020000       mov eax, dword ptr [esp + 0x290]
// 0060025d  8b942494020000       mov edx, dword ptr [esp + 0x294]
// 00600264  53                   push ebx
// 00600265  89442440             mov dword ptr [esp + 0x40], eax
// 00600269  8bc2                 mov eax, edx
// 0060026b  56                   push esi
// 0060026c  8d7001               lea esi, [eax + 1]
// 0060026f  90                   nop 
// 00600270  8a08                 mov cl, byte ptr [eax]
// 00600272  83c001               add eax, 1
// 00600275  84c9                 test cl, cl
// 00600277  75f7                 jne 0x600270
// 00600279  2bc6                 sub eax, esi
// 0060027b  8bb42490020000       mov esi, dword ptr [esp + 0x290]
// 00600282  50                   push eax
// 00600283  52                   push edx
// 00600284  56                   push esi
// 00600285  e896c4ffff           call 0x5fc720
// 0060028a  8b8c24a0020000       mov ecx, dword ptr [esp + 0x2a0]
// 00600291  50                   push eax
// 00600292  51                   push ecx
// 00600293  8d54241c             lea edx, [esp + 0x1c]
// 00600297  52                   push edx
// 00600298  56                   push esi
// 00600299  e8d20d0000           call 0x601070
// 0060029e  8d44246c             lea eax, [esp + 0x6c]
// 006002a2  8d5c2424             lea ebx, [esp + 0x24]
// 006002a6  e8a5d8ffff           call 0x5fdb50
// 006002ab  8b44246c             mov eax, dword ptr [esp + 0x6c]
// 006002af  8bcb                 mov ecx, ebx
// 006002b1  51                   push ecx
// 006002b2  c6404a02             mov byte ptr [eax + 0x4a], 2
// 006002b6  e8e5200000           call 0x6023a0
// 006002bb  8bd3                 mov edx, ebx
// 006002bd  52                   push edx
// 006002be  e8ddfeffff           call 0x6001a0
// 006002c3  83c424               add esp, 0x24
// 006002c6  817c24181f010000     cmp dword ptr [esp + 0x18], 0x11f
// 006002ce  5e                   pop esi
// 006002cf  5b                   pop ebx
// 006002d0  742c                 je 0x6002fe
// 006002d2  8d0424               lea eax, [esp]
// 006002d5  681f010000           push 0x11f
// 006002da  50                   push eax
// 006002db  e8900b0000           call 0x600e70
// 006002e0  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 006002e4  50                   push eax
// 006002e5  6828047c00           push 0x7c0428
// 006002ea  51                   push ecx
// 006002eb  e85085ffff           call 0x5f8840
// 006002f0  50                   push eax
// 006002f1  8d542418             lea edx, [esp + 0x18]
// 006002f5  52                   push edx
// 006002f6  e8750c0000           call 0x600f70
// 006002fb  83c41c               add esp, 0x1c
// 006002fe  8d0424               lea eax, [esp]
// 00600301  50                   push eax
// 00600302  e8f9d8ffff           call 0x5fdc00
// 00600307  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 0060030b  81c488020000         add esp, 0x288
// 00600311  c3                   ret 
// library lua-5.1.1/lparser.c (function _luaY_parser)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
