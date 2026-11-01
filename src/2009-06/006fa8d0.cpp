// from server: 100% by auto
// roc 2009-06 006fa8d0  unit: RBX::GroupDragTool  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fa8d0
//
// 006fa8d0  83ec20               sub esp, 0x20
// 006fa8d3  56                   push esi
// 006fa8d4  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 006fa8d8  8b4610               mov eax, dword ptr [esi + 0x10]
// 006fa8db  57                   push edi
// 006fa8dc  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006fa8e0  56                   push esi
// 006fa8e1  57                   push edi
// 006fa8e2  3b4614               cmp eax, dword ptr [esi + 0x14]
// 006fa8e5  7407                 je 0x6fa8ee
// 006fa8e7  e874ffffff           call 0x6fa860
// 006fa8ec  eb05                 jmp 0x6fa8f3
// 006fa8ee  e85dfbffff           call 0x6fa450
// 006fa8f3  8b06                 mov eax, dword ptr [esi]
// 006fa8f5  8d48ff               lea ecx, [eax - 1]
// 006fa8f8  83c408               add esp, 8
// 006fa8fb  83f904               cmp ecx, 4
// 006fa8fe  0f87a2000000         ja 0x6fa9a6
// 006fa904  ff248db8a96f00       jmp dword ptr [ecx*4 + 0x6fa9b8]
// 006fa90b  817f28ff000000       cmp dword ptr [edi + 0x28], 0xff
// 006fa912  0f8f8e000000         jg 0x6fa9a6
// 006fa918  83f801               cmp eax, 1
// 006fa91b  7519                 jne 0x6fa936
// 006fa91d  8b4f04               mov ecx, dword ptr [edi + 4]
// 006fa920  c744242000000000     mov dword ptr [esp + 0x20], 0
// 006fa928  c744241005000000     mov dword ptr [esp + 0x10], 5
// 006fa930  8d542418             lea edx, [esp + 0x18]
// 006fa934  eb3f                 jmp 0x6fa975
// 006fa936  83f805               cmp eax, 5
// 006fa939  7526                 jne 0x6fa961
// 006fa93b  dd4608               fld qword ptr [esi + 8]
// 006fa93e  83ec08               sub esp, 8
// 006fa941  dd1c24               fstp qword ptr [esp]
// 006fa944  57                   push edi
// 006fa945  e866f5ffff           call 0x6f9eb0
// 006fa94a  83c40c               add esp, 0xc
// 006fa94d  894608               mov dword ptr [esi + 8], eax
// 006fa950  5f                   pop edi
// 006fa951  c70604000000         mov dword ptr [esi], 4
// 006fa957  0d00010000           or eax, 0x100
// 006fa95c  5e                   pop esi
// 006fa95d  83c420               add esp, 0x20
// 006fa960  c3                   ret 
// 006fa961  33c9                 xor ecx, ecx
// 006fa963  83f802               cmp eax, 2
// 006fa966  0f94c1               sete cl
// 006fa969  c744241001000000     mov dword ptr [esp + 0x10], 1
// 006fa971  8d542408             lea edx, [esp + 8]
// 006fa975  894c2408             mov dword ptr [esp + 8], ecx
// 006fa979  52                   push edx
// 006fa97a  8d4c240c             lea ecx, [esp + 0xc]
// 006fa97e  8bc7                 mov eax, edi
// 006fa980  e81bf4ffff           call 0x6f9da0
// 006fa985  83c404               add esp, 4
// 006fa988  894608               mov dword ptr [esi + 8], eax
// 006fa98b  c70604000000         mov dword ptr [esi], 4
// 006fa991  5f                   pop edi
// 006fa992  0d00010000           or eax, 0x100
// 006fa997  5e                   pop esi
// 006fa998  83c420               add esp, 0x20
// 006fa99b  c3                   ret 
// 006fa99c  8b4608               mov eax, dword ptr [esi + 8]
// 006fa99f  3dff000000           cmp eax, 0xff
// 006fa9a4  7eeb                 jle 0x6fa991
// 006fa9a6  56                   push esi
// 006fa9a7  57                   push edi
// 006fa9a8  e8b3feffff           call 0x6fa860
// 006fa9ad  83c408               add esp, 8
// 006fa9b0  5f                   pop edi
// 006fa9b1  5e                   pop esi
// 006fa9b2  83c420               add esp, 0x20
// 006fa9b5  c3                   ret 
// 006fa9b6  8bff                 mov edi, edi
// 006fa9b8  0ba96f000ba9         or ebp, dword ptr [ecx - 0x56f4ff91]
// 006fa9be  6f                   outsd dx, dword ptr [esi]
// 006fa9bf  000b                 add byte ptr [ebx], cl
// 006fa9c1  a96f009ca9           test eax, 0xa99c006f
// 006fa9c6  6f                   outsd dx, dword ptr [esi]
// 006fa9c7  000b                 add byte ptr [ebx], cl
// library lua-5.1/lcode.c (function _luaK_exp2RK)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
