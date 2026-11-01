// from server: 100% by auto
// roc 2009-06 006fa450  unit: RBX::GroupDragTool  size: 256 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fa450
//
// 006fa450  57                   push edi
// 006fa451  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006fa455  8b07                 mov eax, dword ptr [edi]
// 006fa457  83c0fa               add eax, -6
// 006fa45a  83f808               cmp eax, 8
// 006fa45d  0f87c6000000         ja 0x6fa529
// 006fa463  56                   push esi
// 006fa464  ff24852ca56f00       jmp dword ptr [eax*4 + 0x6fa52c]
// 006fa46b  5e                   pop esi
// 006fa46c  c7070c000000         mov dword ptr [edi], 0xc
// 006fa472  5f                   pop edi
// 006fa473  c3                   ret 
// 006fa474  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa478  8b4708               mov eax, dword ptr [edi + 8]
// 006fa47b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006fa47e  8b5108               mov edx, dword ptr [ecx + 8]
// 006fa481  c1e017               shl eax, 0x17
// 006fa484  52                   push edx
// 006fa485  83c804               or eax, 4
// 006fa488  50                   push eax
// 006fa489  e8a2fcffff           call 0x6fa130
// 006fa48e  83c408               add esp, 8
// 006fa491  5e                   pop esi
// 006fa492  894708               mov dword ptr [edi + 8], eax
// 006fa495  c7070b000000         mov dword ptr [edi], 0xb
// 006fa49b  5f                   pop edi
// 006fa49c  c3                   ret 
// 006fa49d  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006fa4a1  8b4708               mov eax, dword ptr [edi + 8]
// 006fa4a4  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006fa4a7  8b5108               mov edx, dword ptr [ecx + 8]
// 006fa4aa  c1e00e               shl eax, 0xe
// 006fa4ad  52                   push edx
// 006fa4ae  83c805               or eax, 5
// 006fa4b1  50                   push eax
// 006fa4b2  e879fcffff           call 0x6fa130
// 006fa4b7  83c408               add esp, 8
// 006fa4ba  5e                   pop esi
// 006fa4bb  894708               mov dword ptr [edi + 8], eax
// 006fa4be  c7070b000000         mov dword ptr [edi], 0xb
// 006fa4c4  5f                   pop edi
// 006fa4c5  c3                   ret 
// 006fa4c6  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 006fa4c9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fa4cd  83caff               or edx, 0xffffffff
// 006fa4d0  f7c100010000         test ecx, 0x100
// 006fa4d6  750b                 jne 0x6fa4e3
// 006fa4d8  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 006fa4dc  3bce                 cmp ecx, esi
// 006fa4de  7c03                 jl 0x6fa4e3
// 006fa4e0  015024               add dword ptr [eax + 0x24], edx
// 006fa4e3  8b4f08               mov ecx, dword ptr [edi + 8]
// 006fa4e6  f7c100010000         test ecx, 0x100
// 006fa4ec  750b                 jne 0x6fa4f9
// 006fa4ee  0fb67032             movzx esi, byte ptr [eax + 0x32]
// 006fa4f2  3bce                 cmp ecx, esi
// 006fa4f4  7c03                 jl 0x6fa4f9
// 006fa4f6  015024               add dword ptr [eax + 0x24], edx
// 006fa4f9  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 006fa4fc  8b5708               mov edx, dword ptr [edi + 8]
// 006fa4ff  51                   push ecx
// 006fa500  52                   push edx
// 006fa501  6a00                 push 0
// 006fa503  6a06                 push 6
// 006fa505  50                   push eax
// 006fa506  e8c5fcffff           call 0x6fa1d0
// 006fa50b  83c414               add esp, 0x14
// 006fa50e  5e                   pop esi
// 006fa50f  894708               mov dword ptr [edi + 8], eax
// 006fa512  c7070b000000         mov dword ptr [edi], 0xb
// 006fa518  5f                   pop edi
// 006fa519  c3                   ret 
// 006fa51a  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006fa51e  57                   push edi
// 006fa51f  50                   push eax
// 006fa520  e84bfaffff           call 0x6f9f70
// 006fa525  83c408               add esp, 8
// 006fa528  5e                   pop esi
// 006fa529  5f                   pop edi
// 006fa52a  c3                   ret 
// 006fa52b  90                   nop 
// 006fa52c  6ba46f0074a46f00     imul esp, dword ptr [edi + ebp*2 + 0x6fa47400], 0
// 006fa534  9d                   popfd 
// 006fa535  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 006fa536  6f                   outsd dx, dword ptr [esi]
// 006fa537  00c6                 add dh, al
// 006fa539  a4                   movsb byte ptr es:[edi], byte ptr [esi]
// 006fa53a  6f                   outsd dx, dword ptr [esi]
// 006fa53b  0028                 add byte ptr [eax], ch
// 006fa53d  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa53e  6f                   outsd dx, dword ptr [esi]
// 006fa53f  0028                 add byte ptr [eax], ch
// 006fa541  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa542  6f                   outsd dx, dword ptr [esi]
// 006fa543  0028                 add byte ptr [eax], ch
// 006fa545  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa546  6f                   outsd dx, dword ptr [esi]
// 006fa547  001a                 add byte ptr [edx], bl
// 006fa549  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa54a  6f                   outsd dx, dword ptr [esi]
// 006fa54b  001a                 add byte ptr [edx], bl
// 006fa54d  a5                   movsd dword ptr es:[edi], dword ptr [esi]
// 006fa54e  6f                   outsd dx, dword ptr [esi]
// library lua-5.1/lcode.c (function _luaK_dischargevars)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
