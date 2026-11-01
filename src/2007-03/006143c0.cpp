// from server: 100% by auto
// roc 2007-03 006143c0  unit: seg_00610000  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006143c0
//
// 006143c0  8b13                 mov edx, dword ptr [ebx]
// 006143c2  8b520c               mov edx, dword ptr [edx + 0xc]
// 006143c5  2bc1                 sub eax, ecx
// 006143c7  83e801               sub eax, 1
// 006143ca  56                   push esi
// 006143cb  8bf0                 mov esi, eax
// 006143cd  57                   push edi
// 006143ce  8d3c8a               lea edi, [edx + ecx*4]
// 006143d1  99                   cdq 
// 006143d2  33c2                 xor eax, edx
// 006143d4  2bc2                 sub eax, edx
// 006143d6  3dffff0100           cmp eax, 0x1ffff
// 006143db  7e11                 jle 0x6143ee
// 006143dd  8b430c               mov eax, dword ptr [ebx + 0xc]
// 006143e0  6878207c00           push 0x7c2078
// 006143e5  50                   push eax
// 006143e6  e885cbfeff           call 0x600f70
// 006143eb  83c408               add esp, 8
// 006143ee  8b0f                 mov ecx, dword ptr [edi]
// 006143f0  81c6ffff0100         add esi, 0x1ffff
// 006143f6  c1e60e               shl esi, 0xe
// 006143f9  81e1ff3f0000         and ecx, 0x3fff
// 006143ff  33f1                 xor esi, ecx
// 00614401  8937                 mov dword ptr [edi], esi
// 00614403  5f                   pop edi
// 00614404  5e                   pop esi
// 00614405  c3                   ret 
// library lua-5.1.1/lcode.c (function _fixjump)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lcode.c
