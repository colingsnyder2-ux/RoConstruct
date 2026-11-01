// from server: 100% by auto
// roc 2009-12 007dcc10  unit: RBX::GroupDragTool  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcc10
//
// 007dcc10  53                   push ebx
// 007dcc11  56                   push esi
// 007dcc12  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007dcc16  57                   push edi
// 007dcc17  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 007dcc1b  57                   push edi
// 007dcc1c  56                   push esi
// 007dcc1d  e85efcffff           call 0x7dc880
// 007dcc22  83c408               add esp, 8
// 007dcc25  833f0c               cmp dword ptr [edi], 0xc
// 007dcc28  7515                 jne 0x7dcc3f
// 007dcc2a  8b4708               mov eax, dword ptr [edi + 8]
// 007dcc2d  a900010000           test eax, 0x100
// 007dcc32  750b                 jne 0x7dcc3f
// 007dcc34  0fb64e32             movzx ecx, byte ptr [esi + 0x32]
// 007dcc38  3bc1                 cmp eax, ecx
// 007dcc3a  7c03                 jl 0x7dcc3f
// 007dcc3c  ff4e24               dec dword ptr [esi + 0x24]
// 007dcc3f  8b16                 mov edx, dword ptr [esi]
// 007dcc41  8b5e24               mov ebx, dword ptr [esi + 0x24]
// 007dcc44  0fb6424b             movzx eax, byte ptr [edx + 0x4b]
// 007dcc48  43                   inc ebx
// 007dcc49  3bd8                 cmp ebx, eax
// 007dcc4b  7e1e                 jle 0x7dcc6b
// 007dcc4d  81fbfa000000         cmp ebx, 0xfa
// 007dcc53  7c11                 jl 0x7dcc66
// 007dcc55  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007dcc58  6834fb9e00           push 0x9efb34
// 007dcc5d  51                   push ecx
// 007dcc5e  e8dd86ffff           call 0x7d5340
// 007dcc63  83c408               add esp, 8
// 007dcc66  8b16                 mov edx, dword ptr [esi]
// 007dcc68  885a4b               mov byte ptr [edx + 0x4b], bl
// 007dcc6b  ff4624               inc dword ptr [esi + 0x24]
// 007dcc6e  8b4624               mov eax, dword ptr [esi + 0x24]
// 007dcc71  48                   dec eax
// 007dcc72  50                   push eax
// 007dcc73  8bc7                 mov eax, edi
// 007dcc75  8bce                 mov ecx, esi
// 007dcc77  e874feffff           call 0x7dcaf0
// 007dcc7c  83c404               add esp, 4
// 007dcc7f  5f                   pop edi
// 007dcc80  5e                   pop esi
// 007dcc81  5b                   pop ebx
// 007dcc82  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_exp2nextreg)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
