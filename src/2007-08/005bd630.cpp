// from server: 100% by auto
// roc 2007-08 005bd630  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd630
//
// 005bd630  8b442408             mov eax, dword ptr [esp + 8]
// 005bd634  56                   push esi
// 005bd635  8b742408             mov esi, dword ptr [esp + 8]
// 005bd639  8bce                 mov ecx, esi
// 005bd63b  e8f0fdffff           call 0x5bd430
// 005bd640  8b5608               mov edx, dword ptr [esi + 8]
// 005bd643  3bd0                 cmp edx, eax
// 005bd645  7624                 jbe 0x5bd66b
// 005bd647  8d4af0               lea ecx, [edx - 0x10]
// 005bd64a  57                   push edi
// 005bd64b  eb03                 jmp 0x5bd650
// 005bd64d  8d4900               lea ecx, [ecx]
// 005bd650  8b39                 mov edi, dword ptr [ecx]
// 005bd652  893a                 mov dword ptr [edx], edi
// 005bd654  8b7904               mov edi, dword ptr [ecx + 4]
// 005bd657  897a04               mov dword ptr [edx + 4], edi
// 005bd65a  8b7908               mov edi, dword ptr [ecx + 8]
// 005bd65d  897918               mov dword ptr [ecx + 0x18], edi
// 005bd660  83ea10               sub edx, 0x10
// 005bd663  83e910               sub ecx, 0x10
// 005bd666  3bd0                 cmp edx, eax
// 005bd668  77e6                 ja 0x5bd650
// 005bd66a  5f                   pop edi
// 005bd66b  8b4e08               mov ecx, dword ptr [esi + 8]
// 005bd66e  8b11                 mov edx, dword ptr [ecx]
// 005bd670  8910                 mov dword ptr [eax], edx
// 005bd672  8b5104               mov edx, dword ptr [ecx + 4]
// 005bd675  895004               mov dword ptr [eax + 4], edx
// 005bd678  8b4908               mov ecx, dword ptr [ecx + 8]
// 005bd67b  894808               mov dword ptr [eax + 8], ecx
// 005bd67e  5e                   pop esi
// 005bd67f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
