// roc 2012-06 005be6b0  unit: RakNet::RakPeer  size: 301 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005be6b0
//
// 005be6b0  8b442418             mov eax, dword ptr [esp + 0x18]
// 005be6b4  81ece8000000         sub esp, 0xe8
// 005be6ba  53                   push ebx
// 005be6bb  55                   push ebp
// 005be6bc  56                   push esi
// 005be6bd  57                   push edi
// 005be6be  8be9                 mov ebp, ecx
// 005be6c0  85c0                 test eax, eax
// 005be6c2  750b                 jne 0x5be6cf
// 005be6c4  bfa05ee200           mov edi, 0xe25ea0
// 005be6c9  897c2414             mov dword ptr [esp + 0x14], edi
// 005be6cd  eb06                 jmp 0x5be6d5
// 005be6cf  89442414             mov dword ptr [esp + 0x14], eax
// 005be6d3  8bf8                 mov edi, eax
// 005be6d5  684c69e200           push 0xe2694c
// 005be6da  8d8c2400010000       lea ecx, [esp + 0x100]
// 005be6e1  e8ba31faff           call 0x5618a0
// 005be6e6  84c0                 test al, al
// 005be6e8  747d                 je 0x5be767
// 005be6ea  33c0                 xor eax, eax
// 005be6ec  33db                 xor ebx, ebx
// 005be6ee  c644241300           mov byte ptr [esp + 0x13], 0
// 005be6f3  663b450e             cmp ax, word ptr [ebp + 0xe]
// 005be6f7  735f                 jae 0x5be758
// 005be6f9  8da42400000000       lea esp, [esp]
// 005be700  8b952c020000         mov edx, dword ptr [ebp + 0x22c]
// 005be706  0fb7cb               movzx ecx, bx
// 005be709  69c908120000         imul ecx, ecx, 0x1208
// 005be70f  803c1100             cmp byte ptr [ecx + edx], 0
// 005be713  8d0411               lea eax, [ecx + edx]
// 005be716  7439                 je 0x5be751
// 005be718  8d4c2418             lea ecx, [esp + 0x18]
// 005be71c  51                   push ecx
// 005be71d  8d88f8000000         lea ecx, [eax + 0xf8]
// 005be723  e818bafdff           call 0x59a140
// 005be728  807c241300           cmp byte ptr [esp + 0x13], 0
// 005be72d  7516                 jne 0x5be745
// 005be72f  b938000000           mov ecx, 0x38
// 005be734  8d742418             lea esi, [esp + 0x18]
// 005be738  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 005be73a  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 005be73e  c644241301           mov byte ptr [esp + 0x13], 1
// 005be743  eb0c                 jmp 0x5be751
// 005be745  8d542418             lea edx, [esp + 0x18]
// 005be749  52                   push edx
// 005be74a  8bcf                 mov ecx, edi
// 005be74c  e8afbeffff           call 0x5ba600
// 005be751  43                   inc ebx
// 005be752  663b5d0e             cmp bx, word ptr [ebp + 0xe]
// 005be756  72a8                 jb 0x5be700
// 005be758  8bc7                 mov eax, edi
// 005be75a  5f                   pop edi
// 005be75b  5e                   pop esi
// 005be75c  5d                   pop ebp
// 005be75d  5b                   pop ebx
// 005be75e  81c4e8000000         add esp, 0xe8
// 005be764  c21800               ret 0x18
// 005be767  8b8c24fc000000       mov ecx, dword ptr [esp + 0xfc]
// 005be76e  8b942400010000       mov edx, dword ptr [esp + 0x100]
// 005be775  6a00                 push 0
// 005be777  6a00                 push 0
// 005be779  83ec14               sub esp, 0x14
// 005be77c  8bc4                 mov eax, esp
// 005be77e  8908                 mov dword ptr [eax], ecx
// 005be780  8b8c2420010000       mov ecx, dword ptr [esp + 0x120]
// 005be787  895004               mov dword ptr [eax + 4], edx
// 005be78a  8b942424010000       mov edx, dword ptr [esp + 0x124]
// 005be791  894808               mov dword ptr [eax + 8], ecx
// 005be794  8b8c2428010000       mov ecx, dword ptr [esp + 0x128]
// 005be79b  89500c               mov dword ptr [eax + 0xc], edx
// 005be79e  894810               mov dword ptr [eax + 0x10], ecx
// 005be7a1  8bcd                 mov ecx, ebp
// 005be7a3  e858d7ffff           call 0x5bbf00
// 005be7a8  85c0                 test eax, eax
// 005be7aa  7422                 je 0x5be7ce
// 005be7ac  8a5504               mov dl, byte ptr [ebp + 4]
// 005be7af  84d2                 test dl, dl
// 005be7b1  751b                 jne 0x5be7ce
// 005be7b3  57                   push edi
// 005be7b4  8d88f8000000         lea ecx, [eax + 0xf8]
// 005be7ba  e881b9fdff           call 0x59a140
// 005be7bf  8bc7                 mov eax, edi
// 005be7c1  5f                   pop edi
// 005be7c2  5e                   pop esi
// 005be7c3  5d                   pop ebp
// 005be7c4  5b                   pop ebx
// 005be7c5  81c4e8000000         add esp, 0xe8
// 005be7cb  c21800               ret 0x18
// 005be7ce  5f                   pop edi
// 005be7cf  5e                   pop esi
// 005be7d0  5d                   pop ebp
// 005be7d1  33c0                 xor eax, eax
// 005be7d3  5b                   pop ebx
// 005be7d4  81c4e8000000         add esp, 0xe8
// 005be7da  c21800               ret 0x18
// copied from an identical function in another client (function ?GetStatistics@RakPeer@RakNet@@UAEPAURakNetStatistics@2@USystemAddress@2@PAU32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-raknet RakPeer.cpp