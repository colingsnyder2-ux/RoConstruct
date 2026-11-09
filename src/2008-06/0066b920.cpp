// from server: 100% by auto
// roc 2008-06 0066b920  unit: RBX::GroupDragTool  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066b920
//
// 0066b920  83ec20               sub esp, 0x20
// 0066b923  56                   push esi
// 0066b924  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0066b928  8b4610               mov eax, dword ptr [esi + 0x10]
// 0066b92b  57                   push edi
// 0066b92c  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0066b930  56                   push esi
// 0066b931  57                   push edi
// 0066b932  3b4614               cmp eax, dword ptr [esi + 0x14]
// 0066b935  7407                 je 0x66b93e
// 0066b937  e874ffffff           call 0x66b8b0
// 0066b93c  eb05                 jmp 0x66b943
// 0066b93e  e85dfbffff           call 0x66b4a0
// 0066b943  8b06                 mov eax, dword ptr [esi]
// 0066b945  8d48ff               lea ecx, [eax - 1]
// 0066b948  83c408               add esp, 8
// 0066b94b  83f904               cmp ecx, 4
// 0066b94e  0f87a2000000         ja 0x66b9f6
// 0066b954  ff248d08ba6600       jmp dword ptr [ecx*4 + 0x66ba08]
// 0066b95b  817f28ff000000       cmp dword ptr [edi + 0x28], 0xff
// 0066b962  0f8f8e000000         jg 0x66b9f6
// 0066b968  83f801               cmp eax, 1
// 0066b96b  7519                 jne 0x66b986
// 0066b96d  8b4f04               mov ecx, dword ptr [edi + 4]
// 0066b970  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0066b978  c744241005000000     mov dword ptr [esp + 0x10], 5
// 0066b980  8d542418             lea edx, [esp + 0x18]
// 0066b984  eb3f                 jmp 0x66b9c5
// 0066b986  83f805               cmp eax, 5
// 0066b989  7526                 jne 0x66b9b1
// 0066b98b  dd4608               fld qword ptr [esi + 8]
// 0066b98e  83ec08               sub esp, 8
// 0066b991  dd1c24               fstp qword ptr [esp]
// 0066b994  57                   push edi
// 0066b995  e876f5ffff           call 0x66af10
// 0066b99a  83c40c               add esp, 0xc
// 0066b99d  894608               mov dword ptr [esi + 8], eax
// 0066b9a0  5f                   pop edi
// 0066b9a1  c70604000000         mov dword ptr [esi], 4
// 0066b9a7  0d00010000           or eax, 0x100
// 0066b9ac  5e                   pop esi
// 0066b9ad  83c420               add esp, 0x20
// 0066b9b0  c3                   ret 
// 0066b9b1  33c9                 xor ecx, ecx
// 0066b9b3  83f802               cmp eax, 2
// 0066b9b6  0f94c1               sete cl
// 0066b9b9  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0066b9c1  8d542408             lea edx, [esp + 8]
// 0066b9c5  894c2408             mov dword ptr [esp + 8], ecx
// 0066b9c9  52                   push edx
// 0066b9ca  8d4c240c             lea ecx, [esp + 0xc]
// 0066b9ce  8bc7                 mov eax, edi
// 0066b9d0  e82bf4ffff           call 0x66ae00
// 0066b9d5  83c404               add esp, 4
// 0066b9d8  894608               mov dword ptr [esi + 8], eax
// 0066b9db  c70604000000         mov dword ptr [esi], 4
// 0066b9e1  5f                   pop edi
// 0066b9e2  0d00010000           or eax, 0x100
// 0066b9e7  5e                   pop esi
// 0066b9e8  83c420               add esp, 0x20
// 0066b9eb  c3                   ret 
// 0066b9ec  8b4608               mov eax, dword ptr [esi + 8]
// 0066b9ef  3dff000000           cmp eax, 0xff
// 0066b9f4  7eeb                 jle 0x66b9e1
// 0066b9f6  56                   push esi
// 0066b9f7  57                   push edi
// 0066b9f8  e8b3feffff           call 0x66b8b0
// 0066b9fd  83c408               add esp, 8
// 0066ba00  5f                   pop edi
// 0066ba01  5e                   pop esi
// 0066ba02  83c420               add esp, 0x20
// 0066ba05  c3                   ret 
// 0066ba06  8bff                 mov edi, edi
// 0066ba08  5b                   pop ebx
// 0066ba09  b966005bb9           mov ecx, 0xb95b0066
// 0066ba0e  66005bb9             add byte ptr [ebx - 0x47], bl
// 0066ba12  6600ec               add ah, ch
// 0066ba15  b966005bb9           mov ecx, 0xb95b0066
// library lua-5.1/lcode.c (function _luaK_exp2RK)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
