// from server: 100% by auto
// roc 2007-03 005bfb80  unit: seg_005b0000  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005bfb80
//
// 005bfb80  8b4108               mov eax, dword ptr [ecx + 8]
// 005bfb83  2bc2                 sub eax, edx
// 005bfb85  c1f804               sar eax, 4
// 005bfb88  c1e004               shl eax, 4
// 005bfb8b  034120               add eax, dword ptr [ecx + 0x20]
// 005bfb8e  56                   push esi
// 005bfb8f  894108               mov dword ptr [ecx + 8], eax
// 005bfb92  8b4168               mov eax, dword ptr [ecx + 0x68]
// 005bfb95  85c0                 test eax, eax
// 005bfb97  741e                 je 0x5bfbb7
// 005bfb99  8da42400000000       lea esp, [esp]
// 005bfba0  8b7008               mov esi, dword ptr [eax + 8]
// 005bfba3  2bf2                 sub esi, edx
// 005bfba5  c1fe04               sar esi, 4
// 005bfba8  c1e604               shl esi, 4
// 005bfbab  037120               add esi, dword ptr [ecx + 0x20]
// 005bfbae  897008               mov dword ptr [eax + 8], esi
// 005bfbb1  8b00                 mov eax, dword ptr [eax]
// 005bfbb3  85c0                 test eax, eax
// 005bfbb5  75e9                 jne 0x5bfba0
// 005bfbb7  8b4128               mov eax, dword ptr [ecx + 0x28]
// 005bfbba  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 005bfbbd  773c                 ja 0x5bfbfb
// 005bfbbf  90                   nop 
// 005bfbc0  8b7008               mov esi, dword ptr [eax + 8]
// 005bfbc3  2bf2                 sub esi, edx
// 005bfbc5  c1fe04               sar esi, 4
// 005bfbc8  c1e604               shl esi, 4
// 005bfbcb  037120               add esi, dword ptr [ecx + 0x20]
// 005bfbce  83c018               add eax, 0x18
// 005bfbd1  8970f0               mov dword ptr [eax - 0x10], esi
// 005bfbd4  8b70e8               mov esi, dword ptr [eax - 0x18]
// 005bfbd7  2bf2                 sub esi, edx
// 005bfbd9  c1fe04               sar esi, 4
// 005bfbdc  c1e604               shl esi, 4
// 005bfbdf  037120               add esi, dword ptr [ecx + 0x20]
// 005bfbe2  8970e8               mov dword ptr [eax - 0x18], esi
// 005bfbe5  8b70ec               mov esi, dword ptr [eax - 0x14]
// 005bfbe8  2bf2                 sub esi, edx
// 005bfbea  c1fe04               sar esi, 4
// 005bfbed  c1e604               shl esi, 4
// 005bfbf0  037120               add esi, dword ptr [ecx + 0x20]
// 005bfbf3  8970ec               mov dword ptr [eax - 0x14], esi
// 005bfbf6  3b4114               cmp eax, dword ptr [ecx + 0x14]
// 005bfbf9  76c5                 jbe 0x5bfbc0
// 005bfbfb  8b410c               mov eax, dword ptr [ecx + 0xc]
// 005bfbfe  2bc2                 sub eax, edx
// 005bfc00  c1f804               sar eax, 4
// 005bfc03  c1e004               shl eax, 4
// 005bfc06  034120               add eax, dword ptr [ecx + 0x20]
// 005bfc09  5e                   pop esi
// 005bfc0a  89410c               mov dword ptr [ecx + 0xc], eax
// 005bfc0d  c3                   ret 
// library lua-5.1.1/ldo.c (function _correctstack)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldo.c
