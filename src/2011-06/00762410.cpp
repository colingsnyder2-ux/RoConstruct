// from server: 100% by auto
// roc 2011-06 00762410  unit: seg_00760000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00762410
//
// 00762410  8b442408             mov eax, dword ptr [esp + 8]
// 00762414  56                   push esi
// 00762415  8b742408             mov esi, dword ptr [esp + 8]
// 00762419  8bce                 mov ecx, esi
// 0076241b  e890fdffff           call 0x7621b0
// 00762420  8b5608               mov edx, dword ptr [esi + 8]
// 00762423  3bd0                 cmp edx, eax
// 00762425  7624                 jbe 0x76244b
// 00762427  8d4af0               lea ecx, [edx - 0x10]
// 0076242a  57                   push edi
// 0076242b  eb03                 jmp 0x762430
// 0076242d  8d4900               lea ecx, [ecx]
// 00762430  8b39                 mov edi, dword ptr [ecx]
// 00762432  893a                 mov dword ptr [edx], edi
// 00762434  8b7904               mov edi, dword ptr [ecx + 4]
// 00762437  897a04               mov dword ptr [edx + 4], edi
// 0076243a  8b7908               mov edi, dword ptr [ecx + 8]
// 0076243d  897918               mov dword ptr [ecx + 0x18], edi
// 00762440  83ea10               sub edx, 0x10
// 00762443  83e910               sub ecx, 0x10
// 00762446  3bd0                 cmp edx, eax
// 00762448  77e6                 ja 0x762430
// 0076244a  5f                   pop edi
// 0076244b  8b4e08               mov ecx, dword ptr [esi + 8]
// 0076244e  8b11                 mov edx, dword ptr [ecx]
// 00762450  8910                 mov dword ptr [eax], edx
// 00762452  8b5104               mov edx, dword ptr [ecx + 4]
// 00762455  895004               mov dword ptr [eax + 4], edx
// 00762458  8b4908               mov ecx, dword ptr [ecx + 8]
// 0076245b  894808               mov dword ptr [eax + 8], ecx
// 0076245e  5e                   pop esi
// 0076245f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
