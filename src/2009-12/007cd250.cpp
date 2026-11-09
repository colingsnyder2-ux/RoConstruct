// from server: 100% by auto
// roc 2009-12 007cd250  unit: RBX::PartDropTool  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd250
//
// 007cd250  8b460c               mov eax, dword ptr [esi + 0xc]
// 007cd253  f6400503             test byte ptr [eax + 5], 3
// 007cd257  740a                 je 0x7cd263
// 007cd259  50                   push eax
// 007cd25a  53                   push ebx
// 007cd25b  e8f0fbffff           call 0x7cce50
// 007cd260  83c408               add esp, 8
// 007cd263  807e0600             cmp byte ptr [esi + 6], 0
// 007cd267  55                   push ebp
// 007cd268  57                   push edi
// 007cd269  7432                 je 0x7cd29d
// 007cd26b  33ed                 xor ebp, ebp
// 007cd26d  807e0700             cmp byte ptr [esi + 7], 0
// 007cd271  766c                 jbe 0x7cd2df
// 007cd273  8d7e18               lea edi, [esi + 0x18]
// 007cd276  837f0804             cmp dword ptr [edi + 8], 4
// 007cd27a  7c12                 jl 0x7cd28e
// 007cd27c  8b07                 mov eax, dword ptr [edi]
// 007cd27e  f6400503             test byte ptr [eax + 5], 3
// 007cd282  740a                 je 0x7cd28e
// 007cd284  50                   push eax
// 007cd285  53                   push ebx
// 007cd286  e8c5fbffff           call 0x7cce50
// 007cd28b  83c408               add esp, 8
// 007cd28e  0fb64607             movzx eax, byte ptr [esi + 7]
// 007cd292  45                   inc ebp
// 007cd293  83c710               add edi, 0x10
// 007cd296  3be8                 cmp ebp, eax
// 007cd298  7cdc                 jl 0x7cd276
// 007cd29a  5f                   pop edi
// 007cd29b  5d                   pop ebp
// 007cd29c  c3                   ret 
// 007cd29d  8b4610               mov eax, dword ptr [esi + 0x10]
// 007cd2a0  f6400503             test byte ptr [eax + 5], 3
// 007cd2a4  740a                 je 0x7cd2b0
// 007cd2a6  50                   push eax
// 007cd2a7  53                   push ebx
// 007cd2a8  e8a3fbffff           call 0x7cce50
// 007cd2ad  83c408               add esp, 8
// 007cd2b0  33ff                 xor edi, edi
// 007cd2b2  807e0700             cmp byte ptr [esi + 7], 0
// 007cd2b6  7627                 jbe 0x7cd2df
// 007cd2b8  8d6e14               lea ebp, [esi + 0x14]
// 007cd2bb  eb03                 jmp 0x7cd2c0
// 007cd2bd  8d4900               lea ecx, [ecx]
// 007cd2c0  8b4500               mov eax, dword ptr [ebp]
// 007cd2c3  f6400503             test byte ptr [eax + 5], 3
// 007cd2c7  740a                 je 0x7cd2d3
// 007cd2c9  50                   push eax
// 007cd2ca  53                   push ebx
// 007cd2cb  e880fbffff           call 0x7cce50
// 007cd2d0  83c408               add esp, 8
// 007cd2d3  0fb64e07             movzx ecx, byte ptr [esi + 7]
// 007cd2d7  47                   inc edi
// 007cd2d8  83c504               add ebp, 4
// 007cd2db  3bf9                 cmp edi, ecx
// 007cd2dd  7ce1                 jl 0x7cd2c0
// 007cd2df  5f                   pop edi
// 007cd2e0  5d                   pop ebp
// 007cd2e1  c3                   ret 
// library lua-5.1/lgc.c (function _traverseclosure)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lgc.c
