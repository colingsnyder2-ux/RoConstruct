// from server: 100% by auto
// roc 2009-12 007dc660  unit: RBX::GroupDragTool  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc660
//
// 007dc660  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007dc664  49                   dec ecx
// 007dc665  b81f85eb51           mov eax, 0x51eb851f
// 007dc66a  f7e9                 imul ecx
// 007dc66c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007dc670  c1fa04               sar edx, 4
// 007dc673  8bc2                 mov eax, edx
// 007dc675  c1e81f               shr eax, 0x1f
// 007dc678  56                   push esi
// 007dc679  8b742408             mov esi, dword ptr [esp + 8]
// 007dc67d  57                   push edi
// 007dc67e  8d7c0201             lea edi, [edx + eax + 1]
// 007dc682  8bc1                 mov eax, ecx
// 007dc684  40                   inc eax
// 007dc685  f7d8                 neg eax
// 007dc687  1bc0                 sbb eax, eax
// 007dc689  23c1                 and eax, ecx
// 007dc68b  81ffff010000         cmp edi, 0x1ff
// 007dc691  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dc694  8b5108               mov edx, dword ptr [ecx + 8]
// 007dc697  7f25                 jg 0x7dc6be
// 007dc699  c1e009               shl eax, 9
// 007dc69c  0bc7                 or eax, edi
// 007dc69e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007dc6a2  c1e008               shl eax, 8
// 007dc6a5  0bc7                 or eax, edi
// 007dc6a7  c1e006               shl eax, 6
// 007dc6aa  52                   push edx
// 007dc6ab  83c822               or eax, 0x22
// 007dc6ae  50                   push eax
// 007dc6af  e8acfeffff           call 0x7dc560
// 007dc6b4  83c408               add esp, 8
// 007dc6b7  47                   inc edi
// 007dc6b8  897e24               mov dword ptr [esi + 0x24], edi
// 007dc6bb  5f                   pop edi
// 007dc6bc  5e                   pop esi
// 007dc6bd  c3                   ret 
// 007dc6be  53                   push ebx
// 007dc6bf  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007dc6c3  c1e011               shl eax, 0x11
// 007dc6c6  0bc3                 or eax, ebx
// 007dc6c8  c1e006               shl eax, 6
// 007dc6cb  52                   push edx
// 007dc6cc  83c822               or eax, 0x22
// 007dc6cf  50                   push eax
// 007dc6d0  e88bfeffff           call 0x7dc560
// 007dc6d5  8b460c               mov eax, dword ptr [esi + 0xc]
// 007dc6d8  8b4808               mov ecx, dword ptr [eax + 8]
// 007dc6db  51                   push ecx
// 007dc6dc  57                   push edi
// 007dc6dd  e87efeffff           call 0x7dc560
// 007dc6e2  83c410               add esp, 0x10
// 007dc6e5  43                   inc ebx
// 007dc6e6  895e24               mov dword ptr [esi + 0x24], ebx
// 007dc6e9  5b                   pop ebx
// 007dc6ea  5f                   pop edi
// 007dc6eb  5e                   pop esi
// 007dc6ec  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_setlist)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
