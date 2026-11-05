// from server: 100% by auto
// roc 2012-06 00831ba0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831ba0
//
// 00831ba0  8b442408             mov eax, dword ptr [esp + 8]
// 00831ba4  56                   push esi
// 00831ba5  8b742408             mov esi, dword ptr [esp + 8]
// 00831ba9  8bce                 mov ecx, esi
// 00831bab  e890fdffff           call 0x831940
// 00831bb0  8b5608               mov edx, dword ptr [esi + 8]
// 00831bb3  3bd0                 cmp edx, eax
// 00831bb5  7624                 jbe 0x831bdb
// 00831bb7  8d4af0               lea ecx, [edx - 0x10]
// 00831bba  57                   push edi
// 00831bbb  eb03                 jmp 0x831bc0
// 00831bbd  8d4900               lea ecx, [ecx]
// 00831bc0  8b39                 mov edi, dword ptr [ecx]
// 00831bc2  893a                 mov dword ptr [edx], edi
// 00831bc4  8b7904               mov edi, dword ptr [ecx + 4]
// 00831bc7  897a04               mov dword ptr [edx + 4], edi
// 00831bca  8b7908               mov edi, dword ptr [ecx + 8]
// 00831bcd  897918               mov dword ptr [ecx + 0x18], edi
// 00831bd0  83ea10               sub edx, 0x10
// 00831bd3  83e910               sub ecx, 0x10
// 00831bd6  3bd0                 cmp edx, eax
// 00831bd8  77e6                 ja 0x831bc0
// 00831bda  5f                   pop edi
// 00831bdb  8b4e08               mov ecx, dword ptr [esi + 8]
// 00831bde  8b11                 mov edx, dword ptr [ecx]
// 00831be0  8910                 mov dword ptr [eax], edx
// 00831be2  8b5104               mov edx, dword ptr [ecx + 4]
// 00831be5  895004               mov dword ptr [eax + 4], edx
// 00831be8  8b4908               mov ecx, dword ptr [ecx + 8]
// 00831beb  894808               mov dword ptr [eax + 8], ecx
// 00831bee  5e                   pop esi
// 00831bef  c3                   ret 
// library lua-5.1/lapi.c (function _lua_insert)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
