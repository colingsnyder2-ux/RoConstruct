// from server: 100% by auto
// roc 2007-03 005ffed0  unit: seg_005f0000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005ffed0
//
// 005ffed0  83ec20               sub esp, 0x20
// 005ffed3  53                   push ebx
// 005ffed4  56                   push esi
// 005ffed5  57                   push edi
// 005ffed6  8bf0                 mov esi, eax
// 005ffed8  8b5e30               mov ebx, dword ptr [esi + 0x30]
// 005ffedb  8d7c2414             lea edi, [esp + 0x14]
// 005ffedf  e86ce7ffff           call 0x5fe650
// 005ffee4  837c24140d           cmp dword ptr [esp + 0x14], 0xd
// 005ffee9  7523                 jne 0x5fff0e
// 005ffeeb  8b03                 mov eax, dword ptr [ebx]
// 005ffeed  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005ffef0  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005ffef4  8d0491               lea eax, [ecx + edx*4]
// 005ffef7  8b08                 mov ecx, dword ptr [eax]
// 005ffef9  5f                   pop edi
// 005ffefa  81e1ff7f80ff         and ecx, 0xff807fff
// 005fff00  81c900400000         or ecx, 0x4000
// 005fff06  5e                   pop esi
// 005fff07  8908                 mov dword ptr [eax], ecx
// 005fff09  5b                   pop ebx
// 005fff0a  83c420               add esp, 0x20
// 005fff0d  c3                   ret 
// 005fff0e  6a01                 push 1
// 005fff10  8d542410             lea edx, [esp + 0x10]
// 005fff14  52                   push edx
// 005fff15  56                   push esi
// 005fff16  c744241800000000     mov dword ptr [esp + 0x18], 0
// 005fff1e  e89defffff           call 0x5feec0
// 005fff23  83c40c               add esp, 0xc
// 005fff26  5f                   pop edi
// 005fff27  5e                   pop esi
// 005fff28  5b                   pop ebx
// 005fff29  83c420               add esp, 0x20
// 005fff2c  c3                   ret 
// library lua-5.1.1/lparser.c (function _exprstat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
