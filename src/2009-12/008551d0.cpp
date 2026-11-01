// from server: 100% by auto
// roc 2009-12 008551d0  unit: CXTPTabClientWnd  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008551d0
//
// 008551d0  53                   push ebx
// 008551d1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 008551d5  56                   push esi
// 008551d6  57                   push edi
// 008551d7  8bf9                 mov edi, ecx
// 008551d9  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 008551df  d1ee                 shr esi, 1
// 008551e1  f7d6                 not esi
// 008551e3  6a02                 push 2
// 008551e5  8bcb                 mov ecx, ebx
// 008551e7  83e601               and esi, 1
// 008551ea  e8d1a10700           call 0x8cf3c0
// 008551ef  897008               mov dword ptr [eax + 8], esi
// 008551f2  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 008551f8  d1ee                 shr esi, 1
// 008551fa  6a04                 push 4
// 008551fc  8bcb                 mov ecx, ebx
// 008551fe  83e602               and esi, 2
// 00855201  e8baa10700           call 0x8cf3c0
// 00855206  897008               mov dword ptr [eax + 8], esi
// 00855209  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0085520f  8bc8                 mov ecx, eax
// 00855211  83e109               and ecx, 9
// 00855214  80f909               cmp cl, 9
// 00855217  7504                 jne 0x85521d
// 00855219  33f6                 xor esi, esi
// 0085521b  eb0c                 jmp 0x855229
// 0085521d  2401                 and al, 1
// 0085521f  0fb6f0               movzx esi, al
// 00855222  f7de                 neg esi
// 00855224  1bf6                 sbb esi, esi
// 00855226  83c602               add esi, 2
// 00855229  6a00                 push 0
// 0085522b  8bcb                 mov ecx, ebx
// 0085522d  e88ea10700           call 0x8cf3c0
// 00855232  897008               mov dword ptr [eax + 8], esi
// 00855235  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0085523b  8bd0                 mov edx, eax
// 0085523d  83e209               and edx, 9
// 00855240  80fa09               cmp dl, 9
// 00855243  7504                 jne 0x855249
// 00855245  33f6                 xor esi, esi
// 00855247  eb0c                 jmp 0x855255
// 00855249  2401                 and al, 1
// 0085524b  0fb6f0               movzx esi, al
// 0085524e  f7de                 neg esi
// 00855250  1bf6                 sbb esi, esi
// 00855252  83c602               add esi, 2
// 00855255  6a01                 push 1
// 00855257  8bcb                 mov ecx, ebx
// 00855259  e862a10700           call 0x8cf3c0
// 0085525e  897008               mov dword ptr [eax + 8], esi
// 00855261  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 00855267  a830                 test al, 0x30
// 00855269  740f                 je 0x85527a
// 0085526b  2420                 and al, 0x20
// 0085526d  0fb6c0               movzx eax, al
// 00855270  f7d8                 neg eax
// 00855272  1bc0                 sbb eax, eax
// 00855274  83c002               add eax, 2
// 00855277  894320               mov dword ptr [ebx + 0x20], eax
// 0085527a  5f                   pop edi
// 0085527b  5e                   pop esi
// 0085527c  5b                   pop ebx
// 0085527d  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?UpdateFlags@CXTPTabClientWnd@@MAEXPAVCWorkspace@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
