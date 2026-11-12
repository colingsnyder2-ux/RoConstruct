// from server: 100% by auto
// roc 2008-06 004be4e0  unit: ProfiledRakPeer  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004be4e0
//
// 004be4e0  55                   push ebp
// 004be4e1  8bec                 mov ebp, esp
// 004be4e3  83ec34               sub esp, 0x34
// 004be4e6  8b4508               mov eax, dword ptr [ebp + 8]
// 004be4e9  53                   push ebx
// 004be4ea  56                   push esi
// 004be4eb  57                   push edi
// 004be4ec  8bf0                 mov esi, eax
// 004be4ee  b908000000           mov ecx, 8
// 004be4f3  8d7dcc               lea edi, [ebp - 0x34]
// 004be4f6  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be4f8  33c9                 xor ecx, ecx
// 004be4fa  8908                 mov dword ptr [eax], ecx
// 004be4fc  894804               mov dword ptr [eax + 4], ecx
// 004be4ff  894808               mov dword ptr [eax + 8], ecx
// 004be502  89480c               mov dword ptr [eax + 0xc], ecx
// 004be505  894810               mov dword ptr [eax + 0x10], ecx
// 004be508  894814               mov dword ptr [eax + 0x14], ecx
// 004be50b  894818               mov dword ptr [eax + 0x18], ecx
// 004be50e  89481c               mov dword ptr [eax + 0x1c], ecx
// 004be511  33c0                 xor eax, eax
// 004be513  8945fc               mov dword ptr [ebp - 4], eax
// 004be516  894df4               mov dword ptr [ebp - 0xc], ecx
// 004be519  8da42400000000       lea esp, [esp]
// 004be520  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004be523  8b1c8a               mov ebx, dword ptr [edx + ecx*4]
// 004be526  c745f820000000       mov dword ptr [ebp - 8], 0x20
// 004be52d  85db                 test ebx, ebx
// 004be52f  0f848a000000         je 0x4be5bf
// 004be535  f6c301               test bl, 1
// 004be538  746d                 je 0x4be5a7
// 004be53a  85c0                 test eax, eax
// 004be53c  7414                 je 0x4be552
// 004be53e  50                   push eax
// 004be53f  8d45cc               lea eax, [ebp - 0x34]
// 004be542  50                   push eax
// 004be543  e898e2ffff           call 0x4bc7e0
// 004be548  83c408               add esp, 8
// 004be54b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004be552  8d4dcc               lea ecx, [ebp - 0x34]
// 004be555  894dec               mov dword ptr [ebp - 0x14], ecx
// 004be558  c745f001000000       mov dword ptr [ebp - 0x10], 1
// 004be55f  8b75ec               mov esi, dword ptr [ebp - 0x14]
// 004be562  8b7d08               mov edi, dword ptr [ebp + 8]
// 004be565  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004be568  8b06                 mov eax, dword ptr [esi]
// 004be56a  33d2                 xor edx, edx
// 004be56c  0107                 add dword ptr [edi], eax
// 004be56e  8b4604               mov eax, dword ptr [esi + 4]
// 004be571  114704               adc dword ptr [edi + 4], eax
// 004be574  8b4608               mov eax, dword ptr [esi + 8]
// 004be577  114708               adc dword ptr [edi + 8], eax
// 004be57a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be57d  11470c               adc dword ptr [edi + 0xc], eax
// 004be580  e322                 jecxz 0x4be5a4
// 004be582  42                   inc edx
// 004be583  42                   inc edx
// 004be584  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004be587  1104d7               adc dword ptr [edi + edx*8], eax
// 004be58a  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004be58e  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004be592  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004be596  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004be59a  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004be59e  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004be5a2  e2de                 loop 0x4be582
// 004be5a4  8b45fc               mov eax, dword ptr [ebp - 4]
// 004be5a7  8145f8ffff0000       add dword ptr [ebp - 8], 0xffff
// 004be5ae  d1eb                 shr ebx, 1
// 004be5b0  40                   inc eax
// 004be5b1  8945fc               mov dword ptr [ebp - 4], eax
// 004be5b4  85db                 test ebx, ebx
// 004be5b6  0f8579ffffff         jne 0x4be535
// 004be5bc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004be5bf  0fb755f8             movzx edx, word ptr [ebp - 8]
// 004be5c3  41                   inc ecx
// 004be5c4  03c2                 add eax, edx
// 004be5c6  8945fc               mov dword ptr [ebp - 4], eax
// 004be5c9  894df4               mov dword ptr [ebp - 0xc], ecx
// 004be5cc  83f908               cmp ecx, 8
// 004be5cf  0f824bffffff         jb 0x4be520
// 004be5d5  5f                   pop edi
// 004be5d6  5e                   pop esi
// 004be5d7  5b                   pop ebx
// 004be5d8  8be5                 mov esp, ebp
// 004be5da  5d                   pop ebp
// 004be5db  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umultiply@$$BY07I$$BY07I@big@@YAXAAY07I0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
