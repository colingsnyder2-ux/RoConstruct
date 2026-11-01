// from server: 100% by auto
// roc 2007-03 005f9070  unit: seg_005f0000  size: 245 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9070
//
// 005f9070  55                   push ebp
// 005f9071  8b6c2408             mov ebp, dword ptr [esp + 8]
// 005f9075  85ed                 test ebp, ebp
// 005f9077  0f84e6000000         je 0x5f9163
// 005f907d  53                   push ebx
// 005f907e  56                   push esi
// 005f907f  57                   push edi
// 005f9080  bb04000000           mov ebx, 4
// 005f9085  f6450510             test byte ptr [ebp + 5], 0x10
// 005f9089  8b7d1c               mov edi, dword ptr [ebp + 0x1c]
// 005f908c  744e                 je 0x5f90dc
// 005f908e  85ff                 test edi, edi
// 005f9090  744a                 je 0x5f90dc
// 005f9092  8bf7                 mov esi, edi
// 005f9094  c1e604               shl esi, 4
// 005f9097  eb07                 jmp 0x5f90a0
// 005f9099  8da42400000000       lea esp, [esp]
// 005f90a0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005f90a3  83ee10               sub esi, 0x10
// 005f90a6  8b4c3008             mov ecx, dword ptr [eax + esi + 8]
// 005f90aa  03c6                 add eax, esi
// 005f90ac  83ef01               sub edi, 1
// 005f90af  3bcb                 cmp ecx, ebx
// 005f90b1  7c25                 jl 0x5f90d8
// 005f90b3  7508                 jne 0x5f90bd
// 005f90b5  8b00                 mov eax, dword ptr [eax]
// 005f90b7  806005fc             and byte ptr [eax + 5], 0xfc
// 005f90bb  eb1b                 jmp 0x5f90d8
// 005f90bd  8b10                 mov edx, dword ptr [eax]
// 005f90bf  8a5205               mov dl, byte ptr [edx + 5]
// 005f90c2  f6c203               test dl, 3
// 005f90c5  750a                 jne 0x5f90d1
// 005f90c7  83f907               cmp ecx, 7
// 005f90ca  750c                 jne 0x5f90d8
// 005f90cc  f6c208               test dl, 8
// 005f90cf  7407                 je 0x5f90d8
// 005f90d1  c7400800000000       mov dword ptr [eax + 8], 0
// 005f90d8  85ff                 test edi, edi
// 005f90da  75c4                 jne 0x5f90a0
// 005f90dc  8a4d07               mov cl, byte ptr [ebp + 7]
// 005f90df  be01000000           mov esi, 1
// 005f90e4  d3e6                 shl esi, cl
// 005f90e6  85f6                 test esi, esi
// 005f90e8  746b                 je 0x5f9155
// 005f90ea  8bfe                 mov edi, esi
// 005f90ec  c1e705               shl edi, 5
// 005f90ef  90                   nop 
// 005f90f0  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005f90f3  83ef20               sub edi, 0x20
// 005f90f6  03c7                 add eax, edi
// 005f90f8  83ee01               sub esi, 1
// 005f90fb  83780800             cmp dword ptr [eax + 8], 0
// 005f90ff  7450                 je 0x5f9151
// 005f9101  8b4818               mov ecx, dword ptr [eax + 0x18]
// 005f9104  3bcb                 cmp ecx, ebx
// 005f9106  7c11                 jl 0x5f9119
// 005f9108  8b4810               mov ecx, dword ptr [eax + 0x10]
// 005f910b  7506                 jne 0x5f9113
// 005f910d  806105fc             and byte ptr [ecx + 5], 0xfc
// 005f9111  eb06                 jmp 0x5f9119
// 005f9113  f6410503             test byte ptr [ecx + 5], 3
// 005f9117  7525                 jne 0x5f913e
// 005f9119  8b4808               mov ecx, dword ptr [eax + 8]
// 005f911c  3bcb                 cmp ecx, ebx
// 005f911e  7c31                 jl 0x5f9151
// 005f9120  7508                 jne 0x5f912a
// 005f9122  8b00                 mov eax, dword ptr [eax]
// 005f9124  806005fc             and byte ptr [eax + 5], 0xfc
// 005f9128  eb27                 jmp 0x5f9151
// 005f912a  8b10                 mov edx, dword ptr [eax]
// 005f912c  8a5205               mov dl, byte ptr [edx + 5]
// 005f912f  f6c203               test dl, 3
// 005f9132  750a                 jne 0x5f913e
// 005f9134  83f907               cmp ecx, 7
// 005f9137  7518                 jne 0x5f9151
// 005f9139  f6c208               test dl, 8
// 005f913c  7413                 je 0x5f9151
// 005f913e  395818               cmp dword ptr [eax + 0x18], ebx
// 005f9141  c7400800000000       mov dword ptr [eax + 8], 0
// 005f9148  7c07                 jl 0x5f9151
// 005f914a  c740180b000000       mov dword ptr [eax + 0x18], 0xb
// 005f9151  85f6                 test esi, esi
// 005f9153  759b                 jne 0x5f90f0
// 005f9155  8b6d18               mov ebp, dword ptr [ebp + 0x18]
// 005f9158  85ed                 test ebp, ebp
// 005f915a  0f8525ffffff         jne 0x5f9085
// 005f9160  5f                   pop edi
// 005f9161  5e                   pop esi
// 005f9162  5b                   pop ebx
// 005f9163  5d                   pop ebp
// 005f9164  c3                   ret 
// library lua-5.1.1/lgc.c (function _cleartable)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
