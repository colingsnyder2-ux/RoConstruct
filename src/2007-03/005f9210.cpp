// from server: 100% by auto
// roc 2007-03 005f9210  unit: seg_005f0000  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005f9210
//
// 005f9210  8b442404             mov eax, dword ptr [esp + 4]
// 005f9214  53                   push ebx
// 005f9215  55                   push ebp
// 005f9216  8b6810               mov ebp, dword ptr [eax + 0x10]
// 005f9219  0fb65d14             movzx ebx, byte ptr [ebp + 0x14]
// 005f921d  56                   push esi
// 005f921e  57                   push edi
// 005f921f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005f9223  8b37                 mov esi, dword ptr [edi]
// 005f9225  83f303               xor ebx, 3
// 005f9228  85f6                 test esi, esi
// 005f922a  746b                 je 0x5f9297
// 005f922c  8d642400             lea esp, [esp]
// 005f9230  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 005f9234  8bc8                 mov ecx, eax
// 005f9236  83e801               sub eax, 1
// 005f9239  85c9                 test ecx, ecx
// 005f923b  8944241c             mov dword ptr [esp + 0x1c], eax
// 005f923f  7656                 jbe 0x5f9297
// 005f9241  807e0408             cmp byte ptr [esi + 4], 8
// 005f9245  7513                 jne 0x5f925a
// 005f9247  8b442414             mov eax, dword ptr [esp + 0x14]
// 005f924b  6afd                 push -3
// 005f924d  8d5668               lea edx, [esi + 0x68]
// 005f9250  52                   push edx
// 005f9251  50                   push eax
// 005f9252  e8b9ffffff           call 0x5f9210
// 005f9257  83c40c               add esp, 0xc
// 005f925a  8a4605               mov al, byte ptr [esi + 5]
// 005f925d  0fb6c8               movzx ecx, al
// 005f9260  83f103               xor ecx, 3
// 005f9263  85cb                 test ebx, ecx
// 005f9265  7411                 je 0x5f9278
// 005f9267  8a5514               mov dl, byte ptr [ebp + 0x14]
// 005f926a  80e203               and dl, 3
// 005f926d  24f8                 and al, 0xf8
// 005f926f  0ad0                 or dl, al
// 005f9271  885605               mov byte ptr [esi + 5], dl
// 005f9274  8bfe                 mov edi, esi
// 005f9276  eb19                 jmp 0x5f9291
// 005f9278  8b06                 mov eax, dword ptr [esi]
// 005f927a  8907                 mov dword ptr [edi], eax
// 005f927c  3b751c               cmp esi, dword ptr [ebp + 0x1c]
// 005f927f  7505                 jne 0x5f9286
// 005f9281  8b0e                 mov ecx, dword ptr [esi]
// 005f9283  894d1c               mov dword ptr [ebp + 0x1c], ecx
// 005f9286  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005f928a  8bc6                 mov eax, esi
// 005f928c  e8dffeffff           call 0x5f9170
// 005f9291  8b37                 mov esi, dword ptr [edi]
// 005f9293  85f6                 test esi, esi
// 005f9295  7599                 jne 0x5f9230
// 005f9297  8bc7                 mov eax, edi
// 005f9299  5f                   pop edi
// 005f929a  5e                   pop esi
// 005f929b  5d                   pop ebp
// 005f929c  5b                   pop ebx
// 005f929d  c3                   ret 
// library lua-5.1.1/lgc.c (function _sweeplist)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lgc.c
