// from server: 100% by auto
// roc 2009-06 0077a440  unit: CXTPTabClientWnd  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077a440
//
// 0077a440  53                   push ebx
// 0077a441  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0077a445  56                   push esi
// 0077a446  57                   push edi
// 0077a447  8bf9                 mov edi, ecx
// 0077a449  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 0077a44f  d1ee                 shr esi, 1
// 0077a451  f7d6                 not esi
// 0077a453  6a02                 push 2
// 0077a455  8bcb                 mov ecx, ebx
// 0077a457  83e601               and esi, 1
// 0077a45a  e8b1a30700           call 0x7f4810
// 0077a45f  897008               mov dword ptr [eax + 8], esi
// 0077a462  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 0077a468  d1ee                 shr esi, 1
// 0077a46a  6a04                 push 4
// 0077a46c  8bcb                 mov ecx, ebx
// 0077a46e  83e602               and esi, 2
// 0077a471  e89aa30700           call 0x7f4810
// 0077a476  897008               mov dword ptr [eax + 8], esi
// 0077a479  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0077a47f  8bc8                 mov ecx, eax
// 0077a481  83e109               and ecx, 9
// 0077a484  80f909               cmp cl, 9
// 0077a487  7504                 jne 0x77a48d
// 0077a489  33f6                 xor esi, esi
// 0077a48b  eb0c                 jmp 0x77a499
// 0077a48d  2401                 and al, 1
// 0077a48f  0fb6f0               movzx esi, al
// 0077a492  f7de                 neg esi
// 0077a494  1bf6                 sbb esi, esi
// 0077a496  83c602               add esi, 2
// 0077a499  6a00                 push 0
// 0077a49b  8bcb                 mov ecx, ebx
// 0077a49d  e86ea30700           call 0x7f4810
// 0077a4a2  897008               mov dword ptr [eax + 8], esi
// 0077a4a5  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0077a4ab  8bd0                 mov edx, eax
// 0077a4ad  83e209               and edx, 9
// 0077a4b0  80fa09               cmp dl, 9
// 0077a4b3  7504                 jne 0x77a4b9
// 0077a4b5  33f6                 xor esi, esi
// 0077a4b7  eb0c                 jmp 0x77a4c5
// 0077a4b9  2401                 and al, 1
// 0077a4bb  0fb6f0               movzx esi, al
// 0077a4be  f7de                 neg esi
// 0077a4c0  1bf6                 sbb esi, esi
// 0077a4c2  83c602               add esi, 2
// 0077a4c5  6a01                 push 1
// 0077a4c7  8bcb                 mov ecx, ebx
// 0077a4c9  e842a30700           call 0x7f4810
// 0077a4ce  897008               mov dword ptr [eax + 8], esi
// 0077a4d1  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0077a4d7  a830                 test al, 0x30
// 0077a4d9  740f                 je 0x77a4ea
// 0077a4db  2420                 and al, 0x20
// 0077a4dd  0fb6c0               movzx eax, al
// 0077a4e0  f7d8                 neg eax
// 0077a4e2  1bc0                 sbb eax, eax
// 0077a4e4  83c002               add eax, 2
// 0077a4e7  894320               mov dword ptr [ebx + 0x20], eax
// 0077a4ea  5f                   pop edi
// 0077a4eb  5e                   pop esi
// 0077a4ec  5b                   pop ebx
// 0077a4ed  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?UpdateFlags@CXTPTabClientWnd@@MAEXPAVCWorkspace@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
