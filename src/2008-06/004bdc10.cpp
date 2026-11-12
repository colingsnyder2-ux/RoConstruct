// from server: 100% by auto
// roc 2008-06 004bdc10  unit: ProfiledRakPeer  size: 271 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004bdc10
//
// 004bdc10  55                   push ebp
// 004bdc11  8bec                 mov ebp, esp
// 004bdc13  83ec30               sub esp, 0x30
// 004bdc16  8b4508               mov eax, dword ptr [ebp + 8]
// 004bdc19  8b08                 mov ecx, dword ptr [eax]
// 004bdc1b  8b5004               mov edx, dword ptr [eax + 4]
// 004bdc1e  894dd0               mov dword ptr [ebp - 0x30], ecx
// 004bdc21  8b4808               mov ecx, dword ptr [eax + 8]
// 004bdc24  8955d4               mov dword ptr [ebp - 0x2c], edx
// 004bdc27  8b500c               mov edx, dword ptr [eax + 0xc]
// 004bdc2a  33c0                 xor eax, eax
// 004bdc2c  894dd8               mov dword ptr [ebp - 0x28], ecx
// 004bdc2f  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004bdc32  8901                 mov dword ptr [ecx], eax
// 004bdc34  894104               mov dword ptr [ecx + 4], eax
// 004bdc37  894108               mov dword ptr [ecx + 8], eax
// 004bdc3a  89410c               mov dword ptr [ecx + 0xc], eax
// 004bdc3d  894110               mov dword ptr [ecx + 0x10], eax
// 004bdc40  894114               mov dword ptr [ecx + 0x14], eax
// 004bdc43  894118               mov dword ptr [ecx + 0x18], eax
// 004bdc46  53                   push ebx
// 004bdc47  89411c               mov dword ptr [ecx + 0x1c], eax
// 004bdc4a  33c9                 xor ecx, ecx
// 004bdc4c  56                   push esi
// 004bdc4d  8955dc               mov dword ptr [ebp - 0x24], edx
// 004bdc50  8945e0               mov dword ptr [ebp - 0x20], eax
// 004bdc53  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004bdc56  8945e8               mov dword ptr [ebp - 0x18], eax
// 004bdc59  8945ec               mov dword ptr [ebp - 0x14], eax
// 004bdc5c  894508               mov dword ptr [ebp + 8], eax
// 004bdc5f  894df8               mov dword ptr [ebp - 8], ecx
// 004bdc62  57                   push edi
// 004bdc63  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004bdc66  8b1c8a               mov ebx, dword ptr [edx + ecx*4]
// 004bdc69  c745fc20000000       mov dword ptr [ebp - 4], 0x20
// 004bdc70  85db                 test ebx, ebx
// 004bdc72  0f848a000000         je 0x4bdd02
// 004bdc78  f6c301               test bl, 1
// 004bdc7b  746d                 je 0x4bdcea
// 004bdc7d  85c0                 test eax, eax
// 004bdc7f  7414                 je 0x4bdc95
// 004bdc81  50                   push eax
// 004bdc82  8d45d0               lea eax, [ebp - 0x30]
// 004bdc85  50                   push eax
// 004bdc86  e855ebffff           call 0x4bc7e0
// 004bdc8b  83c408               add esp, 8
// 004bdc8e  c7450800000000       mov dword ptr [ebp + 8], 0
// 004bdc95  8d4dd0               lea ecx, [ebp - 0x30]
// 004bdc98  894df0               mov dword ptr [ebp - 0x10], ecx
// 004bdc9b  c745f401000000       mov dword ptr [ebp - 0xc], 1
// 004bdca2  8b75f0               mov esi, dword ptr [ebp - 0x10]
// 004bdca5  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004bdca8  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004bdcab  8b06                 mov eax, dword ptr [esi]
// 004bdcad  33d2                 xor edx, edx
// 004bdcaf  0107                 add dword ptr [edi], eax
// 004bdcb1  8b4604               mov eax, dword ptr [esi + 4]
// 004bdcb4  114704               adc dword ptr [edi + 4], eax
// 004bdcb7  8b4608               mov eax, dword ptr [esi + 8]
// 004bdcba  114708               adc dword ptr [edi + 8], eax
// 004bdcbd  8b460c               mov eax, dword ptr [esi + 0xc]
// 004bdcc0  11470c               adc dword ptr [edi + 0xc], eax
// 004bdcc3  e322                 jecxz 0x4bdce7
// 004bdcc5  42                   inc edx
// 004bdcc6  42                   inc edx
// 004bdcc7  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004bdcca  1104d7               adc dword ptr [edi + edx*8], eax
// 004bdccd  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004bdcd1  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004bdcd5  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004bdcd9  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004bdcdd  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004bdce1  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004bdce5  e2de                 loop 0x4bdcc5
// 004bdce7  8b4508               mov eax, dword ptr [ebp + 8]
// 004bdcea  8145fcffff0000       add dword ptr [ebp - 4], 0xffff
// 004bdcf1  d1eb                 shr ebx, 1
// 004bdcf3  40                   inc eax
// 004bdcf4  894508               mov dword ptr [ebp + 8], eax
// 004bdcf7  85db                 test ebx, ebx
// 004bdcf9  0f8579ffffff         jne 0x4bdc78
// 004bdcff  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004bdd02  0fb755fc             movzx edx, word ptr [ebp - 4]
// 004bdd06  41                   inc ecx
// 004bdd07  03c2                 add eax, edx
// 004bdd09  894508               mov dword ptr [ebp + 8], eax
// 004bdd0c  894df8               mov dword ptr [ebp - 8], ecx
// 004bdd0f  83f904               cmp ecx, 4
// 004bdd12  0f824bffffff         jb 0x4bdc63
// 004bdd18  5f                   pop edi
// 004bdd19  5e                   pop esi
// 004bdd1a  5b                   pop ebx
// 004bdd1b  8be5                 mov esp, ebp
// 004bdd1d  5d                   pop ebp
// 004bdd1e  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umultiply@$$BY03I$$BY07I@big@@YAXAAY03I0AAY07I@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
