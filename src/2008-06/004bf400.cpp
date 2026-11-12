// from server: 100% by auto
// roc 2008-06 004bf400  unit: ProfiledRakPeer  size: 268 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bf400
//
// 004bf400  55                   push ebp
// 004bf401  8bec                 mov ebp, esp
// 004bf403  83ec30               sub esp, 0x30
// 004bf406  53                   push ebx
// 004bf407  56                   push esi
// 004bf408  8b7508               mov esi, dword ptr [ebp + 8]
// 004bf40b  57                   push edi
// 004bf40c  6a00                 push 0
// 004bf40e  8d45f0               lea eax, [ebp - 0x10]
// 004bf411  6a00                 push 0
// 004bf413  b908000000           mov ecx, 8
// 004bf418  8d7dd0               lea edi, [ebp - 0x30]
// 004bf41b  50                   push eax
// 004bf41c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004bf41e  e8e1221e00           call 0x6a1704
// 004bf423  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bf426  33c0                 xor eax, eax
// 004bf428  8901                 mov dword ptr [ecx], eax
// 004bf42a  894104               mov dword ptr [ecx + 4], eax
// 004bf42d  894108               mov dword ptr [ecx + 8], eax
// 004bf430  89410c               mov dword ptr [ecx + 0xc], eax
// 004bf433  894110               mov dword ptr [ecx + 0x10], eax
// 004bf436  894114               mov dword ptr [ecx + 0x14], eax
// 004bf439  894118               mov dword ptr [ecx + 0x18], eax
// 004bf43c  83c40c               add esp, 0xc
// 004bf43f  89411c               mov dword ptr [ecx + 0x1c], eax
// 004bf442  33c9                 xor ecx, ecx
// 004bf444  894508               mov dword ptr [ebp + 8], eax
// 004bf447  894df8               mov dword ptr [ebp - 8], ecx
// 004bf44a  8d9b00000000         lea ebx, [ebx]
// 004bf450  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004bf453  8b1c8a               mov ebx, dword ptr [edx + ecx*4]
// 004bf456  c745fc20000000       mov dword ptr [ebp - 4], 0x20
// 004bf45d  85db                 test ebx, ebx
// 004bf45f  0f848a000000         je 0x4bf4ef
// 004bf465  f6c301               test bl, 1
// 004bf468  746d                 je 0x4bf4d7
// 004bf46a  85c0                 test eax, eax
// 004bf46c  7414                 je 0x4bf482
// 004bf46e  50                   push eax
// 004bf46f  8d45d0               lea eax, [ebp - 0x30]
// 004bf472  50                   push eax
// 004bf473  e868d3ffff           call 0x4bc7e0
// 004bf478  83c408               add esp, 8
// 004bf47b  c7450800000000       mov dword ptr [ebp + 8], 0
// 004bf482  8d4dd0               lea ecx, [ebp - 0x30]
// 004bf485  894df0               mov dword ptr [ebp - 0x10], ecx
// 004bf488  c745f401000000       mov dword ptr [ebp - 0xc], 1
// 004bf48f  8b75f0               mov esi, dword ptr [ebp - 0x10]
// 004bf492  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004bf495  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004bf498  8b06                 mov eax, dword ptr [esi]
// 004bf49a  33d2                 xor edx, edx
// 004bf49c  0107                 add dword ptr [edi], eax
// 004bf49e  8b4604               mov eax, dword ptr [esi + 4]
// 004bf4a1  114704               adc dword ptr [edi + 4], eax
// 004bf4a4  8b4608               mov eax, dword ptr [esi + 8]
// 004bf4a7  114708               adc dword ptr [edi + 8], eax
// 004bf4aa  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bf4ad  11470c               adc dword ptr [edi + 0xc], eax
// 004bf4b0  e322                 jecxz 0x4bf4d4
// 004bf4b2  42                   inc edx
// 004bf4b3  42                   inc edx
// 004bf4b4  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bf4b7  1104d7               adc dword ptr [edi + edx*8], eax
// 004bf4ba  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bf4be  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004bf4c2  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bf4c6  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004bf4ca  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bf4ce  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004bf4d2  e2de                 loop 0x4bf4b2
// 004bf4d4  8b4508               mov eax, dword ptr [ebp + 8]
// 004bf4d7  8145fcffff0000       add dword ptr [ebp - 4], 0xffff
// 004bf4de  d1eb                 shr ebx, 1
// 004bf4e0  40                   inc eax
// 004bf4e1  894508               mov dword ptr [ebp + 8], eax
// 004bf4e4  85db                 test ebx, ebx
// 004bf4e6  0f8579ffffff         jne 0x4bf465
// 004bf4ec  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004bf4ef  0fb755fc             movzx edx, word ptr [ebp - 4]
// 004bf4f3  41                   inc ecx
// 004bf4f4  03c2                 add eax, edx
// 004bf4f6  894508               mov dword ptr [ebp + 8], eax
// 004bf4f9  894df8               mov dword ptr [ebp - 8], ecx
// 004bf4fc  83f908               cmp ecx, 8
// 004bf4ff  0f824bffffff         jb 0x4bf450
// 004bf505  5f                   pop edi
// 004bf506  5e                   pop esi
// 004bf507  5b                   pop ebx
// 004bf508  8be5                 mov esp, ebp
// 004bf50a  5d                   pop ebp
// 004bf50b  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umultiply@$$BY07I$$BY07I@big@@YAXAAY07I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
