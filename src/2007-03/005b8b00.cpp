// from server: 100% by auto
// roc 2007-03 005b8b00  unit: seg_005b0000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b8b00
//
// 005b8b00  8b442408             mov eax, dword ptr [esp + 8]
// 005b8b04  56                   push esi
// 005b8b05  8b742408             mov esi, dword ptr [esp + 8]
// 005b8b09  8bce                 mov ecx, esi
// 005b8b0b  e8a0fdffff           call 0x5b88b0
// 005b8b10  8b5608               mov edx, dword ptr [esi + 8]
// 005b8b13  3bd0                 cmp edx, eax
// 005b8b15  7624                 jbe 0x5b8b3b
// 005b8b17  8d4af0               lea ecx, [edx - 0x10]
// 005b8b1a  57                   push edi
// 005b8b1b  eb03                 jmp 0x5b8b20
// 005b8b1d  8d4900               lea ecx, [ecx]
// 005b8b20  8b39                 mov edi, dword ptr [ecx]
// 005b8b22  893a                 mov dword ptr [edx], edi
// 005b8b24  8b7904               mov edi, dword ptr [ecx + 4]
// 005b8b27  897a04               mov dword ptr [edx + 4], edi
// 005b8b2a  8b7908               mov edi, dword ptr [ecx + 8]
// 005b8b2d  897918               mov dword ptr [ecx + 0x18], edi
// 005b8b30  83ea10               sub edx, 0x10
// 005b8b33  83e910               sub ecx, 0x10
// 005b8b36  3bd0                 cmp edx, eax
// 005b8b38  77e6                 ja 0x5b8b20
// 005b8b3a  5f                   pop edi
// 005b8b3b  8b4e08               mov ecx, dword ptr [esi + 8]
// 005b8b3e  8b11                 mov edx, dword ptr [ecx]
// 005b8b40  8910                 mov dword ptr [eax], edx
// 005b8b42  8b5104               mov edx, dword ptr [ecx + 4]
// 005b8b45  895004               mov dword ptr [eax + 4], edx
// 005b8b48  8b4908               mov ecx, dword ptr [ecx + 8]
// 005b8b4b  894808               mov dword ptr [eax + 8], ecx
// 005b8b4e  5e                   pop esi
// 005b8b4f  c3                   ret 
// library lua-5.1.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lapi.c
