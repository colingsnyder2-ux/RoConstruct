// from server: 100% by auto
// roc 2009-12 007dc300  unit: RBX::GroupDragTool  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dc300
//
// 007dc300  8b542408             mov edx, dword ptr [esp + 8]
// 007dc304  8b02                 mov eax, dword ptr [edx]
// 007dc306  83f80d               cmp eax, 0xd
// 007dc309  7523                 jne 0x7dc32e
// 007dc30b  8b4208               mov eax, dword ptr [edx + 8]
// 007dc30e  8b4c2404             mov ecx, dword ptr [esp + 4]
// 007dc312  8b11                 mov edx, dword ptr [ecx]
// 007dc314  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 007dc317  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007dc31b  42                   inc edx
// 007dc31c  c1e20e               shl edx, 0xe
// 007dc31f  331481               xor edx, dword ptr [ecx + eax*4]
// 007dc322  8d0481               lea eax, [ecx + eax*4]
// 007dc325  81e200c07f00         and edx, 0x7fc000
// 007dc32b  3110                 xor dword ptr [eax], edx
// 007dc32d  c3                   ret 
// 007dc32e  83f80e               cmp eax, 0xe
// 007dc331  754d                 jne 0x7dc380
// 007dc333  8b4a08               mov ecx, dword ptr [edx + 8]
// 007dc336  8b442404             mov eax, dword ptr [esp + 4]
// 007dc33a  56                   push esi
// 007dc33b  8b30                 mov esi, dword ptr [eax]
// 007dc33d  8b760c               mov esi, dword ptr [esi + 0xc]
// 007dc340  8d0c8e               lea ecx, [esi + ecx*4]
// 007dc343  8b742410             mov esi, dword ptr [esp + 0x10]
// 007dc347  57                   push edi
// 007dc348  8b39                 mov edi, dword ptr [ecx]
// 007dc34a  46                   inc esi
// 007dc34b  c1e617               shl esi, 0x17
// 007dc34e  81e7ffff7f00         and edi, 0x7fffff
// 007dc354  33f7                 xor esi, edi
// 007dc356  8931                 mov dword ptr [ecx], esi
// 007dc358  8b5208               mov edx, dword ptr [edx + 8]
// 007dc35b  8b08                 mov ecx, dword ptr [eax]
// 007dc35d  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007dc360  8d0c91               lea ecx, [ecx + edx*4]
// 007dc363  8b5024               mov edx, dword ptr [eax + 0x24]
// 007dc366  c1e206               shl edx, 6
// 007dc369  3311                 xor edx, dword ptr [ecx]
// 007dc36b  6a01                 push 1
// 007dc36d  81e2c03f0000         and edx, 0x3fc0
// 007dc373  3111                 xor dword ptr [ecx], edx
// 007dc375  50                   push eax
// 007dc376  e8e5fdffff           call 0x7dc160
// 007dc37b  83c408               add esp, 8
// 007dc37e  5f                   pop edi
// 007dc37f  5e                   pop esi
// 007dc380  c3                   ret 
// library lua-5.1/lcode.c (function _luaK_setreturns)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
