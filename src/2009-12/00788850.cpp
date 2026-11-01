// from server: 100% by auto
// roc 2009-12 00788850  unit: RBX::UniversalTool  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00788850
//
// 00788850  8b442408             mov eax, dword ptr [esp + 8]
// 00788854  56                   push esi
// 00788855  8b742408             mov esi, dword ptr [esp + 8]
// 00788859  8bce                 mov ecx, esi
// 0078885b  e890fdffff           call 0x7885f0
// 00788860  8b5608               mov edx, dword ptr [esi + 8]
// 00788863  3bd0                 cmp edx, eax
// 00788865  7624                 jbe 0x78888b
// 00788867  8d4af0               lea ecx, [edx - 0x10]
// 0078886a  57                   push edi
// 0078886b  eb03                 jmp 0x788870
// 0078886d  8d4900               lea ecx, [ecx]
// 00788870  8b39                 mov edi, dword ptr [ecx]
// 00788872  893a                 mov dword ptr [edx], edi
// 00788874  8b7904               mov edi, dword ptr [ecx + 4]
// 00788877  897a04               mov dword ptr [edx + 4], edi
// 0078887a  8b7908               mov edi, dword ptr [ecx + 8]
// 0078887d  897918               mov dword ptr [ecx + 0x18], edi
// 00788880  83ea10               sub edx, 0x10
// 00788883  83e910               sub ecx, 0x10
// 00788886  3bd0                 cmp edx, eax
// 00788888  77e6                 ja 0x788870
// 0078888a  5f                   pop edi
// 0078888b  8b4e08               mov ecx, dword ptr [esi + 8]
// 0078888e  8b11                 mov edx, dword ptr [ecx]
// 00788890  8910                 mov dword ptr [eax], edx
// 00788892  8b5104               mov edx, dword ptr [ecx + 4]
// 00788895  895004               mov dword ptr [eax + 4], edx
// 00788898  8b4908               mov ecx, dword ptr [ecx + 8]
// 0078889b  894808               mov dword ptr [eax + 8], ecx
// 0078889e  5e                   pop esi
// 0078889f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
