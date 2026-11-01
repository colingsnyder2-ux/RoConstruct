// from server: 100% by auto
// roc 2007-03 005fc5c0  unit: seg_005f0000  size: 191 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fc5c0
//
// 005fc5c0  51                   push ecx
// 005fc5c1  57                   push edi
// 005fc5c2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005fc5c6  8b4710               mov eax, dword ptr [edi + 0x10]
// 005fc5c9  80781502             cmp byte ptr [eax + 0x15], 2
// 005fc5cd  0f84a9000000         je 0x5fc67c
// 005fc5d3  53                   push ebx
// 005fc5d4  55                   push ebp
// 005fc5d5  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 005fc5d9  8d4d01               lea ecx, [ebp + 1]
// 005fc5dc  81f9ffffff3f         cmp ecx, 0x3fffffff
// 005fc5e2  56                   push esi
// 005fc5e3  7717                 ja 0x5fc5fc
// 005fc5e5  8d14ad00000000       lea edx, [ebp*4]
// 005fc5ec  52                   push edx
// 005fc5ed  6a00                 push 0
// 005fc5ef  6a00                 push 0
// 005fc5f1  57                   push edi
// 005fc5f2  e8a90d0000           call 0x5fd3a0
// 005fc5f7  83c410               add esp, 0x10
// 005fc5fa  eb09                 jmp 0x5fc605
// 005fc5fc  57                   push edi
// 005fc5fd  e87e0d0000           call 0x5fd380
// 005fc602  83c404               add esp, 4
// 005fc605  85ed                 test ebp, ebp
// 005fc607  8b5f10               mov ebx, dword ptr [edi + 0x10]
// 005fc60a  8bf0                 mov esi, eax
// 005fc60c  7e0c                 jle 0x5fc61a
// 005fc60e  8bcd                 mov ecx, ebp
// 005fc610  33c0                 xor eax, eax
// 005fc612  8bfe                 mov edi, esi
// 005fc614  f3ab                 rep stosd dword ptr es:[edi], eax
// 005fc616  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005fc61a  33c9                 xor ecx, ecx
// 005fc61c  394b08               cmp dword ptr [ebx + 8], ecx
// 005fc61f  894c2410             mov dword ptr [esp + 0x10], ecx
// 005fc623  7e39                 jle 0x5fc65e
// 005fc625  8b03                 mov eax, dword ptr [ebx]
// 005fc627  8b0488               mov eax, dword ptr [eax + ecx*4]
// 005fc62a  85c0                 test eax, eax
// 005fc62c  7424                 je 0x5fc652
// 005fc62e  8d7dff               lea edi, [ebp - 1]
// 005fc631  8b4808               mov ecx, dword ptr [eax + 8]
// 005fc634  8b10                 mov edx, dword ptr [eax]
// 005fc636  23cf                 and ecx, edi
// 005fc638  85d2                 test edx, edx
// 005fc63a  8b2c8e               mov ebp, dword ptr [esi + ecx*4]
// 005fc63d  8928                 mov dword ptr [eax], ebp
// 005fc63f  89048e               mov dword ptr [esi + ecx*4], eax
// 005fc642  8bc2                 mov eax, edx
// 005fc644  75eb                 jne 0x5fc631
// 005fc646  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005fc64a  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005fc64e  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005fc652  83c101               add ecx, 1
// 005fc655  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 005fc658  894c2410             mov dword ptr [esp + 0x10], ecx
// 005fc65c  7cc7                 jl 0x5fc625
// 005fc65e  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005fc661  8b13                 mov edx, dword ptr [ebx]
// 005fc663  03c9                 add ecx, ecx
// 005fc665  6a00                 push 0
// 005fc667  03c9                 add ecx, ecx
// 005fc669  51                   push ecx
// 005fc66a  52                   push edx
// 005fc66b  57                   push edi
// 005fc66c  e82f0d0000           call 0x5fd3a0
// 005fc671  83c410               add esp, 0x10
// 005fc674  8933                 mov dword ptr [ebx], esi
// 005fc676  5e                   pop esi
// 005fc677  896b08               mov dword ptr [ebx + 8], ebp
// 005fc67a  5d                   pop ebp
// 005fc67b  5b                   pop ebx
// 005fc67c  5f                   pop edi
// 005fc67d  59                   pop ecx
// 005fc67e  c3                   ret 
// library lua-5.1.1/lstring.c (function _luaS_resize)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstring.c
