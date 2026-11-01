// from server: 100% by auto
// roc 2007-03 005fd4d0  unit: seg_005f0000  size: 104 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fd4d0
//
// 005fd4d0  397e10               cmp dword ptr [esi + 0x10], edi
// 005fd4d3  7509                 jne 0x5fd4de
// 005fd4d5  89742404             mov dword ptr [esp + 4], esi
// 005fd4d9  e9c24e0000           jmp 0x6023a0
// 005fd4de  3b4604               cmp eax, dword ptr [esi + 4]
// 005fd4e1  7521                 jne 0x5fd504
// 005fd4e3  57                   push edi
// 005fd4e4  56                   push esi
// 005fd4e5  e886390000           call 0x600e70
// 005fd4ea  50                   push eax
// 005fd4eb  8b4634               mov eax, dword ptr [esi + 0x34]
// 005fd4ee  6828047c00           push 0x7c0428
// 005fd4f3  50                   push eax
// 005fd4f4  e847b3ffff           call 0x5f8840
// 005fd4f9  50                   push eax
// 005fd4fa  56                   push esi
// 005fd4fb  e8703a0000           call 0x600f70
// 005fd500  83c41c               add esp, 0x1c
// 005fd503  c3                   ret 
// 005fd504  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005fd508  50                   push eax
// 005fd509  51                   push ecx
// 005fd50a  56                   push esi
// 005fd50b  e860390000           call 0x600e70
// 005fd510  83c408               add esp, 8
// 005fd513  50                   push eax
// 005fd514  57                   push edi
// 005fd515  56                   push esi
// 005fd516  e855390000           call 0x600e70
// 005fd51b  8b5634               mov edx, dword ptr [esi + 0x34]
// 005fd51e  83c408               add esp, 8
// 005fd521  50                   push eax
// 005fd522  6884047c00           push 0x7c0484
// 005fd527  52                   push edx
// 005fd528  e813b3ffff           call 0x5f8840
// 005fd52d  50                   push eax
// 005fd52e  56                   push esi
// 005fd52f  e83c3a0000           call 0x600f70
// 005fd534  83c41c               add esp, 0x1c
// 005fd537  c3                   ret 
// library lua-5.1.1/lparser.c (function _check_match)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
