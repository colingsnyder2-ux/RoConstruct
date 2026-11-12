// from server: 100% by auto
// roc 2008-06 004be6f0  unit: ProfiledRakPeer  size: 252 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004be6f0
//
// 004be6f0  55                   push ebp
// 004be6f1  8bec                 mov ebp, esp
// 004be6f3  83ec50               sub esp, 0x50
// 004be6f6  53                   push ebx
// 004be6f7  56                   push esi
// 004be6f8  8b7508               mov esi, dword ptr [ebp + 8]
// 004be6fb  57                   push edi
// 004be6fc  6a00                 push 0
// 004be6fe  8d45f0               lea eax, [ebp - 0x10]
// 004be701  6a00                 push 0
// 004be703  b910000000           mov ecx, 0x10
// 004be708  8d7db0               lea edi, [ebp - 0x50]
// 004be70b  50                   push eax
// 004be70c  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 004be70e  e8f12f1e00           call 0x6a1704
// 004be713  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004be716  6a40                 push 0x40
// 004be718  6a00                 push 0
// 004be71a  51                   push ecx
// 004be71b  e8e42f1e00           call 0x6a1704
// 004be720  33c0                 xor eax, eax
// 004be722  83c418               add esp, 0x18
// 004be725  33c9                 xor ecx, ecx
// 004be727  894508               mov dword ptr [ebp + 8], eax
// 004be72a  894df8               mov dword ptr [ebp - 8], ecx
// 004be72d  8d4900               lea ecx, [ecx]
// 004be730  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004be733  8b1c8a               mov ebx, dword ptr [edx + ecx*4]
// 004be736  c745fc20000000       mov dword ptr [ebp - 4], 0x20
// 004be73d  85db                 test ebx, ebx
// 004be73f  0f848a000000         je 0x4be7cf
// 004be745  f6c301               test bl, 1
// 004be748  746d                 je 0x4be7b7
// 004be74a  85c0                 test eax, eax
// 004be74c  7414                 je 0x4be762
// 004be74e  50                   push eax
// 004be74f  8d45b0               lea eax, [ebp - 0x50]
// 004be752  50                   push eax
// 004be753  e848e2ffff           call 0x4bc9a0
// 004be758  83c408               add esp, 8
// 004be75b  c7450800000000       mov dword ptr [ebp + 8], 0
// 004be762  8d4db0               lea ecx, [ebp - 0x50]
// 004be765  894df0               mov dword ptr [ebp - 0x10], ecx
// 004be768  c745f403000000       mov dword ptr [ebp - 0xc], 3
// 004be76f  8b75f0               mov esi, dword ptr [ebp - 0x10]
// 004be772  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 004be775  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004be778  8b06                 mov eax, dword ptr [esi]
// 004be77a  33d2                 xor edx, edx
// 004be77c  0107                 add dword ptr [edi], eax
// 004be77e  8b4604               mov eax, dword ptr [esi + 4]
// 004be781  114704               adc dword ptr [edi + 4], eax
// 004be784  8b4608               mov eax, dword ptr [esi + 8]
// 004be787  114708               adc dword ptr [edi + 8], eax
// 004be78a  8b460c               mov eax, dword ptr [esi + 0xc]
// 004be78d  11470c               adc dword ptr [edi + 0xc], eax
// 004be790  e322                 jecxz 0x4be7b4
// 004be792  42                   inc edx
// 004be793  42                   inc edx
// 004be794  8b04d6               mov eax, dword ptr [esi + edx*8]
// 004be797  1104d7               adc dword ptr [edi + edx*8], eax
// 004be79a  8b44d604             mov eax, dword ptr [esi + edx*8 + 4]
// 004be79e  1144d704             adc dword ptr [edi + edx*8 + 4], eax
// 004be7a2  8b44d608             mov eax, dword ptr [esi + edx*8 + 8]
// 004be7a6  1144d708             adc dword ptr [edi + edx*8 + 8], eax
// 004be7aa  8b44d60c             mov eax, dword ptr [esi + edx*8 + 0xc]
// 004be7ae  1144d70c             adc dword ptr [edi + edx*8 + 0xc], eax
// 004be7b2  e2de                 loop 0x4be792
// 004be7b4  8b4508               mov eax, dword ptr [ebp + 8]
// 004be7b7  8145fcffff0000       add dword ptr [ebp - 4], 0xffff
// 004be7be  d1eb                 shr ebx, 1
// 004be7c0  40                   inc eax
// 004be7c1  894508               mov dword ptr [ebp + 8], eax
// 004be7c4  85db                 test ebx, ebx
// 004be7c6  0f8579ffffff         jne 0x4be745
// 004be7cc  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004be7cf  0fb755fc             movzx edx, word ptr [ebp - 4]
// 004be7d3  41                   inc ecx
// 004be7d4  03c2                 add eax, edx
// 004be7d6  894508               mov dword ptr [ebp + 8], eax
// 004be7d9  894df8               mov dword ptr [ebp - 8], ecx
// 004be7dc  83f910               cmp ecx, 0x10
// 004be7df  0f824bffffff         jb 0x4be730
// 004be7e5  5f                   pop edi
// 004be7e6  5e                   pop esi
// 004be7e7  5b                   pop ebx
// 004be7e8  8be5                 mov esp, ebp
// 004be7ea  5d                   pop ebp
// 004be7eb  c3                   ret 
// library openrbx-raknet/RakPeer.cpp (function ??$umultiply@$$BY0BA@I$$BY0BA@I@big@@YAXAAY0BA@I00@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet RakPeer.cpp
