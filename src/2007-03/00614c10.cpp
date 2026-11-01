// from server: 100% by auto
// roc 2007-03 00614c10  unit: seg_00610000  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00614c10
//
// 00614c10  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00614c14  83c1ff               add ecx, -1
// 00614c17  b81f85eb51           mov eax, 0x51eb851f
// 00614c1c  f7e9                 imul ecx
// 00614c1e  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00614c22  c1fa04               sar edx, 4
// 00614c25  8bc2                 mov eax, edx
// 00614c27  c1e81f               shr eax, 0x1f
// 00614c2a  56                   push esi
// 00614c2b  8b742408             mov esi, dword ptr [esp + 8]
// 00614c2f  57                   push edi
// 00614c30  8d7c0201             lea edi, [edx + eax + 1]
// 00614c34  8bc1                 mov eax, ecx
// 00614c36  83e8ff               sub eax, -1
// 00614c39  f7d8                 neg eax
// 00614c3b  1bc0                 sbb eax, eax
// 00614c3d  23c1                 and eax, ecx
// 00614c3f  81ffff010000         cmp edi, 0x1ff
// 00614c45  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00614c48  8b5108               mov edx, dword ptr [ecx + 8]
// 00614c4b  7f27                 jg 0x614c74
// 00614c4d  c1e009               shl eax, 9
// 00614c50  0bc7                 or eax, edi
// 00614c52  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00614c56  c1e008               shl eax, 8
// 00614c59  0bc7                 or eax, edi
// 00614c5b  c1e006               shl eax, 6
// 00614c5e  52                   push edx
// 00614c5f  83c822               or eax, 0x22
// 00614c62  50                   push eax
// 00614c63  e8a8feffff           call 0x614b10
// 00614c68  83c408               add esp, 8
// 00614c6b  83c701               add edi, 1
// 00614c6e  897e24               mov dword ptr [esi + 0x24], edi
// 00614c71  5f                   pop edi
// 00614c72  5e                   pop esi
// 00614c73  c3                   ret 
// 00614c74  53                   push ebx
// 00614c75  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00614c79  c1e011               shl eax, 0x11
// 00614c7c  0bc3                 or eax, ebx
// 00614c7e  c1e006               shl eax, 6
// 00614c81  52                   push edx
// 00614c82  83c822               or eax, 0x22
// 00614c85  50                   push eax
// 00614c86  e885feffff           call 0x614b10
// 00614c8b  8b460c               mov eax, dword ptr [esi + 0xc]
// 00614c8e  8b4808               mov ecx, dword ptr [eax + 8]
// 00614c91  51                   push ecx
// 00614c92  57                   push edi
// 00614c93  e878feffff           call 0x614b10
// 00614c98  83c410               add esp, 0x10
// 00614c9b  83c301               add ebx, 1
// 00614c9e  895e24               mov dword ptr [esi + 0x24], ebx
// 00614ca1  5b                   pop ebx
// 00614ca2  5f                   pop edi
// 00614ca3  5e                   pop esi
// 00614ca4  c3                   ret 
// library lua-5.1.1/lcode.c (function _luaK_setlist)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
