// from server: 100% by auto
// roc 2009-12 007dc1c0  unit: RBX::GroupDragTool  size: 222 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc1c0
//
// 007dc1c0  51                   push ecx
// 007dc1c1  53                   push ebx
// 007dc1c2  55                   push ebp
// 007dc1c3  56                   push esi
// 007dc1c4  57                   push edi
// 007dc1c5  8bd8                 mov ebx, eax
// 007dc1c7  8b5304               mov edx, dword ptr [ebx + 4]
// 007dc1ca  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007dc1cd  51                   push ecx
// 007dc1ce  52                   push edx
// 007dc1cf  50                   push eax
// 007dc1d0  8944241c             mov dword ptr [esp + 0x1c], eax
// 007dc1d4  e80742ffff           call 0x7d03e0
// 007dc1d9  8b3b                 mov edi, dword ptr [ebx]
// 007dc1db  8b6f28               mov ebp, dword ptr [edi + 0x28]
// 007dc1de  b903000000           mov ecx, 3
// 007dc1e3  83c40c               add esp, 0xc
// 007dc1e6  8d7728               lea esi, [edi + 0x28]
// 007dc1e9  394808               cmp dword ptr [eax + 8], ecx
// 007dc1ec  750e                 jne 0x7dc1fc
// 007dc1ee  dd00                 fld qword ptr [eax]
// 007dc1f0  5f                   pop edi
// 007dc1f1  5e                   pop esi
// 007dc1f2  5d                   pop ebp
// 007dc1f3  5b                   pop ebx
// 007dc1f4  83c404               add esp, 4
// 007dc1f7  e9f48a0100           jmp 0x7f4cf0
// 007dc1fc  db4328               fild dword ptr [ebx + 0x28]
// 007dc1ff  83c328               add ebx, 0x28
// 007dc202  894808               mov dword ptr [eax + 8], ecx
// 007dc205  dd18                 fstp qword ptr [eax]
// 007dc207  8b03                 mov eax, dword ptr [ebx]
// 007dc209  40                   inc eax
// 007dc20a  3b06                 cmp eax, dword ptr [esi]
// 007dc20c  7e21                 jle 0x7dc22f
// 007dc20e  8b4f08               mov ecx, dword ptr [edi + 8]
// 007dc211  8b542410             mov edx, dword ptr [esp + 0x10]
// 007dc215  68b4ee9e00           push 0x9eeeb4
// 007dc21a  68ffff0300           push 0x3ffff
// 007dc21f  6a10                 push 0x10
// 007dc221  56                   push esi
// 007dc222  51                   push ecx
// 007dc223  52                   push edx
// 007dc224  e8d755ffff           call 0x7d1800
// 007dc229  83c418               add esp, 0x18
// 007dc22c  894708               mov dword ptr [edi + 8], eax
// 007dc22f  3b2e                 cmp ebp, dword ptr [esi]
// 007dc231  7d1c                 jge 0x7dc24f
// 007dc233  8bc5                 mov eax, ebp
// 007dc235  c1e004               shl eax, 4
// 007dc238  33c9                 xor ecx, ecx
// 007dc23a  8d9b00000000         lea ebx, [ebx]
// 007dc240  8b5708               mov edx, dword ptr [edi + 8]
// 007dc243  894c1008             mov dword ptr [eax + edx + 8], ecx
// 007dc247  45                   inc ebp
// 007dc248  83c010               add eax, 0x10
// 007dc24b  3b2e                 cmp ebp, dword ptr [esi]
// 007dc24d  7cf1                 jl 0x7dc240
// 007dc24f  8b03                 mov eax, dword ptr [ebx]
// 007dc251  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007dc255  8b11                 mov edx, dword ptr [ecx]
// 007dc257  c1e004               shl eax, 4
// 007dc25a  034708               add eax, dword ptr [edi + 8]
// 007dc25d  8910                 mov dword ptr [eax], edx
// 007dc25f  8b5104               mov edx, dword ptr [ecx + 4]
// 007dc262  895004               mov dword ptr [eax + 4], edx
// 007dc265  8b5108               mov edx, dword ptr [ecx + 8]
// 007dc268  895008               mov dword ptr [eax + 8], edx
// 007dc26b  b804000000           mov eax, 4
// 007dc270  394108               cmp dword ptr [ecx + 8], eax
// 007dc273  7c1c                 jl 0x7dc291
// 007dc275  8b09                 mov ecx, dword ptr [ecx]
// 007dc277  f6410503             test byte ptr [ecx + 5], 3
// 007dc27b  7414                 je 0x7dc291
// 007dc27d  844705               test byte ptr [edi + 5], al
// 007dc280  740f                 je 0x7dc291
// 007dc282  8b442410             mov eax, dword ptr [esp + 0x10]
// 007dc286  51                   push ecx
// 007dc287  57                   push edi
// 007dc288  50                   push eax
// 007dc289  e8721affff           call 0x7cdd00
// 007dc28e  83c40c               add esp, 0xc
// 007dc291  8b03                 mov eax, dword ptr [ebx]
// 007dc293  5f                   pop edi
// 007dc294  5e                   pop esi
// 007dc295  8d4801               lea ecx, [eax + 1]
// 007dc298  5d                   pop ebp
// 007dc299  890b                 mov dword ptr [ebx], ecx
// 007dc29b  5b                   pop ebx
// 007dc29c  59                   pop ecx
// 007dc29d  c3                   ret 
// library lua-5.1/lcode.c (function _addk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
