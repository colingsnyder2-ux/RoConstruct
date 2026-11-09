// from server: 100% by auto
// roc 2010-06 00809250  unit: CXTPTabClientWnd  size: 176 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809250
//
// 00809250  53                   push ebx
// 00809251  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00809255  56                   push esi
// 00809256  57                   push edi
// 00809257  8bf9                 mov edi, ecx
// 00809259  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 0080925f  d1ee                 shr esi, 1
// 00809261  f7d6                 not esi
// 00809263  6a02                 push 2
// 00809265  8bcb                 mov ecx, ebx
// 00809267  83e601               and esi, 1
// 0080926a  e831a30700           call 0x8835a0
// 0080926f  897008               mov dword ptr [eax + 8], esi
// 00809272  8bb7b8000000         mov esi, dword ptr [edi + 0xb8]
// 00809278  d1ee                 shr esi, 1
// 0080927a  6a04                 push 4
// 0080927c  8bcb                 mov ecx, ebx
// 0080927e  83e602               and esi, 2
// 00809281  e81aa30700           call 0x8835a0
// 00809286  897008               mov dword ptr [eax + 8], esi
// 00809289  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 0080928f  8bc8                 mov ecx, eax
// 00809291  83e109               and ecx, 9
// 00809294  80f909               cmp cl, 9
// 00809297  7504                 jne 0x80929d
// 00809299  33f6                 xor esi, esi
// 0080929b  eb0c                 jmp 0x8092a9
// 0080929d  2401                 and al, 1
// 0080929f  0fb6f0               movzx esi, al
// 008092a2  f7de                 neg esi
// 008092a4  1bf6                 sbb esi, esi
// 008092a6  83c602               add esi, 2
// 008092a9  6a00                 push 0
// 008092ab  8bcb                 mov ecx, ebx
// 008092ad  e8eea20700           call 0x8835a0
// 008092b2  897008               mov dword ptr [eax + 8], esi
// 008092b5  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 008092bb  8bd0                 mov edx, eax
// 008092bd  83e209               and edx, 9
// 008092c0  80fa09               cmp dl, 9
// 008092c3  7504                 jne 0x8092c9
// 008092c5  33f6                 xor esi, esi
// 008092c7  eb0c                 jmp 0x8092d5
// 008092c9  2401                 and al, 1
// 008092cb  0fb6f0               movzx esi, al
// 008092ce  f7de                 neg esi
// 008092d0  1bf6                 sbb esi, esi
// 008092d2  83c602               add esi, 2
// 008092d5  6a01                 push 1
// 008092d7  8bcb                 mov ecx, ebx
// 008092d9  e8c2a20700           call 0x8835a0
// 008092de  897008               mov dword ptr [eax + 8], esi
// 008092e1  8b87b8000000         mov eax, dword ptr [edi + 0xb8]
// 008092e7  a830                 test al, 0x30
// 008092e9  740f                 je 0x8092fa
// 008092eb  2420                 and al, 0x20
// 008092ed  0fb6c0               movzx eax, al
// 008092f0  f7d8                 neg eax
// 008092f2  1bc0                 sbb eax, eax
// 008092f4  83c002               add eax, 2
// 008092f7  894320               mov dword ptr [ebx + 0x20], eax
// 008092fa  5f                   pop edi
// 008092fb  5e                   pop esi
// 008092fc  5b                   pop ebx
// 008092fd  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?UpdateFlags@CXTPTabClientWnd@@MAEXPAVCWorkspace@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPTabClientWnd.cpp
