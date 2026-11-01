// from server: 100% by auto
// roc 2007-03 005c5050  unit: seg_005c0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c5050
//
// 005c5050  56                   push esi
// 005c5051  57                   push edi
// 005c5052  8bf8                 mov edi, eax
// 005c5054  803f00               cmp byte ptr [edi], 0
// 005c5057  8bf1                 mov esi, ecx
// 005c5059  7406                 je 0x5c5061
// 005c505b  807f0100             cmp byte ptr [edi + 1], 0
// 005c505f  7511                 jne 0x5c5072
// 005c5061  8b4308               mov eax, dword ptr [ebx + 8]
// 005c5064  68dc9f7b00           push 0x7b9fdc
// 005c5069  50                   push eax
// 005c506a  e8e14affff           call 0x5b9b50
// 005c506f  83c408               add esp, 8
// 005c5072  8a07                 mov al, byte ptr [edi]
// 005c5074  3806                 cmp byte ptr [esi], al
// 005c5076  7405                 je 0x5c507d
// 005c5078  5f                   pop edi
// 005c5079  33c0                 xor eax, eax
// 005c507b  5e                   pop esi
// 005c507c  c3                   ret 
// 005c507d  8b4b04               mov ecx, dword ptr [ebx + 4]
// 005c5080  0fbe7f01             movsx edi, byte ptr [edi + 1]
// 005c5084  ba01000000           mov edx, 1
// 005c5089  03f2                 add esi, edx
// 005c508b  3bf1                 cmp esi, ecx
// 005c508d  55                   push ebp
// 005c508e  0fbee8               movsx ebp, al
// 005c5091  7321                 jae 0x5c50b4
// 005c5093  0fbe06               movsx eax, byte ptr [esi]
// 005c5096  3bc7                 cmp eax, edi
// 005c5098  750c                 jne 0x5c50a6
// 005c509a  83ea01               sub edx, 1
// 005c509d  750e                 jne 0x5c50ad
// 005c509f  5d                   pop ebp
// 005c50a0  5f                   pop edi
// 005c50a1  8d4601               lea eax, [esi + 1]
// 005c50a4  5e                   pop esi
// 005c50a5  c3                   ret 
// 005c50a6  3bc5                 cmp eax, ebp
// 005c50a8  7503                 jne 0x5c50ad
// 005c50aa  83c201               add edx, 1
// 005c50ad  83c601               add esi, 1
// 005c50b0  3bf1                 cmp esi, ecx
// 005c50b2  72df                 jb 0x5c5093
// 005c50b4  5d                   pop ebp
// 005c50b5  5f                   pop edi
// 005c50b6  33c0                 xor eax, eax
// 005c50b8  5e                   pop esi
// 005c50b9  c3                   ret 
// library lua-5.1.1/lstrlib.c (function _matchbalance)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lstrlib.c
