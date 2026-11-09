// from server: 100% by auto
// roc 2011-06 005613e0  unit: seg_00560000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005613e0
//
// 005613e0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 005613e4  56                   push esi
// 005613e5  8b742408             mov esi, dword ptr [esp + 8]
// 005613e9  33c0                 xor eax, eax
// 005613eb  85f6                 test esi, esi
// 005613ed  743d                 je 0x56142c
// 005613ef  f7466c00000c00       test dword ptr [esi + 0x6c], 0xc0000
// 005613f6  7422                 je 0x56141a
// 005613f8  803923               cmp byte ptr [ecx], 0x23
// 005613fb  751d                 jne 0x56141a
// 005613fd  b801000000           mov eax, 1
// 00561402  b220                 mov dl, 0x20
// 00561404  381408               cmp byte ptr [eax + ecx], dl
// 00561407  7411                 je 0x56141a
// 00561409  38540801             cmp byte ptr [eax + ecx + 1], dl
// 0056140d  740a                 je 0x561419
// 0056140f  83c002               add eax, 2
// 00561412  83f80f               cmp eax, 0xf
// 00561415  7ced                 jl 0x561404
// 00561417  eb01                 jmp 0x56141a
// 00561419  40                   inc eax
// 0056141a  8b5644               mov edx, dword ptr [esi + 0x44]
// 0056141d  85d2                 test edx, edx
// 0056141f  740b                 je 0x56142c
// 00561421  03c1                 add eax, ecx
// 00561423  50                   push eax
// 00561424  56                   push esi
// 00561425  ffd2                 call edx
// 00561427  83c408               add esp, 8
// 0056142a  5e                   pop esi
// 0056142b  c3                   ret 
// 0056142c  03c1                 add eax, ecx
// 0056142e  5e                   pop esi
// 0056142f  e9bcfdffff           jmp 0x5611f0
// library libpng-1.2.35/pngerror.c (function _png_warning)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngerror.c
