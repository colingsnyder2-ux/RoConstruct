// roc 2009-12 007dcd00  unit: RBX::GroupDragTool  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dcd00
//
// 007dcd00  83ec20               sub esp, 0x20
// 007dcd03  56                   push esi
// 007dcd04  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 007dcd08  8b4610               mov eax, dword ptr [esi + 0x10]
// 007dcd0b  57                   push edi
// 007dcd0c  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007dcd10  56                   push esi
// 007dcd11  57                   push edi
// 007dcd12  3b4614               cmp eax, dword ptr [esi + 0x14]
// 007dcd15  7407                 je 0x7dcd1e
// 007dcd17  e874ffffff           call 0x7dcc90
// 007dcd1c  eb05                 jmp 0x7dcd23
// 007dcd1e  e85dfbffff           call 0x7dc880
// 007dcd23  8b06                 mov eax, dword ptr [esi]
// 007dcd25  8d48ff               lea ecx, [eax - 1]
// 007dcd28  83c408               add esp, 8
// 007dcd2b  83f904               cmp ecx, 4
// 007dcd2e  0f87a2000000         ja 0x7dcdd6
// 007dcd34  ff248de8cd7d00       jmp dword ptr [ecx*4 + 0x7dcde8]
// 007dcd3b  817f28ff000000       cmp dword ptr [edi + 0x28], 0xff
// 007dcd42  0f8f8e000000         jg 0x7dcdd6
// 007dcd48  83f801               cmp eax, 1
// 007dcd4b  7519                 jne 0x7dcd66
// 007dcd4d  8b4f04               mov ecx, dword ptr [edi + 4]
// 007dcd50  c744242000000000     mov dword ptr [esp + 0x20], 0
// 007dcd58  c744241005000000     mov dword ptr [esp + 0x10], 5
// 007dcd60  8d542418             lea edx, [esp + 0x18]
// 007dcd64  eb3f                 jmp 0x7dcda5
// 007dcd66  83f805               cmp eax, 5
// 007dcd69  7526                 jne 0x7dcd91
// 007dcd6b  dd4608               fld qword ptr [esi + 8]
// 007dcd6e  83ec08               sub esp, 8
// 007dcd71  dd1c24               fstp qword ptr [esp]
// 007dcd74  57                   push edi
// 007dcd75  e856f5ffff           call 0x7dc2d0
// 007dcd7a  83c40c               add esp, 0xc
// 007dcd7d  894608               mov dword ptr [esi + 8], eax
// 007dcd80  5f                   pop edi
// 007dcd81  c70604000000         mov dword ptr [esi], 4
// 007dcd87  0d00010000           or eax, 0x100
// 007dcd8c  5e                   pop esi
// 007dcd8d  83c420               add esp, 0x20
// 007dcd90  c3                   ret 
// 007dcd91  33c9                 xor ecx, ecx
// 007dcd93  83f802               cmp eax, 2
// 007dcd96  0f94c1               sete cl
// 007dcd99  c744241001000000     mov dword ptr [esp + 0x10], 1
// 007dcda1  8d542408             lea edx, [esp + 8]
// 007dcda5  894c2408             mov dword ptr [esp + 8], ecx
// 007dcda9  52                   push edx
// 007dcdaa  8d4c240c             lea ecx, [esp + 0xc]
// 007dcdae  8bc7                 mov eax, edi
// 007dcdb0  e80bf4ffff           call 0x7dc1c0
// 007dcdb5  83c404               add esp, 4
// 007dcdb8  894608               mov dword ptr [esi + 8], eax
// 007dcdbb  c70604000000         mov dword ptr [esi], 4
// 007dcdc1  5f                   pop edi
// 007dcdc2  0d00010000           or eax, 0x100
// 007dcdc7  5e                   pop esi
// 007dcdc8  83c420               add esp, 0x20
// 007dcdcb  c3                   ret 
// 007dcdcc  8b4608               mov eax, dword ptr [esi + 8]
// 007dcdcf  3dff000000           cmp eax, 0xff
// 007dcdd4  7eeb                 jle 0x7dcdc1
// 007dcdd6  56                   push esi
// 007dcdd7  57                   push edi
// 007dcdd8  e8b3feffff           call 0x7dcc90
// 007dcddd  83c408               add esp, 8
// 007dcde0  5f                   pop edi
// 007dcde1  5e                   pop esi
// 007dcde2  83c420               add esp, 0x20
// 007dcde5  c3                   ret 
// 007dcde6  8bff                 mov edi, edi
// 007dcde8  3bcd                 cmp ecx, ebp
// 007dcdea  7d00                 jge 0x7dcdec
// 007dcdec  3bcd                 cmp ecx, ebp
// 007dcdee  7d00                 jge 0x7dcdf0
// 007dcdf0  3bcd                 cmp ecx, ebp
// 007dcdf2  7d00                 jge 0x7dcdf4
// 007dcdf4  cc                   int3 
// 007dcdf5  cd7d                 int 0x7d
// 007dcdf7  003b                 add byte ptr [ebx], bh
// 007dcdf9  cd7d                 int 0x7d
// library lua-5.1/lcode.c (function _luaK_exp2RK)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
