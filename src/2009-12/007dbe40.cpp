// from server: 100% by auto
// roc 2009-12 007dbe40  unit: RBX::GroupDragTool  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dbe40
//
// 007dbe40  8b13                 mov edx, dword ptr [ebx]
// 007dbe42  8b520c               mov edx, dword ptr [edx + 0xc]
// 007dbe45  2bc1                 sub eax, ecx
// 007dbe47  48                   dec eax
// 007dbe48  56                   push esi
// 007dbe49  8bf0                 mov esi, eax
// 007dbe4b  57                   push edi
// 007dbe4c  8d3c8a               lea edi, [edx + ecx*4]
// 007dbe4f  99                   cdq 
// 007dbe50  33c2                 xor eax, edx
// 007dbe52  2bc2                 sub eax, edx
// 007dbe54  3dffff0100           cmp eax, 0x1ffff
// 007dbe59  7e11                 jle 0x7dbe6c
// 007dbe5b  8b430c               mov eax, dword ptr [ebx + 0xc]
// 007dbe5e  6818fb9e00           push 0x9efb18
// 007dbe63  50                   push eax
// 007dbe64  e8d794ffff           call 0x7d5340
// 007dbe69  83c408               add esp, 8
// 007dbe6c  8b0f                 mov ecx, dword ptr [edi]
// 007dbe6e  81c6ffff0100         add esi, 0x1ffff
// 007dbe74  c1e60e               shl esi, 0xe
// 007dbe77  81e1ff3f0000         and ecx, 0x3fff
// 007dbe7d  33f1                 xor esi, ecx
// 007dbe7f  8937                 mov dword ptr [edi], esi
// 007dbe81  5f                   pop edi
// 007dbe82  5e                   pop esi
// 007dbe83  c3                   ret 
// library lua-5.1/lcode.c (function _fixjump)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
