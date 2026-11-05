// from server: 100% by auto
// roc 2009-12 0079d460  unit: seg_00790000  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079d460
//
// 0079d460  56                   push esi
// 0079d461  57                   push edi
// 0079d462  8bf8                 mov edi, eax
// 0079d464  803f00               cmp byte ptr [edi], 0
// 0079d467  8bf1                 mov esi, ecx
// 0079d469  7406                 je 0x79d471
// 0079d46b  807f0100             cmp byte ptr [edi + 1], 0
// 0079d46f  7511                 jne 0x79d482
// 0079d471  8b4308               mov eax, dword ptr [ebx + 8]
// 0079d474  682cb19e00           push 0x9eb12c
// 0079d479  50                   push eax
// 0079d47a  e871c8feff           call 0x789cf0
// 0079d47f  83c408               add esp, 8
// 0079d482  8a07                 mov al, byte ptr [edi]
// 0079d484  3806                 cmp byte ptr [esi], al
// 0079d486  7405                 je 0x79d48d
// 0079d488  5f                   pop edi
// 0079d489  33c0                 xor eax, eax
// 0079d48b  5e                   pop esi
// 0079d48c  c3                   ret 
// 0079d48d  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0079d490  0fbe7f01             movsx edi, byte ptr [edi + 1]
// 0079d494  46                   inc esi
// 0079d495  55                   push ebp
// 0079d496  0fbee8               movsx ebp, al
// 0079d499  ba01000000           mov edx, 1
// 0079d49e  3bf1                 cmp esi, ecx
// 0079d4a0  731d                 jae 0x79d4bf
// 0079d4a2  0fbe06               movsx eax, byte ptr [esi]
// 0079d4a5  3bc7                 cmp eax, edi
// 0079d4a7  750c                 jne 0x79d4b5
// 0079d4a9  83ea01               sub edx, 1
// 0079d4ac  750c                 jne 0x79d4ba
// 0079d4ae  5d                   pop ebp
// 0079d4af  5f                   pop edi
// 0079d4b0  8d4601               lea eax, [esi + 1]
// 0079d4b3  5e                   pop esi
// 0079d4b4  c3                   ret 
// 0079d4b5  3bc5                 cmp eax, ebp
// 0079d4b7  7501                 jne 0x79d4ba
// 0079d4b9  42                   inc edx
// 0079d4ba  46                   inc esi
// 0079d4bb  3bf1                 cmp esi, ecx
// 0079d4bd  72e3                 jb 0x79d4a2
// 0079d4bf  5d                   pop ebp
// 0079d4c0  5f                   pop edi
// 0079d4c1  33c0                 xor eax, eax
// 0079d4c3  5e                   pop esi
// 0079d4c4  c3                   ret 
// library lua-5.1/lstrlib.c (function _matchbalance)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lstrlib.c
